#include <stdio.h>
#define SIZE 100
typedef struct { char items[SIZE]; int top; } Stack;
void initStack(Stack *s) { s->top = -1; }
int isEmpty(Stack s) { return s.top == -1; }
void push(Stack *s, char value) { if (s->top < SIZE - 1) { s->top++; s->items[s->top] = value; } }
char pop(Stack *s) { if (isEmpty(*s)) { return '\0'; }
char value = s->items[s->top];
s->top--;
return value;
}
char peek(Stack s) { if (isEmpty(s)) { return '\0'; }
return s.items[s.top];
}
int main() { Stack s; int i; char expression[] = "(A+B)*C";
initStack(&s);

for (i = 0; expression[i] != '\0'; i++) {
    push(&s, expression[i]);
}

while (!isEmpty(s)) {
    printf("%c ", pop(&s));
}

return 0;
}