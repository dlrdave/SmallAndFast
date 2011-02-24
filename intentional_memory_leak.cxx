#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

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
