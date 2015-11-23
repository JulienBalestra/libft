#include "libft.h"

#include <stdio.h>
#include <stdlib.h>


int	main(int ac, char **av)
{
	if (ac != 3)
	{
		return 1;
	}
	else
	{
		char *str;
		
		str = ft_strndup(av[1], ft_atoi(av[2]));
		printf("%s", str);
		free(str);
	}
	return 0;
}