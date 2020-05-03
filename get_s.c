/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 10:29:44 by akovalyo          #+#    #+#             */
/*   Updated: 2020/05/02 12:07:49 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void print_width(t_printf *flags, char fill)
{
    while (flags->width_val > 0)
        {
            putchar_count(flags, fill);
            flags->width_val--;
        }
}

void width_s(t_printf *flags, char *str)
{
    if (!flags->print_precis)
        flags->width_val -= flags->s_len;
    print_width(flags, ' ');
    putstr_count(flags, str);   
}

void zero_minus_s(t_printf *flags, char *str)
{
    if (flags->zero && !flags->minus)
    {
        if (!flags->print_precis)
            flags->width_val -= flags->s_len;
        print_width(flags, '0');
        putstr_count(flags, str);
    }
    else if (flags->minus)
    {
        if (!flags->print_precis)
            flags->width_val -= flags->s_len;
        putstr_count(flags, str);
        print_width(flags, ' ');
    }
}

void print_precis_s(t_printf *flags)
{
    while (flags->precis_val > 0)
        {
            putchar_count(flags, ' ');
            flags->precis_val--;
        }
}

void get_s(t_printf *flags, va_list *ap)
{
    char *str;

    str = va_arg(*ap, char *);
    flags->s_len = ft_strlen(str);
    if (flags->precis)
    {
        if (flags->precis_minus && flags->precis_val > 0)
        {
            while (flags->precis_val > 0)
            {
                flags->width_val -= flags->precis_val;
                flags->print_precis = 1;
                return ;
            }
        }
        else if (flags->s_len > flags->precis_val)
            print_precis_s(flags);
    }
    if (flags->width)
        width_s(flags, str);
    else if (flags->zero || flags->minus)
        zero_minus_s(flags, str);
    else
        putstr_count(flags, str);
    clear_flags(flags);
}