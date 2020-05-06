/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 10:36:45 by akovalyo          #+#    #+#             */
/*   Updated: 2020/05/05 17:18:01 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	init_flags(t_printf *flags)
{
	flags->specif = "diuscpxX%";
	flags->sp = 10;
	flags->i = 0;
	flags->count = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->width_val = 0;
	flags->precis = 0;
	flags->precis_val = 0;
	flags->precis_minus = 0;
	flags->s_len = 0;
	flags->print_precis = 0;
	flags->dig_minus = 0;
}

void	clear_flags(t_printf *flags)
{
	flags->sp = -1;
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->width_val = 0;
	flags->precis = 0;
	flags->precis_val = 0;
	flags->precis_minus = 0;
	flags->s_len = 0;
	flags->print_precis = 0;
	flags->dig_minus = 0;
}

int		hex_ascii(size_t n, int letter)
{
	if (n <= 9)
		return (n + '0');
	else if (letter == 0)
		return (n + 87);
	else
		return (n + 55);
}

char	*conv_base(unsigned int nbr, unsigned int base, int letter)
{
	char	ch;
	char	*str;

	str = NULL;
	if (nbr >= base)
		str = conv_base(nbr / base, base, letter);
	ch = hex_ascii(nbr % base, letter);
	return (ft_straddchr_free(str, ch));
}

char	*strdup_printf(const char *s)
{
	char *d;

	if (!s)
		return (ft_strdup("(null)"));
	if (!(d = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	ft_strcpy(d, s);
	return (d);
}
