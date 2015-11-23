#include "libft.h"
#include <stdlib.h>

void	ft_str2del(char **array)
{
	int i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}