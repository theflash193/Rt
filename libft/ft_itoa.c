/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:37:35 by lnieto-m          #+#    #+#             */
/*   Updated: 2015/11/29 12:21:40 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_of_nb(int m)
{
	int		i;
	long	d;

	i = 1;
	d = 10;
	while (m / d != 0)
	{
		i++;
		d *= 10;
	}
	return (i);
}

static char		*if_zero(char *str)
{
	int		i;

	i = 0;
	str[i++] = '0';
	str[i] = '\0';
	return (str);
}

static char		*fill(int n, char *str)
{
	int		i;
	int		f_true;
	int		rem;

	i = 0;
	f_true = 0;
	rem = 0;
	if (n < 0)
	{
		f_true = 1;
		n = -n;
	}
	while (n != 0)
	{
		rem = n % 10;
		str[i++] = (rem > 9) ? (rem - 10) + '0' : rem + '0';
		n = n / 10;
	}
	if (f_true == 1)
		str[i++] = '-';
	str[i] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;

	if (n < 0)
		str = (char*)malloc(nb_of_nb(n) + 2);
	else
		str = (char*)malloc(nb_of_nb(n) + 1);
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	else if (n == 0)
		return (if_zero(str));
	else
	{
		str = fill(n, str);
		ft_reverse(str);
	}
	return (str);
}
