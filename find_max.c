#include <stdio.h>

int findMax(int list[], int len)
{
    int max = list[0];

    for (int i = 0; i < len; i++)
    {
        if (list[i] >= max)
        {
            max = list[i];
        }
    }
    return max;
}

void main(void)
{
    int list[] = {2, 56000, 746, 500074, 25, 1, 24, 5, 7, 75};
    int len = (sizeof(list) / sizeof(int));
    printf("\t\t%d\n", findMax(list,len));
}