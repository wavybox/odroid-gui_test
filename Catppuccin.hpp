#ifndef CATPPUCCIN_HPP
#define CATPPUCCIN_HPP

// Macro to convert RGB value into suitable uint16_t
#define COLOR(r, g, b) ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)

// The enum of the colors
enum Colors {
  CAT_ROSEWATER = COLOR(245,  224,  220),
  CAT_FLAMINGO  = COLOR(242,  205,  205),
  CAT_PINK      = COLOR(245,  194,  231),
  CAT_MAUVE     = COLOR(203,  166,  247),
  CAT_RED       = COLOR(243,  139,  168),
  CAT_MAROON    = COLOR(235,  160,  172),
  CAT_PEACH     = COLOR(250,  179,  135),
  CAT_YELLOW    = COLOR(249,  226,  175),
  CAT_GREEN     = COLOR(166,  227,  161),
  CAT_TEAL      = COLOR(148,  226,  213),
  CAT_SKY       = COLOR(137,  220,  235),
  CAT_SAPPHIRE  = COLOR(116,  199,  236),
  CAT_BLUE      = COLOR(137,  180,  250),
  CAT_LAVENDER  = COLOR(180,  190,  254),
  CAT_TEXT      = COLOR(205,  214,  244),
  CAT_SUBTEXT_1 = COLOR(186,  194,  222),
  CAT_SUBTEXT_0 = COLOR(166,  173,  200),
  CAT_OVERLAY_2 = COLOR(147,  153,  178),
  CAT_OVERLAY_1 = COLOR(127,  132,  156),
  CAT_OVERLAY_0 = COLOR(108,  112,  134),
  CAT_SURFACE_2 = COLOR(88,   91,   112),
  CAT_SURFACE_1 = COLOR(69,   71,   90),
  CAT_SURFACE_0 = COLOR(49,   50,   68),
  CAT_BASE      = COLOR(30,   30,   46),
  CAT_MANTLE    = COLOR(24,   24,   37),
  CAT_CRUST     = COLOR(17,   17,   27)
};

#endif