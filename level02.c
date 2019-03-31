
/* ******************************** ispoweroftwo.c ****************************** */


int	    is_power_of_2(unsigned int n)
{
	return ((n & (-n)) == n ? 1 : 0);
}

/* ******************************** alphamirror.c ****************************** */

#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;
	char	ltr;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			ltr = argv[1][i];
			if ('A' <= argv[1][i] && 'Z' >= argv[1][i])
				ltr = 'Z' - argv[1][i] + 'A';
			if ('a' <= argv[1][i] && 'z' >= argv[1][i])
			   	ltr = 'z' - argv[1][i] + 'a';
			write(1, &ltr, 1);
			i += 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}


/* ******************************** wdmatch.c ****************************** */



#include <unistd.h>

void	ft_putstr(char const *str)
{
	int		i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int		main(int argc, char const *argv[])
{
	int		i;
	int		j;

	if (argc == 3)
	{
		i = 0;
		j = 0;
		while (argv[2][j])
			if (argv[2][j++] == argv[1][i])
				i += 1;
		if (!argv[1][i])
			ft_putstr(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}


/* ******************************** ft_atoi.c ****************************** */


int		ft_atoi(char *str)
{
	int		i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if (str == '\0')
		return (0);
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i += 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - '0');
	return (nbr * sign);
}

/* ******************************** do_op.c ****************************** */


#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char *argv[])
{
	if (argc == 4)
	{
		if (argv[2][0] == '+')
			printf("%d", (atoi(argv[1]) + atoi(argv[3])));
		if (argv[2][0] == '-')
			printf("%d", (atoi(argv[1]) - atoi(argv[3])));
		if (argv[2][0] == '*')
			printf("%d", (atoi(argv[1]) * atoi(argv[3])));
		if (argv[2][0] == '/')
			printf("%d", (atoi(argv[1]) / atoi(argv[3])));
		if (argv[2][0] == '%')
			printf("%d", (atoi(argv[1]) % atoi(argv[3])));
	}
	printf("\n");
	return (0);
}



/* ******************************** ft_strcmp.c ****************************** */


int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1 += 1;
		s2 += 2;
	}
	return (*s1 - *s2);
}


/* ******************************** ft_strdup.c ****************************** */


#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		i;

	i = -1;
	if (!src || !(cpy = (char *)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	while (src[++i])
		cpy[i] = src[i];
	cpy[i] = '\0';
	return (cpy);
}


/* ******************************** ft_strrev.c ****************************** */

char		*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	len = 0;
	while (str[len])
		len += 1;
	i = -1;
	while (++i < --len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
	}
	str[i] = '\0';
	return (str);
}



/* ******************************** union.c ****************************** */


#include <unistd.h>

void	ft_union(char *str1, char *str2)
{
	int		i;
	char	str_union[256 + 128] = {0};

	i = 0;
	while (str1[i])
	{
		if (!str_union[+str1[i]])
		{
			str_union[+str1[i]] = 1;
			write (1, &str1[i], 1);
		}
		i += 1;
	}
	i = 0;
	while (str2[i])
	{
		if (!str_union[+str2[i]])
		{
			str_union[+str2[i]] = 1;
			write (1, &str2[i], 1);
		}
		i += 1;
	}
}

int		main (int argc, char *argv[])
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}


/* ******************************** inter.c ****************************** */

#include <unistd.h>

int     iter(char *str, char c, int len)
{
    int     i;
    
    i = 0;
    while (str[i] && (i < len || len == -1))
        if (str[i++] == c)
            return (1);
    return (0);
}

int     main(int argc, char *argv[])
{
    int     i;
    
    if (argc == 3)
    {
        i = 0;
        while(argv[1][i])
        {
            if (!iter(argv[1], argv[1][i], i) && iter(argv[2], argv[1][i], -1))
                write(1, &argv[1][i], 1);
            i += 1;
        }
    }
    write(1, "\n", 1);
    return (0);
}

/* ******************************** last_word.c ****************************** */


#include <unistd.h>

void	fn_word(char *str, int *i)
{
	while (str[*i] != ' ' && str[*i] != '\t' && str[*i])
		(*i) += 1;
}

void	print_word(char *str, int start, int end)
{
	int		i;
	int		c;

	i = start;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && end--)
		write(1, &str[i++], 1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		start;
	int		end;

	if (argc == 2)
	{
		i = 0;
		start = 0;
		end = 0;
		while ((argv[1][i] == ' ' || argv[1][i] == '\t') && argv[1][i])
			i += 1;
		while (argv[1][i])
		{
			start = i;
			fn_word(argv[1], &i);
			end = i;
			while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
				i += 1;
			if (!argv[1][i])
				print_word(argv[1], start, end);
		}
	}
	write(1, "\n", 1);
	return (0);
}

/* ******************************** max.c ****************************** */

int		max(int *tab, unsigned int len)
{
	int		i;
	int		max_value;

	if (!tab)
		return (0);
	i = 0;
	while (len--)
	{
		if (tab[i] > tab[i + 1])
			max_value = tab[i];
		i += 1;
	}
	return (max_value);
}


/* ******************************** print_bits.c ****************************** */


#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}


/* ******************************** reverse_bits.c ****************************** */


unsigned char   reverse_bits(unsigned char octet)
{
	return  (((octet >> 0) & 1) << 7) | \
			(((octet >> 1) & 1) << 6) | \
			(((octet >> 2) & 1) << 5) | \
			(((octet >> 3) & 1) << 4) | \
			(((octet >> 4) & 1) << 3) | \
			(((octet >> 5) & 1) << 2) | \
			(((octet >> 6) & 1) << 1) | \
			(((octet >> 7) & 1) << 0);
}

/* ******************************** swap_bits.c ****************************** */


unsigned char	swap_bits(unsigned char c)
{
	return ((c >> 4) | (c << 4));
}
