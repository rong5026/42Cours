#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    int i = 0;
    while(s[i])
    {
        int j = 0;
        while(reject[j])
        {
            if(s[i] == reject[j])
                return (i);
                j++;
        }
        i++;
    }
    return (i);
}