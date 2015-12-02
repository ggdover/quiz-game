#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

int check_answere(int answere, int correct_answere){
	if (answere == correct_answere)
		return 1;			//Returns 1 if the input answere is correct
	else
		return 0;			//Returns 0 if the input answere is incorrect
}