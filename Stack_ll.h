#ifndef STACK_LL_H
#define STACK_LL_H

struct n{
	struct n * next;
	int data;
};
typedef struct n node;

int pop(node *);
node * push(node *, int );
void bastir(node *);

#endif

