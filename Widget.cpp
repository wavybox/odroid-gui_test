#include <utility>
#include "Widget.hpp"

using namespace Widget;

// BaseWidget

// The constructor method
BaseWidget::BaseWidget() {
  child = NULL;
}

// Sets the child
void BaseWidget::setChild(BaseWidget* widget) {
  this->child = widget;
}

// Returns the minimum size of the widget
std::pair<int, int> BaseWidget::getMinSize() {
  return std::make_pair(min_x, min_y);
}

// Panel

// Renders itself and its child
void Panel::render(int x0, int y0, int x1, int y1) {
  LCD.fillRect(x0, y0, (x1-x0), (y1-y0), color);

  if (child != NULL) {
    child->render(x0+BORDER, y0+BORDER, x1-BORDER, y1-BORDER);
  }
}

// Sets the panel background color
void Panel::setColor(uint16_t p_color) {
  color = p_color;
}

// SplitBoxBase

// Sets the two children for the SplitBoxes
void SplitBoxBase::setChild(BaseWidget* widget1, BaseWidget* widget2) {
  this->child = widget1;
  this->child2 = widget2;
}

// VSplitBox

// Renders the VSplitBox
void VSplitBox::render(int x0, int y0, int x1, int y1) {
  if (child != NULL) {
    child->render(x0, y0, x1/2 - BORDER/2, y1);
  }

  if (child2 != NULL) {
    child2->render(x1/2 + BORDER/2, y0, x1, y1);
  }
}

// HSplitBox

// Renders the HSplitBox
void HSplitBox::render(int x0, int y0, int x1, int y1) {
  if (child != NULL) {
    child->render(x0, y0, x1, y1/2 - BORDER/2);
  }

  if (child2 != NULL) {
    child2->render(x0, y1/2 + BORDER/2, x1, y1);
  }
}

// Text

// Renders the text widget
void Text::render(int x0, int y0, int x1, int y1) {
  LCD.setCursor(x0, y0);
  LCD.setTextColor(frontColor, backColor);
  LCD.setTextSize(fontSize);
  LCD.setTextFont(fontId);

  LCD.print(text);
}

// Sets the contents of the text widget
void Text::setText(String p_text) {
  text = p_text;
  min_x = LCD.textWidth(text) * fontSize;
}

// Sets the foreground color for the text
void Text::setFrontColor(uint16_t color) {
  frontColor = color;
}

// Sets the background color for the text
void Text::setBackColor(uint16_t color) {
  backColor = color;
}

// Sets the font id for the text
void Text::setFont(int id) {
  fontId = id;
  min_y = LCD.fontHeight(id) * fontSize;
}

// Sets the font size fot the text
void Text::setSize(int size) {
  fontSize = size;
  min_x = LCD.textWidth(text) * fontSize;
  min_y = LCD.fontHeight(fontId) * fontSize;
}