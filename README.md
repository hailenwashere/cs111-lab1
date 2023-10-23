## UID: 123456789

## Pipe Up

This program uses processes to pipe a program's output into another program's input.

## Building

To build this program, make sure you are in the same directory as these files. Then run the following command :
```
make
```

## Running

To run the program, the program is called with the following format:
```
./pipe program1 program2 program3...
```

When running the program, its should get the same output as if you were running the progams with the | pipe operator.
```
./pipe ls cat wc
```

The above program returned 
```
6 6 51
```
which is the same as running ls | cat | wc.
## Cleaning up

To clean up this program's binary files, make sure you are in the same directory as these files. Then run the following command :
```
make clean
```