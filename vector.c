#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

#include "ADTDefs.h"
/*------------------------------------------------------------------------------------------------------------------------
										Vector creation, functions, and main

-------------------------------------------------------------------------------------------------------------------------*/



struct Vector
{
	int* m_items;
	size_t m_originalSize;					/*	The size of the vector	*/
	size_t m_size;							/*	The size of the vector after adding blockes	*/
	size_t m_nItems;
	size_t m_blockSize;						/*	The size that is been added */
} ;


Vector* VectorCreate(int _initialize, int _extensioBlockSize)
{
	Vector* vectorTemp;
	
	if ((_initialize < 0) ||(_extensioBlockSize < 1))
	{
		return NULL;
	}
	vectorTemp = malloc(sizeof(Vector)) ;
	if (! vectorTemp)
	{
		return NULL;
	}
	vectorTemp->m_items = malloc(_initialize * sizeof(int)) ;
	if (! vectorTemp->m_items)
	{
		free(vectorTemp);
		return NULL;
	}
	vectorTemp->m_originalSize = _initialize;
	vectorTemp->m_size = _initialize; 
	vectorTemp->m_nItems = 0;
	vectorTemp->m_blockSize = _extensioBlockSize;

	return vectorTemp;
}

void VectorDestroy(Vector* _vector)
{
	if (_vector)
	{
		if (_vector->m_items) 
		{
			free(_vector->m_items);
		}
		free(_vector);
	}
	return;
}

ADTErr VectorAdd(Vector* _vector, int _item)
{
	if ((_vector == NULL)||(! _vector -> m_items))
	{
		return ERR_NOT_INITIALIZE ;
	}
	
	
	if ((_vector -> m_nItems) == (_vector -> m_size))
	{
		int * _new_vec;
		_new_vec = realloc(_vector->m_items, ((_vector->m_size)+(_vector->m_blockSize))*sizeof(int)) ;
		if(_new_vec == NULL)
		{
			return ERR_REALLOCATION_FAILED ;
		}	
		_vector -> m_items = _new_vec ;
		_vector -> m_size += _vector -> m_blockSize ;
	}
	_vector -> m_items [_vector -> m_nItems] = _item ;
	(_vector -> m_nItems)++ ;

	return ERR_OK ;
}


ADTErr VectorDelete(Vector* _vector, int* _item)
{
	int * Temp_vec ;
	if (_vector == NULL)
	{
		return ERR_NOT_INITIALIZE ;
	}
	if (_vector -> m_nItems == 0)
	{
		return ERR_UNDERFLOW ;
	}
	
	* _item = _vector-> m_items [_vector -> m_nItems-1] ;
	_vector -> m_nItems -- ;
	if (_vector -> m_size >= _vector -> m_originalSize)
	{
		if ((_vector -> m_size - _vector -> m_nItems) == _vector -> m_blockSize * 2)
		{
			Temp_vec = realloc(_vector -> m_items , ( _vector->m_size - _vector->m_blockSize 								*2)*sizeof(int)) ; 	
			if (Temp_vec == NULL)
			{
				return ERR_REALLOCATION_FAILED ;
			}
			_vector -> m_items = Temp_vec ;
			_vector -> m_size -= _vector -> m_blockSize * 2 ;
		}
		
	}	
	return ERR_OK ;
}


ADTErr VectorGet(Vector* _vector, size_t _index, int* _item)
{
	if ((_vector == NULL)||(! _vector -> m_items))
	{
		return ERR_NOT_INITIALIZE ;
	}
	
	if ( _index >= _vector -> m_nItems)
	{
		return ERR_OVERFLOW ;
	}
	*_item = _vector->m_items[_index] ;
	return ERR_OK ;
}


ADTErr VectorSet(Vector* _vector, size_t _index, int _item)
{
	
	if ((_vector == NULL)||(! _vector -> m_items))
	{
		return ERR_NOT_INITIALIZE ;
	}
	if ( _index + 1 > _vector -> m_nItems)
	{
		return ERR_OVERFLOW ;
	}
	_vector -> m_items [_index] = _item ;
	return ERR_OK;
}


ADTErr VectorItemsNum(Vector* _vector, int* _Num_Of_Item)
{	
	* _Num_Of_Item = _vector -> m_nItems ;
	return ERR_OK ;
}

