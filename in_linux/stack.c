#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

struct Stack {
	int top;
	unsigned int capacity;
	int *array;
};

struct Stack *create_stack(unsigned int capacity)
{
	struct Stack *stack = malloc(sizeof(struct Stack));

	stack->capacity = capacity;
	stack->top = -1;
	stack->array = malloc(sizeof(int) * capacity);
	return stack;
}

int is_empty(struct Stack *stack)
{
	return stack->top == -1;
}

int is_full(struct Stack *stack)
{
	return stack->top == stack->capacity - 1;
}

void push(struct Stack *stack, int item)
{
	if (is_full(stack))
		return;
	stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{
	if (is_empty(stack))
		return INT_MIN;
	return stack->array[stack->top--];

}

void main()
{
	struct Stack *stack = create_stack(100);

	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	push(stack, 40);
	push(stack, 50);
	printf("%d", pop(stack));
	printf("%d", pop(stack));
	printf("%d", pop(stack));
	printf("%d", pop(stack));
	printf("%d", pop(stack));
	printf("%d", pop(stack));
	printf("%d", pop(stack));
	push(stack,  60);
	printf("%d", pop(stack));
}
