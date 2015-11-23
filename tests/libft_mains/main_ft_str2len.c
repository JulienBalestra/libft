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
        printf("%i", (int) ft_str2len(av));
        return 0;
    }
}