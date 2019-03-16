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
        preHandSize,
        postHandSize,
        preDeckSize,
        postDeckSize,
        seed,
        numOfTests = rand() % (20 + 1 - 10) + 10;
    int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall};

    for (int i = 0; i < numOfTests; i++)
    {
        preHandSize = 0,
        postHandSize = 0,
        preDeckSize = 0,
        postDeckSize = 0;
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

        preHandSize = game.handCount[currentPlayer];
        preDeckSize = game.deckCount[currentPlayer];

        cardEffect(smithy, 0, 0, 0, &game, 0, 0);

        postHandSize = game.handCount[currentPlayer];
        postDeckSize = game.deckCount[currentPlayer];

        int success = 1;

        if(postHandSize != preHandSize + 2)
        {
            printf("Incorrect draw to hand. Test failed.\n");
            testsFailed++;
            success = 0;
        }

        if(postDeckSize != preDeckSize - 3)
        {
            printf("Incorrect draw from deck. Test failed.\n");
            testsFailed++;
            success = 0;
        }

        //Because of bug introduced, smithy only draws two cards. This conditional provides 100% coverage
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