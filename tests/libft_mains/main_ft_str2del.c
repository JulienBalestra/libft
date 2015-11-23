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
        char **duplicate;

        duplicate = ft_str2dup(av);
        ft_str2del(duplicate);

        return 0;
    }
}