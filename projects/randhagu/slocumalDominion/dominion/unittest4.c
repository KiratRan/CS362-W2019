#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Tests updateCoins function
int main(int argc, char **argv)
{
    printf("\n TESTING UPDATECOINS FUNCTION \n");
	struct gameState game;
	int firstUpdate = 0,
		secondUpdate = 0;

	updateCoins(0, &game, 10);
	firstUpdate = game.coins;

	updateCoins(0, &game, 20);
	secondUpdate = game.coins;

	if (firstUpdate == 10 && secondUpdate == 20)
	{
		printf("\n TEST PASSED \n");
	}
	else
	{
		printf("\n TEST FAILED \n");
	}

	return 0;
}