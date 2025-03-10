//	Write a menu-driven program for solving a system of linear equations using Gauss-Elimination method, Jacobi’s method and Gauss Elimination with pivoting method
//	Using the above program solve the following system of equations :				 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

void gauss_elimination(int n, double a[MAX_SIZE][MAX_SIZE], double b[MAX_SIZE], double x[MAX_SIZE]) {
    int i, j, k;
    double m, sum;

    // Forward elimination
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            m = a[j][i] / a[i][i];
            for (k = i; k < n; k++)
                a[j][k] -= m * a[i][k];
            b[j] -= m * b[i];
        }
    }

    // Back substitution
    x[n - 1] = b[n - 1] / a[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--) {
        sum = b[i];
        for (j = i + 1; j < n; j++)
            sum -= a[i][j] * x[j];
        x[i] = sum / a[i][i];
    }
}

void jacobi(int n, double a[MAX_SIZE][MAX_SIZE], double b[MAX_SIZE], double x[MAX_SIZE], double tol, int max_iter) {
    int i, j, iter = 0;
    double sum, x_new[MAX_SIZE],max_diff;

    do {
        for (i = 0; i < n; i++) {
            sum = b[i];
            for (j = 0; j < n; j++) {
                if (j != i)
                    sum -= a[i][j] * x[j];
            }
            x_new[i] = sum / a[i][i];
        }

        max_diff = 0.0;
        for (i = 0; i < n; i++) {
            if (fabs(x_new[i] - x[i]) > max_diff)
                max_diff = fabs(x_new[i] - x[i]);
            x[i] = x_new[i];
        }

        iter++;
    } while (max_diff > tol && iter < max_iter);

    if (iter == max_iter)
        printf("Jacobi method did not converge within the specified number of iterations.\n");
}

void gauss_elimination_pivoting(int n, double a[MAX_SIZE][MAX_SIZE], double b[MAX_SIZE], double x[MAX_SIZE]) {
    int i, j, k, p;
    double m, max, temp;

    // Forward elimination with pivoting
    for (k = 0; k < n - 1; k++) {
        // Find the pivot element
        max = fabs(a[k][k]);
        p = k;
        for (i = k + 1; i < n; i++) {
            if (fabs(a[i][k]) > max) {
                max = fabs(a[i][k]);
                p = i;
            }
        }

        // Swap the rows if necessary
        if (p != k) {
            for (j = 0; j < n; j++) {
                temp = a[k][j];
                a[k][j] = a[p][j];
                a[p][j] = temp;
            }
            temp = b[k];
            b[k] = b[p];
            b[p] = temp;
        }

        // Perform the elimination
        for (i = k + 1; i < n; i++) {
            m = a[i][k] / a[k][k];
            for (j = k; j < n; j++)
                a[i][j] -= m * a[k][j];
            b[i] -= m * b[k];
        }
    }

    // Back substitution
    x[n - 1] = b[n - 1] / a[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--) {
        double sum = b[i];
        for (j = i + 1; j < n; j++)
            sum -= a[i][j] * x[j];
        x[i] = sum / a[i][i];
    }
}

int main() {
    int n, choice;
    double a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE], x[MAX_SIZE];
    double tol = 1e-6;
    int max_iter = 100;

    printf("System of Linear Equations Solver\n");
    printf("1. Gauss Elimination Method\n");
    printf("2. Jacobi Method\n");
    printf("3. Gauss Elimination with Pivoting\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    switch (choice){    
        case  1: {
            printf("Enter the number of equations: ");
            scanf("%d", &n);
            printf("Enter the coefficients of the equations:\n");
            int i,j;
	    for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    scanf("%lf", &a[i][j]);
                }
            }

            printf("Enter the constants of the equations:\n");
            for (i = 0; i < n; i++) {
                scanf("%lf", &b[i]);
            }

            gauss_elimination(n, a, b, x);

            printf("The solution is:\n");
            for (i = 0; i < n; i++) {
                printf("x[%d] = %.6f\n", i, x[i]);
	break;
            }
        } case 2: {
            printf("Enter the number of equations: ");
            scanf("%d", &n);
	    int i,j;
            printf("Enter the coefficients of the equations:\n");
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    scanf("%lf", &a[i][j]);
                }
            }

            printf("Enter the constants of the equations:\n");
            for (i = 0; i < n; i++) {
                scanf("%lf", &b[i]);
            }

            printf("Enter the initial guess:\n");
            for (i = 0; i < n; i++) {
                scanf("%lf", &x[i]);
            }

            jacobi(n, a, b, x, tol, max_iter);

            printf("The solution is:\n");
            for (i = 0; i < n; i++) {
                printf("x[%d] = %.6f\n", i, x[i]);
             break;
            }
        } case 3: {
            printf("Enter the number of equations: ");
            scanf("%d", &n);
            int i,j;
            printf("Enter the coefficients of the equations:\n");
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    scanf("%lf", &a[i][j]);
                }
            }

            printf("Enter the constants of the equations:\n");
            for (i = 0; i < n; i++) {
                scanf("%lf", &b[i]);
            }

            gauss_elimination_pivoting(n, a, b, x);

            printf("The solution is:\n");
            for (i = 0; i < n; i++) {
                printf("x[%d] = %.6f\n", i, x[i]);
            break;
}
        } case 4: {
            break;
        } default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}

