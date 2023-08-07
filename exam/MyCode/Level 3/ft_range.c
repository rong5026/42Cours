
#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int len = abs(end - start) + 1;

    int *result = (int *)malloc(sizeof(int) * (len));

    int i = 0;
    
    while( i < len)
    {
        if(start < end)
        {
            result[i] = start;
            start++;
            i++;
        }
        else
        {
            result[i] = start;
            start--;
            i++;
        }
    }
    return (result);
}