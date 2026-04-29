
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{ // define the linked list structure
    int num;
    struct node *next;
} node;

typedef struct Queue
{
    int count;
    node *front;
    node *rear;
} Queue;

void initQueue(Queue *q)
{
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

int size(Queue *q)
{
    return q->count;
}

bool isEmpty(Queue *q)
{
    return (q->count == 0);
}

int peek(Queue *q)
{
    if (isEmpty(q))
        return -1;

    return q->front->num;
}

void enqueue(Queue *q, int value)
{
    node *newNode = malloc(sizeof(node));

    if (!newNode)
        return;

    newNode->num = value;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->count++;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
        return -1;

    node *temp = q->front;
    int dequeueValue = temp->num;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    q->count--;
    return dequeueValue;
}

void clearQueue(Queue *q)
{
    while (!isEmpty(q))
    {
        dequeue(q);
    }
}

int main()  //with simple logic to test out the different alogorithms for the queue data structure
{
    Queue Queue1;

    initQueue(&Queue1);

    enqueue(&Queue1, 11); 
    printf("11 added to queue\n");
    enqueue(&Queue1, 54);
    printf("54 added to queue\n");
    enqueue(&Queue1, 2004);
    printf("2004 added to queue\n");
    printf("First item in Queue %d\n", peek(&Queue1)); //11
    printf("Queue Size: %d\n", size(&Queue1)); //3
    printf("%d, removed form queue\n",dequeue(&Queue1)); //11
    printf("First Iem in Queue now %d\n", peek(&Queue1)); //54
    printf("Queue Size: %d\n", size(&Queue1)); //2
    clearQueue(&Queue1); //clers queue on program compeltion to avoid memory loss
    printf("Queue Size: %d\n", size(&Queue1)); //0
    return 0;
}