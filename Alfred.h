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
  
#ifndef ALFRED_H_
#define ALFRED_H_

#include "viktor.h"

/*
 * Function: game_menu
 * Usage: game_menu();
 * ------------------------------------------------------
 * Description: Call to open game menu.
 * Contains the menu for the start menu of the game.
 */
int game_menu();

/*
 * Function: check_answer
 * Usage: check_answer(char correct_answer, char input);
 * ------------------------------------------------------
 * Description: Call to check if the correct answer has been entered.
 * The function to check if the input answer is the same as the correct one.
 */
int check_answer(char correct_answer, char input);

/*
 * Function: score_system
 * Usage: score_system(int streak,int difficulty);
 * ------------------------------------------------------
 * Description: Call to calculate the score.
 * Contains the algorithm to calculate the score.
 */
int score_system(int streak, int difficulty);

/*
 * Function: print_player_stats
 * Usage: print_player_stats(game_stats stats);
 * ------------------------------------------------------
 * Description: Call to print the player stats.
 * The function that prints the players current stats.
 */
void print_player_stats(game_stats stats);

#endif
