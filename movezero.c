#include<stdio.h>
#include<stdlib.h>

void movezero(int a[], int size)
{
    int i,j;
    int count=0;
    for(i=0;i<size;i++)
    {
        if(a[i]==0)
            count++;
        else
            printf("%d ",a[i]);
    }
    while(count>0)
    {
        printf("0 ");
        count--;
    }
}
int main()
{
    int a[] = {1,0,2,0,0,4,5,8};
    int n = sizeof(a)/sizeof(a[0]);
    movezero(a,n);
    return 0;
}
