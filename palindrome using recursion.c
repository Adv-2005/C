#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool isPalRec(char str[], int s, int e)
{

    if (s == e)
    return true;

    if (str[s] != str[e])
    return false;

    if (s < e + 1)
    return isPalRec(str, s + 1, e - 1);

    return true;
}

bool isPalindrome(char str[])
{
int n = strlen(str);


if (n == 0)
    return true;

return isPalRec(str, 0, n - 1);
}


int main()
{
    printf("Enter your string\n");
    char str[100];
    gets(str);

    if (isPalindrome(str))
    printf("Yes it is a palindrome");
    else
    printf("No it is not a palindrome");

    return 0;
}
