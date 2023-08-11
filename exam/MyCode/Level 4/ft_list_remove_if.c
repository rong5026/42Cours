
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    if(begin_list == NULL || *begin_list == NULL)
        return;

    t_list *node = *begin_list;

    if(cmp(node->data, data_ref) == 0)
    {
        *begin_list = node->next;
        free(node);
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    node = *begin_list;
    ft_list_remove_if(&node->next,data_ref, cmp);
}