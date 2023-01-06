// Generated by dia2code
#ifndef RENDER__CHARSTILESET__H
#define RENDER__CHARSTILESET__H

#include <string>
#include <memory>

namespace render {
  class Tile;
};
namespace state {
  class Element;
};
namespace render {
  class TileSet;
};
namespace state {
  class CreaturesGroup;
}

#include "state/Element.h"
#include "TileSet.h"
#include "state/CreaturesGroup.h"

namespace render {

  /// class CharsTileSet - 
  class CharsTileSet : public render::TileSet {
    // Attributes
  private:
    Tile** creatures;
    // Operations
  public:
    CharsTileSet ();
    int getCellWidth () const;
    int getCellHeight () const;
    const std::string getImageFile () const;
    const Tile& getTile (const state::Element& elem) const;
    const Tile& getTile (const std::unique_ptr<state::Element>& elem) const;
    // Setters and Getters
  };

};

#endif