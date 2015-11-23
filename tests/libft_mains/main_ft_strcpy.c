#include "libft.h"
#include <string.h>
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
		char *ref;

		ref = (char *)malloc(sizeof(char) * (ft_strlen(av[1]) + 1));
		ref = strcpy(ref, av[1]);

		str = (char *)malloc(sizeof(char) * (ft_strlen(av[1]) + 1));
		str = ft_strcpy(str, av[1]);

		if (strcmp(ref, str) != 0)
			return 2;
		free(str);
		free(ref);
	}
	return 0;
}