#include <stdlib.h>


int getSize(int nbr)
{
    int len = 0;

    if(nbr ==0)
        return (1);
    
    if(nbr < 0)
        len++;

    while(nbr!=0)
    {
        nbr/=10;
        len++;
    }
    return (len);
}

char	*ft_itoa(int nbr)
{
    int sign = 1;
    int len = getSize(nbr);
    
    if(nbr == -2147483648)
		return("-2147483648\0");

    char *result = (char *)malloc(sizeof(char) * (len + 1));
    if(!result )
        return (0);

    result[len] = '\0';
    if(nbr == 0)
    {
        result[0] ='0';
        return (result);
    }
    
    if(nbr < 0)
    {
        result[0] = '-';
        nbr *= -1;
    }
    while(nbr!=0)
    {
        result[--len] =nbr %10 + '0';
        nbr/=10;
    }
    return (result);
    
}
