I have compiled the files as below:

To compile all 3 programs: 
```
make all
```
then to output q1: 
```
./q1.out
```
then to output q2: 
```
./q2.out
```
then to output q3: 
```
./q3.out
```

To compile q1 alone: 
```
make q1
```
then to produce output: 
```
./q1.out
```

After compiling the code: <br>
Insert `<num>` at the end              : insert `<num>` <br>
Insert `<num>` at position `<pos>`     : insert_at `<num>` `<pos>` <br>
Delete at position `<pos>`             : delete `<pos>` <br>
Position of first occurence of `<num>` : find `<num>` <br>
Delete all odd indexes                 : prune <br>
Print from index 0                     : print <br>
Print in reverse order                 : print_reverse <br>
Print current size of linked list      : get_size <br>
TO QUIT                                : quit <br>

To compile q2 alone: 
```
make q2
```
then to produce output: 
```
./q2.out
```

After compiling the code: <br>
- add:    ADD `<N>` <br>
&nbsp;&nbsp;&nbsp;&nbsp;N floating point numbers <br>
&nbsp;&nbsp;&nbsp;&nbsp;N floating point numbers <br>
- sub:    ADD `<N>` <br>
&nbsp;&nbsp;&nbsp;&nbsp;N floating point numbers <br>
&nbsp;&nbsp;&nbsp;&nbsp;N floating point numbers <br>
- mod:    ADD `<N>` <br>
&nbsp;&nbsp;&nbsp;&nbsp;N floating point numbers <br>
- dot:    ADD `<N>` <br>
&nbsp;&nbsp;&nbsp;&nbsp;N floating point numbers <br>
&nbsp;&nbsp;&nbsp;&nbsp;N floating point numbers <br>
- cos:    ADD `<N>` <br>
&nbsp;&nbsp;&nbsp;&nbsp;N floating point numbers <br>
&nbsp;&nbsp;&nbsp;&nbsp;N floating point numbers <br>

To compile q3 alone: 
```
make q3
```
then to produce output: 
```
./q3.out
```

After compiling the code: <br>
- To add user   :   
```
ADD_USER <u>
```
- To add song   :   
```
ADD_SONG <u> <ss>
```
- To insert song:   
```
INSERT_SONG <u> <ss>
```
- To remove song:   
```
REMOVE_SONG <u> <num>
```
- To play song  :   
```
PLAY_SONG <u>
```
- To get song   :   
```
GET_SONG <u>
```
- To like song  :   
```
LIKE_SONG <u> <ss>
```
- To unlike song:   
```
UNLIKE_SONG <u> <ss>
```
- Compatibility :   
```
COMPATIBILITY <u1> <u2>
```
- To quit       :   
```
EXIT
```
(`<u>`: user name, &nbsp;&nbsp;`<ss>`: song name, &nbsp;&nbsp;`<num>`: index)