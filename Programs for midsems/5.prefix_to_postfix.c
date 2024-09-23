#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_midsem_char.h"

int isop(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/');
}

void pre_to_post(char* prefix, char* postfix) {
    stack2 s;
    init(&s);
    int k = 0; // Initialize k
    int i;
    for (i = strlen(prefix) - 1; i >= 0; i--) {
        if (isop(prefix[i])) {
            postfix[k++] = pop(&s);
            postfix[k++] = pop(&s);
            postfix[k++] = prefix[i];
        } else {
            push(&s, prefix[i]);
        }
    }
    while (!isemp(&s)) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0'; // Null-terminate the postfix string
}

int main() {
    char prefix[100], postfix[100];
    printf("Enter prefix: ");
    fgets(prefix, sizeof(prefix), stdin);
    prefix[strcspn(prefix, "\n")] = '\0'; // Remove newline character
    pre_to_post(prefix, postfix);
    printf("Postfix: ");
    puts(postfix);
    return 0;
}
