#include <math.h>  // Include the math library for pow function
#include <stdio.h>

#define MAX_SIZE 5

typedef struct {
    double items[MAX_SIZE];  // Use double to store floating-point results
    int TOS;
} Stack;

void initializeStack(Stack *ST) {
    ST->TOS = -1;
}

void push(Stack *ST, double value) {
    if (ST->TOS == MAX_SIZE - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
    } else {
        ST->items[++(ST->TOS)] = value;
    }
}

double pop(Stack *ST) {
    if (ST->TOS == -1) {
        printf("Stack Underflow. Cannot pop.\n");
        return 0.0;  // Return 0.0 to indicate an error
    } else {
        return ST->items[(ST->TOS)--];
    }
}

int isOperand(char ch) {
    return (ch >= '0' && ch <= '9');
}

double evaluatePostfix(const char *postfix) {
    Stack ST;
    initializeStack(&ST);

    int i = 0;
    while (postfix[i] != '\0') {
        char ch = postfix[i];
        if (isOperand(ch)) {
            push(&ST, ch - '0');  // Convert character to double and push onto the stack
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            double operand2 = pop(&ST);
            double operand1 = pop(&ST);
            double result = 0.0;

            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 != 0) {
                        result = operand1 / operand2;
                    } else {
                        printf("Division by zero is not allowed.\n");
                        return 0.0;  // Return 0.0 to indicate an error
                    }
                    break;
                case '^':
                    result = pow(operand1, operand2);
            }
            push(&ST, result);  // Push the result of the operation back onto the stack
        }
        i++;
    }

    if (ST.TOS == 0) {
        return ST.items[ST.TOS];  // The final result should be at the top of the stack
    } else {
        printf("Invalid postfix expression.\n");
        return 0.0;  // Return 0.0 to indicate an error
    }
}

int main() {
    char postfix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    double result = evaluatePostfix(postfix);

    if (result != 0.0) {
        printf("Result: %lf\n", result);
    }

    return 0;
}
