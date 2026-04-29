
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void){
    // int r;
    // srand(2);

    // do{
    //     r = rand() % 100 ;
    //     printf("%d\n",r);
    // }while(r != 21);

    // for (int i = 0; i < 5; i++)
    //     printf("in for loop: %d\n", rand() % 100);

    int  goat_counts = 0;

    switch (goat_counts) // loks for a case match to the condition and starts teh executionn there, if 
    {
    case 0:
        printf("You  have no goats\n");
        // break;
    case 1:
        printf("You  have one goat\n");
        break;
    case 2:
        printf("You  have two goats\n");
    
    default:
        printf("You have many goats\n");
    }

}


