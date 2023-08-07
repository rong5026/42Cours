#include <unistd.h>

void search_and_replace(char *str, char *str1, char *str2)
{
    int i = 0;
    
    if(str1[1] == '\0' && str2[1] == '\0')
    {
        while(str[i])
        {
            if(str[i] == str1[0])
                write(1, &str2[0], 1);
            else
                write(1, &str[i], 1);
            i++;   
        }
    }
  
}


int main(int ac, char **av)
{
    if (ac == 4)
        search_and_replace(av[1],av[2], av[3]);
    write(1, "\n", 1);
    return (0);
}