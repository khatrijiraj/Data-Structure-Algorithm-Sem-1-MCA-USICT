#include <stdio.h>  // Include the standard I/O library

#define MAXSIZE 100  // Define the maximum size for the stack and other arrays

typedef struct {           // Define a structure to represent a stack
    char items[MAXSIZE];  // Character array to store stack elements
    int TOS;               // An integer to keep track of the top element's index
} Stack;

void initializeStack(Stack *ST) {
    ST->TOS = -1;  // Initialize the stack by setting the top index to -1 (empty)
}

void push(Stack *ST, char value) {  // Function to push an element onto the stack
    if (ST->TOS == MAXSIZE - 1) {  // Check if the stack is full
        printf("Stack overflow! Cannot push more elements.\n");
    } else {
        ST->items[++(ST->TOS)] = value;  // Increment top and add the value to the stack
    }
}

char pop(Stack *ST) {     // Function to pop an element from the stack
    if (ST->TOS == -1) {  // Check if the stack is empty
        printf("Stack is empty. Cannot pop.\n");
        return '\0';  // Return null character to indicate an error
    } else {
        return ST->items[(ST->TOS)--];  // Pop the top element and decrement top
    }
}

char peek(Stack *ST) {  // Function to peek at the top element of the stack
    if (ST->TOS == -1) {
        return '\0';  // Return null character if the stack is empty
    } else {
        return ST->items[ST->TOS];  // Return the top element of the stack
    }
}

int isOperator(char ch) {  // Function to check if a character is an operator
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int isAlphanumeric(char ch) {  // Function to check if a character is alphanumeric
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

int precedence(char op) {  // Function to determine operator precedence
    if (op == '+' || op == '-') {
        return 1;  // Precedence 1 for + and -
    } else if (op == '*' || op == '/') {
        return 2;  // Precedence 2 for * and /
    } else if (op == '^') {
        return 3;  // Precedence 3 for ^
    }
    return 0;  // For other characters or invalid operators, return 0
}

void infixToPostfix(const char *infix) {  // Function to convert an infix expression to postfix
    Stack ST;                             // Create a stack
    initializeStack(&ST);                 // Initialize the stack

    int infixLength = 0;                  // Variable to store the length of the input infix expression
    while (infix[infixLength] != '\0') {  // Calculate the length of the infix expression
        infixLength++;
    }

    char postfix[MAXSIZE];  // Character array to store the postfix expression
    int pIndex = 0;          // Index to keep track of where to add elements to the postfix expression

    int i = 0;  // Loop variable
    while (i < infixLength) {
        char ch = infix[i];  // Get the current character from the infix expression

        if (isAlphanumeric(ch)) {
            postfix[pIndex++] = ch;   // Add alphanumeric characters to the postfix expression
        } else if (isOperator(ch)) {  // Handle operators
            while (precedence(ch) <= precedence(peek(&ST))) {
                postfix[pIndex++] = pop(&ST);  // Pop operators with higher or equal precedence
            }
            push(&ST, ch);  // Push the current operator onto the stack
        } else if (ch == '(') {
            push(&ST, ch);  // Push an opening parenthesis onto the stack
        } else if (ch == ')') {
            while (peek(&ST) != '(') {
                postfix[pIndex++] = pop(&ST);  // Pop and add operators until an opening parenthesis is encountered
            }
            pop(&ST);  // Pop and discard the opening parenthesis
        }
        i++;
    }

    while (peek(&ST) != '\0') {
        postfix[pIndex++] = pop(&ST);  // Pop and add any remaining operators on the stack
    }

    postfix[pIndex] = '\0';                       // Null-terminate the postfix expression
    printf("Postfix expression: %s\n", postfix);  // Print the postfix expression
}

int main() {
    char infix[MAXSIZE];  // Character array to store the user's input infix expression

    printf("Enter an infix expression: ");
    scanf("%s", infix);  // Read the input infix expression from the user

    infixToPostfix(infix);  // Call the function to convert and print the postfix expression

    return 0;  // Return 0 to indicate successful execution
}