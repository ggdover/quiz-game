//
//  filip.c
//  textQuiz
//
//  Created by Filip Doversten on 01/12/15.
//  Copyright © 2015 Filip Doversten. All rights reserved.
//

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
    
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        putchar('\n');
    }
}


//  Funkar ej
void fiftyfiftyAndPrint(question q, char **answers, char *r_answer) {
    
    srand((int)time(NULL));
    
    char **new_answers;
    int r = rand() % 3;
    
    new_answers = malloc(4 * sizeof(char*));
    for (int i = 0; i < 4; i++) {

        new_answers[i] = malloc(30 * sizeof(char));

        new_answers[i] = "";
    }
    
    for (int i = 0; i < 4; i++) {
        printf("%s\n",answers[i]);
    }
    
    for (int i = 0; i < 4; i++) {
        printf("%s\n",new_answers[i]);
    }
    
    int j = 0;
    for (int i = 0; i < 4; i++) {
        if (strcmp(answers[i], r_answer) == 0)
            strcpy(new_answers[i], answers[i]);
        else {
            if (j == r)
                strcpy(new_answers[i], answers[i]);
            
            j++;
        }
    }
    
    printf("%s", q.q);
    
    for (int i = 0; i < 4; i++) {
        printf("%d:%s", i, new_answers[i]);
    }
}

//  Funkar ej
char **printNewQuestion(question q, int *r_answer_pos) {
    
    srand((int)time(NULL));
    
    char **answers;
    
    answers = malloc(4 * sizeof(char*));
    for (int i = 0; i < 4; i++) {

        answers[i] = malloc(30 * sizeof(char));
    }
    
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
    
    *r_answer_pos = r+1;
    
    return answers;
}