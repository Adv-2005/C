#include <stdio.h>
int factorial(int n){
if(n>=1){
    return n*factorial(n-1);
}
else{
        return 1;
}
}
int main(){
    int n;
    printf("Enter number\n");
scanf("%d",&n);
printf("Factorial of number is: %d",factorial(n));

}
