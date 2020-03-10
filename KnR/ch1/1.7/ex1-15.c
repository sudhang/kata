/* Temperature conversion program using functions */

#include <stdio.h>

float fahrToCelsius(float fahr);

main ()
{
  float lower, upper, step, i;

  lower = 0.0;
  upper = 300.0;
  step = 10.0;

  for ( i = lower ; i <= upper ; i += step )  {
    printf("\nFahrenheit: %6.2f\t Celsius: %6.2f", i, fahrToCelsius( i ) );
  }

  printf("\n");
}

float fahrToCelsius(float fahr)
{
  return ( (5./9.0)*(fahr - 32) );
}
