#include<stdio.h>


void selectionsort(int a[],int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(a[min!=i])
        {
            temp=a[min];
            a[min]=a[i];
            a[i]=temp;

        }
    }
}

void printarr(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
}

int main()
{
    int num,i,arr[10];
    printf("ENTER NUMBER OF ELEMNTS IN THE ARRAY:");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("ENTER ELEMENT: ");
        scanf("%d ",&arr[i]);
    }
    selectionsort(arr,num);
    printf("SORTED ARRAY IS:");
    printarr(arr,num);
}
