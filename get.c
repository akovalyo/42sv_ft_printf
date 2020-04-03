/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 18:07:45 by akovalyo          #+#    #+#             */
/*   Updated: 2020/04/03 13:13:48 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	get_diu(t_flag *flags, va_list *ap, t_output *print)
{
	if (flags->specf == 'd' || flags->specf == 'i')
	{
		if (flags->h_flag == 1)
			print->body = ft_itoa((short)va_arg(*ap, int));
		else if (flags->h_flag == 2)
			print->body = ft_itoa((signed char)va_arg(*ap, int));
		else if (flags->l_flag || flags->len == 'j' || flags->len == 'z')
			print->body = ft_itoa_long(va_arg(*ap, long));
		else
			print->body = ft_itoa(va_arg(*ap, int));
	}
	else if (flags->specf == 'u')
	{
		if (flags->l_flag || flags->len == 'j' || flags->len == 'z')
			print->body = ft_itoa_uns(va_arg(*ap, unsigned long));
		else
			print->body = ft_itoa_uns(va_arg(*ap, unsigned int));
	}
}

void	get_sc(t_flag *flags, va_list *ap, t_output *print)
{
	char tmp;

	if (flags->specf == 'c')
	{
		tmp = (char)va_arg(*ap, int);
		if (tmp)
			print->body = ft_straddchr(NULL, tmp);
		else
		{
			print->body = ft_strdup("^@");
			print->count--;
			flags->width++;
		}
	}
	else
	{
		if (!(print->body = va_arg(*ap, char *)))
			print->body = strdup("(null)");
		else
			print->free = 0;
	}
}

void	get_p(t_flag *flags, va_list *ap, t_output *print)
{
	print->body = conv_base_uns(va_arg(*ap, size_t), 16, 0);
	if (flags->plus)
		print->x_prefix = ft_strdup("+0x");
	else
		print->x_prefix = ft_strdup("0x");
	flags->plus = 0;	
}

void	get_xo(t_flag *flags, va_list *ap, t_output *print)
{
	char letter;

	letter = 0;
	if (flags->specf == 'o')
	{
		print->body = conv_base_uns(va_arg(*ap, size_t), 8, 0);
		if (print->body[0] == '0')
		flags->xo = 0;
		return ;
	}
	else if (flags->specf == 'X')
		letter = 1;
	if (flags->len == 'j' || flags->l_flag)
		print->body = conv_base_uns(va_arg(*ap, size_t), 16, letter);
	else
		print->body = conv_base_uns(va_arg(*ap, int), 16, letter);
	if (print->body[0] == '0')
		flags->xo = 0;
}

void	get_f(t_flag *flags, va_list *ap, t_output *print)
{
	if (flags->precis < 0)
		flags->precis = 6;
	if (flags->lb_flag)
		print->body = ft_ftoa_long(va_arg(*ap, long double), flags->precis);
	else	
		print->body = ft_ftoa(va_arg(*ap, double), flags->precis);
}