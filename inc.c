#include <stdio.h>
#include <string.h>

main()
{
   int i=3, j;
   j = ++i*++i*++i;
   printf("j= %d, i=%d",j,i);
   return 0;
}

