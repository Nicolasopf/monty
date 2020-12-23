#include "monty.h"

/**
 * free_all - Free everything!
 */

void free_all(void)
{
	free(GBB.buffer);
	fclose(GBB.f1);
	if (GBB.stack)
		free(GBB.stack);
}
