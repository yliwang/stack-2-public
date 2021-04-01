#pragma once

#include "defs.h"


struct stack
{
	T *store;
	int count;
	int capacity;
};

struct stack *init_stack(struct stack *t, int init_cap);
struct stack *create_stack(int init_cap);

struct stack *push(struct stack *t, T e);

T pop(struct stack *t);

bool is_empty(struct stack *t);

T top(struct stack *t);

void uninit_stack(struct stack *t);
