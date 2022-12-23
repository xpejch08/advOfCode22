//
// Created by stepan on 23.12.22.
//

#include <stdio.h>
#include "str.h"

int findAsciiOfSameCharacter(string *giftsList, int *EOFFlag){
    char currentGift = '\0';
    int lenOfGiftList = 0;
    int indexOfList = 0;
    string firstHalfOfList;
    strInit(&firstHalfOfList);
    string secondHalfOfList;
    strInit(&secondHalfOfList);

    currentGift = (char) fgetc(stdin);

    while((currentGift != '\n') && (currentGift != EOF)){
        lenOfGiftList++;
        strAddChar(giftsList, currentGift);
        currentGift = (char) fgetc(stdin);
    }
    if(currentGift == EOF){
        *EOFFlag = 1;
    }

    for(indexOfList; indexOfList < (lenOfGiftList/2); indexOfList++){
        strAddChar(&firstHalfOfList, giftsList->str[indexOfList]);
    }
    for(indexOfList; indexOfList < (lenOfGiftList); indexOfList++){
        strAddChar(&secondHalfOfList, giftsList->str[indexOfList]);
    }

    printf("%s\n", firstHalfOfList.str);
    printf("%s\n", secondHalfOfList.str);

    for(int j = 0; j < (lenOfGiftList/2); j++){
        for(int k = 0; k < (lenOfGiftList/2); k++) {
            if(firstHalfOfList.str[j] == secondHalfOfList.str[k]){
                return firstHalfOfList.str[j];
            }
        }
    }

    return 0;
}

int main(){
    string giftsList;
    strInit(&giftsList);
    int foundSameType;
    int sumOfPriorities = 0;
    int EOFFlag = 0;

    while((foundSameType = findAsciiOfSameCharacter(&giftsList, &EOFFlag))){
        if(foundSameType >= 65 && foundSameType <= 90){
            foundSameType = foundSameType - 38;
        }
        else if(foundSameType >= 97 && foundSameType <= 122){
            foundSameType = foundSameType - 96;
        }
        strClean(&giftsList);
        sumOfPriorities = sumOfPriorities+foundSameType;
        if(EOFFlag == 1){
            break;
        }
    }

    printf("sum: %d\n", sumOfPriorities);


    return 0;
}