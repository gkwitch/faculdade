#include <stdio.h>

int main(){
    int a;
    int b;
    int sum;

    printf("Write a number for sum: ");
    scanf("%d", &a);
    printf("Write a number for sum: ");
    scanf("%d", &b);

    sum = a + b;
    printf("The result is: %d\n", sum);
    return(0);

}
