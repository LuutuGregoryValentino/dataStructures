
#include <stdio.h>

union person
{
    char *name;
    int age;
    char  gender;
};

void main(){
    union person greg;
    union person *p = &greg;
    p->gender = "M";
    printf("%c",p->gender);
}