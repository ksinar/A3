#include "A3.h"


/*
 * Code by: Kaan Sinar
 */

int main(int argc, char **argv){
    int i, j = 0;

    int F,O,n,s,S,t,x = 0;

    int file_position, output_position = 0;

    FILE *fp1 = NULL;
    FILE *fp2 = NULL;

    int size = 0;

    char input = '\0';

    int encode_guess = 0;

    int decode_guess = 0;

    char buffer[MAX_BUFFER];

    int character_count = 0;

    int alphabet_count = 0;

    double chi_min = 0;

    /*  traverses command line arguments and looks for specific flags   */

    for(i = 0; i < argc; i++){
        for(j = 1; j < strlen(argv[i]); j++){
            if(argv[i][0] == '-'){
                if(argv[i][j] == 'F'){
                    file_position = i + 1;
                    F = 1;
                }
                if(argv[i][j] == 'O'){
                    output_position = i + 1;
                    O = 1;
                }
                if(argv[i][j] == 'n'){
                    n = 1;
                }
                if(argv[i][j] == 's'){
                    s = 1;
                }
                if(argv[i][j] == 'S'){
                    S = 1;
                }
                if(argv[i][j] == 't'){
                    t = 1;
                }
                if(argv[i][j] == 'x'){
                    x = 1;
                }
            }
        }
    }

    /*  opens file after -F flag for reading, or reads from stdin   */

    if(F == 1){
        fp1 = fopen(argv[file_position],"r");
        
        if(fp1 == NULL){
            printf("Failed to open input file\n");
            exit(1);
        }

        size = file_size(fp1);

        fgets(buffer, size + 1, fp1);
        
    }else{
        if(output_position > (argc - 1)){
            printf("Failed to open output file\n");
            exit(1);
        }
        while((fgets(buffer, MAX_BUFFER, stdin)) != NULL){

        }
        
    }

    /*  creates frequency table and adds frequency of letters to it */

    int *frequency_table = create_freq_table();

    character_count = char_count(buffer);
    alphabet_count = letter_count(buffer);

    add_letters(frequency_table, buffer);

    encode_guess = encode_shift(buffer);
    decode_guess = to_decode(encode_shift(buffer));

    /*  opens file after -O flag for writing, if -O flag is used    */

    if(O == 1){
        n = 0;
        if(output_position == 0){
            printf("Failed to open output file\n");
            exit(1);
        }
        fp2 = fopen(argv[output_position], "w");
        if(fp2 == NULL){
            printf("Failed to open output file\n");
            exit(1);
        }
    }

    if(s == 1){
        
        printf("\nDecoding shift: %i\n", decode_guess);
    }

    if(S == 1){
        printf("\nEncoding shift: %i\n\n", encode_guess);
    }    
    
    if(x == 1){
        printf("Chi-Squared Values:\n");
        for(i = 0; i < ALPHABET_LENGTH; i++){
            
            chi_min = chi_sq(i, alphabet_count, frequency_table);
            printf("%i\t%f\n", i, chi_min);
        }
        printf("\n");
    }

    if(t == 1){
              
        char letter = 'A';
        int alphabet_loop = letter;
        printf("Number of letters: %d\t Number of characters: %d\n\n", alphabet_count, character_count);
        printf("Frequency Table:\n");
        for(i = 0; i < ALPHABET_LENGTH; i++){
            printf("%c\t%d\n", alphabet_loop, frequency_table[i]);
            alphabet_loop++;
        }
        printf("\n");
    }
    
    i = 0;

    /*  does checks for flags that influence each other and acts accordingly    */

    if((O == 1) && (n == 0)){
        n = 1;
        while((buffer[i]) != '\0'){
            input = encode(buffer[i], decode_guess);
            fputc(input, fp2);
            i++;
        }
    }
    
    if((n == 0)){
            i = 0;
        printf("\n");
        while(((buffer[i]) != '\0')){
            input = encode(buffer[i], decode_guess);
            printf("%c", input);
            i++;
        }
        printf("\n");
    }
    
    /*  closes files    */

    if(F == 1){
        fclose(fp1);
    }
    if(O == 1){
        fclose(fp2);
    }

    /*  frees allocated memory  */

    free(frequency_table);

    frequency_table = NULL;

    return 0;
}