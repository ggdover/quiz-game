//
//  filip.h
//  textQuiz
//
//  Created by Filip Doversten on 01/12/15.
//  Copyright © 2015 Filip Doversten. All rights reserved.
//

#ifndef filip_h
#define filip_h

#define SCREEN_HEIGHT 25

typedef int bool;
enum { false, true};

typedef struct
{
    char q[80];
    char a0[20];
    char a1[20];
    char a2[20];
    char a3[20];
    int d;
} question;

char displayQuestion(question q, bool ff_active);
void clearScreen();

#endif /* filip_h */
