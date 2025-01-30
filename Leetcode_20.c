#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// Stack structure
typedef struct {
    char data[MAX_STACK_SIZE];
    int top;
} Stack;

// Stack operations
void push(Stack *stack, char ch) {
    if (stack->top < MAX_STACK_SIZE - 1) {
        stack->data[++(stack->top)] = ch;
    }
}

char pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[(stack->top)--];
    }
    return '\0';  // Return null character if stack is empty
}

char peek(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top];
    }
    return '\0';  // Return null character if stack is empty
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to check if a character is an opening bracket
bool isOpenBracket(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
}

// Function to check if a closing bracket matches the opening bracket
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to validate the string
bool isValid(char *s) {
    Stack stack;
    stack.top = -1;

    for (int i = 0; i < strlen(s); i++) {
        char ch = s[i];
        if (isOpenBracket(ch)) {
            push(&stack, ch);  // Push opening brackets onto the stack
        } else {
            // If it's a closing bracket, check if it matches the top of the stack
            if (isEmpty(&stack) || !isMatchingPair(pop(&stack), ch)) {
                return false;
            }
        }
    }

    // If stack is empty at the end, all brackets are matched
    return isEmpty(&stack);
}

// Main function for testing
int main() {
    printf("%d\n", isValid("()"));          // Output: 1 (true)
    printf("%d\n", isValid("()[]{}"));      // Output: 1 (true)
    printf("%d\n", isValid("(]"));          // Output: 0 (false)
    printf("%d\n", isValid("([])"));        // Output: 1 (true)
    printf("%d\n", isValid("([)]"));        // Output: 0 (false)

    return 0;
}

