#include<stdio.h>

int main()
{
    int i,l,n,m;
    int a[10];
    printf("Enter the range : ");
    scanf("%d", &n);
    printf("\nlower bound :");
    scanf("%d",&m);
    l=m+n;
    printf("\nSo the upper bound is %d \n",l);
    printf("and range is from %d to %d\n",m,l);

    for(i=0;i<n;i++)
    {
       printf("Enter the %d element ",i+1);
       scanf("%d",&a[i]);

    }

    for(i=0;i<n;i++)
    {

      if(a[i]>m && a[i]<=l)
       {
           return 1;
       }
       else
            return 0;
    }
    getchar();
    return 0;
}
