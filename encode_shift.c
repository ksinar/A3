#include "A3.h"

/*
 * Code by: Kaan Sinar
 */

int encode_shift(char *string){

    int num_letters = letter_count(string);

    double smallest_chi = 10000000;

    double chi = 0;

    int *freq_table = create_freq_table();

    add_letters(freq_table, string);

    int try, shift = 0;

    for(try = 0; try < 26; try++){
        chi = chi_sq(try, num_letters, freq_table);

        if(chi < smallest_chi){
            smallest_chi = chi;
            shift = try;
        }
        
    }

    if(smallest_chi >= 0.5){
        return 0;
    }

    /*free(freq_table);*/

    return shift;
}