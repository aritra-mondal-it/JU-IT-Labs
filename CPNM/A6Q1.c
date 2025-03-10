//Write a menu-driven program for finding roots of a nonlinear equation using Bisection, Regula Falsi and Newton-Raphson method. 
//Use the above program to find 3 roots of the equation xtan(x)=c where c is a user-input constant. Use both bisection method and Newton-Raphson method.
#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * tan(x);
}

double bisection(double a, double b, double tol, double c) {
    if (f(a) * f(b) >= 0) {
        printf("Bisection method failed.\n");
        return 0;
    }
    double c_n = a;
    while (fabs(b - a) >= tol) {
        c_n = (a + b) / 2;
        if (f(c_n) == 0)
            break;
        if (f(a) * f(c_n) < 0)
            b = c_n;
        else
            a = c_n;
    }
    printf("Root using Bisection method: %.6f\n", c_n);
    return c_n;
}

double regula_falsi(double a, double b, double tol, double c) {
    if (f(a) * f(b) >= 0) {
        printf("Regula Falsi method failed.\n");
        return 0;
    }
    double a_n = a, b_n = b,c_n;
    while (fabs(b_n - a_n) >= tol) {
        c_n = b_n - (f(b_n) * (b_n - a_n)) / (f(b_n) - f(a_n));
        if (f(a_n) * f(c_n) < 0)
            b_n = c_n;
        else
            a_n = c_n;
    }
    printf("Root using Regula Falsi method: %.6f\n", c_n);
    return c_n;
}

double newton_raphson(double x0, double tol, double c) {
    double x_n = x0;
    while (fabs(f(x_n)) >= tol) {
        if (cos(x_n) + x_n * sin(x_n) == 0) {
            printf("Divide by zero error occurred.\n");
            return 0;
        }
        x_n = x_n - f(x_n) / (tan(x_n) + x_n * (1 / pow(cos(x_n), 2) - tan(x_n)));
    }
    printf("Root using Newton-Raphson method: %.6f\n", x_n);
    return x_n;
}

int main() {
    printf("Nonlinear Equation Root Finding\n");
    printf("1. Bisection Method\n");
    printf("2. Regula Falsi Method\n");
    printf("3. Newton-Raphson Method\n");
    printf("4. Find roots of xtan(x)=c\n");
    printf("5. Exit\n");
    int choice;
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);
    switch (choice){ 
        case 1: {
            double a, b, tol;
            printf("Enter the lower bound: ");
            scanf("%lf", &a);
            printf("Enter the upper bound: ");
            scanf("%lf", &b);
            printf("Enter the tolerance: ");
            scanf("%lf", &tol);
            bisection(a, b, tol, 0);
	    break;
        }   case 2:{
            double a, b, tol;
            printf("Enter the lower bound: ");
            scanf("%lf", &a);
            printf("Enter the upper bound: ");
            scanf("%lf", &b);
            printf("Enter the tolerance: ");
            scanf("%lf", &tol);
            regula_falsi(a, b, tol, 0);
            break;
        }   case 3: {
            double x0, tol;
            printf("Enter the initial guess: ");
            scanf("%lf", &x0);
            printf("Enter the tolerance: ");
            scanf("%lf", &tol);
            newton_raphson(x0, tol, 0);
	    break;
        }   case 4: {
            double c;
            printf("Enter the value of c: ");
            scanf("%lf", &c);
            printf("Using Bisection method:\n");
            bisection(0, c, 1e-6, c);
            printf("\nUsing Newton-Raphson method:\n");
            newton_raphson(c/2, 1e-6, c);
	    break;
        }   case 5: {
            break;
        }   default :
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}
