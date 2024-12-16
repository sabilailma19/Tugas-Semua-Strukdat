#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    } else {
        printf("Stack overflow\n");
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return -1;
}

int isEmpty() {
    return top == -1;
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '^') {
        return 3;
    }
    return 0;
}

void infixToPostfix(char* expression) {
    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];
        if (isalnum(c)) {
            printf("%c", c);
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                printf("%c", pop());
            }
            pop();
        }
        else {
            while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                printf("%c", pop());
            }
            push(c);
        }
    }

    while (!isEmpty()) {
        printf("%c", pop());
    }
    printf("\n");
}

int main() {
    char expression[MAX];
    printf("Enter infix expression: ");
    scanf("%s", expression);
    printf("Postfix expression: ");
    infixToPostfix(expression);
    return 0;
}
