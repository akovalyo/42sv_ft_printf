/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 10:50:01 by akovalyo          #+#    #+#             */
/*   Updated: 2020/04/03 13:15:49 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	format_checker(t_flag *flags, const char *str, t_output *print)
{
	init_flags(flags, print->i);
	while (flag_checker(flags, str, print))
		print->i++;
	width_checker(flags, str, print);
    if (str[print->i] == '.' && !(precis_checker(flags, str, print)))
		return (0);
	while (length_checker(flags, str, print))
        print->i++;
	if (specifier_checker(flags, str, print))
	{
		print->i++;
		return (1);
	}
	while (flags->start <= print->i)
	{
		ft_putchar(str[flags->start]);
		(flags->start)++;
		print->count++;
	}
	print->i++;
	return (0);
}

int	length_checker(t_flag *flags, const char *str, t_output *print)
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

int	flag_checker(t_flag *flags, const char *str, t_output *print)
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

void	width_checker(t_flag *flags, const char *str, t_output *print)
{
	int width;

	width = 0;
	if ((width = ft_atoi(&str[print->i])) > 0)
	{
		flags->width = width;
        print->i += ft_nbrlen(width);
	}
}

int 	precis_checker(t_flag *flags, const char *str, t_output *print)
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
		return (1);
	}
	len = ft_atoi(&str[print->i]);
	flags->precis = len;
    print->i += ft_nbrlen(len);
	return (1);
}

int	specifier_checker(t_flag *flags, const char *str, t_output *print)
{
	char 	specif[13];

	ft_bzero(specif, 13);
	ft_strcpy(specif, "diucspxXofF%"); 
	if (!ft_strchr(specif, str[print->i]))
		return (0);
	flags->specf = str[print->i];
 	return (1);
}