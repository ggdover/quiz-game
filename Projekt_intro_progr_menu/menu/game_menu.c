#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

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