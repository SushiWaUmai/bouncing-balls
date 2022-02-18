#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "vec.h"
#include "screen.h"
#include "physics.h"
#include "ball.h"

#define WIDTH	128
#define HEIGHT 64
#define FPS 60
#define DT (1.0f / FPS)
#define BALL_N 20

bool screen_buffer[WIDTH * HEIGHT];
ball balls[BALL_N];

int rand_range(int min, int max) {
  int r = rand() % (max - min + 1);
  return r + min;
}

int main(void) {
  srand(time(NULL));

  for (int i = 0; i < BALL_N; i++) {
    vf pos = vf_makeff(rand_range(WIDTH / 4, WIDTH / 4 * 3), rand_range(HEIGHT / 4, HEIGHT / 4 * 3));
    vf vel = vf_makeff((float)rand_range(-100, 100) / 10.0f, (float)rand_range(-100, 100) / 10.0f);
    vf acc = vf_makeff(0.0f, (float)rand_range(10, 100) / 10.0f);

    physics_body body = create_body(pos, vel, acc);

    balls[i] = create_ball(body, (float)rand_range(10, 100) / 10.0f, (float)rand_range(70, 100) / 100.0f);
  }

  while (true) {
    for (int i = 0; i < BALL_N; i++) {
      update_ball(&balls[i], WIDTH, HEIGHT, DT, screen_buffer);
    }

    show(screen_buffer, WIDTH, HEIGHT);

    usleep(1000 * 1000 / FPS);
    clear(screen_buffer, WIDTH, HEIGHT);
  }

  return 0;
}
