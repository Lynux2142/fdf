/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:16:40 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/29 18:15:08 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_nb(const char *nb, int base)
{
	int		i;
	int		j;
	char	*tab;

	tab = "0123456789abcdef";
	i = (nb[0] == '0' && nb[1] == 'x' && base == 16) ? 1 : -1;
	while (nb[++i])
	{
		j = 0;
		while (j < base && nb[i] != tab[j])
			++j;
		if (j == base && nb[i] != tab[i])
			return (0);
	}
	return (1);
}

static char	*ft_tab_tolower(char *nb)
{
	int i;

	i = -1;
	while (nb[++i])
		if (nb[i] >= 'A' && nb[i] <= 'Z')
			nb[i] = ft_tolower(nb[i]);
	return (nb);
}

int			ft_atoi_base(const char *str, int base)
{
	int		value;
	int		nb_len;
	int		i;
	int		stop;

	str = ft_tab_tolower((char *)str);
	if (base == 10)
		return (ft_atoi(str));
	if (str == NULL || base < 2 || base > 16 || !ft_check_nb(str, base))
		return (0);
	nb_len = ft_strlen(str) - 1;
	value = 0;
	i = 0;
	stop = (str[0] == '0' && str[1] == 'x' && base == 16) ? 2 : 0;
	while (nb_len >= stop)
	{
		if (str[nb_len] >= 'a' && str[nb_len] <= 'z')
			value += (((str[nb_len--] - 'a') + 10) * ft_power(base, i++));
		if (str[nb_len] >= '0' && str[nb_len] <= '9')
			value += ((str[nb_len--] - '0') * ft_power(base, i++));
	}
	return (value);
}
