#include <unistd.h>

// void	print_bits(unsigned char octet)
// {

//     int	i = 256;
// 	while (i >>= 1)
// 		(octet & i) ? write(1, "1", 1) : write(1, "0", 1);
// }


// int main(void)
// {
//     print_bits(2);
//     return (0);
// }


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_bits(unsigned char octet)
{
	int				idx;
	unsigned char	mask;
	unsigned char	bit;

	idx = 7;
	mask = 1;
	while (idx >= 0)
	{
		bit = (((octet >> idx) & mask) + '0');
		ft_putchar(bit);
		idx--;
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	int				idx;
	unsigned char	bit;

	idx = 7;
	while (idx >= 0)
	{
		bit = ((bit * 2) + (octet % 2));
		octet /= 2;
		idx--;
	}
	return (bit);
}


int	main(void)
{
	print_bits(2);
	ft_putchar('\n');
	print_bits(reverse_bits(2));
	ft_putchar('\n');
}

