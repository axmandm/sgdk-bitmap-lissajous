Draws a lissajous curve on screen, building on https://github.com/axmandm/sgdk-bitmap-sine-wave

Bitmap drawing in this way is _slow_. As per the notes in https://github.com/axmandm/sgdk-bitmap-line, the positioning of BMP_flip(); is key to this.

In the version here, the BMP_flip(); is called in the main loop:

```
for (i = 0; i < 1024; i++)
      {
        x = 120 + sinFix16(a*i + delta);
        y = 80 + sinFix16(b*i);
        BMP_setPixel(x, y, pal_green);
        BMP_flip(FALSE);
      }
```

If this is changed so BMP_flip(FALSE); is outside of this loop (i.e. after the closing curly brace) then the drawing speed is significantly faster - because the bitmap is totally computed, and THEN drawn to screen.
