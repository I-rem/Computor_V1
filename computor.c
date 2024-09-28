#include <math.h> // Need it for sqrt for now will take it out later
#include "computor.h"

int is_operator(char c) // We'll use this figure out the start of new term so no ^ operator
{
        if (c == '-' || c == '+')
                return (1);
        return (0);
}

int find_degree(double *arr)
{
    int i = 2;

        while (arr[i] == 0)
        i--;
    return (i);
}

void solve(int a, int b, int c, int disc)
{
        (void)a;
        (void)b;
        (void)c;
        (void)disc;
        /**
         * int discriminant = find_discriminant(a, b, c);

        If discriminant > 0, then the roots are real and unequal
If discriminant = 0, then the roots are real and equal
If discriminant < 0, then the roots are not real (we get a complex solution)
x1,x2 = (-b +/- sqrt(discriminant)) / 2a
        */

}

void set_coefficent(double *arr, char *term, int end)
{
    int sign = 1;
    //int digit_start = 0;
    double coefficent = 0.0;
//    printf("%s\n", term);
    //printf("%s: %d\n", term, end); 
    for (int i=0; i < end; i++)
    {
        if (is_operator(term[i]))
        {
            if (term[i] == '-')
                sign = -1;
        }
        else if (ft_isdigit(term[i]) && (term[i - 1] != '^'))
        {
            coefficent = strtod(term + i, NULL); // double check this           
            coefficent *= sign;
            //printf("Test: %f\n", coefficent);
            break;
        }
        else if ((term[i] == 'X' || term[i] == 'x'))
        {
            coefficent = sign;
            break;
        }
    }
    printf("%s: %f\n", term, coefficent);
    if (ft_strchr(term, '^'))
        arr[atoi(ft_strchr(term, '^') + 1)] = coefficent;   
    else if (ft_strchr(term, 'x') || ft_strchr(term, 'X'))
        arr[1] = coefficent;
    else if (coefficent != 0.0)
        arr[0] = coefficent;
}

void init_coefficents(double *arr, char *terms)
{

    int i = 0;
    int end = 0;
   // Beginning
        while (terms[i] == ' ' || terms[i] == '\t')
            i++;
        int start = i;
        if (is_operator(terms[i]))
            i++;
        while (terms[i++] && !is_operator(terms[i]))
                end++;
        set_coefficent(arr, terms + start, end);
   // Rest of the terms has to start with operand
        end = 0;
        if (is_operator(terms[i]))
        {
            start = i;
            while (terms[i++] && !is_operator(terms[i]))
                end++;
            set_coefficent(arr, terms + start, end);
        }
        end = 0;
        if (is_operator(terms[i]))
        {
            start = i;
            while (terms[i++] && !is_operator(terms[i]))
                end++;
            set_coefficent(arr, terms + start, end);
        }
}

int main(int argc, char **argv)
{
    (void) argv;
        if (argc != 2)
                error(1, 1, "You need to enter a polynomial equation");
    
    double left_coefficents[3] = {0};
    double right_coefficents[3] = {0};

    init_coefficents(left_coefficents, ft_substr(argv[1], 0, ft_strchr(argv[1], '=')- argv[1]));
    init_coefficents(right_coefficents, ft_strchr(argv[1], '=') + 1);

    double reduced_coefficents[3] = {0};
    for (int i=0; i<3;i++)
    { 
       reduced_coefficents[i] = left_coefficents[i] - right_coefficents[i];
        printf("%f ", reduced_coefficents[i]);
    }
   printf("Polynomial degree: %d", find_degree(reduced_coefficents));
}

