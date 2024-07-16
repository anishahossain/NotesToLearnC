#include <stdio.h>

double integrate( double (*f)(double), double limit_a, double limit_b){
    // function pointers are declared as parameters
    double stepSize = 0.01;
    // step size is the small values by sum of which area is calculated through integration
    
    double integral = 0.0;
    double x = limit_a + stepSize;
    double area;

    while(x<=limit_b){
        area = f(x) * stepSize; // calculating each tiny block of area
        //from every x from limit a + stepsize to b
        integral += area; // calculating total integral - adding each block of area (full area)
        x += stepSize;
        // increased by stepsize from limit a 
    }
    return integral;
}

double linear(double x){
    return x; // returns numbers in double form (type castung function)
}

double square(double x){
    return x*x;
}

int main(){

    printf("%lf\n", integrate(linear, 0, 2));
    printf("%lf\n", integrate(square, 2, 4));

    return 0;
}