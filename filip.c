//
//  filip.c
//  textQuiz
//
//  Created by Filip Doversten on 01/12/15.
//  Copyright © 2015 Filip Doversten. All rights reserved.
//

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#include <term.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "filip.h"

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
        printf("%d:%s\n", i+1, answers[i]);
    }
	
    return (r+1) + '0';
}

void clearScreen(void) {
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}