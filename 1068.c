#include <stdio.h>
#include <string.h>

#define MAX_LINE 1100
#define MAX_STACK 1000

int main(void) {
    char s[MAX_LINE];
    char stack[MAX_STACK];
    int top;

    while (fgets(s, sizeof(s), stdin) != NULL) {
        s[strcspn(s, "\n\r")] = '\0';

        top = -1;
        int correct = 1;
        for (size_t i = 0; s[i] != '\0'; ++i) {
            char c = s[i];
            if (c == '(') {
                if (top < MAX_STACK - 1) {
                    stack[++top] = c;
                }
            } else if (c == ')') {
                if (top < 0) {
                    correct = 0;
                    break;
                }
                top--;
            }
        }

        if (correct && top == -1) {
            puts("correct");
        } else {
            puts("incorrect");
        }
    }

    return 0;
}

