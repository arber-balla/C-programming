#include<stdio.h>
#include<math.h>

int main(){
    // Coefficients for the quadratic equation
    float a, b, c;

    // Get input values from the user
    printf("Enter the three coefficients a, b, and c of your equation.\n");

    printf("Enter a: ");
    scanf("%f", &a);

    // Prevent division by zero
    if (a == 0) {
        printf("Coefficient 'a' cannot be zero in a quadratic equation.\n");
        return 1;
    }

    printf("Enter b: ");
    scanf("%f", &b);

    printf("Enter c: ");
    scanf("%f", &c);

    // Calculate delta
    float delta = (b * b) - (4 * a * c);

    // Precompute denominator sice it is used more than one time
    float denominator = 2 * a;

    if (delta < 0) {
        printf("No real solutions exist.\n");
    } else if (delta == 0) {
        float x = -b / denominator;
        printf("The solution x1 = x2 = x is: %f.\n", x);
    } else {
        float sqrt_delta = sqrtf(delta);
        float x1 = (-b + sqrt_delta) / denominator;
        float x2 = (-b - sqrt_delta) / denominator;
        printf("The solution x1 is: %f\n", x1);
        printf("The solution x2 is: %f\n", x2);
    }

    return 0;
}
