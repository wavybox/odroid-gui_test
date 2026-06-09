#include <utility>
#include "Widget.hpp"

using namespace Widget;

// BaseWidget

BaseWidget::BaseWidget() {
  child = NULL;
}

void BaseWidget::setChild(BaseWidget* widget) {
  this->child = widget;
}

std::pair<int, int> BaseWidget::getMinSize() {
  return std::make_pair(min_x, min_y);
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

// Text

void Text::render(int x0, int y0, int x1, int y1) {
  LCD.setCursor(x0, y0);
  LCD.setTextColor(frontColor, backColor);
  LCD.setTextSize(fontSize);
  LCD.setTextFont(fontId);

  LCD.print(text);
}

void Text::setText(String p_text) {
  text = p_text;
  min_x = LCD.textWidth(text) * fontSize;
}

void Text::setFrontColor(uint16_t color) {
  frontColor = color;
}

void Text::setBackColor(uint16_t color) {
  backColor = color;
}

void Text::setFont(int id) {
  fontId = id;
  min_y = LCD.fontHeight(id) * fontSize;
}

void Text::setSize(int size) {
  fontSize = size;
  min_x = LCD.textWidth(text) * fontSize;
  min_y = LCD.fontHeight(fontId) * fontSize;
}