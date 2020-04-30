/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalyo <al.kovalyov@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 10:43:46 by akovalyo          #+#    #+#             */
/*   Updated: 2020/04/06 13:32:15 by akovalyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    print_pre_post(char ch, int len, t_output *print)
{
    int i;

    i = print->x_correct;
    if (print->spplus == '+' || print->spplus == '-' && ((i >= len && ch == ' ') || (i < len && ch == '0')))
    {
        ft_putchar(print->spplus);
        print->spplus = 0;
    }
    while (i < len)
    {
        ft_putchar(ch);
        i++;
    }
    if (print->spplus == '+' || print->spplus == '-')
    {
        ft_putchar(print->spplus);
        print->spplus = 0;
    }  
}

void    print_oxp(t_flag *flags, t_output *print)
{
    if ((print->pref_len || print->postf_len) && print->x_prefix)
        print->x_correct = ft_strlen(print->x_prefix);
    if (print->pref_len && print->prefix == ' ')
    {
        print_pre_post(print->prefix, print->pref_len, print);
        ft_putstr(print->x_prefix);
    }
    else
    {
        if (print->x_prefix)
            ft_putstr(print->x_prefix);
        print_pre_post(print->prefix, print->pref_len, print);
    }
    (flags->precis == 0 && print->body[0] == '0') ? print->count -= 1 : ft_putstr(print->body);
    print_pre_post(print->postf, print->postf_len, print);
    if (print->x_prefix)
        print->count += ft_strlen(print->x_prefix);
    print->count += print->body_len + print->pref_len + print->postf_len - print->x_correct;
}

void    print_output(t_flag *flags, t_output *print)
{
    if (flags->sharp || flags->specf == 'p')
    {
        print_oxp(flags, print);
        return ;
    }
    if (print->spplus == ' ')
        ft_putchar(print->spplus);
    print_pre_post(print->prefix, print->pref_len, print);
    if (print->x_prefix)
        ft_putstr(print->x_prefix);
    (flags->precis == 0 && print->body[0] == '0') ? print->count -= 1 : ft_putstr(print->body);
    print_pre_post(print->postf, print->postf_len, print);
    print->count += print->body_len + print->pref_len + print->postf_len;
}

void    free_print(t_output *print)
{
    if (print->free)
        ft_strdel(&(print->body));
    if (print->x_prefix)   
        ft_strdel(&(print->x_prefix));
}

void	edit_output(t_flag *flags, t_output *print)
{
    analyse_width(flags, print);
    if (flags->precis >= 0)
        analyse_precis(flags, print);
    if  (flags->sharp)
        analyse_sharp(flags, print);
    if (flags->plus || flags->space)
        analyse_spplus(flags, print);
    print_output(flags, print);
    free_print(print);
}