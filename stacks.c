
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct numNode
{ // structure of the linked list
    int num;
    struct numNode *next;
} Node;

typedef struct Stack
{ // to create and track instances of the linked list Stacks
    Node *top;
    int count;
} Stack;

void initStack(Stack *s)
{ // initialises the stack with the NULL initial pointer and a sount of 0, the length of out linked list
    s->top = NULL;
    s->count = 0;
}

void push(Stack *s, int value)
{ // takes the address of a stack and adds the value to it
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL)
        return;

    newNode->next = s->top;
    newNode->num = value;

    s->top = newNode;
    s->count++;
}

int size(Stack *s)
{
    return s->count;
};

bool isEmpty(Stack *s)
{
    if (size(s) == 0)
        return true;
    return false;
};

int peek(Stack *s)
{
    if (isEmpty(s))
        return -1;
    return s->top->num;
};

int pop(Stack *s)
{ // removes and return sthe last item added to the stack, decrements teh count too
    if (isEmpty(s))
        return false;

    Node *temp = s->top;
    int poppedValue = temp->num;

    s->top = s->top->next;
    free(temp); // gives the control of this mem address back to the computer
    s->count--;

    return poppedValue;
}

void clearStack(Stack *s)
{
    while (!isEmpty(s))
    {
        pop(s);
    }
}

int main()
{
    Stack Stack1;
    initStack(&Stack1); // creates a stack instace with count one and init address for next NYLL

    push(&Stack1, 34);
    printf("Added 34\n");
    push(&Stack1, 654);
    printf("Added 654\n");
    push(&Stack1, 10);
    printf("Added 10\n");

    printf("Current Size: %d\n", size(&Stack1));    // Prints 3
    printf("Top Element: %d\n", peek(&Stack1));     // Prints 10
    printf("Item removed: %d\n", pop(&Stack1));     // prints 10
    printf("Top Element now: %d\n", peek(&Stack1)); // Prints 654

    if (isEmpty(&Stack1))
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack still has %d items.\n", size(&Stack1));
    }

    return 0;
}