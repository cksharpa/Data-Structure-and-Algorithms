#include<stdio.h>

 
void bubble(int arr[], int n)
{
 int i, j;
 for(i=0; i<n; i++)
 {
  for(j=0; j < n-i-1; j++)
  {
  if(arr[j]>arr[j+1])
   {
    int temp = arr[j];
    arr[j] = arr[j+1];
    arr[j+1] = temp;
   }
 }
 }
}

printarray(int arr[], int size)
{
 int i;
 for(i = 0; i<size; i++)
  {
  printf( "%d ", arr[i]);
  }
}

int main()
{
 int arr[] = {3,1,6,4,8,5};
 int n = sizeof(arr)/sizeof(arr[0]);
 bubble(arr,n);
 printf(" sorted array is \n");
 printarray(arr,n);
 return 0 ;
}

