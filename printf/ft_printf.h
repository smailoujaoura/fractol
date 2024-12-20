/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:28:04 by soujaour          #+#    #+#             */
/*   Updated: 2024/11/14 22:51:34 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *formated_string, ...);
int		count_printed_chars(int start);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	write_hex(unsigned int ui, char cases);
void	print_string(char *str);
void	print_integer(int i, int *flag);
void	print_char(char c);
void	print_pointer(void *ptr);
void	print_unsinged(unsigned int ui);
void	print_hex(unsigned int i, char cases, int *flag);

#endif