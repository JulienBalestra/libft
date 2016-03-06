#include <stdlib.h>
#include <libft.h>

static int	ft_count_string(char *str, char c, char esc)
{
	int i;
	int n;
	int e;

	i = 0;
	n = 0;
	e = 0;
	while (str[i])
	{
		if (str[i] == esc)
			e ? ((e = 0)) : ((e = 1));
		else if (e == 0 && str[i] == c && str[i - 1] != c)
			n++;
		i++;
	}
	return (++n);
}

static char *move_into_substring(char *str, char c, int match, char esc)
{
	int e;

	e = 0;
	if (match)
	{
		while (*str == c)
			str++;
	}
	else
	{
		while (*str && (*str != c || (*str == c && e == 1)))
		{
			if (*str == esc)
				e ? ((e = 0)) : ((e = 1));
			str++;
		}
	}
	return (str);
}

static size_t get_next_sep(char *str, char c, char esc)
{
	size_t i;
	int e;

	i = 0;
	e = 0;
	while (str[i] && (str[i] != c || (str[i] == c && e == 1)))
	{
		if (str[i] == esc)
			e ? ((e = 0)) : ((e = 1));
		i++;
	}
	return (i);
}

char **ft_esc_strsplit(char *str, char c, char esc)
{
	char **split;
	int nb_str;
	int i;
	size_t range;

	nb_str = ft_count_string(str, c, esc);
	i = 0;
	if ((split = (char **)malloc(sizeof(char *) * (nb_str + 1))))
	{	
		while (i < nb_str)
		{
			if (i != 0)
				str = move_into_substring(str, c, 1, esc);
			range = get_next_sep(str, c, esc);
			split[i] = ft_strndup(str, range);
			str = move_into_substring(str, c, 0, esc);
			i++;
		}
		split[nb_str] = NULL;
	}
	return (split);	
}