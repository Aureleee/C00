/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabbard <ahabbard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:49:24 by ahabbard          #+#    #+#             */
/*   Updated: 2025/08/12 15:16:51 by ahabbard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_max_value(int *position, int *size, char *comb)
{
	return (9 - *size + *position + 1 == (comb[*position] - 48));
}

void	ft_reset(int *position, int *size, char *comb)
{
	int	index;

	index = *position;
	if (!ft_max_value(position, size, comb))
		comb[index] = comb[index] + 1;
	while (index < *size - 1)
	{
		comb[index + 1] = comb[index] + 1;
		index++;
	}
	if (*size == 1 && !ft_max_value(position, size, comb))
	{
		write(1, comb, *size + 2);
	}
}

void	ft_init(int *index, int *size, char *comb)
{
	while (*index != *size)
	{
		comb[*index] = *index + 48;
		(*index)++;
	}
	(*index)--;
	comb[*size] = ',';
	comb[*size + 1] = ' ';
}

void	ft_print_combn(int size)
{
	char	comb[12];
	int		index;

	index = 0;
	ft_init(&index, &size, comb);
	write(1, comb, size + 2);
	while (comb[0] != 48 + 9 - size + 1)
	{
		index = size - 1;
		while (!ft_max_value(&index, &size, comb))
		{
			ft_reset(&index, &size, comb);
			if (size != 1)
				write(1, comb, size + 2);
		}
		while (index > 0 && ft_max_value(&index, &size, comb))
			index--;
		ft_reset(&index, &size, comb);
		if (comb[0] == 48 + 9 - size + 1)
			write(1, comb, size);
		else
			write(1, comb, size + 2);
	}
}

/*
int	main(void)
{
	ft_print_combn(2);
	write(1, "\n_________________\n", 20);
	ft_print_combn(3);
	write(1, "\n__________________\n", 20);
	ft_print_combn(9);
	write(1, "\n__________________\n", 20);
	ft_print_combn(1);
	write(1, "\n__________________\n", 20);
	return (0);
}
 */