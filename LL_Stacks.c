
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct numStack // define the linked list structure
{
    int num;
    struct numStack *next;
} ns;

int struct_size = sizeof(ns); // get size of an item of the linked list

ns *addNum(int a, ns *nextAddr)
{ // linked list helper function to add an new node to the linked list

    ns *currentHead = malloc(struct_size);
    if (currentHead == NULL)
        return nextAddr; // if there no allocated mem addr, return that very address... and stop
    currentHead->num = a;
    currentHead->next = nextAddr;
    printf("%d added to stack \n", currentHead->num);

    return currentHead;
}

ns *head = NULL; // defines the start of our linked list globally giving all functions access to the linked list using the head pointer to numStruct

void push(int num)
{ // adds an item to the linked list stack
    head = addNum(num, head);
}

int pop(void)
{ // removes and returns an item form the linked list stack
    if (head == NULL)
    {
        printf("The stack is empty");
        exit(1);
    }
    else
    {
        ns *temp = head;
        int value = temp->num;
        free(temp); // clears up this memory address
        head = head->next;

        printf("%d removed\n", value);
        return value;
    }
}

int peek(void)
{ // returns the last item added to the linked stack

    if (head == NULL)
    {
        printf("The stack is empty\n");
        // exit(1);
    }
    else
    {
        return head->num;
    }
}

bool isEmpty()
{ // returns boolean values, true is the list is empty and false if the stack contains any items

    if (head == NULL)
    {
        printf("isEmpty = true\n");
        return true;
    }
    else
    {
        printf("isEmpty = false\n");
        return false;
    }
}

int size(void)
{ // returns an interger equal to the number of items in the linked list

    int count = 0;
    ns *fakeHead = head;
    while (fakeHead != NULL)
    {
        fakeHead = fakeHead->next;
        count++;
    }
    printf("Stack is %d items long\n", count);
    return count;
}

void clearStack(void) 
{ //clears up the stack after beofre the progrma ends to prevent memory leaks
    while (head != NULL)
    {
        ns *temp = head;
        head = head->next;
        free(temp);
    }
    printf("stack cleared and memory freed.\n");
}

void main(void)
{
    size();
    isEmpty();
    push(4);
    size();
    isEmpty();
    push(16);
    size();
    pop();
    peek();
    size();
    pop();
    isEmpty();
    peek();
    clearStack();
}
