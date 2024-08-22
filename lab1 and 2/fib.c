int printFib(int n)
{
    if (n < 1) {
        printf("Invalid Number of terms\n");
        return;
    }
    int a = 1;
    int b = 0;
    int i;
for (i = 1; i <= n; i++) {
        if (i > 2) {
            int num = a + b;
            b = a;
            a = num;
            printf("%d ", num);}

        if (i == 1) {
            printf("%d ", b);
        }
        if (i == 2) {
            printf("%d ", a);}
    }}
int main()
{
int n;
printf("Enter number of terms\n");
scanf("%d",&n);
    printFib(n);
    return 0;
}
