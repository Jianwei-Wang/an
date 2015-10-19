#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack {
	int top;
	int capacity;
	int *arr;
};

struct Stack *create_stack(int capacity)
{
	struct Stack *stack = malloc(sizeof(struct Stack));
	
	stack->top = -1;
	stack->capacity = capacity;
	stack->arr = malloc(sizeof(int) * capacity);
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
	if(is_full(stack))
		return;
	stack->arr[++stack->top] = item;
}

int pop(struct Stack *stack)
{
	if(is_empty(stack))
		return INT_MIN;
	return stack->arr[stack->top--];
}

int detect(struct Stack *stack)
{
	if(is_empty(stack))
		return INT_MIN;
	return stack->arr[stack->top];
}

int largestRectangleArea(int* height, int heightSize) {
	struct Stack *stack = create_stack(heightSize);
	int i, count, max = 0, tmp;
	
	i = 0;
	while (i < heightSize) {
		if (is_empty(stack) || detect(stack) < height[i]) {
		    push(stack, height[i]);
		} else {
			count = 0;
			while (!is_empty(stack) && detect(stack) > height[i]) {
				tmp = pop(stack) * (++count);
				max = max > tmp ? max : tmp;
			}
			while (count) {
				push(stack, height[i]);
				count--;
			}
			push(stack, height[i]);
		}
		i++;
	}
	count = 0;
	while (!is_empty(stack)) {
		tmp = pop(stack) * (++count);
		max = max > tmp ? max : tmp;
	}
		return max;
}

void main()
{
	int height[] = {3, 3, 4, 8, 9, 4, 7, 2, 1};
	int size = sizeof(height) / sizeof(height[0]);

	printf("max = %d", largestRectangleArea(height, size));
}
