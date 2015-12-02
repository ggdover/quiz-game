#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

int game_menu();
int check_answere(int correct_answere, int input);
int score_system(int QCount, int difficulty);




int game_menu(){
	char input;
	printf("Welcome to this game of quiz!\nYou have three options:\nPlay	  Credits	Exit\n");
	scanf("%c", &input);

	switch (input){
	case 'P':
	case 'p':
		printf("Play\n");		//Funktionsanrop av game
		system("pause");
		return 1;
		break;
	case 'C':
	case 'c':
		printf("Credits\n");	//Funktionsanrop av credits
		system("pause");
		return 2;
		break;
	case 'E':
	case 'e':
		printf("Exit\n");		//Avslutar spelet
		system("pause");
		return 0;
		break;
	default:
		printf("Wrong input try again\n");			//Vid input som inte matchar något av alternativen
		system("pause");
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