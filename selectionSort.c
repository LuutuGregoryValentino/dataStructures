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

void selectionSort(int arr[], int sizeOfArray)
{
    while (sizeOfArray > 0)
    {
        int max = 0;
        // int range = sizeOfArray;
        int indexOfMax = 0;

        for (int i = 0; i < sizeOfArray; i++)
        {
            if (max < arr[i])
            {
                max = arr[i];
                indexOfMax = i;
            }
        }
        int temp = arr[sizeOfArray - 1];
        arr[indexOfMax] = temp;

        arr[sizeOfArray - 1] = max;
        sizeOfArray--;

    }
}

int main(void)
{
    int arr[] = {189, 290850, 6793, 30, 7, 900};
    selectionSort(arr, 6);

    display_array(arr, 6);

    return 0;
}