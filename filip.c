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


char displayQuestion(question q, bool ff_active) {
    
    srand((int)time(NULL));
    
    char **answers;
    int n_answers;
    
    if (ff_active)
        n_answers = 2;
    else
        n_answers = 4;
    
    answers = malloc(n_answers*sizeof(char*));
    for (int i = 0; i < n_answers; i++) {
        answers[i] = malloc(20 * sizeof(char));
    }
    
    int r = rand() % n_answers;
    
    strcpy(answers[0], q.a0);
    
    if (ff_active) {
        switch (r) {
            case 0:
                strcpy(answers[1], q.a1);
                break;
            case 1:
                strcpy(answers[1], q.a2);
                break;
            case 2:
                strcpy(answers[1], q.a3);
                break;
            default:
                break;
        }
    } else {
        
        strcpy(answers[1], q.a1);
        strcpy(answers[2], q.a2);
        strcpy(answers[3], q.a3);
    }
    
    
    char tempStr[20];
    strcpy(tempStr, answers[r]);
    strcpy(answers[r], q.a0);
    strcpy(answers[0], tempStr);
    
    printf("%s\n\n", q.q);
    
    for (int i = 0; i < n_answers; i++)
        printf("%d:%s\n", i+1, answers[i]);
    
    return (r+1 + '0');
}

void clearScreen() {
    
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        putchar('\n');
    }
}



/*
char displayQuestion(question q) {
    
    srand((int)time(NULL));
    
    char answers[4][20];
    strcpy(answers[0], q.a0);
    strcpy(answers[1], q.a1);
    strcpy(answers[2], q.a2);
    strcpy(answers[3], q.a3);
    
    int r = rand() % 4;
    
    char tempStr[20];
    strcpy(tempStr, answers[r]);
    strcpy(answers[r], q.a0);
    strcpy(answers[0], tempStr);
    
    printf("%s\n\n", q.q);
    
    for (int i = 0; i < 4; i++) {
        printf("%d:%s\n", i+1, answers[i]);
    }
    
    return r+1 + '0';
}*/