#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "list.h"

struct singly_linked_list *init_list( struct singly_linked_list *t )
{
	t->head = NULL;
	t->tail = NULL;
	t->count = 0;

	return t;
}

struct singly_linked_list *create_list()
{
    struct singly_linked_list *t = (struct singly_linked_list *)malloc( sizeof(struct singly_linked_list) );

	return init_list( t );
}

struct node *create_node( T e )
{
	struct node *p = (struct node *)malloc( sizeof(struct node) );

	p->data = e;
	p->next = NULL;

	return p;
}

struct singly_linked_list *add_head( struct singly_linked_list *t, T e )
{
	struct node *p = create_node( e );

	if( t->count == 0 ) {
		t->head = t->tail = p;
		t->count ++;
	} else {
		p->next = t->head;
		t->head = p;

		t->count ++;
	}

	return t;
}

struct singly_linked_list *add_tail( struct singly_linked_list *t, T e )
{
	struct node *p = create_node(e);

	if( t->count == 0 ) {
		t->head = t->tail = p;
		t->count ++;
	} else {
		t->tail->next = p;
		t->tail = p;

		t->count ++;
	}

	return t;
}

struct node *get( struct singly_linked_list *t, int i )
{
	struct node *p;
	int j;

	assert( t->count > 0 );
	assert( i>=0 && i<t->count);


	for( j=0, p=t->head; j<t->count; j++, p=p->next ) {
		if( j == i ) return p;
	}

	return NULL;
}

struct singly_linked_list *insert( struct singly_linked_list *t, int i, T e )
{
	struct node *p, *prev_node, *next_node;

	if( i == 0 ) return add_head( t, e );
	else if( i == t->count ) return add_tail( t, e );

	assert( i > 0 && i < t->count );

	prev_node = get( t, i-1 );
	assert( prev_node != NULL );

	next_node = prev_node->next;

	p = create_node( e );

	prev_node->next = p;
	p->next = next_node;

	t->count ++;

	return t;
}

struct singly_linked_list *remove_head( struct singly_linked_list *t )
{
	struct node *p;

	assert( t->count > 0 );

	if( t->count == 1 ) {
		free( t->head );
		t->head = t->tail = NULL;
		t->count --;
	} else {
		p = t->head->next;
		free( t->head );
		t->head = p;
		t->count --;
	}

	return t;
}

struct singly_linked_list *delete_at( struct singly_linked_list *t, int i )
{
	struct node *prev_node, *cur_node;

	assert( t->count > 0 );

	if( i == 0 ) {
		return remove_head( t );
	} else {
		prev_node = get( t, i-1 );
		assert( prev_node != NULL );

		cur_node = prev_node->next;

		prev_node->next = cur_node->next;

		if( cur_node == t->tail ) t->tail = prev_node;

		t->count --;

		free( cur_node );

		return t;
	}
}

void free_list(struct node *head)
{
	struct node *p;

	while (head != NULL) {
		p = head;
		head = head->next;
		free(p);
	}
}
