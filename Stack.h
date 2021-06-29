#pragma once
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
struct Stack {
	int top;
	int capacity;
	int* array;
};

struct Stack* createStack(int cap)			// function to create a stack of given capacity. It initializes size of stack as 0
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = cap;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

int isFull(struct Stack* stack)			// Stack is full when top is equal to the last index
{
	return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack)		// Stack is empty when top is equal to -1
{
	return stack->top == -1;
}

void push(struct Stack* st, int item)		// Function to add an item to stack.  It increases top by 1
{
	if (isFull(st))
	{
		printf("\nStack is full \n");
		return;
	}
	st->top++;
	st->array[st->top] = item;
	printf("%d pushed to stack\n", item);
}

int pop(struct Stack* st)				// Function to remove an item from stack.  It decreases top by 1
{
	if (isEmpty(st))
		return INT_MIN;
	int temp = st->array[st->top];
	st->top--;
	return temp;
}

// Function to return the top from stack without removing it
int peek(struct Stack* st)
{
	if (isEmpty(st))
		return INT_MIN;
	return st->array[st->top];
}