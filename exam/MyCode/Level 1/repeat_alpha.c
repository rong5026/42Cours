#include <unistd.h>

int     get_alpha_num(char c)
{
    if( c >= 'A' && c <= 'Z')
        return (c - 'A' + 1);
    else if( c >= 'a' && c <= 'z')
        return (c - 'a' + 1);
    return (-1);
}

void    repeat_alpha(char *str)
{
    int i = 0;
    while(str[i])
    {
        int j = 0;
        
        int cnt = get_alpha_num(str[i]);

        if (cnt != -1)
        {
            while(j < cnt)
            {
                write(1, &str[i], 1);
                j++;
            }
        }
        else
            write(1, &str[i],1);
        i++;
    }
}
int main(int ac, char **av)
{
    if(ac == 2)
        repeat_alpha(av[1]);
    write(1, "\n", 1);
    return (0);
}