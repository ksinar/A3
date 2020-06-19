#include "A3.h"

/*
 * Code by: Kaan Sinar
 */

int offset(char letter){
    char lowercase_array[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char uppercase_array[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int i = 0;
    for(i = 0; i < ALPHABET_LENGTH; i++){
        if((letter == lowercase_array[i]) || (letter == uppercase_array[i])){
            return i;
        }
    }

    return 0;
}