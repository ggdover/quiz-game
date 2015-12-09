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
  * This file contains methods: displayQuestion(), and clearScreen().
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

// Function: displayQuestion
// Usage: char right_answer = displayQuestion(question);
//--------------------------------------------
// Description: prints a given question with answer options, 
// with a random position for the right answer. 
// Returns a value representing the position of the right answer.

char displayQuestion(question q) {
    
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

// Function: clearScreen
// Usage: clearScreen();
//--------------------------------------
// Description: Clears the screen from content.
// Compatible with both UNIX and Win platforms.

void clearScreen(void) {
	#ifdef _WIN32
	system("cls");
	#else
	printf("\033[2J\033[1;1H");
	#endif
}