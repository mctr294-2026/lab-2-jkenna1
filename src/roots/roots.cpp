#include "roots.hpp"
#include <iostream>

// Test #1: Bisection Method
bool bisection(std::function<double(double)> f, double a, double b, double *root) {
               
    for(int i = 0; i < 1e6; i++){

        double midpoint = (a + b)/2;
        double y_value = f(midpoint);

        if (std::abs(y_value) < 1e-6){
            *root = midpoint;
            return true;
        }

        if (f(a) * y_value > 0){
            a = midpoint;
        }
        else{
            b = midpoint;
            }
    } 
    return false; // false if runs more than 1000000 times
}

// Test #2: Regula Falsi Method
bool regula_falsi(std::function<double(double)> f, double a, double b, double *root) {
        for(int i = 0; i < 1e6; i++){
        double midpoint = a - (f(a)*(b - a))/(f(b) - f(a));
        double y_value = f(midpoint);

        if (std::abs(y_value) < 1e-6){
            *root = midpoint;
            return true;
        }

        if (f(a) * y_value < 0){
            b = midpoint;
        }
        else{
            a = midpoint;
            }
    }

    return false; 
}

//Test #3: Newton-Raphson's Method
bool newton_raphson(std::function<double(double)> f, std::function<double(double)> g, double a, double b, double c, double *root) {
    double x_n = c;

    for(int i = 0; i < 1e6; i++){
        double y_value = f(x_n);
        double dy_Value = g(x_n);

        if (std::abs(y_value) < 1e-6){
            *root = x_n;
            return true;
        }
        if(std::abs(dy_Value) < 1e-6){
            return false; // cannot divide by 0
        }

        if (x_n < a || x_n > b){  //guess is outside of boundaries
            return false;
        }

        x_n = x_n - (f(x_n)/g(x_n));
    }    

    return false;
}

//Test #4: Secant Method
bool secant(std::function<double(double)> f, double a, double b, double c, double *root) {
    double x_now = c;
    double x_prev = a;
    double x_next;

    for(int i = 0; i < 1e6; i++){

        x_next = x_now - f(x_now)* ((x_now - x_prev)/(f(x_now)- f(x_prev)));

        if (std::abs(x_next - x_now) < 1e-6){
            *root = x_next;
            return true;
        }
        x_prev = x_now;
        x_now = x_next;
    }    

    return false;
}

