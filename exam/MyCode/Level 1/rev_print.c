#include <unistd.h>

int get_size(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return (i);
}
void    print_rev_print(char *str)
{
    int n = get_size(str);

    for(int i = n - 1 ; i >=0 ; i--)
    {
        write(1, &str[i], 1);
    }
}
int main(int ac, char **av)
{
    if(ac == 2)
        print_rev_print(av[1]);
    write(1, "\n", 1);
    return (0);
}