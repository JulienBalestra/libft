#include <stdio.h>
#include <stdlib.h>
#include "libft.h"


int	main(int ac, char **av)
{
	if (ac != 4)
		return 1;
	else
	{
		char	**split;
		int		nb_string = ft_atoi(av[3]);
		int		i;
				
		split = ft_lz_strsplit(av[1], av[2][0]);
		i = 0;
		while (split[i])
		{
			printf("%s", split[i]);
			if (i < nb_string - 1)
				printf(":");
            free(split[i]);
			i++;
		}
		free(split);
	}
	return 0;
}
