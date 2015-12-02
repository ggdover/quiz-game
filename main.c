#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct
{
	char q[40];
	char a0[20];
	char a1[20];
	char a2[20];
	char a3[20];
	int d;
}question;

void flush_buffer();
int pick_question(int n_lines);
int count_file_lines();
question *read_from_file();

int main()
{
	question *questions;	
	questions = read_from_file();
	int n_lines = count_file_lines();
	int *used_questions = malloc(sizeof(int)*n_lines);
	while(1)
	{
		for(int i = 0; i < n_lines; i++)
			used_questions[i] = 0;
		int q_count = 0;
		int stage = 1;
		while(1)
		{
			int picked_q = 0;
			do
			{
				int picked_q = pick_question(n_lines);
			}while((used_questions[picked_q] != 0) && (questions->d != stage));
			q_count++;
			getchar();
			
			questions[picked_q];
			//flush_buffer(); rensa skiten
			//rita osv....
		}
	}
	
	getchar();
}
//80x25
int pick_question(int n_lines)
{
	srand(time(NULL));
	
	return rand()%n_lines;
}

question *read_from_file()
{
	question *questions;
	
	FILE *fp;
	fp = fopen("test.q", "r");
	int n_lines = count_file_lines();
	questions = malloc(sizeof(questions)*n_lines + 1);
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