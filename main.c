#include <stdio.h>
#include<stdlib.h>

 void main()
{
struct bitfield
{
unsigned a:5;
unsigned c:5;
unsigned b:6;

}bit;
char *p;
struct bitfield *ptr,bit1={1,3,3};
p=&bit1;
p++;
//clrscr();
printf("%d",*p);
getchar();
}
