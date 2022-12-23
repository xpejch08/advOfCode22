//
// Created by xpejch08 on 21.12.22.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Z = win, y == draw X == loose

int main(void){

    char activeCharacter = '\0';
    int sum = 0;

    while(activeCharacter != EOF) {
        activeCharacter =  (char) fgetc(stdin);
        //rock
        if(activeCharacter == 'A'){
            activeCharacter =  (char) fgetc(stdin);
            activeCharacter =  (char) fgetc(stdin);
            if(activeCharacter == 'X'){
                //loose
                sum = sum + 3;
                activeCharacter =  (char) fgetc(stdin);
            }
            else if(activeCharacter == 'Y'){
                //draw
                sum = sum + 4;
                activeCharacter =  (char) fgetc(stdin);

            }
            else if(activeCharacter == 'Z'){
                //win
                sum = sum + 8;
                activeCharacter =  (char) fgetc(stdin);
            }
        }
        //opoponent paper
        if(activeCharacter == 'B'){
            activeCharacter =  (char) fgetc(stdin);
            activeCharacter =  (char) fgetc(stdin);
            if(activeCharacter == 'X'){
                //loose
                sum = sum + 1;
                activeCharacter =  (char) fgetc(stdin);
            }
            else if(activeCharacter == 'Y'){
                //draw
                sum = sum + 5;
                activeCharacter =  (char) fgetc(stdin);
            }
            else if(activeCharacter == 'Z'){
                //win
                sum = sum + 9;
                activeCharacter =  (char) fgetc(stdin);
            }
        }
        //scissors
        if(activeCharacter == 'C'){
            activeCharacter =  (char) fgetc(stdin);
            activeCharacter =  (char) fgetc(stdin);
            if(activeCharacter == 'X'){
                //loose
                sum = sum + 2;
                activeCharacter =  (char) fgetc(stdin);
            }
            else if(activeCharacter == 'Y'){
                //draw
                sum = sum + 6;
                activeCharacter =  (char) fgetc(stdin);
            }
            else if(activeCharacter == 'Z'){
                //win
                sum = sum + 7;
                activeCharacter =  (char) fgetc(stdin);
            }
        }
    }

    printf("sum: %d", sum);


    return 0;
}