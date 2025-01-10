#include <stdio.h>
int i;

int gcd(int a, int b) {
    int gcd = 1;
    for ( i = (a < b ? a : b); i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
            break;
        }
    }
    return gcd;
}

int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
    return 0;
}

