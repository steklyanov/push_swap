## PUSH SWAP

The Push_swap project is a very simple and highly e ective algorithm project: data will need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.
Your goal ? Write 2 programs in C:
*   The first, named checker which takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.
*   The second one called push_swap which calculates and displays on the standard output the smallest progam using Push_swap instruction language that sorts inte- ger arguments received.

Yoy can also check [full description][1]

push_swap programm return all necessary commands to sort stack

checker programm apply this commands to stack and check sorting

### Usage:

    git clone https://github.com/steklyanov/push_swap.git
    make
    ./test -full 1 100 5
    ARG="{stack values}"; ./push_swap $ARG | ./checker $ARG

[1]: https://github.com/steklyanov/push_swap/blob/master/push_swap.en.pdf