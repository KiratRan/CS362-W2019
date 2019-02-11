#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Tests village card
int main(int argc, char **argv)
{
	printf("\n TESTING VILLAGE CARD \n");
	int *k = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy);
	struct gameState game;

	initializeGame(2, k, 1, &game);

	int handSize = numHandCards(&game),
		actions = game.numActions;

	cardEffect(village, 0, 0, 0, &game, 0, 0);

	if (numHandCards(&game) == handSize && game.numActions == actions + 2)
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