#include "libft.h"

int	main(int ac, char **av)
{
	int i;
	int n;

	if (ac == 1)
		return 1;
	else
	{
		i = 1;
		while (i < ac)
		{
		    n = 0;
			while (av[i][n] != '\0')
			{
				ft_putchar(av[i][n]);
				n++;
			}
			i++;
		}
	}
	return 0;
}