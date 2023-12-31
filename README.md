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

## Documentation:

### CodeCmd Class

#### Overview

The `CodeCmd` class represents a command that prints the code of the program. It inherits from the `Operation` class.

#### Public Members

- **Type getType()**: Returns the type of the operation (COMMAND).
- **void print()**: Prints the code of the program.
- **Name getName()**: Returns the name of the command (CODE_CMD).

---

### AddCmd Class

#### Overview

The `AddCmd` class represents a command that extends the existing program with the program from the given file. It inherits from the `Operation` class.

#### Public Members

- **Type getType()**: Returns the type of the operation (COMMAND).
- **void print()**: Prints the command in the format "/add <filename>".
- **Name getName()**: Returns the name of the command (ADD_CMD).
- **const std::string &getFilename() const**: Returns the filename of the program to be added.

---

### MemCmd Class

#### Overview

The `MemCmd` class represents a command that prints the values of the registers from x to y. It inherits from the `Operation` class.

#### Public Members

- **Type getType()**: Returns the type of the operation (COMMAND).
- **void print()**: Prints the command in the format "/mem x y".
- **Name getName()**: Returns the name of the command (MEM_CMD).
- **int getX() const**: Returns the starting register address.
- **int getY() const**: Returns the ending register address.
- **void changeRange(int newN)**: Updates the register addresses based on a new value.

---

### CommentCmd Class

#### Overview

The `CommentCmd` class represents a command that adds a comment to the program. It inherits from the `Operation` class.

#### Public Members

- **Type getType()**: Returns the type of the operation (COMMAND).
- **void print()**: Prints the command in the format "/comment <comment>".
- **Name getName()**: Returns the name of the command (COMMENT_CMD).
- **const std::string &getComment() const**: Returns the comment string.

---

### CopyCmd Class

#### Overview

The `CopyCmd` class represents a command that copies the contents of z continuous registers starting from x to z continuous registers starting from y. It inherits from the `Operation` class.

#### Public Members

- **Type getType()**: Returns the type of the operation (COMMAND).
- **void print()**: Prints the command in the format "/copy x y z".
- **Name getName()**: Returns the name of the command (COPY_CMD).
- **int getX() const**: Returns the starting register address.
- **int getY() const**: Returns the ending register address.
- **int getZ() const**: Returns the number of registers to copy.
- **void changeRange(int newN)**: Updates the register addresses based on a new value.

---

### QuoteCmd Class

#### Overview

The `QuoteCmd` class represents a command that adds a new operator to the program. It inherits from the `Operation` class.

#### Public Members

- **Type getType()**: Returns the type of the operation (COMMAND).
- **void print()**: Prints the command in the format "/quote" followed by the quoted operation.
- **Name getName()**: Returns the name of the command (QUOTE_CMD).
- **Operation* getOperation() const**: Returns the quoted operation.
- **~QuoteCmd()**: Destructor to delete the quoted operation.

---

### LoadCmd Class

#### Overview

The `LoadCmd` class represents a command that loads the program from the given file. It inherits from the `Operation` class.

#### Public Members

- **Type getType()**: Returns the type of the operation (COMMAND).
- **void print()**: Prints the command in the format "/load <filename>".
- **Name getName()**: Returns the name of the command (LOAD_CMD).
- **const std::string &getFilename() const**: Returns the filename of the program to be loaded.

---

### RunCmd Class

#### Overview

The `RunCmd` class represents a command that runs the program. It inherits from the `Operation` class.

#### Public Members

- **Type getType()**: Returns the type of the operation (COMMAND).
- **void print()**: Does not print anything.
- **Name getName()**: Returns the name of the command (RUN_CMD).

---

### SetCmd Class

#### Overview

The `SetCmd` class represents a command that sets the value to y of register x. It inherits from the `Operation` class.

#### Public Members

- **Type getType()**: Returns the type of the operation (COMMAND).
- **void print()**: Prints the command in the format "/set x y".
- **Name getName()**: Returns the name of the command (SET_CMD).
- **int getX() const**: Returns the register address.
- **int getY() const**: Returns the value to set.
- **void changeRange(int newN)**: Updates the register address based on a new value.

---

### ZeroCmd Class

#### Overview

The `ZeroCmd` class represents a command that sets the value to 0 of registers from x to y. It inherits from the `Operation` class.

#### Public Members

- **Type getType()**: Returns the type of the operation (COMMAND).
- **void print()**: Prints the command in the format "/zero x y".
- **Name getName()**: Returns the name of the command (ZERO_CMD).
- **int getX() const**: Returns the starting register address.
- **int getY() const**: Returns the ending register address.
- **void changeRange(int newX, int newY)**: Updates the register addresses based on new values.

---

### IncInst Class

#### Overview

The `IncInst` class represents an increment instruction that increments the current value of register n. It inherits from the `Operation` class.

#### Public Members

- **Type getType()**: Returns the type of the operation (INSTRUCTION).
- **void print()**: Prints the instruction in the format "INC n".
- **Name getName()**: Returns the name of the instruction (INC_INST).
- **int getN() const**: Returns the register address.
- **void changeRange(int newN)**: Updates the register address based on a new value.

---

### MoveInst Class

#### Overview

The `MoveInst` class represents a move instruction that sets the value of register y to the value of register x. It inherits from the `Operation` class.

#### Public Members

- **Type getType()**: Returns the type of the operation (INSTRUCTION).
- **void print()**: Prints the instruction in the format "MOVE x y".
- **Name getName()**: Returns the name of the instruction (MOVE_INST).
- **int getX() const**: Returns the source register address.
- **int getY() const**: Returns the destination register address.
- **void changeRange(int newRange)**: Updates the register addresses based on a new value.

---

### JumpInst Class

#### Overview

The `JumpInst` class represents a jump instruction that jumps to line z if x == y, otherwise does nothing. It inherits from the `Operation` class.

#### Public Members

- **Type getType()**: Returns the type of the operation (INSTRUCTION).
- **void print()**: Prints the instruction in the format "JUMP x y z" or "JUMP z" if x ==

 y.
- **Name getName()**: Returns the name of the instruction (JUMP_INST).
- **int getX() const**: Returns the first register address.
- **int getY() const**: Returns the second register address.
- **int getZ() const**: Returns the target line number.
- **void changeRange(int newRange, int newLine)**: Updates the register addresses and line number based on new values.

---

### ZeroInst Class

#### Overview

The `ZeroInst` class represents a zero instruction that sets the value of register n to 0. It inherits from the `Operation` class.

#### Public Members

- **Type getType()**: Returns the type of the operation (INSTRUCTION).
- **void print()**: Prints the instruction in the format "ZERO n".
- **Name getName()**: Returns the name of the instruction (ZERO_INST).
- **int getN() const**: Returns the register address.
- **void changeRange(int newN)**: Updates the register address based on a new value.

---

### Error Class

##### Overview

The `Error` class represents an error in the program. It inherits from the `Operation` class.

#### Public Members

- **Type getType()**: Returns the type of the operation (ERROR).
- **void print()**: Prints an error message.
- **Name getName()**: Returns the name of the error (ERROR_NAME).

---

### SparsedArray Class

#### Overview

The `SparsedArray` class represents a sparse array, implemented using an unordered map to store only non-zero values.

#### Public Members

- **SparsedArray()**: Default constructor to initialize the sparse array.
- **~SparsedArray()**: Destructor to release resources.
- **void set(int index, int value)**: Sets the value at the specified index in the sparse array.
- **int get(int index)**: Returns the value at the specified index in the sparse array.
- **void remove(int index)**: Removes the value at the specified index from the sparse array.
- **void removeAll()**: Clears all values from the sparse array.
- **void print()**: Prints the non-zero values and their corresponding indices in the sparse array.

#### Private Members

- **std::unordered_map<int, int> map**: An unordered map to store non-zero values with their corresponding indices.

#### Usage

```cpp
// Create a sparse array
SparsedArray mySparseArray;

// Set values at specific indices
mySparseArray.set(5, 10);
mySparseArray.set(10, 20);

// Get values at specific indices
int value1 = mySparseArray.get(5);  // Returns 10
int value2 = mySparseArray.get(10); // Returns 20

// Remove value at a specific index
mySparseArray.remove(5);

// Print non-zero values and their indices
mySparseArray.print();
```

#### Note

The `SparsedArray` class provides an efficient way to represent arrays with mostly zero values by only storing non-zero values in the underlying unordered map.

---

## Conclusion

This URM interpreter provides a flexible and interactive environment for executing URM programs. Users can manipulate memory, load and extend programs, and observe program code. The interpreter adheres to specific rules when extending program scope and ensures proper execution flow. The design emphasizes user-friendly dialog mode interactions, making it a versatile tool for working with URM programs in a controlled manner.
