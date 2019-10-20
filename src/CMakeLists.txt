project(peerpingdata)

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package(eosio.cdt)

add_contract( peerpingdata peerpingdata peerpingdata.cpp )
target_include_directories( peerpingdata PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( peerpingdata ${CMAKE_SOURCE_DIR}/../ricardian )