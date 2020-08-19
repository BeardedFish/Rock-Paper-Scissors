/*
 * File Name:     rpcfns.h
 * Purpose:       Contains enums and functions to make the RPC (rock, paper, and scissors) game work.
 * Coder:         Darian Benam (GitHub: https://github.com/BeardedFish/)
 * Date:          Saturday, May 17, 2020
 */

#ifndef RPCFNS_H
#define RPCFNS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum move_t
{
	ROCK,
	PAPER,
	SCISSORS,
	INVALID_MOVE
} Move;

typedef enum move_result_t
{
	COMPUTER_WON,
	HUMAN_WON,
	TIE
} MoveResult;

/*
 * Function Name:     lowercase_str()
 *
 * Brief:             Converts all characters in the C-string to lowercase.
 *
 * Parameters:        str - The C-string to be converted to lowercase.
 *                    len - The length of the C-string.
 *
 * Returns:           Nothing.
 */
void lowercase_str(char* str, size_t len);

/*
 * Function Name:     move_to_str()
 *
 * Brief:             Converts a Move enum to a C-string.
 *
 * Parameters:        move - The Move enum to be converted to a C-string.
 *
 * Returns:           A constant char pointer. If the enum is equal to ROCK then "rock" is returned. If the enum is equal to PAPER then "paper" is returned. If the enum
 *                    is equal to SCISSORS then "scissors" is returned. If the enum is equal to INVALID_MOVE then "invalid move" is returned.
 */
const char* move_to_str(Move move);

/*
 * Function Name:     str_to_move()
 *
 * Brief:             Converts a C-string to a Move enum.
 *
 * Parameters:        str - The C-string to be converted to a move enum.
 *
 * Returns:           If the C-string is equal to "r" or "rock" then ROCK is returned. If the C-string is equal to "p" or "paper" then PAPER is returned. If the C-string
 *                    is equal to "s" or "scissors" then SCISSORS is returned. If the C-string is not any of those then INVALID_MOVE is returned.
 */
Move str_to_move(char* str);

/*
 * Function Name:     get_rand_move()
 *
 * Brief:             Gets a random Move enum.
 *
 * Parameters:        None.
 *
 * Returns:           A move that is either ROCK, PAPER, or SCISSORS.
 */
Move get_rand_move(void);

/*
 * Function Name:     get_round_result()
 *
 * Brief:             Checks two moves and determines the round
 *
 * Parameters:        computerMove - The move performed by the computer.
 *                    humanMove - The move performed by the human.
 *
 * Returns:           If the computers move beat the human player move then COMPUTER_WON is returned. If the human player beat the computers move then HUMAN_WON is returned.
 *                    If both the human player and the computer player have the same move then TIE is returned.
 */
MoveResult get_round_result(Move computerMove, Move humanMove);

#endif // RPCFNS_H