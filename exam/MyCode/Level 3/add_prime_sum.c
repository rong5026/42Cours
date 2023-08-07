#include <unistd.h>
void print_nbr(int sum)
{
    if(sum >= 10)
        print_nbr(sum / 10);
    char c = sum % 10 + '0';
    write(1, &c, 1);
}
int is_prime(int sum)
{
    int i = 2;

    if (sum <= 1)
        return (0);
    while( i * i <= sum)
    {
        if(sum % i == 0)
            return (0);
        i++;
    }
    return (1);

}
void    add_prime(int sum)
{
    if(sum <= 0){
        print_nbr(0);
        return ;
    }
    int i = 2;
    int result = 0;
    while(i <= sum)
    {
        if(is_prime(i) == 1)
            result+= i;
        i++;
    }
    print_nbr(result);

}


int ft_atoi(char *str)
{
    int i = 0;
    int sum = 0;

    while(str[i])
    {
        sum = sum * 10 + (str[i] - '0');
        i++;
    }
    return (sum);
}

int main(int ac, char **av)
{
	if(ac == 2)
		add_prime(ft_atoi(av[1]));
	write(1, "\n", 1);
	return 0;
}
