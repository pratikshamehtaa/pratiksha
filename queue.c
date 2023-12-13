#include <stdio.h>

void enq();
void deq();
void display();
int queue[10], size, front = 0, rear = -1;

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
    if(rear == size - 1)
    {
        printf("overflow\n");
        return;
    }
    rear++;
    printf("enter element\n");
    scanf("%d", &queue[rear]);
    return;

}

void deq()
{
    if(front > rear)
    {
        printf("underflow\n");
        return;
    }
    printf("deleted element %d\n", queue[front]);
    front++;
    return;
}

void display()
{
    if(front > rear)
    {
        printf("underflow\n");
        return;
    }

    for(int i = front; i <= rear; i++)
    {
        printf("%d", queue[i]);
    }
    printf("\n");
}
