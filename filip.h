//
//  filip.h
//  textQuiz
//
//  Created by Filip Doversten on 01/12/15.
//  Copyright © 2015 Filip Doversten. All rights reserved.
//

#ifndef filip_h
#define filip_h

#include "viktor.h"

#define SCREEN_HEIGHT 25

typedef int bool;
enum { false, true};

char displayQuestion(question q);
void clearScreen(void);


//  Funkar ej
void fiftyfiftyAndPrint(question q, char **answers, char *r_answer);
//  Funkar ej
char **printNewQuestion(question q, int *r_answer_pos);

#endif /* filip_h */