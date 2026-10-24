#include <stdio.h>
#define SIZE 100
typedef struct { int items[SIZE]; int top; } Stack;
void initStack(Stack *s) { s->top = -1; }
int isEmpty(Stack s) { return s.top == -1; }
void push(Stack *s, int value) { s->top++; s->items[s->top] = value; }
int pop(Stack *s) { int value = s->items[s->top]; s->top--; return value; }
int evaluate() { Stack s; int a, b, result; char c;
initStack(&s);

while (scanf(" %c", &c) == 1 && c != '=') {
    if (c >= '0' && c <= '9') {
        push(&s, c - '0');
    } else {
        b = pop(&s);
        a = pop(&s);

        if (c == '+')
            result = a + b;
        else if (c == '-')
            result = a - b;
        else if (c == '*')
            result = a * b;
        else if (c == '/')
            result = a / b;

        push(&s, result);
    }
}

return pop(&s);
}
int main() { printf("Enter postfix expression (end with =): "); printf("Result = %d\n", evaluate());
return 0;
}