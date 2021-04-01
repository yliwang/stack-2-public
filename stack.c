#include<stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

#include "stack.h"

//typedef enum { false, true } bool;

struct stack *init_stack(struct stack *t, int init_cap)
{
	if (init_cap <= 0) init_cap = 10;

	t->capacity = init_cap;

	t->store = (T *)malloc(sizeof(T)*init_cap);

	t->count = 0;

	return t;
}

struct stack *create_stack(int init_cap)
{
	struct stack *t;

	t = (struct stack *)malloc(sizeof(struct stack));

	return init_stack(t, init_cap);
}


struct stack *reallocate(struct stack *t)
{
	int j;

	assert(t->capacity == t->count);

	int new_cap = t->capacity * 2;

	T * new_store = (T *)malloc(sizeof(T) * new_cap);

	for (j = 0; j < t->count; j++) {
		new_store[j] = t->store[j];
	}

	t->capacity = new_cap;

	free(t->store);

	t->store = new_store;

	return t;
}

struct stack *push(struct stack *t, T e)
{
	int loc;

	if (t->count == t->capacity) {
		reallocate(t);
	}

	loc = t->count;

	t->store[loc] = e;
	t->count++;

	return t;
}

T pop( struct stack *t )
{
T e;
int loc;

assert(t->count > 0);

loc = t->count - 1;

e = t->store[loc];

t->count--;

return e;
}

bool is_empty(struct stack *t)
{
	return t->count == 0 ? true : false;
}

T top( struct stack *t )
{
	int loc;

	assert(t->count > 0);

	loc = t->count - 1;

	return t->store[loc];
}

void uninit_stack(struct stack *t)
{
	free(t->store);
}

#if 0
void main()
{
	struct stack t;

	init_stack(&t, 5);

	int i;

	for (i = 0; i < 20; i++) {
		push(&t, i);
	}

	while (!is_empty(&t)) {
		printf("%d, ", pop(&t));
	}
	
}
#endif
