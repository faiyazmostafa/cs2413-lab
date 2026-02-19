#include "Student.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static bool is_open(char c) {
    return (c == '(' || c == '[' || c == '{');
}

static bool matches(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isValid(const char *s) {
    if (s == NULL) return true;           // usually not given, but safe
    size_t n = strlen(s);
    if (n == 0) return true;

    // stack of opening brackets (max size = n)
    char *st = (char *)malloc(n * sizeof(char));
    if (!st) return false;                // out of memory → fail safely

    size_t top = 0; // number of items in stack

    for (size_t i = 0; i < n; i++) {
        char c = s[i];

        if (is_open(c)) {
            st[top++] = c;                // push
        } else {
            // closing bracket: must have something to match
            if (top == 0) {               // empty stack → invalid
                free(st);
                return false;
            }
            char open = st[top - 1];      // peek
            if (!matches(open, c)) {      // wrong type/order
                free(st);
                return false;
            }
            top--;                        // pop
        }
    }

    bool ok = (top == 0);                 // all opens matched
    free(st);
    return ok;
}
