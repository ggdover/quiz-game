/*
 * Information about sourcedevelopment
 * -----------------------------------
 * Initial creator: Viktor Siljehov
 * Date created: 2015-11-30
 * Last updated by: Viktor Siljehov
 * Date for update: 2015-12-09
 *
 */
 
/*
 * File: viktor.c
 *
 * -------------------------
 * This file contains methods: game_start, credits_screen, check_if_high_score, get_scores_from_file, load_default_scores,
 * score_screen, write_scores_to_file, handle_input, pick_question, count_file_lines, read_questions_from_file, clean_stdin, name_input
 */

/* To make sure that the program will compile and function on both UNIX and WIN */
#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#include <io.h>
#define F_OK    0
#else
#include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "viktor.h"
#include "Alfred.h"
#include "filip.h"

/*
 * Function: game_start
 * Usage: game_start();
 * ------------------------------------------------------
 * Description: Call to start the game.
 * Contains all the major loops and logic.
 */
void game_start(void)
{
	/* Sweet colours for Windows*/
	/*#ifdef _WIN32
		system("COLOR 12");
	#endif*/

	srand(time(NULL));
	question *questions;
	high_score high_scores[MAX_SCORES];
	
	int n_lines;
	int *used_questions;

	/*Check if question file exits UNIX and WIN*/
	#ifdef _WIN32
	if(_access("questions.txt", F_OK) != -1)
	#else
	if(access("questions.txt", F_OK) != -1)
	#endif
	{
		// file exists
		FILE *fp;
		fp = fopen(QUESTION_FILE, "r");
		n_lines = count_file_lines(fp);
		fclose(fp);
		used_questions = malloc(sizeof(*used_questions)*n_lines);
		questions = malloc(sizeof(*questions)*n_lines);
		read_questions_from_file(n_lines, questions);
	} 
	else 
	{
		// file doesn't exist
		printf("Error!: questions.txt doesn't exist. Enter (e) to exit: ");
		handle_input("Ee");
		return;
	}
		
	/*Check if high score file exists UNIX and WIN*/
	#ifdef _WIN32
	if(_access("scores.txt", F_OK) != -1)
	#else
	if(access("scores.txt", F_OK) != -1)
	#endif
	{
		// file exists
		get_scores_from_file(high_scores);
	} 
	else
	{
		// file doesn't exist
		printf("Error!: scores.txt doesn't exist, loading defaults. Enter (c) to continue: ");
		handle_input("Cc");
		load_default_scores(high_scores);
		write_scores_to_file(high_scores);
	}
	
	/*The main menu loop*/
	while(1)
	{
		/*Print menu and get selection*/
		int selection;
		do
		{
			selection = game_menu();
		}
		while(selection == 4);
		/*Credits screen*/
		if(selection == 2)
		{
			credits_screen();
		}
		/*High score screen*/
		else if (selection == 3)
		{
			score_screen(high_scores);
		}
		/*The play state*/
		else if(selection == 1)
		{
			/*Setting all questions to unused*/
			for(int i = 0; i < n_lines; i++)
				used_questions[i] = 0;
			
			/*Game variables*/
			game_stats stats;
			stats.q_count = 0;
			stats.streak = 0;
			stats.level = 1;
			stats.score = 0;
			stats.lives = 3;
		
			/*The game loop*/
			while(1)
			{
				stats.q_count++;
				
				clearScreen();
				
				/*Pick a question*/
				do
				{
					stats.picked_q = pick_question(n_lines);
				}while((used_questions[stats.picked_q] != 0)
					||(questions[stats.picked_q].d != stats.level));
				
				/*Set the question as used*/
				used_questions[stats.picked_q] = 1;
				
				printf("You can exit to the menu at any time by entering (e)!\n\n");
				print_player_stats(stats);
							
				/*Display question and get the correct answer*/
				char c_answer = displayQuestion(questions[stats.picked_q]);
				printf("\nSelection: ");

				/*Get correct input*/
				char c_input = handle_input("1234Ee");
				
				/*If exit*/
				if(c_input == 'E' || c_input == 'e')
					break;
									
				/*If the answer is correct*/
				if(check_answer(c_answer, c_input) == 1)
				{
					stats.streak++;
					stats.score += score_system(stats.streak, stats.level);
				}
				/*If the answer is wrong*/
				else
				{
					stats.lives--;
					stats.streak = 0;
				}
				
				/*Lives == 0 -> Lose OR win*/
				if(stats.lives == 0 || stats.q_count == 25)
				{
					clearScreen();
					print_player_stats(stats);
					check_if_high_score(stats.score, high_scores);
					score_screen(high_scores);
					write_scores_to_file(high_scores);
					break;
				}
				
				/*Increment the level -> harder questions*/
				if(stats.q_count % 5 == 0 && stats.q_count != 25)
				{
					stats.level++;
				}
			}
		}
		else if (selection == 0)
		{
			/*Clean up!*/
			MY_FREE(questions);
			MY_FREE(used_questions);
			return;
		}
	}
}

/*
 * Function: name_input
 * Usage: name_input();
 * ------------------------------------------------------
 * Description: Function takes name and makes sure that the name doesn't contain 
 * a newline that would break the score screen.
 */
void name_input(char *name)
{
	char *s;
	do
	{
		fgets(name, 4, stdin);
		clean_stdin();
		s = strchr(name, '\n');
		if(s != NULL)
			printf("\nBad name! Try again: ");
	}while(s != NULL);//Loop while s has a pointer to '\n'
}

/*
 * Function: credits_screen
 * Usage: credits_screen();
 * ------------------------------------------------------
 * Description: Show the credits screen. Contains the names of the programmers.
 * Requires you to enter a specific letter to leave the screen.
 */
void credits_screen(void)
{
	clearScreen();
	printf("Programmers:\n\nViktor Siljehov\nAlfred Johansson\nFilip Doversten\nDaniel Tirosh");
	printf("\n\nEnter (e) to go back to the menu: ");
	handle_input("Ee");
}

/*
 * Function: load_default_scores
 * Usage: load_default_scores(high_scores);
 * ------------------------------------------------------
 * Description: Function fills the high score struct array with default scores.
 */
void load_default_scores(high_score *high_scores)
{	
	strcpy(high_scores[0].name, "AAA");
	strcpy(high_scores[1].name, "BBB");
	strcpy(high_scores[2].name, "CCC");
	strcpy(high_scores[3].name, "DDD");
	strcpy(high_scores[4].name, "EEE");
	strcpy(high_scores[5].name, "FFF");
	strcpy(high_scores[6].name, "GGG");
	strcpy(high_scores[7].name, "HHH");
	strcpy(high_scores[8].name, "III");
	strcpy(high_scores[9].name, "JJJ");
	strcpy(high_scores[10].name, "KKK");
	strcpy(high_scores[11].name, "LLL");
	strcpy(high_scores[12].name, "MMM");
	strcpy(high_scores[13].name, "NNN");
	strcpy(high_scores[14].name, "OOO");

	for(int i = 0; i < MAX_SCORES; i++)
	{
		high_scores[i].score = MAX_SCORES*10 - 10*i;
	}
}

/*
 * Function: get_scores_from_file
 * Usage: get_scores_from_file(high_scores);
 * ------------------------------------------------------
 * Description: Will take the struct array and read the high score file into it.
 */
void get_scores_from_file(high_score *high_scores)
{
	FILE *fp;
	fp = fopen(HIGH_SCORE_FILE, "r");
	
	for(int i = 0; i < MAX_SCORES; i++)
	{
		fscanf(fp, "%d;%[^\n;]", &high_scores[i].score, high_scores[i].name);
	}
	fclose(fp);
}

/*
 * Function: write_scores_to_file
 * Usage: write_scores_to_file(high_scores);
 * ------------------------------------------------------
 * Description: Takes the high score struct array and writes it to a file.
 */
void write_scores_to_file(high_score *high_scores)
{
	FILE *fp;
	fp = fopen(HIGH_SCORE_FILE, "w+");
	
	for(int i = 0; i < MAX_SCORES; i++)
	{
		fprintf(fp, "%d;%s\n",  high_scores[i].score, high_scores[i].name);
	}
	fclose(fp);
}

/*
 * Function: score_screen
 * Usage: score_screen(high_scores);
 * ------------------------------------------------------
 * Description: Will write the high scores and require a specific letter to leave.
 */
void score_screen(high_score *high_scores)
{
	clearScreen();
	printf("HIGH SCORES!\n\n");
	for(int i = 0; i < MAX_SCORES; i++)
	{
		printf("%2d: Name: %-4s	Score: %-4d\n",i+1 , high_scores[i].name, high_scores[i].score);
	}
	printf("\nEnter (e) to go back to the menu, or (r) to reset the scores: ");
	
	char temp = handle_input("EeRr");
	if(temp == 'r' || temp == 'R')
	{
		printf("\nAre you sure you want to reset the score?\n(Y/N): ");
		char temp = handle_input("NnYy");
		if(temp == 'y' || temp == 'Y')
		{
			load_default_scores(high_scores);
			write_scores_to_file(high_scores);
		}
		score_screen(high_scores); //Make it reload the screen
	}
	else
	{
		//Nothing...
	}
}

/*
 * Function: check_if_high_score
 * Usage: check_if_high_score(score, high_scores);
 * ------------------------------------------------------
 * Description: Will check if you have a high score by comparing scores.
 * If you have a high score it will ask you to enter your name
 * and add you in the appropriate location by moving the rest one step.
 * If you don't have a high score it will return. 
 */
void check_if_high_score(int score, high_score *high_scores)
{
	int i = 0;
	char name[4];
	while(i < MAX_SCORES && (high_scores[MAX_SCORES - 1 - i].score < score))
	{
		i++;
	}
	if(i == 0)
	{
		printf("\nYou didn't make the high score list. Enter (c) to see the high scores: ");
		handle_input("Cc");
		return;
	}
	else
	{
		printf("\nYou made the high score list! Please enter your name (3 characters): ");
		name_input(name);
	}

	if(i == 1)
	{
		strcpy(high_scores[MAX_SCORES - 1].name, name);
		high_scores[MAX_SCORES - 1].score = score;
	}
	else
	{
		for(int n = 1; n < i; n++)
		{
			strcpy(high_scores[MAX_SCORES - n].name, high_scores[MAX_SCORES - 1 - n].name);
			high_scores[MAX_SCORES - n].score = high_scores[MAX_SCORES - 1 - n].score;
		}
		strcpy(high_scores[MAX_SCORES - i].name, name);
		high_scores[MAX_SCORES - i].score = score;
	}
}

/*
 * Function: pick_question
 * Usage: int picked_question = pick_question(n_questions);
 * ------------------------------------------------------
 * Description: Will pick a random number between 0 and n_questions
 */
int pick_question(int n_questions)
{
	return rand()%n_questions;
}

/*
 * Function: read_questions_from_file
 * Usage: read_questions_from_file(n_lines, questions);
 * -------------------------------------------------------
 * Description: Will fill the struct array questions with data from the file.
 */
void read_questions_from_file(int n_lines, question *questions)
{	
	FILE *fp;
	fp = fopen(QUESTION_FILE, "r");
	for(int i = 0; i < n_lines; i++)
	{
		fscanf(fp, "%d;%[^\n;];%[^\n;];%[^\n;];%[^\n;];%[^\n;]",
		&questions[i].d,
		questions[i].q,
		questions[i].a0,
		questions[i].a1,
		questions[i].a2,
		questions[i].a3);
	}
	fclose(fp);
}

/*
 * Function: count_file_lines
 * Usage: int n_lines = count_files(filePointer);
 * ------------------------------------------------------
 * Description: Will count the file lines from the file pointer and return it.
 */
int count_file_lines(FILE *fp)
{
	char c;
	int lines = 0;


	while(!feof(fp))
	{
		c = fgetc(fp);

		if(c == '\n')
		{
			lines++;
		}
	}
	return lines;
}

/*
 * Function: handle_input
 * Usage: char input = handle_input("ab1");
 * ------------------------------------------------------
 * Description: Takes a string as the parameter.
 * The string contains the accepted characters for the input.
 * The function will loop until it gets a char that is in the string.
 */
char handle_input(char *string)
{
	char test = NULL, input;
	int str_length = 0;

	while (string[str_length] != 0x00)
	{
		str_length++;
	}
	
	do
	{
		input = getchar();
		clean_stdin();
		for(int i = 0; i < str_length; i++)
		{
			if(input == string[i])
				test = string[i];
		}
		if(test != input)
			printf("Invalid input! Try again: ");
	}while(test != input);
		
	return input;
}

/*
 * Function: clean_stdin
 * Usage: clean_stdin();
 * -------------------------------------------------------
 * Description: A platform independent fflush(stdin);.
 */
void clean_stdin(void)
{
		int c;
		do
		{
		    c = getchar();
		}while (c != '\n' && c != EOF);

}