#include <math.h>
#include <stdio.h>

int countDivisors(int number) {
    int divisorCounter = 0;

    for (int i = 1; i <= sqrt(number); i++) {
        if (number % i == 0) {
            divisorCounter++;  // Count i
            if (i != number / i) {
                divisorCounter++;  // Count number / i if it's different
            }
        }
    }

    return divisorCounter;
}

// Level 1: "bruteforce"
int primeLvlOne(int number) {
    // If there are more than one divisors it means that the number is not prime
    if (countDivisors(number) > 2) return 0;

    // Else the number is prime
    return 1;
}

// Level 2: a bit of math
int primeLvlTwo(int number) {
    // If number <= 3 then it is for sure prime
    if (number >= 1 && number <= 3) return 1;

    // If number > 3 then we have to check the divisors
    // If the number is even then it is not prime
    // Else we have to count the divisors
    if (number % 2 == 0 || countDivisors(number) > 2) return 0;

    // Else is prime
    return 1;
}

void printResult(int result) {
    if (result) {
        printf("Is Prime\n");
    } else {
        printf("Not Prime\n");
    }
}

int main() {
    int number;

    printf("Insert a natural number to verify if it is a prime: ");
    scanf("%d", &number);

    printf("Level 1 checking...\n");
    printResult(primeLvlOne(number));

    printf("Level 2 checking...\n");
    printResult(primeLvlTwo(number));

    return 0;
}
