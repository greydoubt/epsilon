#include "fltklcd.h"
#include <stdlib.h>
#include <stdio.h> // FIXME: remove printfs

#include <FL/Fl_draw.H>

FltkLCD::FltkLCD(int x, int y, int w, int h, const char * label) :
  Fl_Widget(x, y, w, h, label) {
  m_framebuffer = malloc(w*h);
// FIXME: Delete the framebuffer!
}

void FltkLCD::draw() {
  printf("DRAW\n");
  fl_draw_image_mono((const uchar *)m_framebuffer,
      x(), // x
      y(), // y
      w(), // width
      h(), // height,
      1, // byte-delta between pixels
      0); // byte-delta between lines;
}
