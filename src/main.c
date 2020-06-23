#include <genesis.h>
#include <bmp.h>

int main()
{

  //Initialise the bitmap engine
  BMP_init(FALSE, BG_A, PAL0, FALSE);
  BMP_setBufferCopy(TRUE); // if we do not do this, the bitmap pixels and lines will flicker when drawing

  //Set some palette colours
  u16 colour_red = RGB24_TO_VDPCOLOR(0xff0000);
  u16 colour_green = RGB24_TO_VDPCOLOR(0x00ff00);
  u16 colour_blue = RGB24_TO_VDPCOLOR(0x0000ff);
  VDP_setPaletteColor(12, colour_red);
  VDP_setPaletteColor(13, colour_green);
  VDP_setPaletteColor(14, colour_blue);

  //When we are working in bitmap mode, we must left shift the colours, or we get gaps in pixels drawn
  int pal_red = 12;
  pal_red |= pal_red << 4;

  int pal_green = 13;
  pal_green |= pal_green << 4;

  int pal_blue = 14;
  pal_blue |= pal_blue << 4;

  //Lissajous Variables
  int a = 2;
  int b = 3;
  fix16 delta = 3.14/2;

  //Variables needed for the loop, and drawing of the bitmap pixels
  fix16 i = 0;
  fix16 x = 0;
  fix16 y = 0;

  while(TRUE)
  {
      //The loop to draw the lissajous curve
      for (i = 0; i < 1024; i++)
      {
        x = 120 + sinFix16(a*i + delta);
        y = 80 + sinFix16(b*i);
        BMP_setPixel(x, y, pal_green);
        BMP_flip(FALSE);
      }

      break;
  }
  return 0;
}
