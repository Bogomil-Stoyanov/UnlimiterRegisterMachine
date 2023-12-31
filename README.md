# Unlimited Register Machine (URM) in C++

## Introduction

The project involves the development of a program for an Unlimited Register Machine (URM). The URM program consists of two primary components: instructions and commands. Instructions are numbered consecutively, and commands, designated with "/", lack sequence numbers. The interpreter operates in dialog mode, accepting commands from standard input and maintaining a loaded program in memory.

## Supported Commands

1. **/zero x y**: Sets memory cells with addresses from x to y inclusive to zero.
2. **/set x y**: Modifies the contents of the cell at address x to y.
3. **/copy x y z**: Copies the contents of z consecutive cells, starting from address x, to corresponding z consecutive cells starting from address y.
4. **/mem x y**: Outputs the contents of cells with addresses from x to y inclusive to standard output.
5. **/load <filename>**: Loads a URM program from a text file, replacing the current program in memory. Execution terminates if the command is part of a running program.
6. **/run**: Executes the loaded program, following the sequence of instructions and commands. Execution terminates when attempting to move beyond the loaded set of operators.
7. **/add <filename>**: Extends the loaded URM program with statements from a text file. The program's scope is updated according to specific rules.
8. **/quote <string>**: Adds a new statement (instruction or command) at the end of the loaded program. Returns an error if the string is not a valid operator.
9. **/code**: Outputs the loaded program to standard output.
10. **/comment <string>**: No operational effect; serves to add comments.

## Conclusion

This URM interpreter provides a flexible and interactive environment for executing URM programs. Users can manipulate memory, load and extend programs, and observe program code. The interpreter adheres to specific rules when extending program scope and ensures proper execution flow. The design emphasizes user-friendly dialog mode interactions, making it a versatile tool for working with URM programs in a controlled manner.
