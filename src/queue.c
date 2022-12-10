#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if(q->size == MAX_QUEUE_SIZE) return;
	q->proc[q->size] = proc;
	q->size++;
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if(q->size <= 0 ) return NULL;
	struct pcb_t * proc_max = NULL;
	int index = 0;
	for(int i = 1; i < q->size; i++){
		if(q->proc[index]->priority > q->proc[i]->priority)
		{
			index = i;
		}
	}
	proc_max = q->proc[index];
	//remove it from q
	for(int i = index; i < q->size-1; i++){
		q->proc[i] = q->proc[i+1];
	}
	q->size--;
	return proc_max;
}

