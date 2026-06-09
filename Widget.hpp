#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <odroid_go.h>
#include <Arduino.h>
#include <string.h>

#include "Catppuccin.hpp"

#define BORDER 4

#define LCD GO.lcd


namespace Widget {
  class BaseWidget {
    public:
      BaseWidget();
      virtual void render(int x0, int y0, int x1, int y1) = 0;
      void setChild(BaseWidget* widget);
    protected:
      BaseWidget* child;
  };

  class Panel : public BaseWidget {
    public:
      void render(int x0, int y0, int x1, int y1) override;
      void setColor(uint16_t p_color);
    protected:
      uint16_t color = CAT_BASE;
  };

  class SplitBoxBase : public BaseWidget {
    public:
      virtual void render(int x0, int y0, int x1, int y1) = 0;
      void setChild(BaseWidget* widget1, BaseWidget* widget2);
    protected:
      BaseWidget* child2;
  };

  class VSplitBox : public SplitBoxBase {
    public:
      void render(int x0, int y0, int x1, int y1) override;
  };

  class HSplitBox : public SplitBoxBase {
    public:
      void render(int x0, int y0, int x1, int y1) override;
  };
}

#endif