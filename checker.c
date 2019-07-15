#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int     **result;
    int     index;

    index  = 1;
    if (!(result = (int **)malloc(sizeof(int *) * argc - 1)));
		return (69);
    while (index < argc)
    {
        result[index - 1] = ft_atoi(argv[index]);
    }
    printf("%d", result);
    // ft_strsplit(**argv);
    return (0);
}