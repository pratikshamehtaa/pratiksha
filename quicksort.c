#include <stdio.h>

int partition(int arr[], int lb, int ub)
{
    int pivot, start, end,temp;
    pivot = arr[lb];
    start = lb;
    end = ub;
    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            temp = arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
    temp=arr[lb];
    arr[lb]=arr[end];
    arr[end]=temp;
    return end;
}

void quicksort(int arr[], int lb, int ub)
{
    int loc;
    if (lb < ub)
    {
        loc = partition(arr, lb, ub);
        quicksort(arr, lb, loc - 1);
        quicksort(arr, loc + 1, ub);
    }
}

void printArr(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main()
{
    int size, array[10], i;
    printf("ENTER SIZE OF THE ARRAY: ");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        printf("ENTER ELEMENT: ");
        scanf("%d", &array[i]);
    }
    quicksort(array, 0, size - 1);
    printf("SORTED ARRAY IS: ");
    printArr(array, size);
    return 0;
}
