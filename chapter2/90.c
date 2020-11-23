float fpwr2(int x) {
  unsigned exp, frac;
  unsigned u;

  if (x < -23) {
    // too small
    exp = 0;
    frac = 0;
  } else if (x < 0) {
    // denormalized result
    exp = 0;
    frac = 1 << (23 - (-x));
  } else if (x < 8) {
    // normalized result
    exp = 1 << (x - 1);
    frac = 0;
  } else {
    // too big
    exp = 1 << 7;
    frac = 0;
  }

  u = exp << 23 | frac;
  return u2f(u);
}