#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
    const char	*s11;
    const char	*s22;

    s11 = s1;
    s22 = s2;
    while (*s11 && (*s11 == *s22))
    {
        s11++;
        s22++;
    }
    return (*(unsigned char *)s11 - *(unsigned char *)s22);
}