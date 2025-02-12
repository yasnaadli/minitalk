#ifndef MINITALK_H
#define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
 
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
void sig_handler(int, siginfo_t *, void *);

#endif
