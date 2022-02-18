#ifndef VEC_H_
#define VEC_H_

typedef struct {
  float x;
  float y;
} vf;

vf vf_makeff(float x, float y) {
  return (vf) {
    .x = x,
    .y = y
  };
}

vf vf_makef(float num) {
  return (vf) {
    .x = num,
    .y = num
  };
}

void vf_str(vf v, char* p) {
  sprintf(p, "(%.1f, %.1f)", v.x, v.y);
}

vf vf_add(vf v1, vf v2) {
  return (vf) {
    .x = v1.x + v2.x,
    .y = v1.y + v2.y
  };
}

vf vf_sub(vf v1, vf v2) {
  return (vf) {
    .x = v1.x - v2.x,
    .y = v1.y - v2.y
  };
}

vf vf_mul(vf v1, vf v2) {
  return (vf) {
    .x = v1.x * v2.x,
    .y = v1.y * v2.y
  };
}

vf vf_div(vf v1, vf v2) {
  return (vf) {
    .x = v1.x / v2.x,
    .y = v1.y / v2.y
  };
}

float vf_magsqr(vf v) {
  return v.x * v.x + v.y * v.y;
}

#endif // VEC_H_
