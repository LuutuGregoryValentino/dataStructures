// #include <stdio.h>

// int main (void){
//     int i = 50;
//     printf("the address of %d is at memory address %p\n",i,&i);
//     int * p = &i;
//     printf("%p/n", p);
// }

#include <stdio.h>

void foo(int x[12])
{
printf("%zu\n", sizeof x);// 8?! What happened to 48?
printf("%zu\n", sizeof(int));// 4 bytes per int
printf("%zu\n", sizeof x / sizeof(int));
}

int y = 3;

int func1(int *p)
{
    printf("%d\n", *p);
    *p = 10;
}

void main(){
    int a = 2*y;
    printf("a:%d\n",a);
    int *n = & y;
    func1(n);
    printf("y:%d\ta:%d\n",y,a);
}

int main(void) 
{
    // int i;
    // float f[4];

    // f [0] = 3.14159;
    // f [1] = 1.41421;
    // f [2] = 1.61803;
    // f [3] = 2.71828;
    
    // for (i = 0; i < 4; i++)
    // {
    //     printf("%f\t", f[i]);
        
    // }

}