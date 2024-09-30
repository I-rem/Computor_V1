# include "computor.h"

int     ft_isalpha(int c)
{
        if ((c >= 'A' && c <= 'Z')
                || (c >= 'a' && c <= 'z'))
                return (1);
        return (0);
}

int is_operator(char c) // We'll use this figure out the start of new term, so no ^ operator
{
        if (c == '-' || c == '+')
                return (1);
        return (0);
}

int     ft_isdigit(int c)
{
        if (c >= '0' && c <= '9')
                return (1);
        return (0);
}

size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i] != '\0')
                i++;
        return (i);
}

char    *ft_strchr(const char *s, int c)
{
        int             i;

        i = 0;
        while (s[i] != (char)c && s[i] != '\0')
                i++;
        if (s[i] == (char)c)
                return ((char *)s + i);
        return (NULL);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        size_t  i;
        char    *substr;

        i = 0;
        if (!s)
                return (NULL);
        if ((size_t)start > ft_strlen(s))
        {
                substr = malloc(sizeof(char) * 1);
                if (!substr)
                        return (NULL);
                substr[0] = '\0';
                return (substr);
        }
        if (len <= ft_strlen(s))
                substr = malloc(sizeof(char) * (len + 1));
        else
                substr = malloc(sizeof(char) *(ft_strlen(s) + 1));
        if (!substr)
                return (NULL);
        while ((char)s[start] != '\0' && i < len)
                substr[i++] = (char)s[start++];
        substr[i] = '\0';
        return (substr);
}
