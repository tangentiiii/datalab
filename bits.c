/* * CS:APP Data Lab 
 * bits.c - Source file with your solutions to the Lab.
 */

#if 0
/*
 * Instructions to Students:
 * STEP 1: Read the following instructions carefully.
 */
#endif

int bitXor(int x, int y) {
  return ~((~(x & ~y)) & (~(~x & y)));
}

int tmin(void) {
  return 1 << 31;
}

int isTmax(int x) {
  int y = x + 1;
  return !(~(x ^ y)) & !!y;
}

int allOddBits(int x) {
  int mask = 0xAA;
  mask = mask | (mask << 8);
  mask = mask | (mask << 16);
  return !(mask ^ (x & mask));
}

int negate(int x) {
  return ~x + 1;
}

int isAsciiDigit(int x) {
  int a = (x ^ 0x30) >> 3;
  int b = (x ^ 0x38) >> 1;
  return (!a) | (!b);
}

int conditional(int x, int y, int z) {
  int y_mask = ~(!x) + ((!x) << 1);
  int z_mask = ~(!x) + 1;
  return (y & y_mask) | (z & z_mask);
}

int isLessOrEqual(int x, int y) {
  int cond = !(x^y);
  int sign_x = (x >> 31) & 1;
  int sign_y = (y >> 31) & 1;
  int diff_sign = (sign_x ^ sign_y);
  int diff = x + (~y) + 1;
  cond = cond | (diff_sign & sign_x);
  cond = cond | (!diff_sign & !!((diff >> 31) & 1));
  return cond;
}

int logicalNeg(int x) {
  int sign_x = (x >> 31) & 1;
  int sign_neg_x = ((~x + 1) >> 31) & 1;
  int temp = sign_neg_x | sign_x;
  return ~temp + 2;
}

int howManyBits(int x) {
  int ans = 1;
  int mask = x >> 31;
  int next_x = 0;
  int z_mask = 0;
  int y_mask = 0;

  x = (x & ~mask) | (~x & mask);

  next_x = x >> 16;
  z_mask = ~(!next_x) + 1;
  y_mask = ~z_mask;
  x = (next_x & y_mask) | (x & z_mask);
  ans = ans + (16 & y_mask);

  next_x = x >> 8;
  z_mask = ~(!next_x) + 1;
  y_mask = ~z_mask;
  x = (next_x & y_mask) | (x & z_mask);
  ans = ans + (8 & y_mask);

  next_x = x >> 4;
  z_mask = ~(!next_x) + 1;
  y_mask = ~z_mask;
  x = (next_x & y_mask) | (x & z_mask);
  ans = ans + (4 & y_mask);

  next_x = x >> 2;
  z_mask = ~(!next_x) + 1;
  y_mask = ~z_mask;
  x = (next_x & y_mask) | (x & z_mask);
  ans = ans + (2 & y_mask);

  next_x = x >> 1;
  z_mask = ~(!next_x) + 1;
  y_mask = ~z_mask;
  x = (next_x & y_mask) | (x & z_mask);
  ans = ans + (1 & y_mask);

  z_mask = ~(!x) + 1;
  y_mask = ~z_mask;
  ans = ans + (1 & y_mask);
  return ans;
}

unsigned floatScale2(unsigned uf) {
  if((uf & 0x7f800000) == 0x7f800000)
    return uf;
  if(((uf >> 23) << 24) == 0)
  {
    return (uf & 0xff800000) | ((uf & 0x007fffff) << 1);
  }
  return uf + 0x00800000;
}

int floatFloat2Int(unsigned uf) {
  int sign = uf & 0x80000000;
  int exp = (uf & 0x7f800000) >> 23;
  int E = exp - 127;
  int frac = uf & 0x007fffff;
  int M = frac;

  if(exp)
      M = frac + 0x00800000;
  if(E >= 0)
  {
    if(E <= 23) M = M >> (23 - E);
    else if(E <= 30) M = M << (E - 23);
    else return 0x80000000u;
  }
  else return 0;
  if(sign) M = ~M + 1;
  return M;
}

unsigned floatPower2(int x) {
    if(x >= 0x00000080) return 0x7f800000u;
    else if(x >= -126) return (127 + x) << 23;
    else if(x >= -149) return 0x00000001 << (x + 149);
    return 0;
}