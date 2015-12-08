#ifndef VIKTOR_H_
#define VIKTOR_H_

#include <stdio.h>

/*
 * STRUCT FOR KEEPING QUESTION, ANSWERS AND DIFFICULTY
 */ 
typedef struct
{
	char q[80];
	char a0[30];
	char a1[30];
	char a2[30];
	char a3[30];
	int d;
}question;

#define MAX_SCORES 15
static const char QUESTION_FILE[] = "questions.txt";
static const char HIGH_SCORE_FILE[] = "scores.txt";

/*
 * STRUCT FOR KEEPING HIGH SCOORES 
 */
 typedef struct
 {
	 char name[4];
	 int score;
 }high_score;

/*
 * THE CONTAINS THE GAMELOOP
 */
void game_start(void);

/*
 *FUNCTION FOR DISPLAYING CREDITS
 */

void credits_screen(void);

/*
 * WILL TEST THE SCORE TO SEE IF IT IS A HIGH SCORE AND THEN ADD
 * IT TO THE ARRAY IN THE APPROPRIATE SLOT
 */
void check_if_high_score(int score, high_score *high_scores);

/*
 * READ HIGH SCORES FORM A TEXT FILE
 */
void get_scores_from_file(high_score *high_scores);

/*
 * LOAD DEFAULT SCORES
 */
void load_default_scores(high_score *high_scores);

/*
 * SHOW HIGH SCORES
 */

void score_screen(high_score *high_scores);

/*
 * WRITE HIGH SCORES TO A TEXT FILE
 */
void write_scores_to_file(high_score *high_scores);

/*
 * FILTER INPUT AND ONLY ACCEPT CERTAIN CHARACTERS
 * Example: char handle_input("abc");
 * The example above will only accept a,b or c as input.
 * If the char is accepted the function will return it.
 */
char handle_input(char *string);

/*
 * PICK A RANDOM QUESTION FROM THE ARRAY
 */
int pick_question(int n_questions);

/*
 * COUNT FILE LINES
 */
int count_file_lines(FILE *fp);

/*
 * READ QUESTIONS FROM A FILE AND PUT THEM IN A STRUCT ARRAY
 */
void read_from_file(int n_lines, question *questions);

/*
 * A PLATFORM INDEPENDENT fflush(stdin);
 */
void clean_stdin(void);

#endif