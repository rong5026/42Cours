
#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
    int len = abs(end - start) + 1;

    int *result = (int *)malloc(sizeof(int) * (len));

    int i = 0;
    
    while(i < len)
    {
        if(start < end)
        {
            result[i] = end;
            end--;
            i++;
        }
        else
        {
            result[i] = end;
            end++;
            i++;
        }
    }
    return (result);
}