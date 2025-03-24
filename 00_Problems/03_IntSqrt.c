#include <stdio.h>

int intSqrt(int number) {
    // The minimum sqrt for any number is 1
    int intSqrt = 1;

    // Increment by one until intSqrt^2 > number
    while (intSqrt * intSqrt < number) {
        intSqrt++;
    }

    // The intSqrt is the number before the one that triggered the cycle
    return intSqrt - 1;
}

int main() {
    int number;

    printf("Insert a number to calculate the integer square root: ");
    scanf("%d", &number);

    printf("intSqrt(%d) = %d\n", number, intSqrt(number));
}
