#include <stdio.h>
#include <stdlib.h>

// Define a structure for each element in the priority queue
struct Node {
    int data;
    int priority;
    struct Node* next;
};
struct Node* head;

// Function to create a new node with given data and priority
struct Node* newNode() {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    printf("enter data\n");
    scanf("%d", &temp->data);

    printf("enter priority\n");
    scanf("%d", &temp->priority);

    temp->next = NULL;

    return temp;
}

// Function to insert a new node with given data and priority into the priority queue
void enqueue() {
    struct Node* new_node = newNode();

    // Special case: if the queue is empty or the new node has less priority
    if (head == NULL || new_node->priority < head->priority) {
        new_node->next = head;
        head = new_node;
        return;
    }
    // Find the position to insert the new node
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->priority <= new_node->priority) {
        temp = temp->next;
    }

    // Insert the new node at the correct position
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to remove from the beginning of priority queue
void dequeue() {
    if (head == NULL) {
        printf("Priority Queue is empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp); // Free the memory of the removed node
}

// Function to print the elements of the priority queue
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("(%d, %d) ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

// Driver program to test the priority queue
int main() {
    int option=0;
    while(option != 5)
    {
        printf("1:enqueue\t2:dequeue\t3:display\t4:exit\n");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    }
}
