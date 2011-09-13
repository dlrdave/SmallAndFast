#include <stdio.h>

int main(int argc, const char* argv[])
{
  unsigned char c = 65537; // a constant clearly outside the range of a 'char'
  unsigned int i = 0; // "i<argc" should produce a "signed/unsigned comparison" warning
  unsigned int j = 0; // j is never used after its assignment
  unsigned int k; // k is neither initialized nor used...
  for (; i<argc; ++i)
  {
    fprintf(stdout, "%s\n", argv[i]);
  }
  return 0;
}
