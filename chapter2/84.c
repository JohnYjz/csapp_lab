
/*
浮点数除了符号位以外，作为无符号数的完全可以比对 P81
*/
int float_le(float x, float y) {
  unsigned ux = f2u(x);
  unsigned uy = f2u(y);

  unsigned sx = ux >> 31;
  unsigned sy = uy >> 31;


  int result;
  (!sy && sx) && (result = 1);
  (sy && !sx) && (result = 0);
  (((ux - uy) >> 31) & 1) && (result = 1); /* +0 == -0 */
  (!sx && !sy) && (result = ux - uy);
  (sx && sy) && (result = uy - ux);
  return result;
}