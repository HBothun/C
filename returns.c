 #include <stdio.h>
#include <stdlib.h>

double cube(double num);

int max(int num1, int num2, int num3){
    int result;

    if(num1 >= num2 && num1 >= num3){
        result = num1;
    } else if(num2 >= num1 && num2 >= num3){
        result = num2;
    } else {
        result = num3;
    }
    return result;
}

int main(){
    printf("%f\n", cube(3.0));
    printf("%d\n", max(10, 20, 30));

    if(!(3 > 2) || 2 != 5){
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}

double cube(double num){
    return num * num * num;
}
