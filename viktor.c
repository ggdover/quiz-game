#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#include <io.h>
#define F_OK    0
#else
#include <unistd.h>
#endif

#define MY_FREE(ptr) free(ptr); ptr = NULL;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "viktor.h"
#include "Alfred.h"
#include "filip.h"

void game_start(void)
{
	#ifdef _WIN32
		system("COLOR 12");
	#endif

	srand(time(NULL));
	question *questions;
	high_score high_scores[MAX_SCORES];
	
	int n_lines;
	int *used_questions;

	/*Check if question file exists*/
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
		read_from_file(n_lines, questions);
	} 
	else 
	{
		// file doesn't exist
		printf("Error!: questions.txt doesn't exist. Enter (e) to exit: ");
		handle_input("e");
		return;
	}
	/*Check if high score file exists*/
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
		handle_input("c");
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
			int q_count = 1;
			int picked_q;
			int streak = 0;
			int level = 1;
			int score = 0;
			int lives = 3;

			/*The game loop*/
			while(1)
			{
				clearScreen();
				
				/*Pick a question*/
				do
				{
					picked_q = pick_question(n_lines);
				}while((used_questions[picked_q] != 0) || (questions[picked_q].d != level));
				
				/*Set the question as used*/
				used_questions[picked_q] = 1;
				
				printf("You can exit to the menu at any time by entering (e)!\n\n");
				print_player_stats(score, lives, level, q_count, streak);
							
				/*Display question and get the correct answer*/
				char c_answer = displayQuestion(questions[picked_q]);
				printf("\nSelection: ");

				/*Get correct input*/
				char c_input = handle_input("1234e");
				
				/*If exit*/
				if(c_input == 'e')
					break;
					
				/*If the answer is correct*/
				if(check_answer(c_answer, c_input) == 1)
				{
					streak++;
					score = score + score_system(streak, level);
				}
				/*If the answer is wromg*/
				else
				{
					lives--;
					streak = 0;
				}
				q_count++;
				/*Lives == 0 -> Lose OR win*/
				if(lives == 0 || (q_count == 25 && level == 5))
				{
					check_if_high_score(score, &high_scores);
					score_screen(high_scores);
					write_scores_to_file(high_scores);
					break;
				}
				/*Increment the level -> harder questions*/
				if(q_count%5== 0)
				{
					level++;
				}
			}
		}
		else if (selection == 0)
		{
			MY_FREE(questions);
			MY_FREE(used_questions);
			return;
		}
	}
}

void credits_screen(void)
{
	clearScreen();
	printf("Programmers:\n\nViktor Siljehov\nAlfred Johansson\nFilip Doversten\nDaniel Tirosh");
	printf("\n\nEnter (e) to go back to the menu: ");
	handle_input("e");
}

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

void score_screen(high_score *high_scores)
{
	clearScreen();
	printf("HIGH SCORES!\n\n");
	for(int i = 0; i < MAX_SCORES; i++)
	{
		printf("%2d: Name: %-4s	Score: %-4d\n",i+1 , high_scores[i].name, high_scores[i].score);
	}
	printf("\nEnter (e) to go back to the menu: ");
	handle_input("e");
}

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
		handle_input("c");
		return;
	}
	else
	{
		printf("\nYou made the high score list! Please enter your name (3 characters): ");
		fgets(name, 4, stdin);
		clean_stdin();
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

int pick_question(int n_questions)
{
	return rand()%n_questions;
}

void read_from_file(int n_lines, question *questions)
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

void clean_stdin(void)
{
		int c;
		do
		{
		    c = getchar();
		}while (c != '\n' && c != EOF);

}