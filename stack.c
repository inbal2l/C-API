#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#include "vector.h"
#include "ADTDefs.h"

# define _PRINT_ printf("Testing %s\n", __FUNCTION__) ;
# define _LINE_ printf("Line num: %d\n", __LINE__) ;

struct Stack
{
	Vector * vector ;
};

Stack* StackCreate(size_t _initSize, size_t _blockSize)
{
	Stack* stackTemp;
	
	if ((_initSize < 0) ||(_blockSize < 1))
	{
		return NULL;
	}
	stackTemp = malloc(sizeof(Stack)) ;
	if (! stackTemp)
	{
		return NULL;
	}
	stackTemp->vector = VectorCreate(_initSize, _blockSize) ;
	if (! stackTemp->vector)
	{
		free(stackTemp);
		return NULL;
	}
	return stackTemp ;
}

void StackDestroy(Stack * _stack)
{
	if (_stack) 
	{
		VectorDestroy( _stack->vector);
		free(_stack);		
	}

return ;
}

ADTErr StackPush(Stack* _stack, int _item)
{
	if (! _stack)
	{
		return ERR_NOT_INITIALIZE ;
	}
	return VectorAdd(_stack->vector,_item) ;
}
ADTErr StackPop(Stack* _stack, int* _item)
{
	if (! _stack)
	{
		return ERR_NOT_INITIALIZE ;
	}
	return VectorDelete(_stack->vector, _item) ;
}

ADTErr StackTop(Stack* _stack, int* _item)
{
	int _num_of ;
	if (! _stack)
	{
		return ERR_NOT_INITIALIZE ;
	}
	VectorItemsNum(_stack->vector, &_num_of);
	if (_num_of == 0)
	{
		return ERR_OVERFLOW;
	}
	return VectorGet(_stack->vector, _num_of - 1, _item) ;
}

int StackIsEmpty(Stack* _stack)
{
	int _num_of = -1;
	if ((_stack == NULL)||(_stack->vector == NULL))
	{	
		return _num_of ;
	}
	VectorItemsNum(_stack->vector, &_num_of);
	if (_num_of==-1) 
	{
		return _num_of ;
	}
	return (_num_of==0) ;
}

