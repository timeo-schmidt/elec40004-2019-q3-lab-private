#include "rover_factory.hpp"
#include "rover_svg_writer.hpp"
#include "rover_action_writer.hpp"

#include <cassert>

Rover *rover_factory(const string &type) {

  if(type=="svg") {
    // Return SVG class pointer
    RoverSVGWriter *concrete_svg = new RoverSVGWriter();
    return concrete_svg;
  }

  else if(type=="action") {
    // Return Action class pointer
    RoverActionWriter *concrete_action = new RoverActionWriter();
    return concrete_action;
  }

  else {
    // Unknown Type
    assert(0);
  }


}
