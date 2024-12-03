#include "computor.h"

int find_degree(double *arr, char *str, int size)
{
    int i = 0;

        if (arr)
    {
        i = size;
        while ((int)arr[i] == 0)
            i--;
    }
    else if (!ft_strchr(str, '^'))
        if (ft_strchr(str, 'X') || ft_strchr(str,'x'))
            i = 1;
    while (str && *str)
    {
        if (*str == '^')
        {
            str++;
            if (str && *str && atoi(str) > i)
                i = atoi(str);
        }
        str++;
    }
    return (i);
}

void print_reduced(double *arr, int degree)
{
        int i = degree;
        printf("Reduced form: ");

         while (i >= 0)
        {
                if (i == 0) // Constant
        {
            if (degree > 0 && arr[i] > 0)
                printf("+");
            if (degree == 0 || (degree != 0 && arr[i] > 0))
                            printf("%.1f", arr[i]);
        }
                else if (arr[i] > 0 || arr[i] < 0) // != 0
                {
                        if ((arr[i] > 1 || arr[i] < 1) && (arr[i] > -1 || arr[i] < -1))
                        {
                                //if ((int)arr[i] > 0 && i != degree)
                                if (arr[i] > 0) 
                                        printf("+");
                                printf("%.1f", arr[i]);
                        }
                        else if ((int)arr[i] == -1)
                                printf("-");
                        else if (i != degree && (int)arr[i] == 1)
                                printf("+");
                        printf("X");
                        if (i != 1)
                                printf("^%d", i);
                        printf(" ");
                }
        i--;
        }
        if (degree < 0)
            printf("0");
        printf(" = 0\n");
}

void solve(double *arr, int size)
{
    double discriminant = arr[1]*arr[1]-4*arr[2]*arr[0];

    if (find_degree(arr, NULL, size) < 0 || (find_degree(arr, NULL, size) == 0 && (int)arr[0] == 0))
        printf("Each real number is a solution for this equation\n");
    else if (find_degree(arr, NULL, size) == 0 && (int)arr[0] != 0)
        error(1, 0, "False equation\n");
    else if (find_degree(arr, NULL, size) == 1)
        printf ("The solution is: %.1f\n", -arr[0]/arr[1]);
    else if ((int)discriminant < 0)
        {
                printf("The discriminant is negative, there are no real roots.\nThe complex solution is:\n");
        printf("X1 = %.1f + %.1fi\nX2 = %.1f - %.1fi\n", -arr[1] / 2*arr[2], ft_sqrt(discriminant) / 2*arr[2], -arr[1] / 2*arr[2], ft_sqrt(discriminant) / 2*arr[2]);
        }
        else if ((int)discriminant > 0)
        printf ("The discriminant is positive, the roots are real and unequal:\nX1 = %.1f\nX2 = %.1f\n",
                (-arr[1] + ft_sqrt(discriminant)) / (2*arr[2]), (-arr[1] - ft_sqrt(discriminant)) / (2*arr[2]));
    else
        printf("The discriminant is zero, the roots are real and equal: X1 = X2 = %.1f\n", ((-arr[1] + ft_sqrt(discriminant)) / (2*arr[2])));
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

    int size = find_degree(NULL, argv[1], 0) + 1; // After finding the reduced form we'll double check the degree
    double left_coefficents[size];
    double right_coefficents[size];
    int degree;

    init_coefficents(left_coefficents, ft_substr(argv[1], 0, ft_strchr(argv[1], '=')- argv[1]));
    init_coefficents(right_coefficents, ft_strchr(argv[1], '=') + 1);

    double reduced_coefficents[size];
    for (int i=0; i<size; i++)
        reduced_coefficents[i] = left_coefficents[i] - right_coefficents[i];
    
    degree = find_degree(reduced_coefficents, NULL, size - 1);
    print_reduced(reduced_coefficents, degree);
    if (degree <= 2)
        solve(reduced_coefficents, size - 1);
    if (degree < 0)
        printf("Polynomial degree: undefined\n");
    else
        printf("Polynomial degree: %d\n", degree);
    if (degree > 2)
        printf("Degree higher than 2, I can't solve\n");
}
