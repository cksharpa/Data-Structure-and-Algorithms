#include<stdio.h>
#include<stdlib.h>

void sumarr(int a[], int n, int sum)
{
    int element,i =0,j;
    while(i<n)
    {
        element = a[i];
        for(j=i+1;j<n;j++)
        {
            element+=a[j];
            if(element == sum)
            {
                printf("index is between %d and %d\n ",i,j);
            }
        }
        i++;
    }
}

int main()
{
    int a[] ={1,2,3,4,5,6};
    int n = sizeof(a)/sizeof(a[0]);
    int sum =21;
    sumarr(a,n,sum);
    return 0;
}
