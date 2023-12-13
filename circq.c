#include <stdio.h>

void enq();
void deq();
void display();
int queue[10], size, front = 0, rear = -1, count=0;

int main(void)
{
    int option=0;

    printf("enter size of queue\n");
    scanf("%d", &size);

    while(1)
    {
        printf("1:enqueue\t2:dequeue\t3:display\t4:exit\n");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                enq();
                break;
            case 2:
                deq();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    }
}

void enq()
{
    if(count == size)
    {
        printf("overflow\n");
        return;
    }
    rear = (rear+1)%size;
    printf("enter element\n");
    scanf("%d", &queue[rear]);
    count++;
    return;

}

void deq()
{
    if(count == 0)
    {
        printf("underflow\n");
        return;
    }
    printf("deleted element %d\n", queue[front]);
    front = (front + 1)%size;
    count--;
    return;
}

void display()
{
    if(count == 0)
    {
        printf("underflow\n");
        return;
    }
    int x = front;
    for(int i = 1; i <= count; i++)
    {
        printf("%d", queue[x]);
        x = (x+1)%size;
    }
    printf("\n");
}
