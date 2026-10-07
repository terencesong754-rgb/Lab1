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
  4. Interprets integer expressions using the Data Lab 32-bit bit-vector
     model: results outside the signed range retain their low 32 bits.


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
#include "bits.h"

// P1
/* 
 * signMask - return a mask with only the most significant bit set (0x80000000)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int signMask(void) {
  return 1 << 31;
}

// P2
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1, bitXor(7, 7) = 0
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 2
 */
int bitXor(int x, int y) {
	return~( ~(~x & y) & ~(~y & x));
}

// P3
/*
 * negativePart - return -x if x < 0, otherwise return 0
 *   Examples: negativePart(-10) = 10, negativePart(5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int negativePart(int x){
  return (~x+1) & (x>>31);;
}


// P4
/*
 * copyByteWithin - copy byte src of x to byte dst, leaving all other bytes unchanged
 *   Bytes are numbered from 0 (least significant) to 3 (most significant).
 *   You can assume 0 <= src <= 3 and 0 <= dst <= 3.
 *   Example: copyByteWithin(0x11223344, 0, 2) = 0x11443344
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int copyByteWithin(int x, int src, int dst) {
  int byte = (0xff) & ( x >> (src << 3));
   x = x & ~(0xff << (dst << 3));
  return x | (byte << (dst << 3));
}

// P5
/* 
 * logicalShift - shift x to the right by n bits, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int logicalShift(int x, int n) {
  int mask = ~(1 << 31 >> n << 1);
  return (x >> n) & mask;
}

// P6
/*
 * swapNibblePairs - swap the low and high 4 bits within each byte of x
 *   Examples: swapNibblePairs(0xAB) = 0xBA
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 18
 *   Rating: 4
 */
int swapNibblePairs(int x) {
    int mask = 0x0F | (0x0F << 8);
    mask = mask | (mask << 16);
    int low = x & mask;
    int high = (x >> 4) & mask;
    return (high) | (low << 4);
}

// P7
/*
 * secondLowestZeroBit - return a mask that marks the position of the second least significant 0 bit
 *   Examples: secondLowestZeroBit(0xFFFFFFFA) = 0x4, secondLowestZeroBit(0x7FFFFFFF) = 0
 *             secondLowestZeroBit(-1) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 4
 */
int secondLowestZeroBit(int x) {
  x = ~x;
  int n = (x & (~x + 1)) ^ x;
  return n & (~n + 1);
}

// P8
/*
 * oddParity - return the odd parity bit of x, that is,
 *      when the number of 1s in the binary representation of x is even, then the return 1, otherwise return 0.
 *   Examples: oddParity(5) = 1, oddParity(7) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 56
 *   Rating: 5
 */
int oddParity(int x) {
    x = x ^ (x >> 16);
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    x = x ^ (x >> 1);
    return !(x & 1);
}

// P9
/* 
 * rotateRightBits - rotate x to right by n bits
 *   you can assume n >= 0
 *   Examples: rotateRightBits(0x12345678, 8) = 0x78123456
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 5
 */
int rotateRightBits(int x, int n) {
   int m = 32 + (~n + 1);

  int right = x << m;

  int left = (x >> n) & ~(~0 << m);

  return left | right;
}

// P10
/*
 * roundEvenPow2 - round nonnegative x to the nearest multiple of 2^n.
 *   If x is exactly halfway between two multiples, choose the multiple whose
 *   quotient by 2^n is even.
 *   You can assume 0 <= x <= 0x3fffffff and 1 <= n <= 16.
 *   Examples: roundEvenPow2(10, 2) = 8, roundEvenPow2(14, 2) = 16
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 5
 */
int roundEvenPow2(int x, int n) {
  int mask = (1 << n) + ~0;
  int remainder = x & mask;
  int base =  ~mask & x;

  int half = 1 << (n + ~0);
  int isUp = !!(remainder & half);
  int lower = !!((half + (~0)) & remainder);
  int odd = (x >> n) & 1;

  int add = isUp & (lower | odd);
  return base + (add << n);
}

// P11
/* 
 * midpointTowardFirst - return the exact mathematical midpoint (x+y)/2
 *   without overflow. If the exact midpoint lies halfway between two
 *   integers, choose the adjacent integer that is closer to the first
 *   argument x.
 *   Examples: midpointTowardFirst(4, 7) = 5,
 *             midpointTowardFirst(7, 4) = 6
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 32
 *   Rating: 5
 */
int midpointTowardFirst(int x, int y) {
  int mid = (x & y) + ((x ^ y) >> 1);
  int odd = (x ^ y) & 1;

  int signX = (x >> 31) & 1;
  int signY = (y >> 31) & 1;
  int signDiff = signX ^ signY;

  int bigger = (signDiff & signY) | ((!signDiff) & !(((x + ~y+1) >> 31) & 1));
  return mid + (odd & bigger);
}


// P12
/* 
 * isBetweenEitherOrder - return 1 when x lies in the inclusive interval whose
 *   endpoints are a and b. The endpoints may be given in either order.
 *   Example: isBetweenEitherOrder(5, 8, 3) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 48
 *   Rating: 7
 */
int isBetweenEitherOrder(int x, int a, int b) {
  int signX = (x >> 31) & 1;
  int signA = (a >> 31) & 1;
  int signB = (b >> 31) & 1;
  int signDA = signA ^ signX;
  int signDB =signB ^ signX;
  
  int BA = (signDA & signA) | ((!signDA) & !(((x + ~a+1) >> 31) & 1));
  int BB = (signDB & signB) | ((!signDB) & !(((x + ~b+1) >> 31) & 1));

  return (BA ^ BB) | !(x ^ a) | !(x ^ b);
}

// P13
/* 
 * mul5Sat - return x*5, and if x*5 overflow, change the result to 
 * INT_MAX(0x7fffffff) or INT_MIN(0x80000000) correspondingly
 *   Examples: mul5Sat(1) = 0x5, mul5Sat(0x40000000) = 0x7fffffff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 7
 */
int mul5Sat(int x) {
  int INT_MIN = 1 << 31;
  int INT_MAX = ~INT_MIN;

  int overflow1 = !!(((x << 2) >> 2) ^ x);
  int mul5 = (x << 2) + x;
  int overflow2 = ((x ^ mul5) >> 31) & 1;
  int sign = x >> 31;
  int isOverflow = overflow1 | overflow2;

  int mask = ~isOverflow + 1;
  int border = (INT_MAX & ~sign) | (INT_MIN & sign);
  return (~mask & mul5) | (mask & border);
}

// P14
/* 
 * classifyAdd3 - classify the exact mathematical sum x+y+z.
 *   Return 1 if the sum is greater than INT_MAX, -1 if it is less than
 *   INT_MIN, and 0 otherwise. You may not use a wider integer type.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 52
 *   Rating: 7
 */
int classifyAdd3(int x, int y, int z) {
  int signX = (x >> 31) & 1;
  int signY = (y >> 31) & 1;

  int xy = x + y;
  int signXY = (xy >> 31) & 1;

  int overflow1 = ~(signX ^ signY) & (signXY ^ signX);

  int signZ = (z >> 31) & 1;

  int xyz = xy + z;
  int signXYZ = (xyz >> 31) & 1;
  int overflow2 = ~(signXY ^ signZ) & (signXYZ ^ signXY);

  int pos1 = overflow1 & !signX;
  int neg1 = overflow1 & signX;

  int pos2 = overflow2 & !signXY;
  int neg2 = overflow2 & signXY;

  int pos = pos1 | pos2;
  int neg = neg1 | neg2;

  return pos + (~neg + 1);
}

// P15
/*
 * floatScaleThreeHalves - Return bit-level equivalent of expression f*3/2 for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   Use round-to-nearest-even. Preserve the sign of both +0 and -0.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 60
 *   Rating: 7
 */
unsigned floatScaleThreeHalves(unsigned uf) {
  unsigned sign = uf & 0x80000000;
  unsigned exp = (uf >> 23) & 0xff;
  unsigned frac = uf & 0x7fffff;
  unsigned sig;
  unsigned prod;
  unsigned result;
  unsigned lost;

  if (exp == 0xff) return uf;

   
  if (exp == 0) {
      prod = frac * 3;
      result = prod >> 1;
      if ((prod & 1) && (result & 1)) result++;
      return sign | result;
  }

  sig = (1u << 23) | frac;
  prod = sig * 3;

  if (prod < (1u << 25)) {
      result = prod >> 1;
      if ((prod & 1) && (result & 1))  result++;
  } 
  else {
     result = prod >> 2;
      lost = prod & 3;

      if (lost > 2 ||
        (lost == 2 && (result & 1))) {
        result++;
      }

      exp++;

      if (exp >= 0xff) return sign | 0x7f800000;
  }

  if (result == (1u << 24)) {
      result >>= 1;
      exp++;

     if (exp >= 0xff) return sign | 0x7f800000;
  }

  frac = result & 0x7fffff;

  return sign | (exp << 23) | frac;
}

// P16
/* 
 * floatRoundEven - round the floating-point value represented by uf to the
 *   nearest integer, with halfway cases rounded to the even integer. Return
 *   the bit-level representation of that integer as a single-precision float.
 *   If rounding produces zero, preserve the input sign; thus a negative
 *   value that rounds to zero returns -0. When uf is NaN or infinity,
 *   return uf unchanged.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 65
 *   Rating: 10
 */
unsigned floatRoundEven(unsigned uf) {
  unsigned sign = uf & 0x80000000;
  unsigned exp = (uf >> 23) & 0xff;
  unsigned frac = uf & 0x7fffff;
  int E;
  unsigned mask;
  unsigned lost;
  unsigned half;
  unsigned value;
  if (exp == 0xff) return uf;

  E = exp - 127;
  if (E < -1) return sign;

  if (E == -1) {
      if (frac == 0) return sign;
      return sign | 0x3f800000;
  }

  if (E >= 23) return uf;

  mask = (1u << (23 - E)) - 1;
  lost = frac & mask;
  half = 1u << (22 - E);

  value = uf & ~mask;

  if (lost > half ||
      (lost == half && ((value >> (23 - E)) & 1))) {
      value += 1u << (23 - E);
  }

  return value;
}


// P17
/*
 * float_i2f - Return bit-level equivalent of expression (float) x.
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 40
 *   Rating: 10
 */
unsigned float_i2f(int x) {
  unsigned sign = 0;
  unsigned ux;
  unsigned exp;
  unsigned frac;
  unsigned rest;
  unsigned half;
  int pos = 31;

  if (x == 0) return 0;

  if (x < 0) {
      sign = 0x80000000;
      ux = ~x + 1;
  } else {
      ux = x;
  }


  while (((ux >> pos) & 1) == 0) pos--;

  exp = pos + 127;

  if (pos <= 23) {
      frac = (ux << (23 - pos)) & 0x7fffff;
  } else {
      int shift = pos - 23;

      frac = (ux >> shift) & 0x7fffff;
      rest = ux & ((1u << shift) - 1);
      half = 1u << (shift - 1);

      if (rest > half ||
          (rest == half && (frac & 1))) {
          frac++;

          if (frac >> 23) {
              exp++;
              frac = 0;
          }
      }
  }

  return sign | (exp << 23) | frac;
}



// P18
/*
 * bitCount - return count of number of 1's in the binary representation of x
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 10
 */
int bitCount(int x) {
  int m1 = 0x55 | (0x55 << 8);
  int m2 = 0x33 | (0x33 << 8);
  int m4 = 0x0f | (0x0f << 8);

  m1 = m1 | (m1 << 16);   /* 0x55555555 */
  m2 = m2 | (m2 << 16);   /* 0x33333333 */
  m4 = m4 | (m4 << 16);   /* 0x0f0f0f0f */

  x = (x & m1) + ((x >> 1) & m1);
  x = (x & m2) + ((x >> 2) & m2);
  x = (x & m4) + ((x >> 4) & m4);

  x = x + (x >> 8);
  x = x + (x >> 16);

  return x & 0x3f;
}

// P19
/*
 * bitReverse - Reverse bits in an 32-bit integer
 *   Examples: bitReverse(0x80000004) = 0x20000001
 *             bitReverse(0x7FFFFFFF) = 0xFFFFFFFE
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 34
 *   Rating: 10
 */
int bitReverse(int x)
{
  int m1 = 0x55 | (0x55 << 8);
  int m2 = 0x33 | (0x33 << 8);
  int m4 = 0x0f | (0x0f << 8);
  int m8 = 0xff | (0xff << 16);

  m1 = m1 | (m1 << 16);   /* 0x55555555 */
  m2 = m2 | (m2 << 16);   /* 0x33333333 */
  m4 = m4 | (m4 << 16);   /* 0x0f0f0f0f */

  x = ((x >> 1) & m1) | ((x & m1) << 1);
  x = ((x >> 2) & m2) | ((x & m2) << 2);
  x = ((x >> 4) & m4) | ((x & m4) << 4);
  x = ((x >> 8) & m8) | ((x & m8) << 8);
  x = (x << 16) | ((x >> 16) & 0xffff);

  return x;
}
