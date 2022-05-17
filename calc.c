#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int mono(double num1, char op, double num2){

    double out;

    if (op == '+'){
        out = (num1 + num2);
    }
    else if (op == '-'){
        out = (num1 - num2);
    }
    else if (op == '*'){
        out = (num1 * num2);
    }
    else if (op == '/'){
        out = (num1 / num2);
    }
    else if (op == '^'){
        double p = num1;
        for (int i = 1; i < num2; ++i)
            p *= num1;
            out = p;
    }
    else {
        printf("Bad operator");
    }
    return out;
}

int algebra(){
    char equation[25];
    printf("What is the equation: ");
    fgets(equation, 25, stdin);

    char *charpointR;
    char *charpointL = equation;
    charpointR = (strchr(equation, 61)+1);
    while(*charpointL != '\0' && *charpointL != 61) *charpointL++;
    *charpointL = '\0';
    int rightValue = atoi(charpointR);
    printf("Left: %s\nRight: %d\n", equation, rightValue);

    char *leftover;
    char *multiplier = equation;
    leftover = (strchr(equation, 'x')+1);
    while(*multiplier != '\0' && *multiplier != 'x') *multiplier++;
    *multiplier = '\0';
    int leftMulti = atoi(equation);
    printf("multiplier: %d\noperator: %s\n", leftMulti, leftover);

    char *operator;
    *operator = leftover[1];
    printf("%s\n", *operator);
}

int main(){
    algebra();
    double num1;
    double num2;
    char op;

    printf("Enter a number: ");
    scanf("%lf", &num1);
    printf("Enter opterator: ");
    scanf(" %c", &op);
    printf("Enter a number: ");
    scanf("%lf", &num2);

    double out = mono(num1, op, num2);
    printf("%lf\n", out);
    int i = 3;
    while(i > 0){
        char cont[i];
        printf("Do you wanna keep going? [Y/n]: ");
        scanf(" %c", &cont[i]);
        if(cont[i] == 'y'|| cont[i] == 'Y'){
            double num[i];
            printf("Enter operator: ");
            scanf(" %c", &op);
            printf("Enter a number: ");
            scanf(" %lf", &num[i]);

            out = mono(out, op, num[i]);
            printf("%lf\n", out);

        }
        else if(cont[i] == 'n'|| cont[i] == 'N'){
            printf("\nGood Bye\n-H\n");
            i = 0;
        }
        else {
            printf("Error 9000\n");
        }
    }
    return 0;
}
