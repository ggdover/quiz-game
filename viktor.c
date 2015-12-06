#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "viktor.h"

void game_start()
{
	srand(time(NULL));
	question *questions;	
	questions = read_from_file();
	int n_lines = count_file_lines();
	int *used_questions = malloc(sizeof(*used_questions));
	while(1)
	{
		for(int i = 0; i < n_lines; i++)
			used_questions[i] = 0;
		int q_count = 0;
		int picked_q;
		int stage = 1;
		while(1)
		{
			do
			{
				picked_q = pick_question(n_lines);
				printf("picked_q = %d\n", picked_q);
			}while((used_questions[picked_q] != 0) || (questions[picked_q].d != stage));
			used_questions[picked_q] = 1;
			q_count++;
			printf("gameloop\n");
			getchar();
			//questions[picked_q];
			//flush_buffer(); rensa skiten
			//rita osv....
			if(q_count == 5)
			{
				q_count = 0;
				stage++;
			}
		}
	}
}

int pick_question(int n_questions)
{
	return rand()%n_questions;
}

question *read_from_file()
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

int count_file_lines()
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
	int str_length;

	while (string[str_length] != 0x00)
	{
		str_length++;
	}
	
	do
	{
		input = getchar();
		fflush(stdin);
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