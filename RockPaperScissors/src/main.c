/*
 * File Name:     main.c
 * Purpose:       Contains the main entry point of the rock, paper, and scissors game.
 * Coder:         Darian Benam (GitHub: https://github.com/BeardedFish/)
 * Date:          Saturday, May 17, 2020
 */

#include "../includes/rpcfns.h"
#include <stdbool.h>
#include <time.h>

#define MAX_SCORE_TO_WIN 10

/*
 * Main entry point of the program.
 */
int main()
{
	printf("Rock, Paper, Scissors - By: Darian Benam\n");

	srand((unsigned)time(NULL));

	Move computerMove;
	Move humanMove;
	char* strComputerMove;
	char* strHumanMove;
	int computerScore = 0;
	int humanScore = 0;

	char userInput[255] = { '\0' };
	while (true)
	{
		if (computerScore == MAX_SCORE_TO_WIN || humanScore == MAX_SCORE_TO_WIN)
		{
			char* output = computerScore == MAX_SCORE_TO_WIN ? "You lost" : "You won";
			printf("\n%s %s", output, "against the computer!");

			break;
		}

		printf("\nEnter a move/command: ");
		scanf_s("%s", &userInput, sizeof(userInput));

		lowercase_str(userInput, strlen(userInput));

		if (strcmp(userInput, "quit") == 0)
		{
			break;
		}
		else if (strcmp(userInput, "help") == 0)
		{
			printf("\nCommands:\n");
			printf("help - Displays a list of commands on how to use the program.\n");
			printf("scores - Displays the amount of rounds both the computer and the human player won.\n");
			printf("quit - Quits the program.\n");
			printf("r or rock - Sets your move for the current round as rock.\n");
			printf("p or paper - Sets your move for the current round as paper.\n");
			printf("s or scissors - Sets your move for the current round as scissors.\n");
		}
		else if (strcmp(userInput, "scores") == 0)
		{
			printf("Computer: %d | Human (You): %d\n", computerScore, humanScore);
		}
		else if ((humanMove = str_to_move(userInput)) != INVALID_MOVE)
		{
			computerMove = get_rand_move();

			strComputerMove = move_to_str(computerMove);
			strHumanMove = move_to_str(humanMove);

			switch (get_round_result(humanMove, computerMove))
			{
				case COMPUTER_WON:
					printf("Computer chose %s which beats %s. You lost this round!\n", strComputerMove, strHumanMove);

					computerScore++;
					break;
				case HUMAN_WON:
					printf("You chose %s which beats %s. You win this round!\n", strHumanMove, strComputerMove);

					humanScore++;
					break;
				case TIE:
					printf("You both chose %s. This round ended in a tie!\n", strComputerMove);
					break;
			}
		}
		else
		{
			printf("Invalid command!\n");
		}
	}

	return 0;
}