#ifndef COMPUTOR_H
#define COMPUTOR_H

# include <stdio.h>
# include <error.h>
# include <stdlib.h>
// consider linked lists for bonus
double  ft_pow(double base, int power);
int count_digits(int num);
double find_initial_guess(double num);
double  ft_abs(double num);
double  ft_sqrt(double S);

int ft_isdigit(int c);
int     ft_isalpha(int c);
size_t  ft_strlen(const char *s);
char    *ft_strchr(const char *s, int c);
char    *ft_substr(char const *s, unsigned int start, size_t len);
double  ft_pow(double base, int power);
double  ft_sqrt(double num);
int is_operator(char c);
int find_degree(double *arr);
#endif
