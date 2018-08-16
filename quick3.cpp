#include <eosiolib/eosio.hpp>
#include <eosiolib/asset.hpp>
#include <eosiolib/time.hpp>

using namespace eosio;

class quick3 : public eosio::contract {
public:
    using contract::contract;

    /// @abi action
    void hi( account_name user ) {
       print( "Hello, ", name{user} );
    }

private:
    account_name _banker;

    //@abi table game i64
    struct game {
        uint64_t id;
        asset    bet;
        time_point_sec deadline;

        uint64_t primary_key()const { return id; }

        EOSLIB_SERIALIZE( game, (id)(bet)(deadline) )
    };
};

EOSIO_ABI( quick3, (hi) )
