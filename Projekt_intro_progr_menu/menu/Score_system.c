#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

int main(int QCount, int Difficulty)
{
	int score = (QCount * Difficulty) / (QCount - (Difficulty - 0.5));
	return score;
}