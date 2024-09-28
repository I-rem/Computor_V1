#include <math.h> // Need it for sqrt for now will take it out later
#include "computor.h"

int is_operator(char c)
{
        if (c == '-' || c == '+')
                return (1);
        return (0);
}

int find_degree(char *argv)
{
        int     degree = 0;

        while (*argv)
        {
                if (*argv == '^')
                        if (*(argv + 1) > degree)
                                degree = *(argv + 1);
                argv++;
        }
        return (degree);
}

char *reduced_form(char *equation)
{
        //(void) *equation;
        //char *lhs;
        //char *rhs;
        //char *reduced;

        //printf("Reduced form: %s", reduced);
    return equation;
}

void solve(int a, int b, int c, int disc);
void parse(char *reduced)
{
        int     a;
        int     b;
        int     c;
    (void)a;
        (void)b;
        (void)c;
        (void)reduced;
    
        //solve(a, b, c, disc);
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

void init_coefficents(double *arr, char *term)
{
   // int exponent_pos = 0;
   (void) arr;
    (void) term;
    printf("%s\n", term);
}

int main(int argc, char **argv)
{
    (void) argv;
        if (argc != 2)
                error(1, 1, "You need to enter a polynomial equation");
    
    double left_coefficents[3] = {0};
    double right_coefficents[3] = {0};

    init_coefficents(left_coefficents, ft_substr(argv[1], 0, argv[1] + ft_strlen(argv[1]) - ft_strchr(argv[1], '=') - 1));
    init_coefficents(right_coefficents, ft_strchr(argv[1], '=') + 1);
        //printf("Polynomial degree: %d", find_degree(reduced_form(argv[1])));
}
