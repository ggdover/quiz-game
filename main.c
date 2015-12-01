//
//  main.c
//  textQuiz
//
//  Created by Filip Doversten on 30/11/15.
//  Copyright © 2015 Filip Doversten. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "filip.h"

int main(int argc, const char * argv[]) {
    
    question quest;
    strcpy(quest.q ,"Vem kan mest?");
    strcpy(quest.a0 ,"Jag");
    strcpy(quest.a1 ,"Han");
    strcpy(quest.a2 ,"Bertil");
    strcpy(quest.a3 ,"Gertrud");
    
    int ra = displayQuestionWithRightAnswer(quest);
    
    printf("Position of right answer: %d", ra);
    
    while(1);
    
    return 0;
    
}
