#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Tests adventurer card
int main(int argc, char **argv)
{
	printf("\n TESTING ADVENTURER CARD \n");
	int *k = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy);
	struct gameState game;

	initializeGame(2, k, 1, &game);

	if (cardEffect(adventurer, 0, 0, 0, &game, 0, 0) == 0)
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