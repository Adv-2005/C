#include <stdio.h>


typedef struct {
    float real;
    float imag;
} Complex;


Complex addComplex(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}

Complex subtractComplex(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real - num2.real;
    result.imag = num1.imag - num2.imag;
    return result;
}


Complex multiplyComplex(Complex num1, Complex num2) {
    Complex result;
    result.real = (num1.real * num2.real) - (num1.imag * num2.imag);
    result.imag = (num1.real * num2.imag) + (num1.imag * num2.real);
    return result;
}

int main() {
    Complex num1, num2, sum, difference, product;


    printf("Enter real and imaginary parts of the first complex number: ");
    scanf("%f %f", &num1.real, &num1.imag);


    printf("Enter real and imaginary parts of the second complex number: ");
    scanf("%f %f", &num2.real, &num2.imag);


    sum = addComplex(num1, num2);
    difference = subtractComplex(num1, num2);
    product = multiplyComplex(num1, num2);


    printf("Sum: %.2f + %.2fi\n", sum.real, sum.imag);
    printf("Difference: %.2f + %.2fi\n", difference.real, difference.imag);
    printf("Product: %.2f + %.2fi\n", product.real, product.imag);

    return 0;
}

