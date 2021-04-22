# Caeser Cipher Encoder and Decoder using Chi-Squared

    Compilation: make all
    usage: ./decode (-sStx) (-F) (input file) (-O) (output file) (-n)

    flag functions: 

    s: prints shift used to decode message
    S: prints shift used to encode message
    F: write input filename after to take text from the file to decode
    O: write output filename after to put  the decoded message into it
    t: prints character and letter count summary with frequency table of letters
    x: prints Chi-Squared values per shift from 0 to 25
    n: suppresses printing to stdout, does nothing if flag O is being used

    not including flag F makes program take input from stdin
    not including flag O makes program output into stdout

    there is a max amount of characters you can read in per run (1000000)

    NOTE: when reading from stdin, to stop reading in you have to press enter and then hit ^D or hit ^D twice (EOF)
