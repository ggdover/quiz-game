//
//  main.c
//  textQuiz
//
//  Created by Filip Doversten on 06/12/15.
//  Copyright © 2015 Filip Doversten. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "filip.h"

int main(){
    
    question q;
    strcpy(q.q ,"Vem är du?");
    strcpy(q.a0, "Bobbel");
    strcpy(q.a1, "Jonas");
    strcpy(q.a2, "Karl");
    strcpy(q.a3, "Erik");
    
    char ra1 = displayQuestion(q, false);
    printf("Rätt svar pos:%c\n\n", ra1);
    
    char ra2 = displayQuestion(q, true);
    printf("Rätt svar pos:%c\n\n", ra2);
    
    return 0;
}
