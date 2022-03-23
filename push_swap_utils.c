#include "push_swap.h"

int     error(const char *message)
{
    if (!message)
        return (0);
    write(2, message, ft_strlen(message));
    return (0);
}
