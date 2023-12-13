#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int hashtable[SIZE];

int hash(int key) 
{
    return key % SIZE;
}

void insert(int key) 
{
    int index = hash(key);
    while (hashtable[index] != 0) 
    {
        index = (index + 1) % SIZE;
    }
    hashtable[index] = key;
}

void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d: %d\n", i, hashtable[i]);
    }
}

int main() {
    int key,res,i;

    printf("How many keys do you want to insert");
    scanf("%d",&res);

    for(i=0;i<res;i++)
    {
        printf("Enter key to insert into the hash table: ");
        scanf("%d", &key);

        insert(key);
    }
    display();

    return 0;
}
