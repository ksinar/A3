#include "A3.h"

/*
 * Code by: Kaan Sinar
 */

int to_decode(int shift){
    int decoding = 26 - shift;
    
    if(decoding == 26){
        return 0;
    }

    return decoding;
}