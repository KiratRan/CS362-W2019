#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Tests isGameOver function
int main(int argc, char **argv)
{
    printf("\n TESTING isGameOver FUNCTION \n");
    int *k = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy);
	struct gameState game;

	initializeGame(2, k, 1, &game);

	game.supplyCount[province] = 0;
    
    if(isGameOver(&game) == 1)
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