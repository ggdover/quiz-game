#ifndef ALFRED_H_
#define ALFRED_H_

int game_menu(void);
int check_answer(char correct_answer, char input);
int score_system(int QCount, int difficulty);
void score_print(int score);

#endif