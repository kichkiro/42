/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <kichkiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:01:45 by kichkiro          #+#    #+#             */
/*   Updated: 2022/08/03 19:59:46 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/*
char	*take_map(char *map)
{
	int		file;
	int		len;
	char	*buff;
	char	*tmp;

	file = open (map, O_RDONLY);
	len = 0;
	tmp = (char *)malloc (1);
	if (file == -1)
		return (0);
	else
	{
		while (read (file, tmp, 1))
			len++;
		close (file);
		buff = (char *)malloc (len);
		file = open (map, O_RDONLY);
		read (file, buff, len);
		buff[len] = 0;
	}
	close (file);
	return (buff);
}

int	main(int argc, char **argv)
{
	char	*map;

	if (argc > 1)
	{
		if (!(map = take_map (argv[1])))
			write (1, "non esiste nessun file con questo nome\n", 40);
		else
			//print
	}
	else
		write (1, "Nessun argomento passato\n", 25);
	return (0);
}

int	len_row(*map)
{
	int	len;

	len = 0;
	while (*map)
		len++;
	return (len);
}*/

// cicla la riga fino al primo ostacolo o fino al quadrato o fino alla fine
int	find_obst_rows(char *map, int max_side, char obst, int j)
{
	int i;
	
	i = 0;
	while (i < max_side)
	{
		if (map[j] == '\n')
			return (-1);
		else if (map[j] == obst)
			return (j);
		j++;
		i++;
	}
	return (j);
}

void	find_square(int max_side, char obst)
{
	int		i;
	int		i2;
	int 	j; // colonne
	int		k; // righe
	int		new_max;

	char	map[10][31] = 
	{
		"..............................\n", "................o....o........\n", 
		"..............................\n", "..............................\n", 
		"....o.........................\n", "..............o...............\n", 
		"..............o...............\n", "..............................\n", 
		"..............................\n", "...o....................o.....\n"
	};
	
	k = 0;
	i = 200;
	new_max = max_side;

	j = find_obst_rows(map[k], max_side, obst, 0);
	// cicla fintanto che il quadrato e' maggiore di 1
	//while (max_side > 0)
	//{
		i2 = 0;

		//print ("%d\n", j);
		//print ("%d\n", k);

		// cicla fintanto che ci sono righe da ciclare (9 * 9 = 1, 8 * 8 = 2)
		while (i2 <= i)
		{
			
			//print ("j = %d,  k = %d, max = %d\n", j, k, new_max);

			// se ha trovato la fine della riga o non ha trovato ostacoli, passa linea successiva
			if (j == -1)
			{
				//k++;
				max_side--;
				j = find_obst_rows(map[k], max_side, obst, 0);
				new_max = max_side;
				//print ("%d %d\n", j, i2);
				//print ("%d\n", j);
			}
			else if (j == new_max)
			{
				k++;
				j = find_obst_rows(map[k], max_side, obst, j - max_side);
				
			}
			// se ha trovato un ostacolo, riparti dalla riga originale e dalla col del ostacolo + 1
			else if (j != new_max)
			{
				
				k = 0;
				new_max = j + max_side + 1;
				j = find_obst_rows(map[k], max_side, obst, j + 1);
				
				
				//print ("%d\n", j);
			}
			i2++;
		}
		i++;
		//max_side--;
	//}
}

int	main(void)
{
	find_square (10, 'o');

	return (0);
}