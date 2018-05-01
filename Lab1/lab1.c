/***********************************************************************
* Program:
*    Lab C_lab, ECEN 324 Learning C Lab
*    Brother Jones, ECEN 324
* Author:
*    Bryan Muller
* Summary:
*    This is a conversion of the provided C++ program into C
*    The program will create a table of ASCII characters of the letters A - Z
************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415926

/**
 * This main function will display an ASCII table of the letters A - Z
 */
int main(void)
{
   const char LETTER = 'A';
   // print an integer
   printf("%d\n", 24);
   // print a floating point number with 5 numbers after the decimal
   printf("%.5f\n", PI);
   // print a character
   printf("%c\n", LETTER);

   float payRate = 10.50;
   int hours = 40;

   // print various number types, setting the precision for floats
   printf("Users pay rate: $%.1f\n", payRate);
   printf(" Hours worked: %d\n", hours);
   printf("    Gross Pay: $%.0f\n", (hours * payRate));

   int number;
   // print to stderr using fprintf
   fprintf(stderr, "Enter number: ");
   // read a value into number using scanf
   scanf("%d", &number);
   printf("Twice %d is %d\n", number, number * 2);


   /*********************************************************************/
   /*********************** Output an Integer ***************************/
   /*********************************************************************/
   int anInt = 99;
   float aFloat = 43.2;

   // default integer formatting

   printf("\n"); // blank line
   printf("Integer: %d ###\n", anInt);

   // Output the integer in a fixed field width of 10.
   // The object will be right justified in the field.
   //
   printf("Integer: %10d ###\n", anInt);

   // Output the integer in a fixed field width of 10
   // and left justified in the field.
   // note that we do not need to set the justification direction
   // in printf. We pass it a negative number, and it will justify left.
   printf("Integer: %-10d ###\n\n", anInt);

   /*********************************************************************/
   /************************* Output a Float ****************************/
   /*********************************************************************/

   // default formatting
   printf("  Float: %.1f ###\n", aFloat);

   // Output the float in a fixed field width of 10.
   printf("  Float: %-10.1f ###\n", aFloat);

   // Output the float right justified in a field width of 10 with
   // a precision of 2 places after the decimal point for the float.
   printf("  Float: %10.2f ###\n", aFloat);

   // Output the float with 3 places of precision after the decimal point but
   // not giving a field width.
   //
   printf("  Float: %.3f ###\n", aFloat);

   // Output the float with 3 places of precision after the decimal point with
   // a field width of 10.  The other flags set above are still in effect.
   printf("  Float: %10.3f ###\n", aFloat);

   // Output the float with 4 places of precision after the decimal point with
   // a field width of 10 and left justify the numb
   printf("  Float: %-10.4f ###\n\n", aFloat);

   /*********************************************************************
    *************** Create some code to output a table ******************
    *********************************************************************/

   printf("\tOct   Dec   Hex   Char\n");
   printf("\t----------------------\n");
   int letter = 97; // use integer value for character
   for (letter; letter <= 122; letter++)
   {
      // %o, %d, %x, %c used for printing integer, Octal, Decimal, Hex, and Character
      // values respectively
      printf("\t%o   %-5d %-5x %c\n", letter, letter, letter, letter);
   }
   printf("\n");


   /*********************************************************************
    *************** Now play with pointers to finish up *****************
    *********************************************************************/
   int *p1;
   int *p2;

   // malloc replaces new. You must pass it the size of the memory to be allocated
   p1 = (int *) malloc(sizeof(int));
   *p1 = 42;
   p2 = p1;
   printf("*p1 == %d\n", *p1);
   printf("*p2 == %d\n", *p2);

   *p2 = 53;
   printf("*p1 == %d\n", *p1);
   printf("*p2 == %d\n", *p2);

   // allocate some new memory
   p1 = (int *) malloc(sizeof(int));
   *p1 = 88;

   printf("*p1 == %d\n", *p1);
   printf("*p2 == %d\n", *p2);

   printf("Hope you got the point of this example!\n");

   // free is used to deallocate
   free(p1);
   free(p2);

   return 0;
}


