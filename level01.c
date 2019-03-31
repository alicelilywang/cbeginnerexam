/* ********************************* first_word.c ******************************** */

#include <unistd.h>

int		ft_isspace(int i)
{
	if (i == '\t' || i == '\n' || i == '\v' || i == '\f' || i == ' ')
		return (1);
	return (0);
}

int		main(int argc, char *argv[])
{
	int		i;

	i = 0;
	if (argc == 2)
	{
		while (ft_isspace((argv[1][i])))
				i += 1;
		while (!(ft_isspace(argv[1][i])) && argv[1][i])
			write(1, &argv[1][i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}

/********************************** ft_putstr.c ******************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
		write(1, &str[i++], 1);
}


/* ********************************* ft_putstr.c ******************************** */


char	*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i += 1;
	}
	dst[i] = '\0';
	return (dst);
}


/* ********************************* ft_strcpy.c ******************************** */


char	*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i += 1;
	}
	dst[i] = '\0';
	return (dst);
}

/* ********************************* ft_strlen.c ******************************** */


int		ft_strlen(char *str)
{
	int		i;
	i = 0;

	while (str[i])
		i += 1;
	return (i);
}


/* ********************************** ft_swap.c ********************************* */

void	ft_swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = temp;
}


/* ********************************** repeat_alpha.c ********************************* */

int		main(int argc, char *argv[])
{
	int		i;
	int		letter;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			letter = 0;
			if (argv[1][i] >= 'A' && 'Z' >= argv[1][i])
				letter = argv[1][i] - 63;
			else if (argv[1][i] >= 'a' && 'z' >= argv[1][i])
            {
				letter = argv[1][i] - 95;
				while (--letter)
					write(1, &argv[1][i], 1);
            }
            else
                write(1, &argv[1][i], 1);
			i += 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/* ********************************** rev_print.c ********************************* */

#include <unistd.h>

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int i;

		i = 0;
		while(argv[1][i])
			i += 1;
		while(i)
			write(1, &argv[1][--i], 1);
	}
	write(1 ,"\n", 1);
	return (0);
}

/* ********************************** rot_13.c ********************************* */

#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;
	char	mvup;
	char	mvdwn;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			mvup = argv[1][i] + 13;
			mvdwn = argv[1][i] - 13;
			if (('A' <= argv[1][i] && 'M' >= argv[1][i])
				|| ('a' <= argv[1][i] && 'm' >= argv[1][i]))
				write(1, &mvup, 1);
			else if (('N' <= argv[1][i] && 'Z' >= argv[1][i])
				|| ('n' <= argv[1][i] && 'z' >= argv[1][i]))
				write(1, &mvdwn, 1);
			else
				write(1, &argv[1][i], 1);
			i += 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}


/* ********************************** rot_one.c ********************************* */

#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;
	char	letter;
	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			letter = argv[1][i];
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Y')
				letter += 1;
			if (argv[1][i] >= 'a' && argv[1][i] <= 'y')
				letter += 1;
			if (argv[1][i] == 'z' || argv[1][i] == 'Z')
				letter -= 25;
			write(1, &letter, 1);
			i += 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}


/* ********************************** search_and_replace.c ********************************* */


#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;

	if (argc == 4)
	{
		if (!argv[2][1] && !argv[3][1])
		{
			while (argv[1][i])
			{
				if (argv[1][i] == argv[2][0])
					write(1, &argv[3][0], 1);
				else
					write(1, &argv[1][i], 1);
				i += 1;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}


/* ********************************** ulstr.c ********************************* */


#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;
	char	letter;

	i = 0;
	if (argc == 2)
	{
		while(argv[1][i])
		{
			letter = argv[1][i];
			if (argv[1][i] >= 'A' && 'Z' >= argv[1][i])
				letter += 32;
			if (argv[1][i] >= 'a' && 'z' >= argv[1][i])
				letter -= 32;
			write(1, &letter, 1);
			i += 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}
