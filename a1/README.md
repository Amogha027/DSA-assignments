I have compiled the files as below:

To compile all 3 programs: make all
then to output q1: ./q1.out
then to output q2: ./q2.out
then to output q3: ./q3.out

To compile q1 alone: make q1
then to produce output: ./q1.out

After compiling the code:
Insert <num> at the end              : insert <num>
Insert <num> at position <pos>       : insert_at <num> <pos>
Delete at position <pos>             : delete <pos>
Position of first occurence of <num> : find <num>
Delete all odd indexes               : prune
Print from index 0                   : print
Print in reverse order               : print_reverse
Print current size of linked list    : get_size
TO QUIT                              : quit

To compile q2 alone: make q2
then to produce output: ./q2.out

After compiling the code:
add:    ADD <N>
        N floating point numbers
        N floating point numbers
sub:    ADD <N>
        N floating point numbers
        N floating point numbers
mod:    ADD <N>
        N floating point numbers
dot:    ADD <N>
        N floating point numbers
        N floating point numbers
cos:    ADD <N>
        N floating point numbers
        N floating point numbers

To compile q3 alone: make q3
then to produce output: ./q3.out

After compiling the code:
To add user   :   ADD_USER <u>
To add song   :   ADD_SONG <u> <s>
To insert song:   INSERT_SONG <u> <s>
To remove song:   REMOVE_SONG <u> <num>
To play song  :   PLAY_SONG <u>
To get song   :   GET_SONG <u>
To like song  :   LIKE_SONG <u> <s>
To unlike song:   UNLIKE_SONG <u> <s>
Compatibility :   COMPATIBILITY <u1> <u2>
To quit       :   EXIT
(<u>: user name, <s>: song name, <num>: index)