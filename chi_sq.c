#include "A3.h"

/*
 * Code by: Kaan Sinar
 */

double chi_sq(int shift, int num_letters, int* text_freq){
    double ef[26] = EF;

    double chi = 0;

    int i = 0;

    for(i = 97; i < 123; i++){
        chi += (((num_letters * ef[offset(i)] - text_freq[offset(encode(i, shift))]) * (num_letters * ef[offset(i)] - text_freq[offset(encode(i, shift))]))/(num_letters * num_letters * ef[offset(i)]));
    }
    return chi;
}