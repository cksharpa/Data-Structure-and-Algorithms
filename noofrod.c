#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int max(int a, int b)
{
    return(a>b)? a : b;
}

int costmax(int price[], int n)
{
    int val[n+1];
    val[0]=0;
    int i,j;

    for(i=1;i<=n;i++)
    {
        int max_val=INT_MIN;
        for(j=0;j<i;j++)
        {
           max_val=max(max_val, price[j] + val[i-j-1]);
        }
        val[i] = max_val;
    }
    return val[n];
}

int main()

{
    int price[] = {2,3,3,4,5,7,8,9};
    int size= sizeof(price)/sizeof(price[0]);
    printf("max obtain val %d ", costmax(price,size));
    return 0;
}
