#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* simplifyPath(char* path) {
    int len = strlen(path);
    char** stack = (char**)malloc(len * sizeof(char*));
    int top = -1;
    
    char* token = strtok(path, "/");
    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            if (top >= 0) {
                free(stack[top--]);
            }
        } else if (strcmp(token, ".") != 0 && strlen(token) > 0) {
            stack[++top] = strdup(token);
        }
        token = strtok(NULL, "/");
    }
    
    if (top == -1) {
        free(stack);
        return strdup("/");
    }
    
    int totalLen = 0;
    for (int i = 0; i <= top; i++) {
        totalLen += strlen(stack[i]) + 1;
    }
    
    char* result = (char*)malloc((totalLen + 1) * sizeof(char));
    result[0] = '\0';
    
    for (int i = 0; i <= top; i++) {
        strcat(result, "/");
        strcat(result, stack[i]);
        free(stack[i]);
    }
    
    free(stack);
    return result;
}

int main() {
    char path[] = "/a/./b/../../c/";
    char* result = simplifyPath(path);
    printf("%s\n", result);
    free(result);
    return 0;
}