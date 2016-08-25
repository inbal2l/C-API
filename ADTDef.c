#include <stdio.h>
#include <stdlib.h>
#include "ADTDefs.h"


/*-------------------------------------------------------------------------------------------------------------------------
											create enum function

-------------------------------------------------------------------------------------------------------------------------*/


const char* ErrDescription[] = 
{
	"OK",
	"General Error",
	"Initialization Error",
	"Allocation Error",
	"Reallocation Error",
	"Underflow Error",
	"Overflow Error",
	"Wrong index"
} ;

void HandleErr(ADTErr errNum, char *msg)
{
	if(errNum) 
	{
		printf("ErrNum = %d , ErrDesctiption = %s, msg = %s\n", errNum,  ErrDescription[errNum], msg) ;
	}
}

