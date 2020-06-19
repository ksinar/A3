#include "A3.h"

/*
 * Code by: Kaan Sinar
 */

char encode(char input, int shift){

    if(((input > 64) && (input < 91)) || ((input > 96) && (input < 123))){
        char alpha = islower(input) ? 'a' : 'A';
        return (input - alpha + shift) % 26 + alpha;
    }

    return input;
}