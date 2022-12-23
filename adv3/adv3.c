//
// Created by stepan on 23.12.22.
//

#include <stdio.h>
#include "str.h"

int copyGiftsList(string *giftList, int * EOFFlag){
    char currentGift = '\0';
    int lenOfGiftList = 0;

    currentGift = (char) fgetc(stdin);

    while((currentGift != '\n') && (currentGift != EOF)){
        lenOfGiftList++;
        strAddChar(giftList, currentGift);
        currentGift = (char) fgetc(stdin);
    }
    if(currentGift == EOF){
        *EOFFlag = 1;
    }

    return 0;
}

int findAsciiOfSameCharacter(string *giftsList1, string *giftsList2, string *giftsList3, int *EOFFlag){
    char currentGift = '\0';
    int lenOfGiftList = 0;
    int indexOfList = 0;
    string firstHalfOfList;
    strInit(&firstHalfOfList);
    string secondHalfOfList;
    strInit(&secondHalfOfList);

    copyGiftsList(giftsList1, EOFFlag);
    copyGiftsList(giftsList2, EOFFlag);
    copyGiftsList(giftsList3, EOFFlag);


    for(int i = 0; i<giftsList1->length; i++){
        for (int j = 0; j < giftsList2->length; ++j) {
            for (int k = 0; k < giftsList3->length; ++k) {
                if(giftsList1->str[i] == giftsList2->str[j] && giftsList1->str[i] == giftsList3->str[k]){
                    return giftsList1->str[i];
                }
            }
        }
    }

    return 0;
}

int main(){
    string giftsList1;
    strInit(&giftsList1);
    string giftsList2;
    strInit(&giftsList2);
    string giftsList3;
    strInit(&giftsList3);
    int foundSameType;
    int sumOfPriorities = 0;
    int EOFFlag = 0;

    while((foundSameType = findAsciiOfSameCharacter(&giftsList1,&giftsList2, &giftsList3, &EOFFlag))){
        if(foundSameType >= 65 && foundSameType <= 90){
            foundSameType = foundSameType - 38;
        }
        else if(foundSameType >= 97 && foundSameType <= 122){
            foundSameType = foundSameType - 96;
        }
        strClean(&giftsList1);
        strClean(&giftsList2);
        strClean(&giftsList3);
        sumOfPriorities = sumOfPriorities+foundSameType;
        if(EOFFlag == 1){
            break;
        }
    }

    printf("sum: %d\n", sumOfPriorities);


    return 0;
}