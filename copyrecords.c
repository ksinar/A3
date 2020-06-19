#include "A3.h"

int main(int argc, char **argv){
    int F,O,D,r = 0;

    int i,j = 0;

    int file_position, output_position, decode_position = 0;

    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    FILE *fp3 = NULL;

    int encode_guess = 0;

    int decode_guess = 0;

    char buffer[MAX_BUFFER];

    int character_count = 0;

    int size = 0;

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
                if(argv[i][j] == 'D'){
                    D = 1;
                    decode_position = i + 1;
                }
                if(argv[i][j] == 'r'){
                    r = 1;
                }
            }
        }
    }

    /*  opens file after -F flag for reading    */

    if(F == 1){
        fp1 = fopen(argv[file_position],"rb");
        
        if(fp1 == NULL){
            printf("Failed to open input file\n");
            exit(1);
        }


        
    }else{
        printf("Input file in binary needed\n");
        exit(1);
        
    }


    /*  opens file after -O flag for writing, if -O flag is used    */

    if(O == 1){
        if(output_position == 0){
            printf("Failed to open output file\n");
            exit(1);
        }
        fp2 = fopen(argv[output_position], "wb");
        if(fp2 == NULL){
            printf("Failed to open output file\n");
            exit(1);
        }
    }

    if(D == 1){
        fp3 = fopen(argv[decode_position],"r");
        
        if(fp3 == NULL){
            printf("Failed to open decoding file\n");
            exit(1);
        }

        size = file_size(fp3);

        fgets(buffer, size + 1, fp3);
        
    }

    if(r == 1){

    }

    /*  creates frequency table and adds frequency of letters to it */

    int *frequency_table = create_freq_table();

    character_count = char_count(buffer);

    add_letters(frequency_table, buffer);

    encode_guess = encode_shift(buffer);
    decode_guess = to_decode(encode_shift(buffer));

    printf("char count: %d\t encoded by: %d\t decode with: %d\n", character_count, encode_guess, decode_guess);

    

    return 0;
}