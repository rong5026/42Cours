#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int i = 0;
    while(src[i])
        i++;
    char *str;

    str = (char *)malloc(sizeof(char) * (i + 1));
    i = 0;
    
    if(str == NULL)
        return (NULL);
    while(src[i])
    {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}