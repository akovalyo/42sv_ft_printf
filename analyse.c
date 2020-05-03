/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 18:11:08 by akovalyo          #+#    #+#             */
/*   Updated: 2020/05/03 16:37:01 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    analyse_flags(t_printf *flags, const char *str)
{
    if (str[flags->i] == '0')
    {
        flags->zero = 1;
        flags->i++;
    }
    if (str[flags->i] == '-')
    {
        flags->minus = 1;
        flags->i++;
    }
    while (str[flags->i] && str[flags->i] == '0')
        flags->i++;
}

void    analyse_asterisk(t_printf *flags, const char *str, va_list *ap)
{
    if (str[flags->i - 1] == '%' || str[flags->i - 1] == '0' || str[flags->i - 1] == '-')
        asterisk_width(flags, ap);
    if (str[flags->i - 1] == '.')
        asterisk_precis(flags, ap);
    flags->i++;
}

void    analyse_precis(t_printf *flags, const char *str)
{
    int len;

    flags->precis = 1;
    flags->i++;
    while (str[flags->i] == '-')
    {
        flags->precis_minus = 1;
        flags->i++;
    }
    if (str[flags->i] == '0')
    {
        while (str[flags->i] == '0')
            flags->i++;
        flags->precis_val = 0;  
    }
    len = ft_atoi(&str[flags->i]);
    if (str[flags->i] >= '0' && str[flags->i] <= '9') 
        flags->i += ft_nbrlen(len);
    flags->precis_val = len;
}


void    analyse_width(t_printf *flags, const char *str)
{
    int width;

    flags->width = 1;
    width = ft_atoi(&str[flags->i]);
    flags->i += ft_nbrlen(width);
    flags->width_val = width;
}

void    asterisk_width(t_printf *flags, va_list *ap)
{
    flags->width = 1;
    flags->width_val = va_arg(*ap, int);
    if (flags->width_val < 0)
    {
        flags->minus = 1;
        flags->width_val = -flags->width_val;
    }
}

void    asterisk_precis(t_printf *flags, va_list *ap)
{
    flags->precis = 1;
    flags->precis_val = va_arg(*ap, int);
    if (flags->precis_val < 0)
        flags->precis = 0;
}
