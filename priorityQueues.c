#define maxN 5
#include <stdio.h>

static int a[maxN + 1], N;

void construct(int b[], int M)
{
    for (N = 1; N <= M; N++)
        a[N] = b[N];
}
void insert(int v)
{
    a[++N] = v;
}

int Remove()
{
    int j, max = 1, v;
    for (j = 2; j <= N; j++)
        if (a[j] > a[max])
            max = j;
    v = a[max];
    a[max] = a[N--];
    return v;
}

int main(void){
    int list[5];
    construct(list,5);

    printf("%d\n",Remove());
    printf("%d\n",Remove());
    printf("%d\n",Remove());
    printf("%d\n",Remove());
    printf("%d\n",Remove());
    printf("%d\n",Remove());

}