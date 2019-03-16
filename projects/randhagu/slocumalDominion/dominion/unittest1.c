#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Tests kingdomCards function
int main(int argc, char **argv)
{
    printf("\n TESTING KINGDOMCARDS FUNCTION \n");
    int *k = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy);
    
    if(k[0] == adventurer && k[1] ==  gardens && k[2] == embargo && k[3] == village && k[4] == minion
    && k[5] == mine && k[6] == cutpurse && k[7] == sea_hag && k[8] == tribute && k[9] == smithy)
    {
        printf("\n TEST PASSED \n");
    }
    else
    {
		printf("\n TEST FAILED \n");
    }
    
	free(k);

	return 0;
}