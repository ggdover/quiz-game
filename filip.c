/*
 * Information about sourcedevelopment
 * -----------------------------------
 * Initial creator: Filip Doversten
 * Date created: 30/11 2015
 * Last updated by: Viktor Siljehov
 * Date for update: 8/12 2015
 *
 */
 
 /*
  * File:
  * -------------------------
  * This file contains methods: display_question, clearScreen, display_answers, shuffle_array and fifty_fifty.
  * 
  */
  
#ifdef _WIN32
//#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "filip.h"

// Function: display_question
// Usage: char right_answer = display_question(question);
//--------------------------------------------
// Description: prints a given question with answer options, 
// with a random position for the right answer. 
// Returns a value representing the position of the right answer.

char display_question(question q) {
    
    srand((int)time(NULL));
    
    char answers[4][30];

    strcpy(answers[0], q.a0);
    strcpy(answers[1], q.a1);
    strcpy(answers[2], q.a2);
    strcpy(answers[3], q.a3);
    
    int r = rand() % 4;
    
    char tempStr[30];
    strcpy(tempStr, answers[r]);
    strcpy(answers[r], q.a0);
    strcpy(answers[0], tempStr);
    
    printf("%s\n\n", q.q);
    
    for (int i = 0; i < 4; i++) {
        printf("%d: %s\n", i+1, answers[i]);
    }
	
    return (r+1) + '0';
}

// Function: display_answers
// Usage: char display_answers(char answers[][30], char* r_answer);
//----------------------------------------
// Description: prints the answers in the order which is the given from the array passed on as a argument.
// Second argument takes a string representing the right answer. The method returns a value relative to the position of the right answer.

char display_answers(char answers[][30], char* r_answer) {

    int pos_r_answer = 0;

    for (int i = 0; i < 4; i++) {
        if (strcmp(answers[i], r_answer) == 0)
            pos_r_answer = i+1;

        printf("%d: %s\n", i+1, answers[i]);
    }

    return (pos_r_answer) + '0';
}

// Function: shuffle_array
// Usage: shuffle_array(char answers[][30], char* r_answer);
//-----------------------------------------
// Description: First argument takes a array with answer options, where the method will swap the position of the right answer and a second answer in the array. The second argument tells the function what represents the right answer.

void shuffle_array(char answers[][30], char* r_answer) {

    int r = rand() % 4;
    int r_answer_origin = 0;

    for (int i = 0; i < 4; i++)
        if (strcmp(answers[i], r_answer) == 0)
            r_answer_origin = i;

    char tempStr[30];
    strcpy(tempStr, answers[r]);
    strcpy(answers[r], r_answer);
    strcpy(answers[r_answer_origin], tempStr);
}

// Function: fifty_fifty
// Usage: fifty_fifty(char answers[][30], char* r_answer);
//-------------------------------------------
// Description: First argument takes a array with answer options. The function will empty the string ("") on two elements. Any of these two elements can't be the element holding the right answer. The second argument gives us the right answer which we use to find the element representing the right answer.

void fifty_fifty(char answers[][30], char* r_answer) {

    int pos_r_answer = 0;

    for (int i = 0; i < 4; i++) {
        if (strcmp(answers[i], r_answer) == 0)
            pos_r_answer = i;
    }

    int r = rand() % 3;

    if (r == pos_r_answer)
        r++;

    for (int i = 0; i < 4; i++)
        if (i != r && i != pos_r_answer)
            strcpy(answers[i], "");
}

// Function: clearScreen
// Usage: clearScreen();
//--------------------------------------
// Description: Clears the screen from content.
// Compatible with both UNIX and Win platforms.

void clear_screen(void) {
	#ifdef _WIN32
	system("cls");
	#else
    //int n;
    //for (n = 0; n < 10; n++)
    //  printf( "\n\n\n\n\n\n\n\n\n\n" );
	printf("\033[2J");
	#endif
}
