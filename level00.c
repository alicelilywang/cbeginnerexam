/************************ aff_a.c **************************/

#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;

	i = 0;
	if (argc != 2)
		write(1, "a\n", 2);
	else
	{
		while (argv[1][i])
		{
			if (argv[1][i] == 'a')
			{
				write(1, "a", 1);
				break ;
			}
			i += 1;
		}
		write(1, "\n", 1);
	}
	return (0);
}


/************************ aff_first_param.c **************************/

#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;
	i = 0;
	if (argc > 1)
	{
		while(argv[1][i])
			write(1, &argv[1][i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}


/************************ aff_last_param.c **************************/

#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;
	i = 0;
	if (argc > 1)
	{
		while(argv[argc - 1][i])
			write(1, &argv[argc - 1][i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}


/************************ ft_countdown.c **************************/

#include <unistd.h>

int		main(void)
{
	write(1, "9876543210\n", 11);
	return (0);
}

/************************ ft_print_numbers.c **************************/

#include <unistd.h>

void	ft_print_numbers(void)
{
	write(1, "0123456789", 10);
}


/************************ hello.c **************************/

#include <unistd.h>

int		main(void)
{
	write(1, "Hello world!\n", 13);
	return (0);
}

/************************ maff_alpha.c **************************/

#include <unistd.h>

int		main(void)
{
	write(1, "aBcDeFgIjKlMnOpQrStUwXyZ\n", 25);
	return (0);
}


/************************ maff_revalpha.c **************************/

#include <unistd.h>

int		main(void)
{
	write(1, "zYxWuTsRqPoNmLkJiGfEdCbA\n", 25);
	return (0);
}

/************************ only_a.c **************************/

#include <unistd.h>

int		main(void)
{
	write(1, "a", 1);
	return (0);
}
