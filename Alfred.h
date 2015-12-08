#ifndef ALFRED_H_
#define ALFRED_H_

int game_menu();
int check_answer(char correct_answer, char input);
int score_system(int QCount, int difficulty);
void print_player_stats(int score, int lives, int level, int q_number, int streak);
#endif