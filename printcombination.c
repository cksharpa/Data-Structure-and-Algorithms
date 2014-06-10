#include<stdio.h>

void combinationutil(int arr[], int data[], int start, int end, int index,int r);

void printcombination(int arr[], int n, int r)
{
    int data[r];
    combinationutil(arr,data,0,n-1,0,r);
}

void combinationutil(int arr[], int data[], int start, int end, int index, int r)
{
    int i,j;
    if(index == r)
    {
        for( j=0;j<r;j++)
            printf("%d ", data[j]);
        printf("\n");
        return;
    }

    for(i=start;i<=end && end-i+1 >=r-index; i++)
    {
        data[index] = arr[i];
        combinationutil(arr,data,i+1,end,index+1,r);
    }
}
int main()
{
    int arr[] = {1,2,3,4,5};
    int r=3;
    int n = sizeof(arr)/sizeof(arr[0]);
    printcombination(arr, n,r);
}
