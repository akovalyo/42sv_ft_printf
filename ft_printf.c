/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:40:44 by akovalyo          #+#    #+#             */
/*   Updated: 2020/04/30 13:29:59 by akovalyo         ###   ########.fr       */
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
	va_list	ap;
	t_list	flags;
	conv	*fn_array[] = {conv_di, conv_di, conv_s, conv_c}
	
	init_output(&flags);
	va_start(ap, format);
	while (format[flags.i])
	{
		if (format[flags.i] != '%')
		{
			putchar_count(&flags, format);
			flags.i++;
		}
		else
		{
			flags.i++;
			format_checker(&flags, format, ap);	
			if (specifier_checker(&flags, format))
				(*fn_array[flags.sp])(&flags, ap)
		}
	va_end(ap);
	return(flags.count)
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
	//i = ft_printf("%0+-8.3d\n", -8473);
	d = printf("%0+-8.3d\n", -8473);
	ft_printf("%i - %i\n", i, d);
	return (0);
}