/*
 * Information about sourcedevelopment
 * -----------------------------------
 * Initial creator: Viktor Siljehov
 * Date created: 2015-11-30
 * Last updated by: Viktor Siljehov
 * Date for update: 2015-12-08
 *
 */
 
/*
 * File: viktor.h
 * -------------------------
 * This file contains methods: game_start, credits_screen, check_if_high_score, get_scores_from_file, load_default_scores,
 * score_screen, write_scores_to_file, handle_input, pick_question, count_file_lines, read_questions_from_file, clean_stdin, name_input
 */


#ifndef VIKTOR_H_
#define VIKTOR_H_

/* Necessary includes */
#include <stdio.h>

/* Struct for keeping a question with answers and it's difficulty */
typedef struct
{
	char q[80];
	char a0[30];
	char a1[30];
	char a2[30];
	char a3[30];
	int d;
}question;

/* Struct for keeping high scores with a name and score */
 typedef struct
 {
	 char name[4];
	 int score;
}high_score;

/* Struct for keeping game stats */
typedef struct
{
	int q_count;
	int picked_q;
	int streak;
	int level;
	int score;
	int lives;
}game_stats;

/* Defines */
#define MAX_SCORES 15

/* MY_FREE(ptr) will both free and NULL the pointer */
#define MY_FREE(ptr) free(ptr); ptr = NULL;

/* File name constants */
static const char QUESTION_FILE[] = "questions.txt";
static const char HIGH_SCORE_FILE[] = "scores.txt";

/*
 * Function: game_start
 * Usage: game_start();
 * ------------------------------------------------------
 * Description: Call to start the game.
 * Contains all the major loops and logic.
 */
void game_start(void);

/*
 * Function: name_input
 * Usage: name_input();
 * ------------------------------------------------------
 * Description: Function takes name and makes sure that the name doesn't contain 
 * a newline that would break the score screen.
 */
void name_input(char *name);

/*
 * Function: credits_screen
 * Usage: credits_screen();
 * ------------------------------------------------------
 * Description: Show the credits screen. Contains the names of the programmers.
 * Requires you to enter a specific letter to leave the screen.
 */
 void credits_screen(void);

/*
 * Function: check_if_high_score
 * Usage: check_if_high_score(score, high_scores);
 * ------------------------------------------------------
 * Description: Will check if you have a high score by comparing scores.
 * If you have a high score it will ask you to enter your name
 * and add you in the appropriate location by moving the rest one step.
 * If you don't have a high score it will return. 
 */
void check_if_high_score(int score, high_score *high_scores);

/*
 * Function: get_scores_from_file
 * Usage: get_scores_from_file(high_scores);
 * ------------------------------------------------------
 * Description: Will take the struct array and read the high score file into it.
 */
void get_scores_from_file(high_score *high_scores);

/*
 * Function: load_default_scores
 * Usage: load_default_scores(high_scores);
 * ------------------------------------------------------
 * Description: Function fills the high score struct array with default scores.
 */
void load_default_scores(high_score *high_scores);

/*
 * Function: score_screen
 * Usage: score_screen(high_scores);
 * ------------------------------------------------------
 * Description: Will write the high scores and require a specific letter to leave.
 */
void score_screen(high_score *high_scores);

/*
 * Function: write_scores_to_file
 * Usage: write_scores_to_file(high_scores);
 * ------------------------------------------------------
 * Description: Takes the high score struct array and writes it to a file.
 */
void write_scores_to_file(high_score *high_scores);

/*
 * Function: handle_input
 * Usage: char input = handle_input("ab1");
 * ------------------------------------------------------
 * Description: Takes a string as the parameter.
 * The string contains the accepted characters for the input.
 * The function will loop until it gets a char that is in the string.
 */
char handle_input(char *string);

/*
 * Function: pick_question
 * Usage: int picked_question = pick_question(n_questions);
 * ------------------------------------------------------
 * Description: Will pick a random number between 0 and n_questions
 */
int pick_question(int n_questions);

/*
 * Function: count_file_lines
 * Usage: int n_lines = count_files(filePointer);
 * ------------------------------------------------------
 * Description: Will count the file lines from the file pointer and return it.
 */
int count_file_lines(FILE *fp);

/*
 * Function: read_from_file
 * Usage: read_from_file(n_lines, questions);
 * -------------------------------------------------------
 * Description: Will fill the struct array questions with data from the file.
 */
void read_questions_from_file(int n_lines, question *questions);

/*
 * Function: clean_stdin
 * Usage: clean_stdin();
 * -------------------------------------------------------
 * Description: A platform independent fflush(stdin);.
 */
void clean_stdin(void);

#endif