#include <odroid_go.h>

#include "Gui.hpp"
#include "Catppuccin.hpp"
#include "Widget.hpp"

void setup() {
  Serial.begin(115200);
  GO.begin();

  // The back panel of the whole software
  Widget::Panel backPanel;

  backPanel.setColor(CAT_BASE);

  backPanel.render(0, 0, 320, 240);
}

void loop() {
  //GO.update();
}
