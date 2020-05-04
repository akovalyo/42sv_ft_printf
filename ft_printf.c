/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 10:40:44 by akovalyo          #+#    #+#             */
/*   Updated: 2020/05/04 11:03:34 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int 	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_printf	flags;
	conv	*fn_array[] = {get_di, get_di, get_di, get_s, get_c, get_px, get_px, get_px, get_c};
	
	init_flags(&flags);
	va_start(ap, format);
	while (format[flags.i])
	{
		if (format[flags.i] != '%')
		{
			putchar_count(&flags, format[flags.i]);
			flags.i++;
		}
		else
		{
			flags.i++;
			format_checker(&flags, format, &ap);
			if (specifier_checker(&flags, format))
				fn_array[flags.sp](&flags, &ap);
			flags.i++;
		}
		
	}
	va_end(ap);
	return(flags.count);
}

/* int main()
{
	int i = 0;
	int d = 0;
	int num = 29;
	long ln = 12344;
	char ch;
	char c = 'c';
	char *str;
	i = ft_printf("%.-5d\n", -123);
	d = printf("%.5d\n", -123);
	printf("%i - %i\n", i, d);
	return (0);
}
 */