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
char **A; char **F; char **K; char **O; char **S; char **W;
char **B; char **G; char **L; char **P; char **T; char **X;
char **C; char **H; char **M; char **Q; char **U; char **Y;
char **D; char **I; char **N; char **R; char **V; char **Z;
char **E; char **J; char **_0; char **_1; char **_2; char **_3;
char **_4; char **_5; char **_6; char **_7; char **_8; char **_9;
char **_dot; char **_excl; char **_interr; char **_hyfn; char **_uscore;

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
	char	i = 0;
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
	switch (c)
	{
		case 'A':
			return(A[li]);
		case 'B':
			return(B[li]);
		case 'C':
			return(C[li]);
		case 'D':
			return(D[li]);
		case 'E':
			return(E[li]);
		case 'F':
			return(F[li]);
		case 'G':
			return(G[li]);
		case 'H':
			return(H[li]);
		case 'I':
			return(I[li]);
		case 'J':
			return(J[li]);
		case 'K':
			return(K[li]);
		case 'L':
			return(L[li]);
		case 'M':
			return(M[li]);
		case 'N':
			return(N[li]);
		case 'O':
			return(O[li]);
		case 'P':
			return(P[li]);
		case 'Q':
			return(Q[li]);
		case 'R':
			return(R[li]);
		case 'S':
			return(S[li]);
		case 'T':
			return(T[li]);
		case 'U':
			return(U[li]);
		case 'V':
			return(V[li]);
		case 'W':
			return(W[li]);
		case 'X':
			return(X[li]);
		case 'Y':
			return(Y[li]);
		case 'Z':
			return(Z[li]);
		case '0':
			return(_0[li]);
		case '1':
			return(_1[li]);
		case '2':
			return(_2[li]);
		case '3':
			return(_3[li]);
		case '4':
			return(_4[li]);
		case '5':
			return(_5[li]);
		case '6':
			return(_6[li]);
		case '7':
			return(_7[li]);
		case '8':
			return(_8[li]);
		case '9':
			return(_9[li]);
		case '.':
			return(_dot[li]);
		case '!':
			return(_excl[li]);
		case '?':
			return(_interr[li]);
		case '-':
			return(_hyfn[li]);
		case '_':
			return(_uscore[li]);
		default :
			return(NULL);
	}
}

void	_print(char *str)
{
	printf("%s", str);
}

void	_init_alph(char c)
{
	_upper(&c);
	switch (c)
	{
		case 'A':
			if (A == NULL)
			{
				A = malloc(sizeof(char *) * 6);
				A[0] = "   ##   "; A[1] = "  ####  ";
				A[2] = " ##  ## "; A[3] = "########";
				A[4] = "##    ##"; A[5] = NULL;
			}
			break ;
		case 'B':
			if (B == NULL)
			{
				B = malloc(sizeof(char *) * 6);
				B[0] = "####### "; B[1] = "##    ##";
				B[2] = "####### "; B[3] = "##    ##";
				B[4] = "####### "; B[5] = NULL;
			}
			break ;
		case 'C':
			if (C == NULL)
			{
				C = malloc(sizeof(char *) * 6);
				C[0] = "  ##### "; C[1] = " ##   ##";
				C[2] = "##      "; C[3] = " ##   ##";
				C[4] = "  ##### "; C[5] = NULL;
			}
			break ;
		case 'D':
			if (D == NULL)
			{
				D = malloc(sizeof(char *) * 6);
				D[0] = "####### "; D[1] = "##    ##";
				D[2] = "##    ##"; D[3] = "##    ##";
				D[4] = "####### "; D[5] = NULL;
			}
			break ;
		case 'E':
			if (E == NULL)
			{
				E = malloc(sizeof(char *) * 6);
				E[0] = "########"; E[1] = "##      ";
				E[2] = "####### "; E[3] = "##      ";
				E[4] = "########"; E[5] = NULL;
			}
			break ;
		case 'F':
			if (F == NULL)
			{
				F = malloc(sizeof(char *) * 6);
				F[0] = "########"; F[1] = "##      ";
				F[2] = "#####   "; F[3] = "##      ";
				F[4] = "##      "; F[5] = NULL;
			}
			break ;
		case 'G':
			if (G == NULL)
			{
				G = malloc(sizeof(char *) * 6);
				G[0] = " ###### "; G[1] = "##      ";
				G[2] = "##  ####"; G[3] = "##    ##";
				G[4] = " ###### "; G[5] = NULL;
			}
			break ;
		case 'H':
			if (H == NULL)
			{
				H = malloc(sizeof(char *) * 6);
				H[0] = "##    ##"; H[1] = "##    ##";
				H[2] = "########"; H[3] = "##    ##";
				H[4] = "##    ##"; H[5] = NULL;
			}
			break ;
		case 'I':
			if (I == NULL)
			{
				I = malloc(sizeof(char *) * 6);
				I[0] = "  ####  "; I[1] = "   ##   ";
				I[2] = "   ##   "; I[3] = "   ##   ";
				I[4] = "  ####  "; I[5] = NULL;
			}
			break ;
		case 'J':
			if (J == NULL)
			{
				J = malloc(sizeof(char *) * 6);
				J[0] = "  ####  "; J[1] = "   ##   ";
				J[2] = "   ##   "; J[3] = "## ##   ";
				J[4] = " ###    "; J[5] = NULL;
			}
			break ;
		case 'K':
			if (K == NULL)
			{
				K = malloc(sizeof(char *) * 6);
				K[0] = "##    ##"; K[1] = "##  ##  ";
				K[2] = "####    "; K[3] = "##  ##  ";
				K[4] = "##    ##"; K[5] = NULL;
			}
			break ;
		case 'L':
			if (L == NULL)
			{
				L = malloc(sizeof(char *) * 6);
				L[0] = "##      "; L[1] = "##      ";
				L[2] = "##      "; L[3] = "##      ";
				L[4] = "########"; L[5] = NULL;
			}
			break ;
		case 'M':
			if (M == NULL)
			{
				M = malloc(sizeof(char *) * 6);
				M[0] = "##    ##"; M[1] = "###  ###";
				M[2] = "## ## ##"; M[3] = "##    ##";
				M[4] = "##    ##"; M[5] = NULL;
			}
			break ;
		case 'N':
			if (N == NULL)
			{
				N = malloc(sizeof(char *) * 6);
				N[0] = "##    ##"; N[1] = "###   ##";
				N[2] = "## ## ##"; N[3] = "##  ####";
				N[4] = "##    ##"; N[5] = NULL;
			}
			break ;
		case 'O':
			if (O == NULL)
			{
				O = malloc(sizeof(char *) * 6);
				O[0] = "  ####  "; O[1] = " ##  ## ";
				O[2] = "##    ##"; O[3] = " ##  ## ";
				O[4] = "  ####  "; O[5] = NULL;
			}
			break ;
		case 'P':
			if (P == NULL)
			{
				P = malloc(sizeof(char *) * 6);
				P[0] = "####### "; P[1] = "##    ##";
				P[2] = "####### "; P[3] = "##      ";
				P[4] = "##      "; P[5] = NULL;
			}
			break ;
		case 'Q':
			if (Q == NULL)
			{
				Q = malloc(sizeof(char *) * 6);
				Q[0] = " #####  "; Q[1] = "##   ## ";
				Q[2] = "## # ## "; Q[3] = "##  ### ";
				Q[4] = " #######"; Q[5] = NULL;
			}
			break ;
		case 'R':
			if (R == NULL)
			{
				R = malloc(sizeof(char *) * 6);
				R[0] = "####### "; R[1] = "##    ##";
				R[2] = "####### "; R[3] = "## ##   ";
				R[4] = "##   ## "; R[5] = NULL;
			}
			break ;
		case 'S':
			if (S == NULL)
			{
				S = malloc(sizeof(char *) * 6);
				S[0] = " ###### "; S[1] = "##      ";
				S[2] = " ###### "; S[3] = "      ##";
				S[4] = " ###### "; S[5] = NULL;
			}
			break ;
		case 'T':
			if (T == NULL)
			{
				T = malloc(sizeof(char *) * 6);
				T[0] = "########"; T[1] = "   ##   ";
				T[2] = "   ##   "; T[3] = "   ##   ";
				T[4] = "   ##   "; T[5] = NULL;
			}
			break ;
		case 'U':
			if (U == NULL)
			{
				U = malloc(sizeof(char *) * 6);
				U[0] = "##    ##"; U[1] = "##    ##";
				U[2] = "##    ##"; U[3] = "##    ##";
				U[4] = " ###### "; U[5] = NULL;
			}
			break ;
		case 'V':
			if (V == NULL)
			{
				V = malloc(sizeof(char *) * 6);
				V[0] = "##    ##"; V[1] = "##    ##";
				V[2] = " ##  ## "; V[3] = "  ####  ";
				V[4] = "   ##   "; V[5] = NULL;
			}
			break ;
		case 'W':
			if (W == NULL)
			{
				W = malloc(sizeof(char *) * 6);
				W[0] = "##    ##"; W[1] = "## ## ##";
				W[2] = "## ## ##"; W[3] = "## ## ##";
				W[4] = " ##  ## "; W[5] = NULL;
			}
			break ;
		case 'X':
			if (X == NULL)
			{
				X = malloc(sizeof(char *) * 6);
				X[0] = "##    ##"; X[1] = " ##  ## ";
				X[2] = "   ##   "; X[3] = " ##  ## ";
				X[4] = "##    ##"; X[5] = NULL;
			}
			break ;
		case 'Y':
			if (Y == NULL)
			{
				Y = malloc(sizeof(char *) * 6);
				Y[0] = "##    ##"; Y[1] = " ##  ## ";
				Y[2] = "  ####  "; Y[3] = "   ##   ";
				Y[4] = "   ##   "; Y[5] = NULL;
			}
			break ;
		case 'Z':
			if (Z == NULL)
			{
				Z = malloc(sizeof(char *) * 6);
				Z[0] = "########"; Z[1] = "     ## ";
				Z[2] = "   ##   "; Z[3] = " ##     ";
				Z[4] = "########"; Z[5] = NULL;
			}
			break ;
		case '0':
			if (_0 == NULL)
			{
				_0 = malloc(sizeof(char *) * 6);
				_0[0] = " ##### "; _0[1] = "##   ##";
				_0[2] = "##   ##"; _0[3] = "##   ##";
				_0[4] = " ##### "; _0[5] = NULL;
			}
			break ;
		case '1':
			if (_1 == NULL)
			{
				_1 = malloc(sizeof(char *) * 6);
				_1[0] = "####   "; _1[1] = "  ##   ";
				_1[2] = "  ##   "; _1[3] = "  ##   ";
				_1[4] = "#######"; _1[5] = NULL;
			}
			break ;
		case '2':
			if (_2 == NULL)
			{
				_2 = malloc(sizeof(char *) * 6);
				_2[0] = "###### "; _2[1] = "     ##";
				_2[2] = " ##### "; _2[3] = "##     ";
				_2[4] = "#######"; _2[5] = NULL;
			}
			break ;
		case '3':
			if (_3 == NULL)
			{
				_3 = malloc(sizeof(char *) * 6);
				_3[0] = "###### "; _3[1] = "     ##";
				_3[2] = "  #### "; _3[3] = "     ##";
				_3[4] = "###### "; _3[5] = NULL;
			}
			break ;
		case '4':
			if (_4 == NULL)
			{
				_4 = malloc(sizeof(char *) * 6);
				_4[0] = "  # ## "; _4[1] = " ## ## ";
				_4[2] = "##  ## "; _4[3] = "#######";
				_4[4] = "    ## "; _4[5] = NULL;
			}
			break ;
		case '5':
			if (_5 == NULL)
			{
				_5 = malloc(sizeof(char *) * 6);
				_5[0] = "#######"; _5[1] = "##     ";
				_5[2] = "###### "; _5[3] = "     ##";
				_5[4] = "###### "; _5[5] = NULL;
			}
			break ;
		case '6':
			if (_6 == NULL)
			{
				_6 = malloc(sizeof(char *) * 6);
				_6[0] = " ##### "; _6[1] = "##     ";
				_6[2] = "###### "; _6[3] = "##   ##";
				_6[4] = "###### "; _6[5] = NULL;
			}
			break ;
		case '7':
			if (_7 == NULL)
			{
				_7 = malloc(sizeof(char *) * 6);
				_7[0] = "#######"; _7[1] = "    ## ";
				_7[2] = "   ##  "; _7[3] = "  ##   ";
				_7[4] = " ##    "; _7[5] = NULL;
			}
			break ;
		case '8':
			if (_8 == NULL)
			{
				_8 = malloc(sizeof(char *) * 6);
				_8[0] = " ##### "; _8[1] = "##   ##";
				_8[2] = " ##### "; _8[3] = "##   ##";
				_8[4] = " ##### "; _8[5] = NULL;
			}
			break ;
		case '9':
			if (_9 == NULL)
			{
				_9 = malloc(sizeof(char *) * 6);
				_9[0] = " ######"; _9[1] = "##   ##";
				_9[2] = " ######"; _9[3] = "     ##";
				_9[4] = " ##### "; _9[5] = NULL;
			}
			break ;
		case '.':
			if (_dot == NULL)
			{
				_dot = malloc(sizeof(char *) * 6);
				_dot[0] = "        "; _dot[1] = "        ";
				_dot[2] = "        "; _dot[3] = "        ";
				_dot[4] = "   ##   "; _dot[5] = NULL;
			}
			break ;
		case '-':
			if (_hyfn == NULL)
			{
				_hyfn = malloc(sizeof(char *) * 6);
				_hyfn[0] = "        "; _hyfn[1] = "        ";
				_hyfn[2] = " ###### "; _hyfn[3] = "        ";
				_hyfn[4] = "        "; _hyfn[5] = NULL;
			}
			break ;
		case '_':
			if (_uscore == NULL)
			{
				_uscore = malloc(sizeof(char *) * 6);
				_uscore[0] = "        "; _uscore[1] = "        ";
				_uscore[2] = "        "; _uscore[3] = "        ";
				_uscore[4] = "########"; _uscore[5] = NULL;
			}
			break ;
		case '!':
			if (_excl == NULL)
			{
				_excl = malloc(sizeof(char *) * 6);
				_excl[0] = "   ##   "; _excl[1] = "   ##   ";
				_excl[2] = "    #   "; _excl[3] = "    #   ";
				_excl[4] = "   ##   "; _excl[5] = NULL;
			}
			break ;
		case '?':
			if (_interr == NULL)
			{
				_interr = malloc(sizeof(char *) * 6);
				_interr[0] = " ###### "; _interr[1] = "      ##";
				_interr[2] = "  ##### "; _interr[3] = "   #    ";
				_interr[4] = "   ##   "; _interr[5] = NULL;
			}
			break ;
		default :
			return;
	}
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
