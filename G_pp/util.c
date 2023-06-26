<<<<<<< HEAD
#include "util.h"

void CHECKERROR(int e)
{
	if (e == 1)
	{
		printf("\n[line:%d, %s] Game\n", __LINE__, __func__);
		exit(1);
	}
=======
#include "util.h"

void CHECKERROR(int e)
{
	if (e == 1)
	{
		printf("\n[line:%d, %s] Game\n", __LINE__, __func__);
		exit(1);
	}
>>>>>>> 78f931ab14a97fc7ff776d9425ac7fe48ac315d8
}