#include <am.h>
#include <klib-macros.h>

void draw(uint32_t color) {
  // change the code below
  io_write(AM_GPU_FBDRAW, 0, 0, NULL, 0, 0, false);
}

int main() {
  ioe_init(); // initialization for GUI
  while (1) {
    draw(0x000000ff);
  }
  return 0;
}
