#include<stdio.h>

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void selection(int arr[], int n)
{
 int i, j, min_idx;
 for(i=0;i<n-1;i++)
 {
   min_idx = i;
   for(j=i+1; j < n; j++)
   {
     if(arr[j] < arr[min_idx])
	{
       min_idx = j;
	}
    }
   swap(&arr[min_idx], &arr[i]);
 
 }
}
 void printarray(int arr[], int size)
  {
   int i;
   for(i=0; i< size; i++)
	printf("%d ", arr[i]);
  }

int main()
{
 int arr[]={23,12,24,4,6,15};
 int n= sizeof(arr)/sizeof(arr[0]);
 selection(arr,n);
 printf("sort array : \n");
 printarray(arr,n);
 return 0;
}
 
