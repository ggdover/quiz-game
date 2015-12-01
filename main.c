//
//  main.c
//  textQuiz
//
//  Created by Filip Doversten on 30/11/15.
//  Copyright © 2015 Filip Doversten. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filip.h"

int main(int argc, const char * argv[]) {
    
    question quest;
    strcpy(quest.q ,"Vem kan mest?");
    strcpy(quest.a0 ,"Hej");
    strcpy(quest.a1 ,"Yngve");
    strcpy(quest.a2 ,"Sofia");
    strcpy(quest.a3 ,"Gustav");
    
    int ra = displayQuestionWithRightAnswer(quest);
    
    printf("Position of right answer: %d", ra);
    
    getchar();
    
    return 0;
    
}
