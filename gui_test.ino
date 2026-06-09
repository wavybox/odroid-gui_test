#include <odroid_go.h>

#include "Gui.hpp"
#include "Catppuccin.hpp"
#include "Widget.hpp"

void setup() {
  Serial.begin(115200);
  GO.begin();

  Widget::Panel backPanel;

  backPanel.setColor(CAT_BASE);

  Widget::VSplitBox split;

  Widget::HSplitBox lSplit;
  Widget::Panel rPanel;

  Widget::Panel uPanel;
  Widget::Panel dPanel;

  uPanel.setColor(CAT_TEAL);
  dPanel.setColor(CAT_RED);

  rPanel.setColor(CAT_BLUE);

  lSplit.setChild(&uPanel, &dPanel);

  split.setChild(&lSplit, &rPanel);

  backPanel.setChild(&split);

  backPanel.render(0, 0, 320, 240);
}

void loop() {
  //GO.update();
}
