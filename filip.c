//
//  filip.c
//  textQuiz
//
//  Created by Filip Doversten on 01/12/15.
//  Copyright © 2015 Filip Doversten. All rights reserved.
//

#include <stdio.h>
#include "filip.h"

int displayQuestionWithRightAnswer(question q) {
    
    clearScreen();
    
    printf("%s\n\n", q.q);
    
    printf("%s\n%s\n%s\n%s", q.a0, q.a1, q.a2, q.a3);
    
    
    
    return 0;
}

void clearScreen() {

    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        putchar('\n');
    }
}