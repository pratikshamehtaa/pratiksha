#include <stdio.h>

void enqueue(int val);
int dequeue();
int queue[100],front = 0, rear = -1;

int main(void)
{
    int node;
    int i = 1;
    int visited[7] = {0,0,0,0,0,0,0};
    int a [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("%d", i);
    visited[i] = 1;
    enqueue(i); // Enqueue i for exploration
    while (front <= rear)
    {
        node = dequeue();
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

void enqueue(int val)
{
    rear++;
    queue[rear] = val;
}

int dequeue()
{
    if(front > rear)
    {
        printf("underflow\n");
        return -1;
    }
    front++;
    return front;
}
