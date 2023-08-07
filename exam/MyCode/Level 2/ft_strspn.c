#include <stdio.h>


size_t	ft_strspn(const char *s, const char *accept)
{

    int i = 0;

    while(s[i])
    {
        int j = 0;
        while(accept[j])
        {
            if(accept[j] != s[i])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}