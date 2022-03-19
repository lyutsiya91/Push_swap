# Push_swap

This program takes as an argument the stack 'a' formatted as a list of integers. 
The goal is to sort the stack with the lowest possible number of the limited set of instructions. 
These instructions are designed to manipulate the stack 'a' and the stack 'b'(which is empty at the beginning).
In case of error, it must display "Error". Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates.
To succeed I had to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

Bonus is the program 'Checker'. It takes as an argument the stack 'a' formatted as a list of integers.
It will then wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, the program has to execute them on the stack received as an argument.
If after executing those instructions, the stack 'a' is actually sorted and the stack 'b' is empty, then the program must display "OK" on the standard output.
In every other case, it must display "KO" on the standard output.
