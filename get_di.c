/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 08:49:49 by akovalyo          #+#    #+#             */
/*   Updated: 2020/05/04 11:01:51 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int precis_di(t_printf *flags, char *str)
{
    if (flags->precis_minus && flags->precis_val > 0)
    {
        putstr_count(flags, str);
        while (flags->precis_val > flags->s_len)
        {
            putchar_count(flags, ' ');
            flags->precis_val--;
            return (1);
        }
    }
    else if ((flags->s_len - flags->dig_minus) < flags->precis_val)
    {
        flags->precis_val = flags->precis_val - flags->s_len + flags->dig_minus;
        flags->width_val = flags->width_val - flags->s_len - flags->precis_val;
        flags->print_precis  = 1; 
    }
    return (0);
}

void width_di(t_printf *flags, char *str)
{
    if (!flags->precis)
        flags->width_val -= flags->s_len;
    if (flags->print_precis && flags->precis_val == 0 && str[0] == '0'
                && !flags->print_precis)
        flags->width_val++;
    print_width(flags, ' ');
    if (flags->dig_minus)
        putchar_count(flags, '-');
    if (flags->print_precis)
        print_precis_di(flags);
    if (flags->dig_minus)
        putstr_count(flags, &str[1]);
    else
        putstr_count(flags, str);
}

void zero_di(t_printf *flags, char *str)
{
    if (!flags->print_precis)
        flags->width_val -= flags->s_len;
    if (flags->precis && flags->precis_val == 0 && str[0] == '0'
                && !flags->print_precis)
        flags->width_val++;
    if (flags->precis)
    {
        print_width(flags, ' ');
        if (flags->dig_minus)
            putchar_count(flags, '-');
        if (flags->print_precis)
            print_precis_di(flags);
    }
    else
    {
        if (flags->dig_minus)
            putchar_count(flags, '-');
        print_width(flags, '0');
    }
    if (flags->dig_minus)
        putstr_count(flags, &str[1]);
    else
        putstr_count(flags, str);
}

void minus_di(t_printf *flags, char *str)
{
    if (!flags->print_precis)
        flags->width_val -= flags->s_len;
    if (flags->precis && flags->precis_val == 0 && str[0] == '0'
                && !flags->print_precis)
        flags->width_val++;
    if (flags->dig_minus)
        putchar_count(flags, '-');
    if (flags->print_precis)
        print_precis_di(flags);
    putstr_count(flags, str);
    print_width(flags, ' ');
}

void get_di(t_printf *flags, va_list *ap)
{
    char *str;

    str = ft_itoa(va_arg(*ap, int));
    flags->dig_minus = (str[0] == '-') ? 1 : 0;
    flags->s_len = ft_strlen(str);
    if (flags->precis && precis_di(flags, str))
        return ;
    if (flags->width)
        width_di(flags, str);
    else if (flags->zero && !flags->minus)
        zero_di(flags, str);
    else if (flags->minus)
        minus_di(flags, str);
    else
    {
        if (flags->dig_minus)
            putchar_count(flags, '-');
        if (flags->precis)
            print_precis_di(flags);
        if (flags->dig_minus)
            putstr_count(flags, &str[1]);
        else
            putstr_count(flags, str);
    }
    ft_strdel(&str);
    clear_flags(flags);    
}