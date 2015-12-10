/*
 * Information about sourcedevelopment
 * -----------------------------------
 * Initial creator: Alfred Johansson
 * Date created: 30/11 2015
 * Last updated by: Viktor Siljehov
 * Date for update: 8/12 2015
 *
 */
 
 /*
  * File: Alfred.c
  * -------------------------
  * This file contains methods: game_menu(), check_answer(), score_system(), print_player_stats().
  * 
  */
  
#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include "Alfred.h"
#include "filip.h"

/*
 * Function: game_menu
 * Usage: game_menu();
 * ------------------------------------------------------
 * Description: Call to open game menu.
 * Contains the menu for the start menu of the game.
 */
int game_menu()
{
	char input;
	clear_screen();
	printf("Welcome to this game of quiz!\n\nYou have four options:\n\n(p)Play\n(h)High Score\n(c)Credits\n(e)Exit\n\nSelection: ");
	scanf("%c", &input);
	clean_stdin();

	switch (input){
	case 'E':
	case 'e':
		return 0;
		break;
	case 'H':
	case 'h':
		return 3;
		break;
	case 'C':
	case 'c':
		return 2;
		break;
	case 'P':
	case 'p':
		return 1;
		break;
	default:	//Vid input som inte matchar något av alternativen
		return 4;
		break;
	}
}

/*
 * Function: check_answer
 * Usage: check_answer(char correct_answer, char input);
 * ------------------------------------------------------
 * Description: Call to check if the correct answer has been entered.
 * The function to check if the input answer is the same as the correct one.
 */
int check_answer(char correct_answer, char input)
{
	if (input == correct_answer)
		return 1;
	else
		return 0;
}

/*
 * Function: score_system
 * Usage: score_system(int QCount,int Difficulty);
 * ------------------------------------------------------
 * Description: Call to calculate the score.
 * Contains the algorithm to calculate the score.
 */
int score_system(int streak, int difficulty)
{
	int score = (streak * difficulty);
	return score;
}

/*
 * Function: print_player_stats
 * Usage: print_player_stats(game_stats stats);
 * ------------------------------------------------------
 * Description: Call to print the player stats.
 * The function that prints the players current stats.
 */
void print_player_stats(game_stats stats)
{
	printf("Score: %-3d Lives: %-3d Level: %-3d Streak: %-3d Question: %3d of %-3d\n\n",
		stats.score,
		stats.lives,
		stats.level,
		stats.streak,
		stats.q_count,
		25);
}
