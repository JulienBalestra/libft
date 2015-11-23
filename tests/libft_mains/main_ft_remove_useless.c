#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int i;
	char *new_str;

	i = 1;
	new_str = NULL;
	if (ac == 1)
	{
		return 1;
	}	
	else
	{
		while (i < ac)
		{
			new_str = ft_remove_useless(av[i], ' ');
			printf("%s", new_str);
			i++;
			free(new_str);
		}
	}
	return 0;
}
