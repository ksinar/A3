#include "A3.h"

int char_count(char *string){
    int i = 0;
    while(string[i] != '\0'){
        i++;
    }
    return i;
}