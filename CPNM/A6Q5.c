#include <stdio.h>
#include <math.h>

#define MAX_POINTS 100

int main() {
    int choice, i, j;
    float x[4], y[4], xp, yp;

    printf("Interpolation Techniques in C\n");
    printf("1. Lagrange's Formula\n");
    printf("2. Newton's Forward Difference Formula\n");
    printf("3. Newton's Backward Difference Formula\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);
    x[0]=1.00,x[1]=2.00,x[2]=3.00,x[3]=4.00;
    y[0]=1.00,y[1]=8.00,y[2]=27.00,y[3]=64.00;

    printf("Enter the point at which interpolation is to be performed: ");
    scanf("%f", &xp);

    switch (choice) {
        case 1:
            yp = 0;
            for (i = 0; i < 4; i++) {
                float L = 1;
                for (j = 0; j < 4; j++) {
                    if (j != i) {
                        L *= (xp - x[j]) / (x[i] - x[j]);
                    }
                }
                yp += y[i] * L;
            }
            printf("The interpolated value at x = %.2f is: %.2f\n", xp, yp);
            break;

        case 2:
            yp = y[0];
            float h = x[1] - x[0];
            float delta[MAX_POINTS];
            for (i = 0; i < 3; i++) {
                delta[i] = y[i + 1] - y[i];
            }
            for (i = 1; i < 4; i++) {
                float term = 1;
                for (j = 0; j < i; j++) {
                    term *= (xp - x[j]) / h;
                }
                yp += term * delta[j];
            }
            printf("The interpolated value at x = %.2f is: %.2f\n", xp, yp);
            break;

        case 3:
            yp = y[3];
            float h2 = x[1] - x[0];
            float delta2[MAX_POINTS];
            for (i = 3; i > 0; i--) {
                delta2[i - 1] = y[i] - y[i - 1];
            }
            for (i = 1; i < 4; i++) {
                float term = 1;
                for (j = 3; j >= 4 - i; j--) {
                    term *= (xp - x[j]) / h2;
                }
                yp += term * delta2[j];
            }
            printf("The interpolated value at x = %.2f is: %.2f\n", xp, yp);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}
