// Generated by dia2code
#ifndef SERVER__GAMESERVICE__H
#define SERVER__GAMESERVICE__H

#include <json/json.h>

namespace server {
  class Game;
  class AbstractService;
}

#include "Game.h"
#include "HttpStatus.h"
#include "AbstractService.h"

namespace server {

  /// class GameService - 
  class GameService : public server::AbstractService {
    // Associations
    // Attributes
  public:
    Game game;
    // Operations
  public:
    GameService ();
    HttpStatus get (Json::Value& out, int id) const;
    HttpStatus post (const Json::Value& in, int id);
    HttpStatus put (Json::Value& out, const Json::Value& in);
    // Setters and Getters
  };

};

#endif