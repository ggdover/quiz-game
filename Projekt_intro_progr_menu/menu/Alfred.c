#include "Alfred.h"
#include "viktor.h"
#include "filip.h"
#include <stdio.h>

int game_menu(void){
	char input;
	clearScreen();
	printf("Welcome to this game of quiz!\nYou have three options:\nPlay(p)	  Credits(c)	Exit(e)\n");
	input = getchar();
	clean_stdin();

	switch (input){
	case 'P':
	case 'p':
		printf("Play\n");		//Funktionsanrop av game
		return 1;
		break;
	case 'C':
	case 'c':
		printf("Credits\n");	//Funktionsanrop av credits
		return 2;
		break;
	case 'E':
	case 'e':
		printf("Exit\n");		//Avslutar spelet
		return 0;
		break;
	default:
		printf("Wrong input try again\n");			//Vid input som inte matchar något av alternativen
		return 3;
		break;
	}
}

int check_answer(char correct_answer, char input)
{
	if (input == correct_answer)
		return 1;
	else
		return 0;
}

int score_system(int QCount, int Difficulty)
{
	int score = (QCount * Difficulty);
	return score;
}

void score_print(int score)
{
	printf("Score: %d\n", score);
}