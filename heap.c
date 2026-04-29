#include <stdio.h>
#include <stdlib.h>

// heap datatype
typedef struct heap
{
    int data[10];
    int max;
    int next;
} heap;

heap *initHeap(void)
{
    heap *p = malloc(sizeof(heap));
    return p;
}

int swapElements(int *addr1, int *addr2)
{ // are the addresses provided both valid
    if (addr1 == NULL || addr2 == NULL)
        return -1;
    // are the addresses pointing to the same element
    if (addr1 == addr2)
    {
        printf("Cannot be the same element");
        return -1;
    }

    int temp = *addr1;
    *addr1 = *addr2;
    *addr2 = temp;

    return 0;
}

void display_array(int arr[], int length)
{
    if (length == 0 ){printf("This heap is empty");}
    for (int i = 0; i < length; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int swapElementsByIndex(int index1, int index2, int arr[])
{
    if (index1 < 0 || index2 < 0)
        return -1;

    if (index1 == index2)
    {
        printf("Cannot swap with same indexes");
        return -1;
    }

    int temp = arr[index2];
    arr[index2] = arr[index1];
    arr[index1] = temp;
}

int getChildrenNodes(int arr[], int node)
{
    int child1 = arr[2 * node + 1];
    int child2 = arr[2 * node + 2];
    printf("children are %d and %d \n", child1, child2);
}

void checkAndSwapParent(int child, int arr[])
{
    int parent = (child - 1) / 2;

    if (parent < 0)
        parent = 0;

    if (arr[child] > arr[parent])
    {
        printf("swapping child and parent\n");
        swapElementsByIndex(child, parent, arr);
    }
}

void Heapify(int arr[], int sizeOfArray)
{
    int i = sizeOfArray - 1;
    for (i; i != 0; i--)
    {
        checkAndSwapParent(i, arr);
    }
}

void addItem(int newItem, heap *p)
{
    p->data[p->next] = newItem;
    p->next++;

    Heapify(p->data, p->next);
}

// typedef struct heap
// {
//     int data[10];
//     int max;
//     int last;
// }heap;

void main(void)
{
    heap *p = initHeap();
    p->max = 10;
    p->next = 0;

    int array[7] = {15, 30, 8, 10, 20, 40, 5};

    display_array(p->data, p->next);

    for (int i = 0; i < 7; i++)
    {
        addItem(array[i], p);
    }

    display_array(p->data, p->next);

    addItem(89,p);

    display_array(p->data, p->next);

    Heapify(p->data, p->next);

    display_array(p->data, p->next);

}