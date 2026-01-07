*This project has been created as part of the 42 curriculum by cmacaroc.*

## PUSH SWAP

## Description

**push_swap** is a sorting algorithm project that challenges students to sort a stack of integers using the minimum number of operations. The program must sort data on stack A using only a limited set of operations, with the help of an auxiliary stack B.

The goal is to implement an efficient sorting algorithm that:
- Handles any size of input (from 2 to 500+ integers)
- Minimizes the number of operations required
- Uses only the allowed stack operations
- Produces a sorted stack in ascending order

This project teaches algorithm complexity, optimization techniques, and data structure manipulation.

## Instructions

### Compilation

Compile the project using the provided Makefile:

```bash
make
```

This will generate the `push_swap` executable.

To clean object files:
```bash
make clean
```

To remove all generated files:
```bash
make fclean
```

To recompile everything:
```bash
make re
```

### Usage

Run the program with a list of integers as arguments:

```bash
./push_swap 4 67 3 87 23
```

Or with quoted string input:
```bash
./push_swap "4 67 3 87 23"
```

The program outputs the list of operations needed to sort the stack.

### Testing with checker

To verify that the operations correctly sort the stack, use the checker program (provided by 42):

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

Output:
- `OK` if the stack is correctly sorted
- `KO` if the stack is not sorted or operations are invalid
- `Error` if invalid input is provided

### Input Requirements

- Only integers are accepted
- Integers must be within the range of `int` type (INT_MIN to INT_MAX)
- No duplicates are allowed
- Input can be provided as separate arguments or as a single quoted string

### Error Handling

The program displays `Error` on standard error and exits if:
- Non-numeric arguments are provided
- Integers overflow/underflow
- Duplicate values are detected
- Invalid input format

## Available Operations

The program uses the following operations to sort the stack:

| Operation | Description |
|-----------|-------------|
| `sa`      | Swap the first two elements of stack A |
| `sb`      | Swap the first two elements of stack B |
| `ss`      | Perform `sa` and `sb` simultaneously |
| `pa`      | Push the top element from stack B to stack A |
| `pb`      | Push the top element from stack A to stack B |
| `ra`      | Rotate stack A up (first element becomes last) |
| `rb`      | Rotate stack B up |
| `rr`      | Perform `ra` and `rb` simultaneously |
| `rra`     | Reverse rotate stack A (last element becomes first) |
| `rrb`     | Reverse rotate stack B |
| `rrr`     | Perform `rra` and `rrb` simultaneously |

## Algorithm Implementation

### Sorting Strategy

The program implements different sorting strategies based on input size:

1. **2 numbers**: Simple swap if needed (`sa`)
2. **3 numbers**: Optimized sorting with maximum 2 operations
3. **4-5 numbers**: Move smallest elements to stack B, sort remaining 3, push back
4. **6+ numbers**: Radix sort using binary representation of indexed values

### Radix Sort Approach

For larger inputs, the program uses a radix sort algorithm:

1. **Index Assignment**: Each number is assigned an index based on its position in the sorted array (smallest = 0, largest = n-1)
2. **Bit-by-bit Sorting**: Numbers are sorted by examining each bit position from least significant to most significant
3. **Binary Partitioning**: For each bit position, numbers with 0 are pushed to stack B, numbers with 1 stay in stack A
4. **Reconstruction**: All elements from stack B are pushed back to stack A after each bit pass

This approach ensures O(n log n) complexity and produces efficient operation counts:
- 100 numbers: ~1100 operations
- 500 numbers: ~6000 operations

## Project Structure

```
push_swap/
├── push_swap.h           # Header file with structure definitions and function prototypes
├── commands/
│   ├── command_push.c           # Push operations (pa, pb)
│   ├── command_swap.c           # Swap operations (sa, sb, ss)
│   ├── command_rotate.c         # Rotate operations (ra, rb, rr)
│   └── command_reverse_rotate.c # Reverse rotate operations (rra, rrb, rrr)
├── helper_functions/
│   ├── list_functions.c         # Linked list manipulation functions
│   ├── error_handling.c         # Error handling
│   ├── helper_functions.c       # Utility functions (ft_atol, ft_putstr)
│   └── helper_functions_split.c # Split functions	
├── sorting/
│   ├── build_stack.c            # Build stacks A and B
│   ├── sort_small.c             # Algorithms for 2, 3, and 5 elements
│   └── index_array.c            # Assign index to array
└── push_swap.c                  # Radix sort and program entry point
```

## Performance Benchmarks

Operation counts:

| Input Size | Maximum Operations |
|------------|--------------------|
| 3 numbers  | 3                  |
| 5 numbers  | 12                 |
| 100 numbers| 1100               |
| 500 numbers| 8500               |

## Testing

### Basic Tests

```bash
# Test with 3 numbers
./push_swap 2 1 3 | ./checker_linux 2 1 3

# Test with 5 numbers
./push_swap 5 4 3 2 1 | ./checker_linux 5 4 3 2 1

# Test with random 100 numbers
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); 
./push_swap $ARG
./checker_linux $ARG

# Count operations for 100 numbers
./push_swap $(shuf -i 1-100 -n 100) | wc -l
```

### Error Tests

```bash
# Test with duplicates (should show Error)
./push_swap 1 2 3 2

# Test with non-numeric input (should show Error)
./push_swap 1 2 abc

# Test with overflow (should show Error)
./push_swap 1 2 2147483648
```

## Resources

### Documentation
- [Sorting Algorithms - GeeksforGeeks](https://www.geeksforgeeks.org/sorting-algorithms/)
- [Radix Sort Explained](https://www.geeksforgeeks.org/dsa/radix-sort/)
- [Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/)

### Tutorials & Articles
- [Push_swap Tutorial - Medium](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
- [Understanding Radix Sort for Push_swap](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

### Tutorials & Articles
AI was used to understand concepts and explore the different algorithms, their limitations and benefits.

## Author

**cmacaroc** - 42 Student

---