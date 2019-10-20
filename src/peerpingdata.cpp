/*
*	Created by CryptoLions, 2019
*
*	Web: https://CryptoLions.io
*   Git: https://github.com/CryptoLions/PeerPingData
*/


#include <peerpingdata.hpp>

ACTION peerpingdata::push( name source,  name destination, uint64_t latency) {

	require_auth( source );

	check( is_account( source ), "source account does not exist" );
	check( is_account( destination ), "destination account does not exist" );

	uint128_t cid = (uint128_t(source.value) << 64) | destination.value;

	data datatable( _self, _self.value );

	auto cid_index = datatable.template get_index<"cid"_n>();
    auto rec = cid_index.find( cid );
	
	if( rec == cid_index.end() ) {
		datatable.emplace( source, [&]( auto& s ){  
			s.id 			= datatable.available_primary_key();
			s.cid 			= cid;
			s.source      	= source;
			s.destination   = destination;
			s.latency  		= latency;
			s.date 			= current_time_point().sec_since_epoch();
		});
	} else {
		cid_index.modify( rec, source, [&]( auto& s ) {   
			s.latency  		= latency;
			s.date 			= current_time_point().sec_since_epoch();
		});
	}
	
}