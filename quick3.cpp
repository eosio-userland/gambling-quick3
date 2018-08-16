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
  // banker account
  const static auto BANKER_ACCOUNT = N(eosvegasteam);
  account_name _banker;

  // game config
  constexpr static uint64_t ROUND_TIME = 60 * 10; // 10 mins
  constexpr static uint64_t SINGLE_BET = 2; // 0.0002eos / bet

  constexpr static uint8_t BET_TYPE_1 = 1;
  constexpr static uint8_t BET_TYPE_2 = 1;
  constexpr static uint8_t BET_TYPE_3 = 1;
  constexpr static uint8_t BET_TYPE_4 = 1;
  constexpr static uint8_t BET_TYPE_5 = 1;
  constexpr static uint8_t BET_TYPE_6 = 1;
  constexpr static uint8_t BET_TYPE_7 = 1;
  constexpr static uint8_t BET_TYPE_8 = 1;

  //@abi table game i64
  struct game {
    // overview info
    uint64_t round_counter;
    uint64_t total_man_time;

    // current round
    int64_t bet_pool;
    uint64_t man_time;
    time_point_sec start_time;
    time_point_sec end_time;

    uint64_t primary_key()const { return round_counter; }

    EOSLIB_SERIALIZE( game, (round_counter)(total_man_time)(bet_pool)(man_time)(start_time)(end_time) )
  };

  struct bet {
    account_name      player;

    // memo format: {bet_times}-{bet_type}-{bet_content}
    uint8_t           bet_times; // 256 times as max
    uint8_t           bet_type;
    uint8_t           bet_content;

    uint64_t primary_key()const { return player; }

    EOSLIB_SERIALIZE( offer, (id)(owner)(bet)(commitment)(gameid) )
  };

  // how to record details in each round?
};

EOSIO_ABI( quick3, (hi) )
