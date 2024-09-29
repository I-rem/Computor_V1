#include "computor.h"

int is_operator(char c) // We'll use this figure out the start of new term, so no ^ operator
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

void solve(double *arr)
{
    double discriminant = arr[1]*arr[1]-4*arr[2]*arr[0];

    if (find_degree(arr) == 0 && arr[0] == 0)
        printf("Each real number is a solution for this equation\n");
    else if (find_degree(arr) == 0 && arr[0] != 0)
        error(1, 0, "False equation\n");
    else if (find_degree(arr) == 1)
        printf ("The solution is: %f\n", -arr[0]/arr[1]);
    else if (discriminant < 0)
        printf("The discriminant is negative, the roots are not real.\n");
    else if (discriminant > 0)
        printf ("The discriminant is positive, the roots are real and unequal:\nX1 = %f\nX2 = %f\n",
                (-arr[1] + ft_sqrt(discriminant)) / 2*arr[2], (-arr[1] - ft_sqrt(discriminant)) / 2*arr[2]);
    else
        printf("The roots are real and equal: X1 = X2 = %f\n", (-arr[1] + ft_sqrt(discriminant)) / 2*arr[2]);
}

void set_coefficent(double *arr, char *term, int end)
{
    int sign = 1;
    double coefficent = 0.0;
 
    for (int i=0; i < end; i++)
    {
        if (is_operator(term[i]))
        {
            if (term[i] == '-')
                sign = -1;
        }
        else if (ft_isdigit(term[i]) && (term[i - 1] != '^'))
        {
            coefficent = strtod(term + i, NULL); // double-check this           
            coefficent *= sign;
            break;
        }
        else if ((term[i] == 'X' || term[i] == 'x'))
        {
            coefficent = sign;
            break;
        }
    }
    if (ft_strchr(term, '^'))
        arr[atoi(ft_strchr(term, '^') + 1)] = coefficent; // To do: add error handling for degrees higher than 2 here  
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
        {
            end++;
            i++;
        }
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
            set_coefficent(arr, terms + start, end); // Do we need a +1 for end?
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

void syntax_check(int argc, char **argv)
{
    if (argc != 2)
        error(1, 0, "Enter a polynomial equation as a single argument\n");
    if (!ft_strchr(argv[1], '='))
        error(1, 0, "You need to enter an equation\n");
    for (int i = 0; argv[1][i]; i++)
    {
        if (ft_isalpha(argv[1][i]))
            if (argv[1][i] != 'x' && argv[1][i] != 'X')
                error(1, 0, "Improper form\n");
    }    
}

int main(int argc, char **argv)
{
    syntax_check(argc, argv);

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
    //To do: print reduced form
   solve(reduced_coefficents);
   printf("Polynomial degree: %d\n", find_degree(reduced_coefficents));
}
