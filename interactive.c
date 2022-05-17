#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char secretPhrase(input){
    if (strcmp(input, "carley") == 0){
        printf("Somehow you know the word");
    }
}

int main(){
    printf("Do you know the word?\n");
    fgets(input, 25, stdin);
    secretPhrase(input);
	return 0;
}
