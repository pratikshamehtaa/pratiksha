#include<stdio.h>
#include<stdlib.h>

int visited[100];
int A[100][100];

void DFS(int i,int size){
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < size; j++)
    {
        if(A[i][j]==1 && !visited[j]){
            DFS(j,size);
        }
    }
}

int main(){

    int size;
    printf("enter size of matrix\n");
    scanf("%d", &size);

    for(int i = 0; i < size; i++)
    {
        for(int j =0; j < size; j++)
        {
            printf("enter element %d,%d \n",i,j);
            scanf("%d", &A[i][j]);
        }
    }

    int ele;
    printf("dfs of element \n");
    scanf("%d", &ele);

    DFS(ele,size);
}
