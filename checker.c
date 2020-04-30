/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 10:50:01 by akovalyo          #+#    #+#             */
/*   Updated: 2020/04/30 13:58:13 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	format_checker(t_printf *flags, const char *str, va_list ap)
{
	while (str[flags->i] && (str[flags->i] == '-' || str[flags->i] == '*' ||
			(str[flags->i] >= '0' || str[flags->i] <= '9') || str[flags->i] = '.'))
	{
		if (str[flags->i] == '-' || (str[flags->i] == '0' && str[flags->i - 1] == '%')
			analyse_flags(flags, str);
		if (str[flags->i] == '*')
			analyse_asterisk(flags, str, ap);
		if (str[flags->i] >= '1' && str[flags->i] <= '9')
			analyse_width(flags, str);
		if (str[flags->i] == '.')
			analyse_precis(flags, str);

		
	}
}

int	length_checker(t_flag *flags, const char *str)
{
	if (str[print->i] == 'j')
		flags->len = str[print->i];
	else if (str[print->i] == 'z')
		flags->len = str[print->i];
	else if (str[print->i] == 'L')
		flags->lb_flag = str[print->i];
	else if (str[print->i] == 'h')
		flags->h_flag = (!flags->h_flag) ? 1 : 2;
	else if (str[print->i] == 'l')
		flags->l_flag = (!flags->l_flag) ? 1 : 2;
	else
		return (0);
	return (1);
}

int	flag_checker(t_flag *flags, const char *str)
{
	
		if (str[print->i] == '-')
			flags->minus = 1;
		else if (str[print->i] == '+')
			flags->plus = 1;
		else if (str[print->i] == '#')
			flags->sharp = 1;
		else if (str[print->i] == '0')
			flags->zero = 1;
		else if (str[print->i] == ' ')
			flags->space = 1;
		else
			return (0);
	return (1);
}

void	width_checker(t_flag *flags, const char *str)
{
	int width;

	width = 0;
	if ((width = ft_atoi(&str[print->i])) > 0)
	{
		flags->width = width;
        print->i += ft_nbrlen(width);
	}
}

int 	precis_checker(t_flag *flags, const char *str)
{
	int len;

	print->i++;
	if (str[print->i] < '0' || str[print->i] > '9')
	{
		if (!(specifier_checker(flags, str, print)))
		{
			print->i++;
			flags->start = print->i;
			return (0);
		}
		flags->zero = 0;
		flags->precis = 0;
		return (1);
	}
	len = ft_atoi(&str[print->i]);
	flags->precis = len;
    print->i += ft_nbrlen(len);
	return (1);
}

int	specifier_checker(t_flag *flags, const char *str)
{
	if ((flags->sp = ft_strchr_ind(flags->specif, str[print->i]) == -1)
		return (0);
 	return (1);
}