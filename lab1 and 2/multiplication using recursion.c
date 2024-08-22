#include <stdio.h>

int product(int x, int y)
{
    if (x < y)
        return product(y, x);

    else if (y != 0)
    return (x + product(x, y - 1));

    else
        return 0;
}
int main()
{
    int x,y;
    printf("Enter first number\n");
    scanf("%d",&x);
    printf("Enter second number\n");
    scanf("%d",&y);
    printf("%d",product(x,y));
    return 0;
}
