#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int age = 26;
    double number = 3.33;
    char letter = 'H';
    char string[] = "Holden";
    /* This cannot be changed */
    const int NUM = 5;
    printf("Hello\n\"World\"\n");
    printf("%s %d %f %c\n", string, age, number, letter);
    printf("here is math\n%f\n", 5.0 * 4.5);
    printf("%f\n", pow(2, 3));
    return 0;
}
