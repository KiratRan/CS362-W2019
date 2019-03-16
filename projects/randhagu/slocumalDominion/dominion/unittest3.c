#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Tests getCost function
int main(int argc, char **argv)
{
	printf("\n TESTING GETCOST FUNCTION \n");
	if (getCost(curse) == 0 && getCost(smithy) == 4 && getCost(gold) == 6 && getCost(estate) == 2)
	{
		printf("\n TEST PASSED \n");
	}
	else
	{
		printf("/n TEST FAILED \n");
	}

	return 0;
}