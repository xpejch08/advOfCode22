//
// Created by xpejch08 on 21.12.22.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void){

    char activeCharacter;
    char charBeforeActive;
    char numberInString[100];
    int number;
    int sumOfCalories = 0;
    int highestSumOfCalories = 0;
    int secondHighestSumOfCalories = 0;
    int thirdHighestSumOfCalories = 0;


    activeCharacter =  (char) fgetc(stdin);


    while(activeCharacter != EOF){
        while(!((activeCharacter == '\n') && (activeCharacter == charBeforeActive))){
            if(activeCharacter == '\n' || activeCharacter == EOF){
                number = atoi(numberInString);
                sumOfCalories = sumOfCalories + number;
                numberInString[0] = '\0';
                charBeforeActive = activeCharacter;
                activeCharacter = (char) fgetc(stdin);
                if(activeCharacter == EOF){
                    break;
                }
            }
            else {
                strncat(numberInString, &activeCharacter, 1);
                charBeforeActive = activeCharacter;
                activeCharacter = (char) fgetc(stdin);
            }
        }

            if(sumOfCalories > highestSumOfCalories){
                thirdHighestSumOfCalories = secondHighestSumOfCalories;
                secondHighestSumOfCalories = highestSumOfCalories;
                highestSumOfCalories = sumOfCalories;


                printf("empty line\n") ;
                sumOfCalories = 0;
                numberInString[0] = '\0';
            }
            else if(sumOfCalories > secondHighestSumOfCalories){
                thirdHighestSumOfCalories = secondHighestSumOfCalories;
                secondHighestSumOfCalories = sumOfCalories;

                printf("empty line\n") ;
                sumOfCalories = 0;
                numberInString[0] = '\0';
            }
            else if(sumOfCalories > thirdHighestSumOfCalories){
                thirdHighestSumOfCalories = sumOfCalories;

                printf("empty line\n") ;
                sumOfCalories = 0;
                numberInString[0] = '\0';
            }
        sumOfCalories = 0;
        charBeforeActive = activeCharacter;
        activeCharacter = (char) fgetc(stdin);
    }
    printf("highestSum: %d", highestSumOfCalories+secondHighestSumOfCalories+thirdHighestSumOfCalories);


    return 0;
}