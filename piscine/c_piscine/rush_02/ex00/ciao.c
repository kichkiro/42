/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ciao.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpollini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:59:04 by lpollini          #+#    #+#             */
/*   Updated: 2022/07/30 14:59:06 by lpollini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct num_word
{
	char *num;
	char *word;
};

int	stop(char *str, char *mat)
{
	int	i;

	i = 0;
	while (*(mat + i) != '\0')
	{
		if (*(mat + i) != *(str + i))
			break ;
		i++;
	}
	if (*(mat + i) == '\0')
		return (1);
	return (0);
}

int	ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (stop((str + i), to_find))
			break ;
		i++;
	}
	if (*(str + i) != '\0')
		return (1);
	return (0);
}

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	checknumer(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) > '9' || *(str + i) < '0')
			return (0);
		i++;
	}
	return (1);
}

char	*strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	*(dest) = *(src);
	while (*(src + i) != '\0')
	{
		i++;
		*(dest + i) = *(src + i);
	}
	return (dest);
}

char	*strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(dest + i) != '\0')
	{
		i++;
	}
	while (*(src + j) != '\0')
	{
		*(dest + j + i) = *(src + j);
		j++;
	}
	*(dest + j + i) = '\0';
	return (dest);
}

int isended(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == EOF)
			return (1);
		i++;
	}
	return (0);
}

int	touchfile(char *buff, char *filename, char **numarr, char **wordarr)
{
	int		i;
	int		n;
	int		h;
	int		size;
	int		file;
	char	*temp;

	temp = malloc(5999);
	file = open(filename, O_RDONLY);
	i = 0;
	n = 0;
	size = read(file, buff, 59000);
	while (i < size - 1)
	{
		h = 0;
		while (*(buff + i) != ':')
		{
			if (*(buff + i) != ' ' && *(buff + i) != '\n')
				*(temp + h) = *(buff + i);
			h++;
			i++;
		}
		*(temp + h) = '\0';
		strcpy(*(numarr + n), temp);
		h = 0;
		i++;
		while (*(buff + i) != '\n' && *(buff + i) != '\0')
		{
				*(temp + h) = *(buff + i);
			h++;
			i++;
		}
		*(temp + h) = '\0';
		strcpy(*(wordarr + n), temp);
		//putstr(*(numarr + n));
		n++;
	}
	free(temp);
	close(file);
	return (n);
}

void	initptpt(char **pt)
{
	int	i;

	i = 0;
	while (i < 500)
	{
		*(pt + i) = malloc(5999);
		i++;
	}
}

int	findit(char a, char *in)
{
	int	i;

	i = 0;
	while (*(in + i) != '\0')
	{
		if (a == *(in + i) && *(in + i) == ' ')
			return (1);
		if (a == *(in + i) && *(in + i) == '0')
			return (-1);
		i++;
	}
	return(0);
}

int	search(char a, int zs, char **numarr, int sizedict)
{
	int	i;
	int	n;

	n = 0;
	if (zs == 0)
	{
		while (n < sizedict)
		{
			if (findit(a, *(numarr + n)) == 1)
				return (n);
			n++;
		}
	}
	if (zs == 1)
	{
		while (n < sizedict)
		{
			if (findit(a, *(numarr + n)) == -1)
				return (n);
			n++;
		}
	}
	return (0);
}

void	printer(char *numer, char **numarr, char **wordarr, int sizedict)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (*(numer + size) != '\0')
		size++;
	while (size)
	{
		printf("%i",search(*(numer + i), size - 1, numarr, sizedict));
		i++;
		size--;
	}
}

int	main(int a, char **strs)
{
	int		i;
	int		sizedict;
	char	**numarr;
	char	**wordarr;
	char	*numer;
	char	*dictname;
	char	*readed;

	dictname = malloc(9999);
	numarr = malloc(9999);
	wordarr = malloc(9999);
	initptpt(numarr);
	initptpt(wordarr);
	readed = malloc(9999);
	strcpy(dictname, "numbers.dict");


	if (a == 3)
		dictname = *(strs + 2);
	numer = *(strs + 1);
	if ((a != 2 && a != 3) || !checknumer(numer))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	sizedict = touchfile(readed, dictname, numarr, wordarr);
	printer(numer, numarr, wordarr, sizedict);


	free(dictname);
	free(readed);
	write(1, "\n", 1);
	return (0);
}









