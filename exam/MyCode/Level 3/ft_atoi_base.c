int	ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int sign = 1;
    int sum = 0;
    if(str[i] == '-')
    {
        sign = -1;
        i++;
    }

    while(str[i])
    {
        sum = sum * str_base;

        if(str[i] >='0' && str[i] <='9')
        {
            sum += (str[i] - '0');
        }
        else if(str[i] >= 'A' && str[i] <='Z')
            sum += str[i] - '7';
        else if(str[i] >= 'a' && str[i] <='z')
            sum+= str[i] - 'W';
        i++;
    }
    return (sum * sign);
}
#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_atoi_base("14", 8) );
}