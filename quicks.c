int quicksort(int [], int, int);

int main()
{
    int arr[] = {7,4,2,8,9,1,5};
    int i;
    int n = sizeof(arr)/sizeof(arr[0]);

    quicksort(arr, 0, n-1);

    printf("%d \n",n);
    for(i=0;i<n;i++)
    {
        printf("%d  ", arr[i]);
    }
    return 0;
}

int quicksort(int arr[], int first, int last)
{
    int pivot, i,j, temp;

    if(first<last)
    {

    pivot = first;
    i = first;
    j = last;

    while(i<j)
    {

        while(arr[i] <= arr[pivot] && i<last)
            i++;
        while(arr[j] > arr[pivot])
            j--;
        if(i<j)
        {
            int k = arr[i];
            arr[i] = arr[j];
            arr[j] = k;
        }
    }

        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quicksort(arr, first,j-1);
        quicksort(arr, j+1, last);

    }
    return 0;
}
