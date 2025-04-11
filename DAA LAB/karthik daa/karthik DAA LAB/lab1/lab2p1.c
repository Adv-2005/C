#include <stdio.h>

int findGCD(int a, int b) {
    int min = (a < b) ? a : b;
    while (min > 0) {
        if (a % min == 0 && b % min == 0)
            return min;
        min--;
    }
    return 1;
}

int main() {
    int a = 36, b = 60;
    int gcd = findGCD(a, b);
    printf("GCD of %d and %d is %d\n", a, b, gcd);
    return 0;
}

