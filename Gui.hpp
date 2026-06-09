#ifndef GUI_HPP
#define GUI_HPP

#include <odroid_go.h>
#include <Arduino.h>
#include <string.h>

#include "Catppuccin.hpp"

#define WIDTH 320     // screen width
#define HEIGHT 240     // screen height

#define LCD GO.lcd


class Screen {
  public:
    Screen() {}

    virtual ~Screen() = 0;
  private:

};

#endif