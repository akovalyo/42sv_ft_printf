/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:40:44 by akovalyo          #+#    #+#             */
/*   Updated: 2020/04/03 13:15:40 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	create_output(t_flag *flags, va_list *ap, t_output *print)
{
	if (flags->specf == 'd' || flags->specf == 'i' || flags->specf == 'u')
		get_diu(flags, ap, print);
	else if (flags->specf == 's' || flags->specf == 'c')
		get_sc(flags, ap, print);
	else if (flags->specf == 'o' || flags->specf == 'x' || flags->specf == 'X')
		get_xo(flags, ap, print);
	else if (flags->specf == 'p')
		get_p(flags, ap, print);
	else if (flags->specf == 'f' || flags->specf == 'F')
		get_f(flags, ap, print);
	else if (flags->specf == '%')
		print->body = ft_strdup("%");
	print->body_len = ft_strlen(print->body);
	edit_output(flags, print);
}

int 	ft_printf(const char *format, ...)
{
	va_list 	ap;
	t_output 	print;
	t_flag 		flags;

	init_output(&print);
	va_start(ap, format);
	while (format[print.i])
	{
		if (format[print.i] != '%')
		{
			ft_putchar(format[print.i]);
			print.i++;
			print.count++;
		}
		else
		{
			print.i++;
			if (format_checker(&flags, format, &print))	
				create_output(&flags, &ap, &print);
		}
	}
	va_end(ap);
	return (print.count);
}

int main()
{
	int i = 0;
	int d = 0;
	int num = 29;
	long ln = 12344;
	char ch;
	char c = 'c';
	char *str;
	i = ft_printf("%d%\n", 5);
	d = printf("%d%\n", 5);
	ft_printf("%i - %i\n", i, d);
	return (0);
}