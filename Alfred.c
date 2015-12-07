#include "Alfred.h"

int game_menu()
{
	char input;
	clearScreen();
	printf("Welcome to this game of quiz!\nYou have three options:\nPlay	  Credits	Exit\n");
	scanf("%c", &input);

	switch (input){
	case 'E':
	case 'e':
		return 0;
		break;
	case 'C':
	case 'c':
		return 1;
		break;
	case 'P':
	case 'p':
		return 2;
		break;
	default:
		printf("Wrong input try again\n");			//Vid input som inte matchar något av alternativen
		return 3;
		break;
	}
}

int check_answere(int correct_answere, int input)
{
	if (input == correct_answere)
		return 1;
	else
		return 0;
}

int score_system(int QCount, int Difficulty)
{
	int score = (QCount * Difficulty) / (QCount - (Difficulty - 0.5));
	return score;
}

void score_print(int score)
{
	printf("%d", score);
}