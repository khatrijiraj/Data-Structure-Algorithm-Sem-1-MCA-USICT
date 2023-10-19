#include <stdbool.h>
#include <stdio.h>

#define MAXSIZE 5

typedef struct {
    char items[MAXSIZE];
    int TOS;
} Stack;

void initializeStack(Stack *ST) {
    ST->TOS = -1;
}

void push(Stack *ST, char value) {
    if (ST->TOS == MAXSIZE - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
    } else {
        ST->items[++(ST->TOS)] = value;
    }
}

char pop(Stack *ST) {
    if (ST->TOS == -1) {
        printf("Stack Underflow. Cannot pop.\n");
        return '\0';
    } else {
        return ST->items[(ST->TOS)--];
    }
}

char peek(Stack *ST) {
    if (ST->TOS == -1) {
        return '\0';
    } else {
        return ST->items[ST->TOS];
    }
}

int operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int isAlphanumeric(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return 0;
}

void infixToPostfix(char *infix) {
    Stack ST;
    initializeStack(&ST);

    int infixLength = 0;
    while (infix[infixLength] != '\0') {
        infixLength++;
    }

    char postfix[MAXSIZE];
    int pIndex = 0;
    int i = 0;
    while (i < infixLength) {
        char ch = infix[i];

        if (isAlphanumeric(ch)) {
            postfix[pIndex++] = ch;
        } else if (operator(ch)) {
            while (precedence(ch) <= precedence(peek(&ST))) {
                postfix[pIndex++] = pop(&ST);
            }
            push(&ST, ch);
        } else if (ch == '(') {
            push(&ST, ch);
        } else if (ch == ')') {
            while (peek(&ST) != '(') {
                postfix[pIndex++] = pop(&ST);
            }
            pop(&ST);
        }
        i++;
    }

    while (peek(&ST) != '\0') {
        postfix[pIndex++] = pop(&ST);
    }

    postfix[pIndex] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

bool isValidInfix(char *infix) {
    Stack ST;
    initializeStack(&ST);

    int i = 0;
    while (infix[i] != '\0') {
        char ch = infix[i];

        if (isAlphanumeric(ch)) {
        } else if (operator(ch)) {
            if (i == 0) {
                return false;
            }
            char prevChar = infix[i - 1];
            if (prevChar == '(' || prevChar == ')' || operator(prevChar)) {
                return false;
            }
        } else if (ch == '(') {
            push(&ST, ch);
        } else if (ch == ')') {
            if (peek(&ST) != '(') {
                return false;
            }
            pop(&ST);
        } else {
            return false;
        }
        i++;
    }
    return ST.TOS == -1;
}

int main() {
    char infix[MAXSIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    if (isValidInfix(infix)) {
        printf("The infix expression is valid.\n");
        infixToPostfix(infix);
    } else {
        printf("The infix expression is not valid.\n");
    }

    return 0;
}