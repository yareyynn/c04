/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakarya <ysakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:25:45 by ysakarya          #+#    #+#             */
/*   Updated: 2024/02/11 20:22:52 by ysakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	man_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	charcheck(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (j < i)
		{
			if (str[i] == str[j] || str[i] == '+' || str[i] == '-')
				return (0);
			else
				j++;
		}
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nbr, int i, char *base)
{
	long	x;

	x = nbr;
	if (x < 0)
	{
		ft_putchar('-');
		x *= -1;
	}
	if (x < i)
	{
		ft_putchar(base[x]);
		return ;
	}
	else
		ft_putnbr(x / i, i, base);
	ft_putnbr(x % i, i, base);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	j;

	i = man_strlen(base);
	j = charcheck(base);
	if (i <= 1 || j == 0)
		return ;
	else
		ft_putnbr(nbr, i, base);
}
