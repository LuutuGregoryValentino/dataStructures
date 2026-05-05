#include <stdio.h>

void display_array(int arr[], int length)
{
    if (length == 0)
    {
        printf("This heap is empty");
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void bubble(int arr[], int size, int num, int index)
{
    while (index != (size - 1))
    {
        int temp = arr[index + 1];
        arr[index + 1] = num;
        arr[index] = temp;

        index++;
    }
}

void bubbleSort(int arr[], int size)
{
    while (size > 0)
    {
        int lastIndex = size - 1;
        int max = 0;
        int indexOfMax = 0;
        for (int i = 0; i < size; i++)
        {
            if (max < arr[i])
            {
                max = arr[i];
                indexOfMax = i;
            }
        }

        bubble(arr, size, max, indexOfMax);
        size--;
        display_array(arr,6);
    }
}

int main(void)
{
    int array[] = {45, 67, 12, 34, 25, 39};

    bubbleSort(array, 6);
    display_array(array, 6);
}