#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Queue {
	int front, rear, size;
	unsigned int capacity;
	int *array;
};

int is_empty(struct Queue *queue)
{
	return queue->size == 0;
}

int is_full(struct Queue *queue)
{
	return queue->size == queue->capacity;
}

struct Queue *create_queue(unsigned int capacity)
{
	struct Queue *queue = malloc(sizeof(struct Queue));

	queue->front = queue->size = 0;
	queue->capacity = capacity;
	queue->rear = queue->capacity - 1;
	queue->array = malloc(sizeof(int) * capacity);

	return queue;
}

void enqueue(struct Queue *queue, int item)
{
	if (is_full(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size++;
	return;
}

int dequeue(struct Queue *queue)
{
	int item;

	if (is_empty(queue))
		return INT_MIN;
	item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size--;
	return item;

}

int front(struct Queue *queue)
{
	if (is_empty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

int rear(struct Queue *queue)
{
	if (is_empty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

struct Stack {
	int top;
	unsigned capacity;
	int *array;
};

int is_empty(struct Stack *stack)
{
	return stack->top == -1;
}

int is_full(struct Stack *stack)
{
	return stack->top == stack->capacity - 1;
}

struct Stack *create_stack(unsigned int capacity)
{
	struct Stack *stack = malloc(sizeof(struct Stack));

	stack->top = -1;
	stack->capacity = capacity;
	stack->array = malloc(sizeof(int) * capacity);
	return stack;
}

void push(struct Stack *stack, int item)
{
	if (is_full(stack))
		return;
	stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{
	if(is_empty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

void main()
{
//	struct Queue *queue = create_queue(10);
//
//	enqueue(queue, 10);
//	enqueue(queue, 20);
//	enqueue(queue, 30);
//	enqueue(queue, 40);
//	enqueue(queue, 50);
//	enqueue(queue, 60);
//	enqueue(queue, 70);
//	enqueue(queue, 80);
//	printf("dequeue: %d\n", dequeue(queue));
//	printf("dequeue: %d\n", dequeue(queue));
//	printf("dequeue: %d\n", dequeue(queue));
//	printf("dequeue: %d\n", dequeue(queue));
//	printf("dequeue: %d\n", dequeue(queue));
//	printf("dequeue: %d\n", dequeue(queue));
//	enqueue(queue, 10);
//	enqueue(queue, 20);
//	enqueue(queue, 30);
//	enqueue(queue, 40);
//	enqueue(queue, 50);
//	enqueue(queue, 60);
//	enqueue(queue, 70);
//	enqueue(queue, 80);
//	printf("dequeue: %d\n", dequeue(queue));
//	printf("dequeue: %d\n", dequeue(queue));
//	printf("dequeue: %d\n", dequeue(queue));
//	printf("dequeue: %d\n", dequeue(queue));
//	printf("dequeue: %d\n", dequeue(queue));
//	printf("dequeue: %d\n", dequeue(queue));
//	printf("dequeue: %d\n", dequeue(queue));
//	printf("dequeue: %d\n", dequeue(queue));
//	printf("dequeue: %d\n", dequeue(queue));
//	printf("dequeue: %d\n", dequeue(queue));
//	printf("dequeue: %d\n", dequeue(queue));
	struct Stack *stack = create_stack(100);

	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	push(stack, 40);
	push(stack, 50);
	push(stack, 60);
	push(stack, 70);
	push(stack, 80);
	push(stack, 90);
	printf("pop: %d\n", pop(stack));
	printf("pop: %d\n", pop(stack));
	printf("pop: %d\n", pop(stack));
	printf("pop: %d\n", pop(stack));
	printf("pop: %d\n", pop(stack));
	printf("pop: %d\n", pop(stack));
	printf("pop: %d\n", pop(stack));
	printf("pop: %d\n", pop(stack));
	printf("pop: %d\n", pop(stack));
	printf("pop: %d\n", pop(stack));
	printf("pop: %d\n", pop(stack));
}
