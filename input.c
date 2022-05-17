#include <stdio.h>
#include <stdlib.h>

int main()
{
    char object;
    printf("Favorite letter: ");
    scanf( "%c", &object);
    printf("You picked the letter %c\n", object);
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("You are %d years old\n", age);
    double decimal;
    printf("Enter a decimal: ");
    scanf("%lf", &decimal);
    printf("That was %f\n", decimal);
    char string[20];
    printf("Give your name: ");
    scanf("%s", string);
    printf("well ok %s\n", string);
    // alt for getting strings with space
//     char fullName[25];
//     printf("Full name please: ");
//     fgets(fullName, 25, stdin);
//     printf(fullName);


    return 0;
}
