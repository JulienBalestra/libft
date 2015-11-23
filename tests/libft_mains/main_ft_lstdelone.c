#include <stdlib.h>
#include <stdio.h>
#include "libft.h"


static void ft_memdel_range(void *mem, size_t mem_size)
{
    if (mem)
    {
        free(mem);
        mem = NULL;
    }
    (void)mem_size;
}


int     main(int ac, char **av)
{
    if (ac != 3)
        return 1;
    else
    {
            t_list  *mylist;
            t_list  *new_link;
            t_list  *last;

            mylist = ft_lstnew(av[1], ft_strlen(av[1]));
            last = mylist;
            new_link = ft_lstnew(av[2], ft_strlen(av[2]));
            ft_lstadd(&mylist, new_link);

            ft_lstdelone(&mylist, ft_memdel_range);

            printf("%s:", (char *) last->content);
            printf("%i", (int) last->content_size);
            printf("->");
            if (mylist == NULL && mylist == NULL)
                printf("NULL");
    }
    return 0;
}