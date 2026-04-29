#include <stdio.h>
#include <stdlib.h> // Essential for malloc() and free()
#include <string.h>

// 1. The Blueprint
typedef struct node
{
    char *name;
    struct node *next; // The "pointer" to the next scattered struct
} node;

// 2. The Helper Function (The "Push" Logic)
node *addNode(node *currentHead, char *newName)
{
    // Grab memory for a new node
    node *newNode = malloc(sizeof(node));

    // Safety Check: malloc returns NULL if memory is full
    if (newNode == NULL)
    {
        return currentHead;
    }

    newNode->name = newName;

    // Link the new node to the old start of the list
    newNode->next = currentHead;

    printf("Name added: %s\n", newName);

    // The new node is now the new "front" of the chain
    return newNode;
}

int main()
{
    // Start with an empty list (The NULL sentinel)
    node *head = NULL;

    // Add some names
    head = addNode(head, "Paul");
    head = addNode(head, "Greg");
    head = addNode(head, "Alice");

    // 3. THE TRAVERSAL LOOP (The "Important Part")
    node *temp = head; // Start at the beginning
    int pos = 1;

    printf("Walking through the list:\n");
    while (temp != NULL)
    { // Keep going until we hit the NULL end
        printf("%d: %s\n", pos, temp->name);
        pos++;

        // This is the "Hop": Move temp to the next address
        temp = temp->next;
    }

    // 4. CLEANUP (Memory Management)
    // In C, we must manually free what we malloc'd
    node *next;
    while (head != NULL)
    {
        next = head->next;
        free(head);
        head = next;
    }

    return 0;
}



/*so the next pointer is actually teh pointer to a previous item in the linked list?

the pointer doesnt point the next item. pauls next pointer doesnt point to greg, gregs pointer points to paul?

memAddress:A, {name:paul,next:null} ====> memAddress: B {nmae:greg,next:A} */