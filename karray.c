#include<stdio.h>
#include<limits.h>

int minjumps(int arr[], int l, int h)
{
    if(h==l)
        return 0;
    if(arr[l] == 0)
        return 9;
    int min = 9;
    int i;
    for( i= l+1;i<=h && i <= l+arr[l];i++)
    {
        int jumps = minjumps(arr, i, h);
        if(jumps != 9 && jumps+1<min)
            min = jumps + 1;
    }
    return min;
}

int main()
{
    int arr[] = {1,3,6,3,2,3,6,8,9,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("minimum number of jumps to reach end is %d ", minjumps(arr,0, n-1));
    return 0;
}
