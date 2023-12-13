#include<stdio.h>

void insertionsort(int arr[], int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
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
    int size, array[10],i;
    printf("ENTER SIZE OF THE ARRAY");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        printf("ENTER ELEMMENT:");
        scanf("%d",&array[i]);
    }
    insertionsort(array,size);
    printf("SORETED ARRAY IS:");
    printArr(array,size);
}
