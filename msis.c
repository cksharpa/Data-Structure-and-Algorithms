#include<stdio.h>
#include<stdlib.h>

int maxsis(int arr[], int n)
{
    int *msis, i, j, max = 0;
    msis = (int*)malloc(sizeof(int) * n);

    for(i = 0;i<n;i++)
        msis[i] = arr[i];

    for(i = 1;i < n; i++)
        for(j=0;j<i;j++)
            if(arr[i] > arr[j] && msis[i] < msis[j] + arr[i])
                msis[i] = msis[j] + arr[i];

    for(i=0;i<n;i++)
        if(max < msis[i])
            max = msis[i];

    free(msis);

    return max;
}

int main()
{
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("sum of msis is %d\n", maxsis(arr,n));
    return 0;
}
