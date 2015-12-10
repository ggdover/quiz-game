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

// Function: displayAnswers
// Usage: char displayAnswers(char answers[][30], char* r_answer);
//----------------------------------------
// Description: prints the answers in the order which is the given from the array passed on as a argument.
// Second argument takes a string representing the right answer. The method returns a value relative to the position of the right answer.

char displayAnswers(char answers[][30], char* r_answer);

// Function: shuffleArray
// Usage: shuffleArray(char answers[][30], char* r_answer);
//-----------------------------------------
// Description: First argument takes a array with answer options, where the method will swap the position of the right answer and a second answer in the array. The second argument tells the function what represents the right answer.

void shuffleArray(char answers[][30], char* r_answer);

// Function: fiftyFifty
// Usage: fiftyfifty(char answers[][30], char* r_answer);
//-------------------------------------------
// Description: First argument takes a array with answer options. The function will empty the string ("") on two elements. Any of these two elements can't be the element holding the right answer. The second argument gives us the right answer which we use to find the element representing the right answer.

void fiftyfifty(char answers[][30], char* r_answer);

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
