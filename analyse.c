/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 18:11:08 by akovalyo          #+#    #+#             */
/*   Updated: 2020/04/30 13:53:08 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    analyse_flags(t_printf *flags, char *str)
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

void    analyse_asterisk(t_printf *flags, char *str, va_list ap)
{
    if (str[flags->i - 1] == '%' || str[flags->i - 1] == '0' || str[flags->i - 1] == '-')
        asterisk_width(flags, ap);
    if (str[flags->i - 1] == '.')
        asterisk_precis(flags, ap);
    flags->i++;
}

void    analyse_precis(t_printf *flags, char *str)
{

}


void    analyse_width(t_flag *flags, char *str)
{
    int width;

    flags->width = 1;
    width = ft_atoi(&str[flags->i]);
    flags->i += ft_nbrlen(width);
    flags->width_val = width;
}


    /* int precis;
        
    precis = (flags->precis >= 0) ? flags->precis - (int)print->body_len : 0;
    if (print->body_len < flags->width) 
    {
        if (!(flags->minus))
            print->pref_len = flags->width - print->body_len - precis;
        else if (flags->minus)
            print->postf_len = flags->width - print->body_len - precis;
        if (print->x_prefix && !(flags->zero))
            flags->width -= ft_strlen(print->x_prefix);
    }
    if (flags->specf == 'c' || flags->specf == 's')
        print->cmplt = 0;
    if (print->cmplt && flags->zero && print->pref_len > 0)
        print->prefix = '0';
}

void     analyse_sharp(t_flag *flags, t_output *print)
{
    if (flags->xo && flags->specf == 'x')
    {
        if (flags->plus)
            print->x_prefix = ft_strdup("+0x");
        else
            print->x_prefix = ft_strdup("0x");
    }
    else if (flags->xo && flags->specf == 'X')
    {
        if (flags->plus)
            print->x_prefix = ft_strdup("+0X");
        else
            print->x_prefix = ft_strdup("0X");
    }       
    else if (flags->xo && flags->specf == 'o' && print->prefix != '0')
        print->x_prefix = ft_strdup("0");
    if (print->x_prefix)
    {
        if (ft_strlen(print->x_prefix) == 3)
            flags->plus = 0;
    }
}

void    analyse_spplus(t_flag *flags, t_output *print)
{
    if (flags->specf == 'd' || flags->specf == 'i' || flags->specf == 'p')
    {
        if (print->spplus == '-')
        {
            flags->plus = 0;
            return ;
        }
        if (!(flags->plus) && !(flags->width))
        {
            print->spplus = ' ';
            print->count++;
        }
        else if (flags->plus)
        {
            print->spplus = '+';
            if (flags->width > print->body_len)
                print->pref_len--;
            print->count++;
        }
    }
}

void    add_precision(t_flag *flags, t_output *print)
{
    char *precis_part;
    char *tmp;
    int len;

    if ((len = flags->precis - ft_strlen(print->body)))
    {
        tmp = print->body;
        precis_part = ft_strnew(len);
        ft_memset(precis_part, '0', len);
        print->body = ft_strjoin(precis_part, tmp);
        ft_strdel(&tmp);
        ft_strdel(&precis_part);
        print->body_len += len;
    }
    return ;
}

void	analyse_precis(t_flag *flags, t_output *print)
{
	char	*output;
	int		len;

	len = ft_strlen(print->body);
	if (flags->specf == 's' && flags->precis >= 0 && flags->precis < len)
	{
		output = ft_strnew(flags->precis);
		ft_memmove(output, print->body, flags->precis);
		print->body = ft_strdup(output);
		ft_strdel(&output);
	}
    else if (flags->specf == 'f' || flags->specf == 'F')
    {
        print->pref_len = (flags->precis > print->pref_len) ? 0 : print->pref_len - flags->precis;
        print->postf_len = (flags->precis > print->postf_len) ? 0 : print->postf_len - flags->precis;
    }
    else if (flags->precis > 0)
        add_precision(flags, print);
    
} */