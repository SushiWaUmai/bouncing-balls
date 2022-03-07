#ifndef SCREEN_H_
#define SCREEN_H_

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "./vec.h"

char *table = "._^C";

void clear(bool* buffer, int width, int height) {

  // Move back to the starting position 
  printf("\x1b[%dD", width);
  printf("\x1b[%dA", height / 2);

  memset(buffer, 0, width * height);
}

void show(bool* buffer, int width, int height) {
  assert(height % 2 == 0);

  char* row_buffer = malloc(width * sizeof(char));

  for (int y = 0; y < height / 2; y++) {
    for (int x = 0; x < width; x++) {
      bool t = buffer[(2*y + 0) * width + x];
      bool b = buffer[(2*y + 1) * width + x];

      row_buffer[x] = table[(t<<1)|b];
    }

    fwrite(row_buffer, sizeof(char), width, stdout);
    fputs("\n", stdout);
  }

  free(row_buffer);
}


void draw_circle(vf c, float r, bool* buffer, int width, int height) {
  vf s = vf_sub(c, vf_makef(r));
  vf e = vf_add(c, vf_makef(r));

  for (int y = s.y; y < e.y; y++) {
    for (int x = s.x; x < e.x; x++) {
      vf d = vf_sub(c, vf_makeff((float)x, (float)y));

      if(x >= 0 && x < width && y >= 0 && y < height) {
        // if the current "pixel" is in the range of the circle
        if(vf_sqrmag(d) < r*r) {
          buffer[y * width + x] = true;
        }
      }
    }
  }
}

#endif // SCREEN_H_
