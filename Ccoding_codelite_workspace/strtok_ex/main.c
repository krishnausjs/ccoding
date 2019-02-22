/* strtok example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="- This, a sample string.This is string2\nThis is string3";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str,",.\n");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, ",.\n");
  }
  return 0;
}