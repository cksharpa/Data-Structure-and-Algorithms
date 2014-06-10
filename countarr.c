#include<stdio.h>

int countarr(int a[], int n, int item)
{
    int count = 0;
    int i=0;
    while(i<n)
    {
        if(a[i] == item)
        {
            count++;
            i++;
        }
        else
            i++;
    }
    return count;
}
int main()
{
    int a[] = {1,2,2,2,2,3,4,4};
    int count;
    int n =sizeof(a)/sizeof(a[0]);
    count = countarr(a,n,4);
    printf("total element %d",n);
    printf("\ntotal count is %d ", count);
    getchar();
    return 0 ;
}
