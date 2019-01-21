#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>

/* Variables */
struct node {int value; struct node *next;};

/* Function Prototypes */
void insert_into_list (struct node **list, int n);

#endif