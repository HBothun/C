#include <stdio.h>
#include <stdlib.h>

int main(){

    char grade = 'A';

    switch(grade){

        case 'A':
            printf("You did great!\n");
            break;
        case 'B':
            printf("You did alright!\n");
            break;
        case 'C':
            printf("You did ok!\n");
            break;
        case 'D':
            printf("You did bad!\n");
            break;
        case 'F':
            printf("You fail!\n");
            break;
        default :
            printf("did you?");
    }

    return 0;
}
