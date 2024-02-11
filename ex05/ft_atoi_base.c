/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakarya <ysakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:30:36 by ysakarya          #+#    #+#             */
/*   Updated: 2024/02/11 22:30:11 by ysakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	charcheck(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (j < i)
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-')
				return (0);
			else
				j++;
		}
		i++;
	}
	return (i);
}

int	spacetab(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		{
			i++;
			continue ;
		}
		else
			break ;
	}
	return (i);
}

int	signcheck(char *str)
{
	int	sign;
	int	i;

	sign = 0;
	i = spacetab(str);
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign++;
			i++;
			continue ;
		}
		else
			break ;
	}
	if (sign % 2 == 1)
		return (-i);
	else
		return (i);
}

int	makestr(int i, int j, char *base, char *str)
{
	int	k;
	int	n;

	k = 0;
	n = 0;
	while (str[j] != '\0')
	{
		k = 0;
		while (base[k] != '\0')
		{
			if (str[j] != base[k])
				k++;
			else
				break ;
		}
		n = n * i + k;
		j++;
	}
	return (n);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	k;
	int	c;

	i = 0;
	j = charcheck(base);
	while (base[i] != '\0')
		i++;
	if (i <= 1 || j == 0)
		return (0);
	else
	{
		j = signcheck(str);
		c = 1;
		if (j < 0)
		{
			j = -j;
			c = -1;
		}
		k = makestr(i, j, base, str);
		return (k * c);
	}
}
#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf("%d", ft_atoi_base("  89" , "abcdef1234"));
}