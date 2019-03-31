/********************************* 1/15 ispoweroftwo.c ****************************** */
Write a function that determines if a given number is a power of 2.
This function returns 1 if the given number is a power of 2, otherwise it returns 0.
int	    is_power_of_2(unsigned int n)
{
	return ((n & (-n)) == n ? 1 : 0);
}
/********************************* 2/15 alphamirror.c ****************************** */
Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.
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
/********************************* 3/15 wdmatch.c ****************************** */
Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.
If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.
If the number of arguments is not 2, the program displays a \n.
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
/********************************* 4/15 ft_atoi.c ****************************** */
Write a function that converts the string argument str to an integer (type int)
and returns it.
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
/********************************* 5/15 do_op.c ****************************** */
Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %
The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.
You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.
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
/********************************* 6/15 ft_strcmp.c ****************************** */
Compares the C string str1 to the C string str2.
This function starts comparing the first character of each string. If they are equal to each other, it continues with the following pairs until the characters differ or until a terminating null-character is reached.
This function performs a binary comparison of the characters. 
int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1 += 1;
		s2 += 2;
	}
	return (*s1 - *s2);
}
/********************************* 7/15 ft_strdup.c ****************************** */
The strdup() function returns a pointer to a new string which is a
duplicate of the string s.  Memory for the new string is obtained
with malloc(3), and can be freed with free(3).
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
/********************************* 8/15 ft_strrev.c ****************************** */
Write a function that reverses (in-place) a string.
It must return its parameter.
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
/********************************* 9/15 union.c ****************************** */
Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.
The display will be in the order characters appear in the command line, and
will be followed by a \n. If the number of arguments is not 2, the program displays \n.
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
/********************************* 10/15 inter.c ****************************** */
Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one. The display will be followed by a \n. If the number of arguments is not 2, the program displays \n.
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
/********************************* 11/15 last_word.c ****************************** */
Write a program that takes a string and displays its last word followed by a \n.
A word is a section of string delimited by spaces/tabs or by the start/end of
the string. If the number of parameters is not 1, or there are no words, display a newline.
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
/********************************* 12/15 max.c ****************************** */
Write the following function:
int		max(int* tab, unsigned int len);
The first parameter is an array of int, the second is the number of elements in
the array. The function returns the largest number found in the array. 
If the array is empty, the function returns 0.
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
/********************************* 13/15 print_bits.c ****************************** */
Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.Your function must be declared as follows:
void	print_bits(unsigned char octet);
Example, if you pass 2 to print_bits, it will print "00000010".
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
/********************************* 14/15 reverse_bits.c ****************************** */
Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result. Your function must be declared as follows:
unsigned char	reverse_bits(unsigned char octet); 
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
/********************************* 15/15 swap_bits.c ****************************** */
Write a function that takes a byte, swaps its halves (like the example) and
returns the result. Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);
unsigned char	swap_bits(unsigned char c)
{
	return ((c >> 4) | (c << 4));
}
