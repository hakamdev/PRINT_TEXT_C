/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:07:35 by ehakam            #+#    #+#             */
/*   Updated: 2019/11/04 21:14:03 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	*_get_line(char c, int li);
void	_print(char *str);
void	_init_alph(char c);
void	_upper(char *c);
char	*_toupper(char *str);
int		_is_alphnum(const char c);
void	_set_color(char *olor);
char	*ft_strtrim(const char *str,const char *delims);
char	**ft_split(const char *str, char delim);
void	_print_word(char *word, char *color, int j);

/* 	Global Vars */

#define N_TEXT (126 - 32) /* the first 32 ascii's char pannel are not anyway */
#define LINE_PER_TEXT 5
#define CHAR_PER_LINE 8

/* The whole table costs less than 4ko of memory */
char    lookup_table[N_TEXT][LINE_PER_TEXT][CHAR_PER_LINE] = {
	[(int)'A'] = {
		"   ##   ", "  ####  ",
		"  #  #  ", "########",
		"##    ##",
	},
};

/* Main */
int		main(int ac, char **av)
{
	/* Declare Vars */
	int		i = 0, j = 0, x = 0;
	char	*str = NULL, *color = NULL;
	char	**lines;

	/* Init */
	if (ac > 1)
	{
		str = av[1];
		if (ac >= 3)
			color = av[2];
		while (str[i])
		{
			if (_is_alphnum(str[i]))
				_init_alph(str[i]);
			i++;
		}
		lines = ft_split(str, ' ');
		if (!lines)
			return (1);

		while (lines[x])
		{
			while (j < 5)
			{
				_print_word(lines[x], color, j++);
			}
			_print("\n\n");
			j = 0;
			x++;
		}
	}
	else
	{
		printf("Usage:\n	$>./PRINT_N <TEXT> <COLOR>\nExample:\n	$>./PRINT_N 1337 red\nAvailable Colors:\n	\033[0;31mred\n	\033[0;32mgreen\n	\033[0;33myellow\n	\033[0;34mblue\n	\033[0;35mmagneta\n	\033[0;36mcyan\n");
	}
	return (0);
}

void	_print_word(char *word, char *color, int j)
{
	size_t  i = 0;

	_set_color(color);
	_print("   ");
	while (word[i])
	{
		if (_is_alphnum(word[i]))
		{
			_print(_get_line(word[i], j));
			_print("  ");
		}
		i++;
	}
	_print("\n");
}

char	*_get_line(char c, int li)
{
	_upper(&c);
	if (c > 32 && c < N_TEXT)
	{
		return lookup_table[(int)c - 32][li];
	}
	return NULL;
}

void	_print(char *str)
{
	printf("%s", str);
}

void	_init_alph(char c)
{
	_upper(&c);
}

void	_upper(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

char	*_toupper(char *str)
{
	int		i = 0;
	char	*ss;

	if (*str)
	{
		ss = str;
		while (ss[i])
			_upper(&(ss[i++]));
	}
	return (ss);
}

int		_is_alphnum(const char c)
{
	return ((c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z') ||
			(c >= '0' && c <= '9') ||
			c == '-' || c == '_' ||
			c == '!' || c == '.' ||
			c == '?');
}

void	_set_color(char *color)
{
	if (color != NULL)
	{
		color = _toupper(color);
		if (!strcmp(color, "RED"))
			printf("\033[0;31m");
		else if (!strcmp(color, "GREEN"))
			printf("\033[0;32m");
		else if (!strcmp(color, "YELLOW"))
			printf("\033[0;33m");
		else if (!strcmp(color, "BLUE"))
			printf("\033[0;34m");
		else if (!strcmp(color, "MAGENTA"))
			printf("\033[0;35m");
		else if (!strcmp(color, "CYAN"))
			printf("\033[0;36m");
		else
		{
			printf("\033[0m");
		}
	}
	else
	{
		printf("\033[0m");
	}
}
