#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    struct gameState game;
    int numPlayers = 2,
        testsPassed = 0,
        testsFailed = 0,
        currentPlayer,
        deckSize,
        handSize,
        preCoins,
        postCoins,
        seed,
        numOfTests = rand() % (20 + 1 - 10) + 10;
    int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall};

    for (int i = 0; i < numOfTests; i++)
    {
        preCoins = 0;
        postCoins = 0;
        seed = rand() % 1000;

        initializeGame(numPlayers, kingdomCards, seed, &game);

        currentPlayer = 0;
        deckSize = rand() % (MAX_DECK + 1);
        handSize = rand() % (deckSize + 1);
        game.whoseTurn = currentPlayer;
        game.numActions = 1;
        game.handCount[currentPlayer] = handSize;
        game.deckCount[currentPlayer] = deckSize - handSize;
        game.discardCount[currentPlayer] = 0;

        //Counts number of coins in player's hand before adventurer is played
        for (int j = 0; j < game.handCount[currentPlayer]; j++)
        {
            if(game.hand[currentPlayer][j] == copper || game.hand[currentPlayer][j] == silver || game.hand[currentPlayer][j] == gold)
            {
                preCoins++;
            }
        }

        cardEffect(adventurer, 0, 0, 0, &game, 0, 0);

        //Counts number of coins in player's hand after adventurer is played
        for (int j = 0; j < game.handCount[currentPlayer]; j++)
        {
            if(game.hand[currentPlayer][j] == copper || game.hand[currentPlayer][j] == silver || game.hand[currentPlayer][j] == gold)
            {
                postCoins++;
            }
        }

        int discardedTreasures = 0;

        //Checks to make sure treasures weren't discarded
        for (int j = 0; j < game.discardCount[currentPlayer]; j++)
        {
            if(game.discard[currentPlayer][j] == copper || game.discard[currentPlayer][j] == silver || game.discard[currentPlayer][j] == gold)
            {
                discardedTreasures++;
            }
        }


        int success = 1;

        if(postCoins > preCoins + 2)
        {
            printf("Overdrew. Test failed.\n");
            testsFailed++;
            success = 0;
        }

        if(postCoins < preCoins)
        {
            printf("Underdrew. Test failed.\n");
            testsFailed++;
            success = 0;
        }

        if(discardedTreasures != 0)
        {
            printf("Tresures were discarded. Test failed.\n");
            testsFailed++;
            success = 0;
        }

        if(success == 1)
        {
            printf("Tests successfully passed\n");
            testsPassed++;
        }
    }

    printf("Number of tests passed: %d\n", testsPassed);
    printf("Number of tests failed: %d\n", testsFailed);

    return 0;
}