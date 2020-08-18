/*
 * File Name:     rpcfns.c
 * Purpose:       Refer to rpcfns.h for purpose.
 * Coder:         Darian Benam (GitHub: https://github.com/BeardedFish/)
 * Date:          Saturday, May 17, 2020
 */

#include "../includes/rpcfns.h"
#include <ctype.h>

void lowercase_str(char* str, size_t len)
{
	for (unsigned i = 0; i < len; i++)
	{
		str[i] = tolower(str[i]);
	}
}

const char* move_to_str(Move move)
{
	if (move == ROCK)
	{
		return "rock";
	}
	else if (move == PAPER)
	{
		return "paper";
	}
	else if (move == SCISSORS)
	{
		return "scissors";
	}
	else
	{
		return "invalid move";
	}
}

Move str_to_move(char* str)
{
	if (strcmp(str, "r") == 0 || strcmp(str, "rock") == 0)
	{
		return ROCK;
	}
	else if (strcmp(str, "p") == 0 || strcmp(str, "paper") == 0)
	{
		return PAPER;
	}
	else if (strcmp(str, "s") == 0 || strcmp(str, "scissors") == 0)
	{
		return SCISSORS;
	}
	else
	{
		return INVALID_MOVE;
	}
}

Move get_rand_move(void)
{
	int randMove = rand() % MAX_MOVES_POSSIBLE;

	if (randMove == 0)
	{
		return ROCK;
	}
	else if (randMove == 1)
	{
		return PAPER;
	}
	else // randMove equals 2
	{
		return SCISSORS;
	}
}

MoveResult get_round_result(Move humanMove, Move computerMove)
{
	MoveResult result = TIE;

	if (humanMove == ROCK && computerMove == SCISSORS || humanMove == PAPER && computerMove == ROCK || humanMove == SCISSORS && computerMove == PAPER)
	{
		result = HUMAN_WON;
	}

	if (computerMove == ROCK && humanMove == SCISSORS || computerMove == PAPER && humanMove == ROCK || computerMove == SCISSORS && humanMove == PAPER)
	{
		result = COMPUTER_WON;
	}

	return result;
}