#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Tests outpost card
int main(int argc, char **argv)
{
	printf("\n TESTING OUTPOST CARD \n");
	int *k = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy);
	struct gameState game;

	initializeGame(2, k, 1, &game);

	int timesPlayed = game.outpostPlayed;

	cardEffect(outpost, 0, 0, 0, &game, 0, 0);

	if (game.outpostPlayed == timesPlayed + 1)
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