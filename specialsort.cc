#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int main()
 {
  int a[] = {-1,1,3,-2,2};
  int b[5], p=0, q=0;
  int negative=0,i;
  
  for(i=0;i<5;i++)
   {
    if(a[i]<0)
     negative++;
   }

   for(i=0;i<5;i++)
   {
    if(a[i]<0) {
    b[p]=a[i];
    p++;
    } 
    else {
      b[q+negative]=a[i];
      q++;
    }
   }
   for(i=0;i<5;i++)
   {
    printf("%d ",b[i]);
   }
  return 0;
 }
