#include <stdio.h>
#include <math.h>

#define MAX_POINTS 100

int main() {
    int choice, n, i, j;
    float x[MAX_POINTS], y[MAX_POINTS], xp, yp;

    printf("Interpolation Techniques in C\n");
    printf("1. Lagrange's Formula\n");
    printf("2. Newton's Forward Difference Formula\n");
    printf("3. Newton's Backward Difference Formula\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the x and y values:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    printf("Enter the point at which interpolation is to be performed: ");
    scanf("%f", &xp);

    switch (choice) {
        case 1:
            yp = 0;
            for (i = 0; i < n; i++) {
                float L = 1;
                for (j = 0; j < n; j++) {
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
            for (i = 0; i < n - 1; i++) {
                delta[i] = y[i + 1] - y[i];
            }
            for (i = 1; i < n; i++) {
                float term = 1;
                for (j = 0; j < i; j++) {
                    term *= (xp - x[j]) / h;
                }
                yp += term * delta[j];
            }
            printf("The interpolated value at x = %.2f is: %.2f\n", xp, yp);
            break;

        case 3:
            yp = y[n - 1];
            float h2 = x[1] - x[0];
            float delta2[MAX_POINTS];
            for (i = n - 1; i > 0; i--) {
                delta2[i - 1] = y[i] - y[i - 1];
            }
            for (i = 1; i < n; i++) {
                float term = 1;
                for (j = n - 1; j >= n - i; j--) {
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
