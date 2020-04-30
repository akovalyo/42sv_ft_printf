/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 10:36:45 by akovalyo          #+#    #+#             */
/*   Updated: 2020/04/30 13:46:15 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	putchar_count(t_printf *flags, char c)
{
	putchar_count(format[flags->i]);
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

void init_flags(t_print *flags)
{
	flags->specif = "diuscpxX%";
	flags->i = 0;
	flags->count = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->width_val = 0;
}

void	init_flags(t_flag *flags, int i)
{
	flags->zero = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->sharp = 0;
	flags->space = 0;
	flags->perc = 0;
    flags->h_flag = 0;
    flags->l_flag = 0;
	flags->lb_flag = 0;
	flags->width = 0;
    flags->precis = -1;
	flags->start = i - 1;
	flags->specf = 0;
    flags->xo = 1;
	flags->len = 0;
}

void	init_output(t_output *print)
{
	print->body_len = 0;
	print->count = 0;
	print->i = 0;
	print->cmplt = 1;
	print->prefix = ' ';
	print->pref_len = 0;
	print->postf = ' ';
	print->postf_len = 0;
	print->x_prefix = NULL;
	print->spplus = 0;
	print->x_correct = 0;
	print->free = 1;
}