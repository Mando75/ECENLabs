/***********************************************************************
* Program:
*    Lab Datalab
*    Brother Jones, ECEN 324
* Author:
*    Bryan Muller
* Summary:
*    This file contains several challenge problems intended to
*    teach us more about bitwise operators
***********************************************************************/

/* 
 * CS:APP Data Lab 
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *          Even though you may work as a team, all students should
 *          individually submit a solution.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
        {
                /* Team name: Replace with either:
                   Your login ID (Linux Lab username) if working as a one person team
                   or, ID1+ID2 where ID1 is the login ID of the first team member
                   and ID2 is the login ID of the second team member.
                    Example: joestudent+zmename */
                "mando0975+agehring",
                /* Student name 1: Replace with the name of first team member */
                "Bryan Muller",
                /* Login ID 1: Replace with the login ID of first team member */
                "mando0975",

                /* The following should only be changed if there are two team members */
                /* Student name 2: Name of the second team member */
                "Adam Gehring",
                /* Login ID 2: Login ID of the second team member */
                "agehring"
        };

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:
 
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

  Note that in order to make the dlc (data lab checker) happy you need
  to declare all variables at the first of the function.
      dlc happy with:                 dlc not happy with:
      ---------------                 -------------------
      int Funct( arg1, arg2) {          int Funct( arg1, arg2) {
         int varA = ~0;                    int varA = ~0;
         int varB = 1;                     varA = varA + 4;
         varA = varA + 4;                  int varB = 1;
          ...                               ...

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
     NOTE: You may create big constants using code.  
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
     NOTE: You may define additional functions while you are working to
           solve the problems, but the final submission should not have any.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce 
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
    /* This is an application of DeMorgan's law
     * to distribute the negation*/
    return ~x & ~y;
}

/*
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 */
int bitXor(int x, int y) {
/**
 *  Uses nand operations to produce a xor
 */
    int nand1 = ~(x & y);
    int nand2 = ~(x & nand1);
    int nand3 = ~(y & nand1);
    int nand4 = ~(nand2 & nand3);
    return nand4;
}

/*
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
    /**
     * If x and y are equal, xor will produce 0x00
     * To turn that into a value of 0x00 or 0x01 (true/false)
     * We need to use the logical not (!) twice.
     */
    return !!(x ^ y);
}

/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    /**
     * Shifts x n bytes
     * Uses a mask to get the last byte
     */
    n = n << 3;
    x = x >> n;
    return x & 0xFF;
}

/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
    /**
     * Executes a right shift to move LSB to the MSB
     * Then executes a right shift to move the MSB back to the LSB
     */
    int y = x << 31;
    return y >> 31;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
    /**
     *  shift x n to the right
     *  Create a mask by shifting 1 (-n + 32) and adding ~0
     *  This will convert the arithmetically changed bits back
     *  to their logical values.
     */
    int negN= ~n + 1;
    int maxVal = ~0;
    // this mask will consist of n leading 0s followed by 32 - n 1s
    int mask = (1 << (negN + 32)) + maxVal;
    x = x >> n;
    return x & mask;
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    /**
     * Based off of what Brother Jones presented in class, with help
     * from the book Hacker's Delight pg. 66.
     * 35 operations
     */
    int mask1 = ((((((0x55 << 8) + 0x55) << 8) + 0x55) << 8) + 0x55);
    int mask2 = ((((((0x33 << 8) + 0x33) << 8) + 0x33) << 8) + 0x33);
    int mask3 = ((((((0x0F << 8) + 0x0F) << 8) + 0x0F) << 8) + 0x0F);

    x = x + (~((x >> 1) & mask1) + 0x01);
    x = (x & mask2) + ((x >> 2) & mask2);
    x = (x + (x >> 4)) & mask3;
    x = x + (x >> 8);
    x = x + (x >> 16);
    return x & 0x3f;
}

/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
    /**
     * //TODO Add description
     */
    int invX = ~x;
    int negX = invX + 1;
    return ((~negX  & invX) >> 31) & 1;
}

/*
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 4 
 */
int leastBitPos(int x) {
    /**
     * By inverting and adding one, we create
     * a mask that will return the position
     * of the least significant 1 bit.
     */
    int negX = ~x + 1;
    return x & negX;
}

/*
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
    /**
     * Shift one to the 32nd position,
     * not the bitstring, and you will have
     * a zero followed by 31 ones = maxVal.
     */
    return ~(0x1 << 31);
}

/*
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
    /**
     * Isolates the most significant bit
     * via masking and returns whether
     * the number is negative
     */
    int mask = 0x1 << 31;
    int masked = x & mask;
    return (masked >> 31) + 1;
}

/*
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
    /**
     *  Checks the msb of x and y
     *  Also checks if x and y are equal
     */
    int msbX = !((x >> 31) + 1);
    int msbY = !((y >> 31) + 1);
    /**
     * when x is larger, then the sign bit of (~y + x) is 0
     * when y is larger, then the sign bit of (~y + x) is 1
     */
    int mask = ((~y + x) >> 31);
    /* Checks if signs are equal */
    int equal = (!(msbX ^ msbY)) & mask;

    int lessThan = msbX & !msbY;

    return !(equal | lessThan);
}

/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    /**
     * I used StackOverflow for help on this one.
     * https://stackoverflow.com/questions/5061093/dividing-by-power-of-2-using-bit-shifting
     *
     */
     // shift msb to first position
     int shifted = x >> 31;
     // create a mask by shifting n over 1 and adding -1
     int mask = (1 << n) + ~0;
     return (x + (shifted & mask)) >> n;
}

/*
 * abs - absolute value of x (except returns TMin for TMin)
 *   Example: abs(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int abs(int x) {
    /**
     * Uses the msb to transform negative numbers
     * into their positive values
     **/
    int msbX = x >> 31;
    int invMsb = (~msbX) + 1;
    return((x ^ (msbX)) + invMsb);
}

/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
    /**
     * Uses the msb of the sum of x and y, along with
     * the msb of x and y to determine whether or not
     * sum x + y overflowed
     */
    int sum = x + y;
    int msbSum = (~(sum >> 31)) + 1;
    int msbX = (~(x >> 31)) + 1;
    int msbY = (~(y >> 31)) + 1;
    return !((~(msbX ^ msbY)) & (msbY ^ msbSum));
}
