#include<stdio.h>
#include<stdlib.h>

int maxcount(int a[], int size)
{
    int i,j;
    int count[]={1,1,1,1,1,1,1};
     int max = count[0];
     int result;
    for(i=0;i<size;i++)
    {
        for(j=i+1; j<size;j++)
        {
            if(a[i]==a[j])
            {
                count[i] = count[i] + 1;

            }

        }
        printf(" %d\n ",count[i]);

    }
    for(i=1;i<size-1;i++)
    {

        if(max<count[i+1])
        {
            max = count[i];

            result = i;
        }

    }
    printf("max is %d index is %d", max, result);

    return result;
}
int main()
{
    int a[] = {2,2,5,5,5,5,7};
    int n = sizeof(a)/sizeof(a[0]);
    int max_num=maxcount(a,n);
    printf("number with max count is %d\n", a[max_num]);
    return 0;
}
