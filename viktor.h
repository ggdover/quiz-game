#ifndef VIKTOR_H_
#define VIKTOR_H_

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

/*
 * THE CONTAINS THE GAMELOOP
 */
void game_start(void);

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
int count_file_lines(void);

/*
 * READ QUESTIONS FROM A FILE AND PUT THEM IN A STRUCT ARRAY
 */
question *read_from_file(void);

/*
 * A PLATFORM INDEPENDENT fflush(stdin);
 */
void clean_stdin(void);

#endif