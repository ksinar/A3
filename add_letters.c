#include "A3.h"

/*
 * Code by: Kaan Sinar
 */

void add_letters(int *freq_table, char *string){
    int i = 0;

    /* compares letters and increments frequency array */

    int check = 0;

    while(string[i] != '\0'){
        check = string[i];
        if((check > 96) && (check < 123)){
            freq_table[check - 97]++;
        }else if((check > 64) && (check < 91)){
            freq_table[check - 65]++;
        }
        i++;
    }

}