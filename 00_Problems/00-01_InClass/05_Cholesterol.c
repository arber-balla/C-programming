#include<stdio.h>

int evaluateRisk(int age, int level) {
    if(age <= 30){
        if (level > 240) return 40;
        return 0;
    }

    if (level > 240) return 70;
    return 10;
}

int main() {
    int age, level;

    printf("Insert your age: ");
    scanf("%d", &age);

    printf("Insert you cholesterol levels: ");
    scanf("%d", &level);

    printf("Your risk increment is %d%s.\n", evaluateRisk(age, level), "%");
    return 0;
}
