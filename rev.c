#include<stdio.h>
#include<stdlib.h>

void rev(char *str)
{
    if(*str)
        rev(str+1);
        printf("%c",*str);
}
int main()
{
    char str[] = "tasks";
    rev(str);
    getchar();
    return 0;
}
