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
    
    int ra = displayQuestion(q);
    printf("Rätt svar pos:%d", ra);
    
    return 0;
}