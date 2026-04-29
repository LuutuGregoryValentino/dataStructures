#include <stdio.h>



int main(void){
    char * name = "Luutu gregory valentino";
    int num = 10;

    // printf("%s\n",name);
    
    if (sizeof(name) == 4) printf("This name is of an ivalid format\n");
    else if (sizeof name == 8) printf("This name is correct\nName: %s\n",name);
    else printf("Name is of unknown format");

    while (num > 0 ){
        printf("%d\n",num);
        --num;
    }

    do {
        printf("\n\nexecuting the do while loop");
        num ++;
    } while(num<=10);



    // while(1){
    //     printf("This is an infinity loop because one is always true\n");
    // }
}