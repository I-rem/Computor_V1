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

int main(int argc, char **argv)
{
	if (argc != 2)
		error("You need to enter a polynomial equation")
	
	printf("Polynomial degree: %d", find_degree(reduced_form(argv[1])));
	find_disciminant();
}
