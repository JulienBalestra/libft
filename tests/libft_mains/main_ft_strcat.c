#include <string.h>
#include "libft.h"
#include <stdlib.h>


int     main(int ac, char **av)
{
    if (ac != 3)
        return 1;
    else
    {
        char *str;
        char *ref;

		ref = (char *)malloc(sizeof(char) * (ft_strlen(av[1]) + ft_strlen(av[2]) + 1));
		ref = strcpy(ref, av[1]);
		ref = strcat(ref, av[2]);

        str = (char *)malloc(sizeof(char) * (ft_strlen(av[1]) + ft_strlen(av[2]) + 1));
        str = ft_strcpy(str, av[1]);
        str = ft_strcat(str, av[2]);


        if (strcmp(ref, str) != 0)
            return 2;
        free(str);
        free(ref);
    }
    return 0;
}