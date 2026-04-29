
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char * data;
    struct node * next;
    
} node;

typedef struct Queue
{
node * front;
node * rear;
int count;

}Queue;

void initQueue(Queue *q){
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}

void enqueue(Queue*q,char *data){
    node *newNode = malloc(sizeof(node));
    if (!newNode) return;

    newNode->data = data;
    newNode->next = NULL;

    if (q->front==NULL && q->rear== NULL){
        q->front = q->rear = newNode;
    }else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->count++;
    printf("new node %s added succesfully",newNode->data);
    return;
}

char* dequeue(Queue *q){
    if (q->front == NULL) return "the queue is empty";

    node * temp = q->front;
    char * s = temp->data;

    q->front = temp->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    q->count--;
    free(temp);

    return s;
}

char * getFront(Queue *q){
    if (q->front == NULL) return "Empty Queue";
    return q->front->data;
}

char * getBack(Queue*q){
    if (q->rear == NULL) return "Empty Queue";
    return q->rear->data;
}

void WalkQueue(Queue *q){
    node * temp = q->front;
    for (int i = 0;  i < q->count; i++){
        char *s = temp->data;
        temp = temp->next;
        printf("%d. %s\n",i+1,s);
    }
}

int main() {
    // 1. Initialize the Queue
    Queue myQueue;
    initQueue(&myQueue); // We pass the address so initQueue can modify it

    printf("--- Testing Enqueue ---\n");
    enqueue(&myQueue, "Greg");
    printf("\n");
    enqueue(&myQueue, "Paul");
    printf("\n");
    enqueue(&myQueue, "Alice");
    printf("\n");

    printf("\n--- Current Queue Stats ---\n");
    printf("Count: %d\n", myQueue.count);
    printf("Front: %s\n", getFront(&myQueue));
    printf("Back: %s\n", getBack(&myQueue));

    printf("\n--- Walking the Queue ---\n");
    WalkQueue(&myQueue);

    printf("\n--- Testing Dequeue ---\n");
    printf("Removed: %s\n", dequeue(&myQueue)); // Should be Greg
    printf("New Front: %s\n", getFront(&myQueue)); // Should be Paul
    printf("New Count: %d\n", myQueue.count);

    printf("\n--- Emptying the Queue ---\n");
    dequeue(&myQueue); // Removes Paul
    dequeue(&myQueue); // Removes Alice
    
    printf("Final Status: %s\n", getFront(&myQueue)); // Should be "Empty Queue"

    return 0;
}