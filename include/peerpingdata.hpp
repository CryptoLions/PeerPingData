/*
*	Created by CryptoLions, 2019
*
*	Web: https://CryptoLions.io
*   Git: https://github.com/CryptoLions/PeerPingData
*/

#include <eosio/eosio.hpp>
#include <eosio/transaction.hpp>
using namespace eosio;


CONTRACT peerpingdata : public contract {
   public:
      using contract::contract;

      ACTION push( name source,  name destination, uint64_t latency);
      using push_action = action_wrapper<"push"_n, &peerpingdata::push>;
	  
	  
	private:
	
		TABLE datat {
				uint64_t		id;
				uint128_t		cid;
				name			source;
				name			destination;
				uint64_t		latency;
				uint64_t		date; 

				auto primary_key() const {
					return id;
				}
		
				uint64_t by_latency() const {
					return latency;
				}
				
				uint64_t by_cid() const {
					return cid;
				}
		};
		typedef eosio::multi_index< "data"_n, datat, 		
				eosio::indexed_by< "cid"_n, eosio::const_mem_fun< datat, uint64_t, &datat::by_cid > >,
				eosio::indexed_by< "latency"_n, eosio::const_mem_fun< datat, uint64_t, &datat::by_latency > >
		> data;
};