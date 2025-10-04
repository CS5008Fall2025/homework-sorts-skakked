#include <stdbool.h>  
#include <stdlib.h>   
#include <string.h>   
// LeetCode 20: Valid Parentheses

static inline bool matches(char open, char close) {
    // Returns true if `open` and `close` are a matching pair.
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isValid(const char *s) {
    if (!s) return false;                 // Null input is invalid

    size_t n = strlen(s);
    if (n & 1u) return false;             // Odd length cannot be balanced

    // All brackets are single chars, so max stack size is n
    char *stack = (char *)malloc(n);
    if (!stack) return false;             // Memory allocation is false

    // `top` is index of top element in stack, -1 when empty
    long top = -1;

    for (size_t i = 0; i < n; ++i) {
        char c = s[i];

        // If it's an opening bracket, push to stack
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } else {
            // It's a closing bracket; there must be a corresponding open
            if (top < 0) {                
                free(stack);
                return false;
            }

            char open = stack[top--];      
            if (!matches(open, c)) {      // Mismatched pair
                free(stack);
                return false;
            }
        }
    }

    bool ok = (top == -1);                // Stack should be empty if valid
    free(stack);
    return ok;
}