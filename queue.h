#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#include "vector.h"
#include "ADTDefs.h"

struct Queue
{
	int* m_items;			
	size_t m_size;							/*	The size of the Queue*/
	size_t m_numItems;
	int m_front ;
	int m_rear ;
} ;

typedef struct Queue Queue ;

Queue* QueueCreate(size_t _size);
ADTErr QueueInsert(Queue *_queue, int _val);
ADTErr QueueRemove(Queue *_queue, int* _pval);
int QueueIsEmpty(Queue *_queue);
void QueuePrint(Queue *_queue);
void QueueDestroy(Queue *_queue);

#endif /*__QUEUE_H__*/
