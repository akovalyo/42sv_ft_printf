/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 10:36:45 by akovalyo          #+#    #+#             */
/*   Updated: 2020/05/01 13:18:17 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	putchar_count(t_printf *flags, char ch)
{
	ft_putchar(ch);
	flags->count++;
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
	char 	ch;
	char 	*str;
	str = NULL;
	if (nbr >= base)
		str = conv_base(nbr / base, base, letter);
	ch = hex_ascii(nbr % base, letter);
	return(ft_straddchr(str, ch));
}

char	*conv_base_uns(size_t nbr, int base, char letter)
{
	char 	ch;
	char 	*str;
	str = NULL;
	if (nbr >= (size_t)base)
		str = conv_base_uns(nbr / base, base, letter);
	ch = hex_ascii(nbr % base, letter);
	return(ft_straddchr(str, ch));
}

void init_flags(t_printf *flags)
{
	flags->specif = "diuscpxX%";
	flags->sp = -1;
	flags->i = 0;
	flags->count = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->width_val = 0;
	flags->precis = 0;
	flags->precis_val = 0;
	flags->precis_minus = 0;
}

void clear_flags(t_printf *flags)
{
	flags->sp = -1;
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->width_val = 0;
	flags->precis = 0;
	flags->precis_val = 0;
	flags->precis_minus = 0;
}
