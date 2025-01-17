
#include <stdio.h>
#include <string.h>
int i;

void brute_force_string_match(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    for ( i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[] = "THIS IS A SIMPLE EXAMPLE";
    char pattern[] = "EXAMPLE";
    brute_force_string_match(text, pattern);
    return 0;
}
