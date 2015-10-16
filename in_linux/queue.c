#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

struct Queue {
	int front, rear, size;
	unsigned int capacity;
	int *array;
};

struct Queue *create_queue(unsigned capacity)
{
	struct Queue *queue = malloc(sizeof(struct Queue));

	queue->front = queue->size = 0;
	queue->capacity = capacity;
	queue->rear = queue->capacity - 1;
	queue->array = malloc(sizeof(int) * capacity);

	return queue;
}

int is_full(struct Queue *queue)
{
	return queue->capacity == queue->size;
}

int is_empty(struct Queue *queue)
{
	return queue->size == 0;
}

void enqueue(struct Queue *queue, int item)
{
	
	if (is_full(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size +=1;
}

int dequeue(struct Queue *queue)
{
	int item;
	if (is_empty(queue))
		return INT_MIN;
	item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size -=1;
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

int main()
{
	struct Queue* queue = create_queue(1000);
	
	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);
	
	printf("%d dequeued from queue\n", dequeue(queue));
	
	printf("Front item is %d\n", front(queue));
	printf("Rear item is %d\n", rear(queue));
	
	return 0;
}
