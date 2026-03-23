/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /*
  100 ^ 101 == 001
  a^b = ~((~(a & ~b)) & (~(~a & b)))
  */
  return ~((~(x & ~y)) & (~(~x & y)));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return  1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  //利用Tmax的性质: TMax + 1 = TMin, TMax ^ TMin = -1 (全1)
  //可以通过 !(~z) 将 全1/非全1 转化为 1/0
  //需要注意的是, 满足上式的还有 -1 + 1 = 0, -1 ^ 0 = -1 (全1)
  //怎么证明满足这个条件的只有这两种情况？（一个数+1之后的结果和自己按位完全相反）
  int y = x + 1;
  return !(~(x ^ y)) & !!y;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int mask = 0xAA;
  mask = mask | (mask << 8);
  mask = mask | (mask << 16);
  return !(mask ^ (x & mask));
  // int y = x & mask;
  // return !~(y | (y >> 1))
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int a = (x ^ 0x30) >> 3;
  int b = (x ^ 0x38) >> 1;
  return (!a) | (!b);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  //思路：
  //先想到将conditional转化成(y & y_mask) | (z & z_mask)的形式
  //x == 0则 y_mask = 0, z_mask = 11..1, etc
  //再来想mask怎么用x来表示
  int y_mask = ~(!x) + ((!x) << 1); //可以直接用~z_mask
  int z_mask = ~(!x) + 1;
  return (y & y_mask) | (z & z_mask);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int cond = !(x^y); //equal
  int sign_x = (x >> 31) & 1;
  int sign_y = (y >> 31) & 1;
  int same_sign = (sign_x ^ sign_y);
  int diff = x + (~y) + 1; //注意正溢出问题
  cond = cond | (same_sign & sign_x); //如果x,y符号相反，且x为负数，则return 1; x为正数,则return 0;
  
  cond = cond | (!same_sign & !!((diff >> 31) & 1)); //需要same_sign，在这里起到shortcut的作用！确保在符号不同时，不进行这一步
  return cond;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  //思路：一个数x是否为0的判断方法：x和-x的符号位都是0，当且仅当x=0
  int sign_x = (x >> 31) & 1;
  int sign_neg_x = ((~x + 1) >> 31) & 1;
  int temp = sign_neg_x | sign_x;
  //或者直接将x和-x放在一起：
  //combine_sign = (x | (~x + 1)) >> 31;
  return ~temp + 2;// return temp ^ 1; 利用^1来翻转0，1
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int ans = 1; //符号位
  /*
  int sign = (x >> 31) & 1;
  int mask = (~!sign + 1); //sign = 0, mask = 11..1
  x = (x & mask) | (~x & ~mask); //x为正数则不变，x为负数则x = ~x
  */

  //利用符号位+算数右移构建mask
  int mask = x >> 31;
  int next_x = 0;
  int z_mask = 0;
  int y_mask = 0;

  x = (x & ~mask) | (~x & mask);

  next_x = x >> 16;
  z_mask = ~(!next_x) + 1;
  y_mask = ~z_mask;
  x = (next_x & y_mask) | (x & z_mask); // x = (x >> 16) ? (x >> 16) : x
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
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  if((uf & 0x7f800000) == 0x7f800000) // E =11111111, NaN
    return uf;
  //if(!uf) return uf; // 0 在denorm中有讨论
  if(((uf >> 23) << 24) == 0) // denorm：很巧妙的不需要讨论scale之后是denorm还是norm--操作是相同的。
    {
      return (uf & 0xff800000) | ((uf & 0x007fffff) << 1); //保留符号位和 0 阶码，尾数左移 1 位，溢出部分自动顶进阶码位
      //更节省：return (uf << 1) | (uf & 0x80000000)
    }
  return uf + 0x00800000;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  int sign = uf & 0x80000000;
  int exp = (uf & 0x7f800000) >> 23;
  int E = exp - 127; //denorm会直接round to zero
  int frac = uf & 0x007fffff;
  int M = frac;

  if(exp) //exp != 0, uf是norm
      M = frac + 0x00800000;
  if(E >= 0)
  {
    if(E <= 23) M = M >> (23 - E);
    else if(E <= 30) M = M << (E - 23);
    else return 0x80000000u;
  }
  else return 0; // E < 0的时候，round to zero;
  if(sign)   M = ~M + 1;
  return M;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  // 2.0 ^ x = 1.0 * 2 ^ (x + 127 - Bias)
    //unsigned a = 0x40000000;
    if(x >= 0x00000080) return 0x7f800000u; //+inf
    else if(x >= -126) return (127 + x) << 23; //norm
    else if(x >= -149) return 0x00000001 << (x + 149); //denorm
    return 0; //less than denorm
}
