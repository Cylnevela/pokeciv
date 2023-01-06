// Generated by dia2code
#ifndef ENGINE__PROTECTEDCOMMAND__H
#define ENGINE__PROTECTEDCOMMAND__H

#include <vector>
#include <stack>
#include <memory>
#include <json/json.h>

namespace engine {
  class Action;
};
namespace state {
  class State;
};
namespace engine {
  class ProtectedCommand;
  class Command;
}

#include "Action.h"
#include "Command.h"

namespace engine {

  /// class ProtectedCommand - 
  class ProtectedCommand : public engine::Command {
    // Attributes
  protected:
    std::vector<int> target;
    // Operations
  public:
    ProtectedCommand (int i, int j);
    void execute (std::stack<std::shared_ptr<Action>>& pile, state::State& state);
    void serialize (Json::Value& out, int nTour) const;
    static ProtectedCommand* deserialize (const Json::Value& in);
    // Setters and Getters
    const std::vector<int>& getTarget() const;
    void setTarget(const std::vector<int>& target);
  };

};

#endif