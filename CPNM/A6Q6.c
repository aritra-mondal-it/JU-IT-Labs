#include <stdio.h>
#include <math.h>
int main() {
    int i;
    float x[9]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
    float y[9]={5.5,7.0,9.6,11.5,12.6,14.4,17.6,19.5,20.5};
    float sumX = 0, sumX2 = 0, sumX3 = 0, sumX4 = 0;
    float sumY = 0, sumXY = 0, sumX2Y = 0;
    float a, b, c;
    for (i = 0; i < 9; i++) {
        sumX += x[i];
        sumX2 += x[i] * x[i];
        sumX3 += x[i] * x[i] * x[i];
        sumX4 += x[i] * x[i] * x[i] * x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2Y += x[i] * x[i] * y[i];
    }
    float denominator = 9 * sumX2 * sumX4 - sumX * sumX * sumX4 - sumX2 * sumX2 * sumX2;
    a = (sumX2 * sumX2Y - sumX2 * sumXY) / denominator;
    b = (9 * sumX2Y - sumX * sumXY) / denominator;
    c = (9 * sumXY - sumX * sumY) / denominator;

    printf("\nThe equation of the second-degree polynomial curve fit is:\n");
    printf("y = %.3f + %.3fx + %.3fx^2\n", c, b, a);

    return 0;
}
