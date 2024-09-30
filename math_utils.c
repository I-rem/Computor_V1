# include "computor.h"

double  ft_pow(double base, int power)
{
    if (power == 0)
        return 1;
    else
        return base * ft_pow(base, power - 1);
}

int count_digits(int num)
{
        int digits = 1;

        if (num == 0)
                return num;
        return digits + num / 10;
}

double find_initial_guess(double num)
{
        int digits = count_digits(num);
        if (digits % 2 != 0)
                digits++;
        double guess = 2 * ft_pow(10, digits / 2);
    return guess;
}

double  ft_abs(double num)
{
        if (num < 0)
                return -num;
        else
                return num;
}

double  ft_sqrt(double S) // Babylonian square-root algorithm
{
   
        double guess = find_initial_guess(S); 
        while (ft_abs(guess * guess - S) > 0.00001)
                guess = (guess + S / guess) / 2;
    return guess;
}
