#include "A3.h"

/*
 * Code by: Kaan Sinar
 */

int letter_count(char *string){
    int count = 0;
    int i = 0;
    while(string[i] != '\0'){
        if(((string[i] > 64) && (string[i] < 91)) || ((string[i] > 96) && (string[i] < 123))){
            count++;
        }
        i++;
    }
    return count;
}