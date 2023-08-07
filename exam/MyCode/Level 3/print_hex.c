#include <unistd.h>



int ft_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while(str[i] == 32 || (str[i]>=9 && str[i]<=13))
        i++;
    if(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            sign = -1;
        i++;
    }
    while(str[i] >='0' && str[i] <='9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (sign * result);
}

void    print_hex(int n)
{
    char digit[] = "0123456789abcdef";
    if(n >= 16)
        print_hex(n / 16);
    write(1, &digit[n%16],1);
}
int	main(int ac, char **av)
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	write(1, "\n", 1);
}
