#include <stdio.h>
#include <stdlib.h>

int main (){
    //w for write
    //a for append
    //r for read
//     FILE * fpointer = fopen("employees.txt", "w");
//
//     fprintf(fpointer, "Jim, Salesman\nPam, Reception\nOscar Acounting\n");

    char line[255];
    FILE * fpointer = fopen("employees.txt", "r");

    fgets(line, 255, fpointer);
    printf("%s", line);
    fgets(line, 255, fpointer);
    printf("%s", line);

    fclose(fpointer);
    return 0;
}


