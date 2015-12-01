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

int displayQuestionWithRightAnswer(question q) {
    
    srand((int)time(NULL));
    
    char answers[4][20];
    strcpy(answers[0], q.a0);
    strcpy(answers[1], q.a1);
    strcpy(answers[2], q.a2);
    strcpy(answers[3], q.a3);
    
    int r = rand() % 4;
    
    char foo[20];
    strcpy(foo, answers[r]);
    strcpy(answers[r], q.a0);
    strcpy(answers[0], foo);
    
    printf("%s\n\n", q.q);
    
    for (int i = 0; i < 4; i++)
      printf("%d:%s\n", i+1, answers[i]);

//  retunerar: 0-3
    return r;
    
//  returnerar: 1-4
//  return r+1;
}

void clearScreen() {
    
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        putchar('\n');
    }
}

//int displayQuestionWithRightAnswer(question q) {
//    
//    srand((int)time(NULL));
//    
//    clearScreen();
//    
//    printf("%s\n\n", q.q);
//    
//    int positions[4];
//    
//    for (int i = 0; i < 4; i++) {
//        bool getNewPos;
//        int randPos;
//        
//        do {
//            getNewPos = false;
//            randPos = (rand() % 4)+1;
//            
//            for (int k = 0; k < 4; k++)
//                if (positions[k] == randPos)
//                    getNewPos = true;
//            
//        } while (getNewPos);
//        
//        positions[i] = randPos;
//    }
//    
//    char unsorted[4][20];
//    strcpy(unsorted[0], q.a0);
//    strcpy(unsorted[1], q.a1);
//    strcpy(unsorted[2], q.a2);
//    strcpy(unsorted[3], q.a3);
//    
//    char sorted[4][20];
//    
//    for (int i = 0; i < 4; i++)
//        strcpy(sorted[i],unsorted[(positions[i])-1]);
//    
//    for (int i = 0; i < 4; i++) {
//        printf("%d:%s\n", i+1, sorted[i]);
//        if (strcmp(sorted[i], q.a0) == 0)
//            return i;
//    }
//    
//    return 5;
//}