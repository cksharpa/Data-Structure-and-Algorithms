#include<stdio.h>
#include<stdlib.h>

void crsmall(int a[], int i, int n)
{
    int element = a[0];
    int b[10];

    int count = 0;
    while(i<n)
    {
      if(element > a[i+1])
    {
        count++;
        i++;

    }
    printf(" %d ", count);
    crsmall(a,i+1,n-1);

    }



/*printf("Number of element smaller at right are \n");
for(i=0;i<n;i++)
{
    printf("%d ",b[i]);
} */
}

int main()
{
    int a[] = {5,4,3,2,1};
    int n = sizeof(a)/sizeof(a[0]);
    crsmall(a,0,n-1);
    getchar();
    return 0;
}
