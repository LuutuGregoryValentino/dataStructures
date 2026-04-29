#include <stdio.h>

int main(void){
    int i = 11 ;
    int g; g=1;
    g += i > 10 ? 11: 31;
    printf("%d\n",g);


    int x ;
    x=2;
    printf("%d is : %s\n",x,x%2==0 ? "even":"odd");



    printf("\n\n");

    int a;int b;
    char  * we = "783700000";

    for(a=0,b=0; a<5; a++,b++){
        printf("a=%d,b=%d\n",a,b);
    }

    printf("%zu\n",sizeof we);


}