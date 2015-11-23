#include "libft.h"

size_t	ft_str2len(char **array)
{
	int i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			i++;
		}
	}
	return (i);
}