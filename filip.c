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

int displayQuestionWithRightAnswer(question q, fifityfifty ff) {
    
    srand((int)time(NULL));
    
    char **answers;
    int n_answers;
    
    if (ff.active)
        n_answers = 2;
    else
        n_answers = 4;
    
    answers = malloc(n_answers * sizeof(char*));
    for (int i = 0; i < n_answers; i++)
        answers[i] = malloc(20 * sizeof(char));
    
    strcpy(answers[0], q.a0);
    
    if (ff.active) {
        
        if ((sizeof(answers)/sizeof(answers[0])) != 2)
            //Throw error
        
        switch (ff.rem_answer) {
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
                //Should never end up here
                break;
        }
    } else {
        
        if ((sizeof(answers)/sizeof(answers[0])) != 4)
            //Throw error
        
        strcpy(answers[1], q.a1);
        strcpy(answers[2], q.a2);
        strcpy(answers[3], q.a3);
    }
    
    int r = rand() % n_answers;
    
    char tempStr[20];
    strcpy(tempStr, answers[r]);
    strcpy(answers[r], q.a0);
    strcpy(answers[0], tempStr);
    
    printf("%s\n\n", q.q);
    
    for (int i = 0; i < n_answers; i++)
        printf("%d:%s\n", i+1, answers[i]);
    
    //  returnerar: 1-4 eller 1-2
    return r+1;
}


//int displayQuestionWithRightAnswer(question q, fifityfifty ff) {
//    
//    srand((int)time(NULL));
//    
//    char tempArr[4][20];
//    char answers[4][20];
//    
//    strcpy(tempArr[0], q.a0);
//    strcpy(tempArr[1], q.a1);
//    strcpy(tempArr[2], q.a2);
//    strcpy(tempArr[3], q.a3);
//    
//    if (ff.active) {
//        
//        
//    } else {
//        for (int i = 0; i < 4; i++) {
//            strcpy(answers[i], tempArr[i]);
//        }
//    }
//    
//    
//    
//    int r = rand() % 4;
//    
//    char tempStr[20];
//    strcpy(tempStr, answers[r]);
//    strcpy(answers[r], q.a0);
//    strcpy(answers[0], tempStr);
//    
//    printf("%s\n\n", q.q);
//    
//    for (int i = 0; i < sizeof(answers[0])/sizeof(char[20]); i++)
//      printf("%d:%s\n", i+1, answers[i]);
//
////  returnerar: 1-4
//    return r+1;
//}

void clearScreen() {
    
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        putchar('\n');
    }
}
