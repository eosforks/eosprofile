#include "eosprofile.hpp"


namespace eosio {


   void profile::blacklistadd( account_name account, asset token_min ) {
      require_auth( _self );

      print(token_min, "\n");

      eosio_assert( _blacklist.find( account ) == _blacklist.end(),
                   " account alreaded blacklisted" );

      // _blacklist.emplace( _self, [&](auto& bl) {
      //    bl.account = account;
      // });
   }


   void profile::blacklistrm( account_name account ) {
      require_auth( _self );

      auto blacklist_itr = _blacklist.find( account );

      eosio_assert( blacklist_itr != _blacklist.end(),
                    " account not on blacklist");

      const auto& blacklisted_account = *blacklist_itr;

      _blacklist.erase( blacklisted_account );
   }


}  /// namespace eosio
