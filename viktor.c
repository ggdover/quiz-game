#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "viktor.h"
#include "Alfred.h"
#include "filip.h"

void game_start()
{
	srand(time(NULL));
	
	question *questions;	
	questions = read_from_file();
	
	int n_lines = count_file_lines();
	int *used_questions = malloc(sizeof(*used_questions));
	
	/*The main menu loop*/
	while(1)
	{
		/*Print menu and get selection*/
		int selection;
		do
		{
			selection = game_menu();
		}
		while(selection == 3);
		/*Credits screen*/
		if(selection == 2)
		{
			//credits
		}
		/*The play state*/
		else if(selection == 1)
		{
			/*Setting all questions to unused*/
			for(int i = 0; i < n_lines; i++)
				used_questions[i] = 0;
				
			/*Game variables*/
			int q_count = 0;
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
				q_count++;
				
				score_print(score);
				printf("Lives: %d\n", lives);
				
				/*Display question and get the correct answer*/
				char c_answer = displayQuestion(questions[picked_q]);
				
				/*Get correct input*/
				char c_input = handle_input("1234e");
				
				/*If exit*/
				if(c_input == 'e')
					return;
					
				/*If the answer is right*/
				if(check_answer(c_answer, c_input) == 1)
				{
					printf("You were right!");
					streak++;
					score = score + score_system(streak, level);
				}
				/*If the answer*/
				else
				{
					lives--;
					streak = 0;
				}
				
				/*Lives == 0 -> Lose*/
				if(lives == 0)
				{
					//do stuff
					printf("You suck!");
				}
				//questions[picked_q];
				//flush_buffer(); rensa skiten
				//rita osv....
				if(q_count == 5)
				{
					q_count = 0;
					level++;
				}
			}
		}
		else if(selection == 0)
			return;			
	}
}

int pick_question(int n_questions)
{
	return rand()%n_questions;
}

question *read_from_file(void)
{
	question *questions;
	
	FILE *fp;
	fp = fopen("test.q", "r");
	int n_lines = count_file_lines();
	questions = malloc(sizeof(*questions)*n_lines);
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
	return questions;
}

int count_file_lines(void)
{
	FILE *fp;
	fp = fopen("test.q", "r");
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
	fclose(fp);
	return lines;
}

char handle_input(char *string)
{
	char test, input;
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