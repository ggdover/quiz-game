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


//	Constants
//---------------
#define SCREEN_HEIGHT 25

/* Function prototypes */


// Function: displayQuestion
// Usage: char right_answer = displayQuestion(question);
//--------------------------------------------
// Description: prints a given question with answer options, 
// with a random position for the right answer. 
// Returns a value representing the position of the right answer.

char displayQuestion(question q);

// Function: clearScreen
// Usage: clearScreen();
//--------------------------------------
// Description: Clears the screen from content.
// Compatible with both UNIX and Win platforms.

void clearScreen(void);

#endif /* filip_h */
