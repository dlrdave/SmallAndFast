#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>


//
// Define a function, but do not call it from anywhere. No reason, just
// testing things here, move along. This is not the function you're
// looking for.
//
unsigned int multiply_by_e_and_round(const unsigned int input)
{
  double output = 2.718281828459045 * (double) input;
  return (unsigned int)(output + 0.5);
}


int main(int argc, const char* argv[])
{
  const char *leak = (const char *) malloc(42); // no free, intentionally
  int i = 0;
  for (; i<argc; ++i)
  {
    fprintf(stdout, "%s\n", argv[i]);
  }
  return 0;
}
