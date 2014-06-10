#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include<stdio.h>

int main()
{
 uint64_t n,length,breadth, area;
 printf("enter the number of straw ");
 scanf( "%llu", &n);

 if(n%4==0 || n%4==1)
  {
   breadth = n/4;
   length = breadth;
  }
 else if (n%4==2||n%4==3)
  {
   breadth = n/4;
   length = breadth+1;
  }
  
  area = length * breadth;
  printf(" Max area is %llu \n", area);
  
  return 0; 
}
 
