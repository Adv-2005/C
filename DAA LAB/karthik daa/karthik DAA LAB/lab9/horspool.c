#include <stdio.h>
#include <string.h>
#define MAX 256
void shiftTable(char pattern[], int table[])
{
int i;
int m = strlen(pattern);
for (i = 0; i < MAX; i++)
{
table[i] = m;
}
for (i = 0; i < m - 1; i++)
{
table[(unsigned char)pattern[i]] = m - 1 - i;
}
}
int horspool(char text[], char pattern[], int* successfulComparisons, int* unsuccessfulComparisons) {
int m = strlen(pattern);
int n = strlen(text);
int table[MAX];
shiftTable(pattern, table);
int i = m - 1;
*successfulComparisons = 0;
*unsuccessfulComparisons = 0;
while (i < n)
{
int k = 0;
while (k < m && pattern[m - 1 - k] == text[i - k])
{
(*successfulComparisons)++;
k++;
}
if (k == m)
{
return i - m + 1; // Pattern found at index i - m + 1
}
else
{
(*unsuccessfulComparisons)++;
i += table[(unsigned char)text[i]];
}
}
return -1; // Pattern not found
}
int main()
{
char text[100], pattern[50];
int successfulComparisons, unsuccessfulComparisons, position;
printf("Enter the text: ");
fgets(text, sizeof(text), stdin);
text[strcspn(text, "\n")] = 0; // Remove trailing newline
printf("Enter the pattern: ");
fgets(pattern, sizeof(pattern), stdin);
pattern[strcspn(pattern, "\n")] = 0; // Remove trailing newline
position = horspool(text, pattern, &successfulComparisons, &unsuccessfulComparisons);
if (position != -1)
{
printf("Pattern found at position: %d\n", position);
printf("Successful comparisons: %d\n", successfulComparisons);
printf("Unsuccessful comparisons: %d\n", unsuccessfulComparisons);
}
else
{
printf("Pattern not found\n");
printf("Successful comparisons: %d\n", successfulComparisons);
printf("Unsuccessful comparisons: %d\n", unsuccessfulComparisons);
}
return 0;
}
