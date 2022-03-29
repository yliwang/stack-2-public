#pragma once

#include "defs.h"
#include "list.h"

struct stack
{
	struct singly_linked_list sll;
};

struct stack *init_stack(struct stack *t);
struct stack *create_stack();

void uninit_stack( struct stack * t );

struct stack *push(struct stack *t, T e);

T pop(struct stack *t);

bool is_empty(struct stack *t);

T top(struct stack *t);

