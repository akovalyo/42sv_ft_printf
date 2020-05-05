/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 10:50:01 by akovalyo          #+#    #+#             */
/*   Updated: 2020/05/05 09:55:01 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	format_checker(t_printf *flags, const char *str, va_list *ap)
{
	while (str[flags->i] && (str[flags->i] == '-' || str[flags->i] == '*' ||
			(str[flags->i] >= '0' && str[flags->i] <= '9') || str[flags->i] == '.'))
	{
		if (str[flags->i] == '-' || (str[flags->i] == '0' && str[flags->i - 1] == '%'))
			analyse_flags(flags, str);
		if (str[flags->i] == '*')
			analyse_asterisk(flags, str, ap);
		if (str[flags->i] >= '1' && str[flags->i] <= '9')
			analyse_width(flags, str);
		if (str[flags->i] == '.')
			analyse_precis(flags, str);
	}
}

int	specifier_checker(t_printf *flags, const char *str)
{
	if ((flags->sp = ft_strchr_ind(flags->specif, str[flags->i])) == 10)
		return (0);
 	return (1);
}