#ifndef __VECTOR_H__
#define __VECTOR_H__

/*-------------------------------------------------------------------------------------------------------------------------
							.h file for user - contains functions for Vector struct.

-------------------------------------------------------------------------------------------------------------------------*/

typedef struct Vector Vector;

Vector* VectorCreate(int _initialize, int _extensioBlockSize);
void VectorDestroy(Vector* _Vector);
ADTErr VectorAdd(Vector* _Vector, int _item);
ADTErr VectorDelete(Vector* _Vector, int* _item);
ADTErr VectorGet(Vector* _Vector, size_t _index, int* _item);
ADTErr VectorSet(Vector* _Vector, size_t _index, int _item);
ADTErr VectorItemsNum(Vector* _Vector, int* _Num_Of_Item);

#endif /* __VECTOR_H__ */
