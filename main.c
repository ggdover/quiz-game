#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "filip.h"

int main() {
    
    question q;
    strcpy(q.q, "Vad heter han?");
    strcpy(q.a0, "Blobb");
    strcpy(q.a1, "Bob");
    strcpy(q.a2, "John");
    strcpy(q.a3, "Mikael");
    
    fifityfifty ff;
    ff.active = false;
    ff.rem_answer = 1;
    
    int ra = displayQuestionWithRightAnswer(q, ff);
    
    printf("Rättsvar: %d", ra);
    
    //gameStart();
    return 0;
}