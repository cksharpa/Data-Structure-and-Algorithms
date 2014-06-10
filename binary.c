#include<stdio.h>

int binary(int arr[], int l, int h, int x)
{
 if(h>=l)
 {
 int mid = l + (h-l)/2;
 if(arr[mid]==x) return mid;
 if(arr[mid]>x) return binary(arr,l,mid-1,x);
 return binary(arr,mid+1,h,x);
 }
 return -1;
}
main()
{
 int arr[]={3,7,9,13,16};
 int n = sizeof(arr)/sizeof(arr[0]);
 int result;
 int x=7;
 result = binary(arr,0,n-1,x);
 printf("position is %d ", result);
 return 0;
}
