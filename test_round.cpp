#include <iostream>


#include <stdio.h>      /* printf */
#include <math.h>       /* round, floor, ceil, trunc */

int main ()
{
  const char * format = "%.1f \t%.1f \t%.1f \t%.1f \t%.1f\n";
  printf ("value\tround\tfloor\tceil\ttrunc\n");
  printf ("-----\t-----\t-----\t----\t-----\n");
  printf (format, 0.01,round( 0.01),floor( 2.3),ceil( 2.3),trunc( 2.3));
  printf (format, 0.8,round( 0.8),floor( 3.8),ceil( 3.8),trunc( 3.8));
  printf (format, 0.5,round( 0.5),floor( 5.5),ceil( 5.5),trunc( 5.5));
  printf (format, 0.2,round( 0.2),floor( 5.5),ceil( 5.5),trunc( 5.5));
  printf (format, 0.02,round( 0.02),floor( 5.5),ceil( 5.5),trunc( 5.5));
  return 0;
}
