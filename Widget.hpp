#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <odroid_go.h>
#include <Arduino.h>
#include <utility>

#include "Catppuccin.hpp"
#include "WString.h"

// The border/margin size
#define BORDER 4

// For having to write less
#define LCD GO.lcd

// The main namespace for the widgets
namespace Widget {
  // The base widget, an abstract class that serves as a common interface for all of the widgets
  class BaseWidget {
    public:
      BaseWidget();
      virtual void render(int x0, int y0, int x1, int y1) = 0;
      void setChild(BaseWidget* widget);
      std::pair<int, int> getMinSize();
    protected:
      BaseWidget* child;
      int min_x, min_y = 0;
  };

  // A basic single-color panel
  class Panel : public BaseWidget {
    public:
      void render(int x0, int y0, int x1, int y1) override;
      void setColor(uint16_t p_color);
    protected:
      uint16_t color = CAT_BASE;
      int min_x, min_y = 0;
  };

  // An abstract base class for the SplitBoxes
  class SplitBoxBase : public BaseWidget {
    public:
      virtual void render(int x0, int y0, int x1, int y1) = 0;
      void setChild(BaseWidget* widget1, BaseWidget* widget2);
    protected:
      BaseWidget* child2;
  };

  // Vertical SplitBox, divides the area given into two equally big areas
  class VSplitBox : public SplitBoxBase {
    public:
      void render(int x0, int y0, int x1, int y1) override;
  };

  // Horizontal SplitBox, divides the area given into two equally big areas
  class HSplitBox : public SplitBoxBase {
    public:
      void render(int x0, int y0, int x1, int y1) override;
  };

  // Text widget
  class Text : public BaseWidget {
    public:
      void render(int x0, int y0, int x1, int y1) override;
      void setText(String text);
      void setFrontColor(uint16_t color);
      void setBackColor(uint16_t color);
      void setFont(int id);
      void setSize(int size);
    protected:
      int fontId = 2;
      int fontSize = 1;
      int min_x = 0;
      int min_y = LCD.fontHeight(2);
      uint16_t frontColor = CAT_TEXT;
      uint16_t backColor = CAT_BASE;
      String text;
  };
}

#endif