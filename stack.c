#include<stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

#include "stack.h"

//typedef enum { false, true } bool;

struct stack *init_stack(struct stack *t)
{
	init_list( &t->sll );
	
	return t;
}

struct stack *create_stack()
{
	struct stack *t;

	t = (struct stack *)malloc(sizeof(struct stack));

	return init_stack(t);
}

void uninit_stack( struct stack *t )
{
    free_list( &t->sll );
}
