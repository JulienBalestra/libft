#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int     main(int ac, char **av)
{
    if (ac == 1)
        return 1;
    else
    {
        char **dup;
        int i;

        dup = ft_str2dup(&av[1]);
        i = 0;
        while (i < ac - 1)
        {
            printf("%s", dup[i]);
            free(dup[i]);
            i++;
        }
        free(dup);

        return 0;
    }
}