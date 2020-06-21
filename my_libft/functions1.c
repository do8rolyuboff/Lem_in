#include "libft.h"

void	ft_put_zeros_backsp(t_s *sp)
{
	if (sp->numb > 1)
	{
		if (sp->zero)
			ft_put_n_chars(48, sp->numb - 1);
		else
			ft_put_n_chars(32, sp->numb - 1);
	}
	else
		sp->numb = 1;
}

int		ft_putchar_c(char c, t_s *sp)
{
	if (sp->minus)
	{
		write(1, &c, 1);
		ft_put_zeros_backsp(sp);
	}
	else
	{
		ft_put_zeros_backsp(sp);
		write(1, &c, 1);
	}
	return (sp->numb);
}
