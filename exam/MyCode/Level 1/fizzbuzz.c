#include <unistd.h>

int getSize(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return (i);
}

void    print_number(int num)
{
    char str[10] = "0123456789";

    if(num > 9)
        print_number(num / 10);
    write(1, &str[num % 10], 1);
}

int main(void)
{
    for(int i =  1 ; i <= 100 ; i++)
    {
        if(i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz", getSize("fizzbuzz"));
        else if(i % 3 == 0)
            write(1, "fizz", getSize("fizz"));
        else if(i % 5 == 0)
             write(1, "buzz", getSize("buzz"));
        else
            print_number(i);
        write(1, "\n", 1);
    }
}