#include "A3.h"

/*
 * Code by: Kaan Sinar
 */

int *create_freq_table(){

    int *freq_table = malloc(sizeof(int) * ALPHABET_LENGTH);

    int i = 0;

    for(i = 0; i < ALPHABET_LENGTH; i++){
        freq_table[i] = 0;
    }

    return freq_table;

}