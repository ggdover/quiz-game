#include "Alfred.h"

#include <stdio.h>

int game_menu()
{
	char input;
	clearScreen();
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

void print_player_stats(int score, int lives, int level, int q_number, int streak)
{
	printf("Score: %-4d Lives: %-2d Level: %-2d Streak: %-2d Question: %2d of %-2d\n\n", score, lives, level, streak, q_number, 25);
}