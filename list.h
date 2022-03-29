#pragma once

#include "defs.h"

struct node {
	T data;
	struct node *next;
};

struct singly_linked_list {
	struct node *head;
	struct node *tail;
	int count;
};

struct singly_linked_list *init_list(struct singly_linked_list *t);

struct singly_linked_list *create_list();

struct node *create_node(T e);

struct singly_linked_list *add_head(struct singly_linked_list *t, T e);

struct singly_linked_list *add_tail(struct singly_linked_list *t, T e);

struct node *get(struct singly_linked_list *t, int i);

struct singly_linked_list *insert(struct singly_linked_list *t, int i, T e);

struct singly_linked_list *remove_head(struct singly_linked_list *t);

struct singly_linked_list *delete_at(struct singly_linked_list *t, int i);


void free_list(struct node *head);








