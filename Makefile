all:
	gcc -Wall -ansi -c letter_count.c
	gcc -Wall -ansi -c create_freq_table.c
	gcc -Wall -ansi -c add_letters.c
	gcc -Wall -ansi -c chi_sq.c
	gcc -Wall -ansi -c encode_shift.c
	gcc -Wall -ansi -c encode.c
	gcc -Wall -ansi -c offset.c
	gcc -Wall -ansi -c to_decode.c
	gcc -Wall -ansi -c char_count.c
	gcc -Wall -ansi -c file_size.c

	gcc -Wall -ansi letter_count.o create_freq_table.o add_letters.o chi_sq.o encode_shift.o encode.o offset.o to_decode.o char_count.o file_size.o -o decode decode.c
	gcc -Wall -ansi letter_count.o create_freq_table.o add_letters.o chi_sq.o encode_shift.o encode.o offset.o to_decode.o char_count.o file_size.o -o copyrecords copyrecords.c


clean:
	rm *.o decode copyrecords