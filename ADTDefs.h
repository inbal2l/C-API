#ifndef __ADTDEF_H__
#define __ADTDEF_H__

/*-------------------------------------------------------------------------------------------------------------------------
											create enum shortcuts

-------------------------------------------------------------------------------------------------------------------------*/

typedef enum 
{
	ERR_OK = 0, 
	ERR_GENERAL,
	ERR_NOT_INITIALIZE,
	ERR_ALLOCATION_FAILED,
	ERR_REALLOCATION_FAILED,
	ERR_UNDERFLOW,
	ERR_OVERFLOW,
	ERR_WRONG_INDEX,
	ERR_STACK_BBBBB = 30
} ADTErr;

void HandleErr(ADTErr errNum, char *msg);

#endif /* __ADTDEF_H__ */

