#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int evalRPN(char** tokens, int tokensSize) {
    char** stack = (char**)malloc(tokensSize * sizeof(char*));
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        if (tokens[i][0] >= '0' && tokens[i][0] <= '9' || (tokens[i][0] == '-' && tokens[i][1] != '\0')) {
            stack[++top] = tokens[i];
        } else {
            int num2 = atoi(stack[top--]);
            int num1 = atoi(stack[top--]);
            int result = 0;
            switch (tokens[i][0]) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1 / num2;
                    break;
            }
            char* str = (char*)malloc(12 * sizeof(char));
            sprintf(str, "%d", result);
            stack[++top] = str;
        }
    }

    int result = atoi(stack[top]);
    free(stack);

    return result;
}


int main(void) {
    char* tokens[] = {"2", "1", "+", "3", "*"};
    int tokensSize = 5;
    printf("%d\n", evalRPN(tokens, tokensSize));

    char* tokens2[] = {"4", "13", "5", "/", "+"};
    int tokensSize2 = 5;
    printf("%d\n", evalRPN(tokens2, tokensSize2));

    char* tokens3[] = {"10", "6", "9", "3", "/", "-", "*"};
    int tokensSize3 = 5;
    printf("%d\n", evalRPN(tokens3, tokensSize3));

    return 0;
}