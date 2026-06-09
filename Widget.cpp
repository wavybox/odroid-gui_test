#include "Widget.hpp"

using namespace Widget;

// BaseWidget

BaseWidget::BaseWidget() {
  child = NULL;
}

void BaseWidget::setChild(BaseWidget* widget) {
  this->child = widget;
}

// Panel

void Panel::render(int x0, int y0, int x1, int y1) {
  LCD.fillRect(x0, y0, (x1-x0), (y1-y0), color);

  if (child != NULL) {
    child->render(x0+BORDER, y0+BORDER, x1-BORDER, y1-BORDER);
  }
}

void Panel::setColor(uint16_t p_color) {
  color = p_color;
}

// SplitBoxBase

void SplitBoxBase::setChild(BaseWidget* widget1, BaseWidget* widget2) {
  this->child = widget1;
  this->child2 = widget2;
}

// VSplitBox

void VSplitBox::render(int x0, int y0, int x1, int y1) {
  if (child != NULL) {
    child->render(x0, y0, x1/2 - BORDER/2, y1);
  }

  if (child2 != NULL) {
    child2->render(x1/2 + BORDER/2, y0, x1, y1);
  }
}

// HSplitBox

void HSplitBox::render(int x0, int y0, int x1, int y1) {
  if (child != NULL) {
    child->render(x0, y0, x1, y1/2 - BORDER/2);
  }

  if (child2 != NULL) {
    child2->render(x0, y1/2 + BORDER/2, x1, y1);
  }
}