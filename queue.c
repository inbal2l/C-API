#include <stdio.h>
#include <stdlib.h>

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

Queue* QueueCreate(size_t _size)
{
	Queue* temp_queue ;

	if (_size == 0)
	{
		return NULL ;
	}
	temp_queue = (Queue*)malloc(sizeof(Queue)) ;
	if (temp_queue == NULL)
	{
		return NULL ;
	}
	temp_queue->m_items = (int*)malloc(sizeof(int)) ;
	if (temp_queue->m_items == NULL)
	{
		return NULL ;
	}
	temp_queue->m_size = _size ;
	temp_queue->m_numItems = 0 ;
	temp_queue->m_front = 0 ;
	temp_queue->m_rear = -1 ;

	return temp_queue;
}

int IsEmpty(Queue *_queue)
{
	if (_queue->m_front == -1) 
	{
		return 1;
	}
	return 0;
}

void QueueDestroy(Queue *_queue)
{
	if (_queue != NULL)
	{		
		free (_queue->m_items);	
		free (_queue);
	}
	return ;
}


ADTErr QueueRemove(Queue *_queue, int* _pval)
{
	if ((_queue == NULL)||(_queue->m_items == NULL))
	{
		return ERR_NOT_INITIALIZE;
	}
	if ((_queue->m_rear == -1)||(_queue->m_rear < _queue->m_front))
	{
		printf("The array is empty, can\'t remove items.\n");
		_queue->m_rear = -1;
		_queue->m_front = 0;	
		return ERR_UNDERFLOW ;
	}
	if (_queue->m_numItems >= 0)
	{
		* _pval = _queue->m_items[_queue->m_front];
		 _queue->m_front =  ((_queue->m_front + 1) % _queue->m_size);
		 _queue->m_numItems--;
	}
	return ERR_OK ;
}

ADTErr QueueInsert(Queue *_queue, int _val)
{
	if ((_queue == NULL)||(_queue->m_items == NULL))
	{
		return ERR_NOT_INITIALIZE;
	}

	if (_queue->m_numItems == _queue->m_size)
	{
		printf("The Queue is full, can't enter an int.\n");
		return ERR_OVERFLOW ;	
	}
	
	_queue->m_rear++;
	_queue->m_rear = ((_queue->m_rear)%_queue->m_size) ;
	_queue->m_items[_queue->m_rear] = _val ;
	_queue->m_numItems++;
	return ERR_OK ;
}
int QueueIsEmpty(Queue *_queue)
{	
	if ((_queue == NULL)||(_queue->m_items == NULL))
	{
		return 0;
	}
	if (_queue->m_numItems == 0)
	{
		printf("The Queue is Empry.\n");	
		return 1 ;
	}
	return 0 ;
}



void QueuePrint(Queue *_queue)
{
	int i=0;

	for(i=0 ; i < _queue->m_numItems ; i++)
	{
		printf("The object num: %d at the Queue is: %d\n", (_queue->m_front+i), _queue->m_items[(_queue->m_front+i)%_queue->m_size]);
	}
	
	return ;
}

