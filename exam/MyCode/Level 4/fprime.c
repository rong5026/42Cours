#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if(ac == 2)
    {
        int number = atoi(av[1]);

        if(number == 1)
            printf("1");
        int i = 2;
        while(number >= i)
        {
            if(number & i == 0)
            {
                printf("%d", i);
                if(number / i == 1)
                    break;
                printf("*");
                number /= i;
                i = 1;
            }

            i++;
        }
    }
    printf("\n");
    return (0);
}