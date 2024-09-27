# include <stdio.h>
# include <error.h>

int is_operator(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int find_degree(char *argv)
{
	int	degree = 0;

	while (*argv)
	{
		if (*argv == '^')
			if (*(argv + 1) > degree)
				degree = *(argv + 1)
		argv++	
	}
	return (degree);
}

char *reduced_form(char *equation)
{
	char *lhs;
	char *rhs;
	char *reduced;

	printf("Reduced form: %s", reduced);
}

void parse(char *reduced)
{
	int	a;
	int	b;
	int	c;

	solve((a, b, c);
}

void solve(int disc)
{
	int discriminant = find_discriminant(a, b, c);

	If discriminant > 0, then the roots are real and unequal
If discriminant = 0, then the roots are real and equal
If discriminant < 0, then the roots are not real (we get a complex solution)
x1,x2 = (-b +/- sqrt(discriminant)) / 2a
}

int main(int argc, char **argv)
{
	if (argc != 2)
		error("You need to enter a polynomial equation")
	
	printf("Polynomial degree: %d", find_degree(reduced_form(argv[1])));
}
