#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int     main(int ac, char **av)
{
	if (ac < 3)
		return 1;
	else
	{
		char **dup;
		int i;

		dup = ft_str2dup(&av[0]);
		i = 0;
		free(dup[0]);
		dup[0] = NULL;
		ft_str2defrag(dup, ac);
		while (i < ac - 1)
		{
			printf("%s", dup[i]);
			i++;
		}
		ft_str2del(dup);


		return 0;
	}
}