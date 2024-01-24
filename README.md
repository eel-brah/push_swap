# Push_Swap

Given a set of integers, sort it using a predefined set of instructions using
two stacks. The instruction set is defined below. This program outputs a program
in push_swap instructions that sorts the input integers.

## Instruction
For the following instructions, if the instruction is not possible, the part of
it that can't be executed won't.

| Code  | Instruction                         
| ----- | ------------------------------------
| `sa`  | swap a                              | 
| `sb`  | swap b                              | 
| `ss`  | swap a + swap b                     |    
| `pa`  | push a                              | 
| `pb`  | push b                              | 
| `ra`  | rotate a                            |
| `rb`  | rotate b                            | 
| `rr`  | rotate a + rotate b                 | 
| `rra` | reverse rotate a                    | 
| `rrb` | reverse rotate b                    | 
| `rrr` | reverse rotate a + reverse rotate b |

### Bonus

The bonus part is to write a program named checker, which will get as an argument the stack A formatted as a list of integers. 
Checker will then wait and read instructions on the standard input. Once all the instructions have been read, checker will execute them on the stack received as an argument (After giving the instructions press ctrl + d).

If after executing those instructions, stack a is actually sorted and b is empty, then
checker must display "OK" else "KO". If checker arguments are invalid it displays Error.
