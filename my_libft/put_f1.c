#include "libft.h"

int		ft_put_double_help_pl_nsi(double a, t_s *sp)
{
	if (sp->plus && !sp->sign)
		write(1, "+", 1);
	else if (sp->backsp && !sp->sign)
		write(1, " ", 1);
	if (sp->sign)
		write(1, "-", 1);
	return ((sp->plus || sp->backsp || sp->sign) + ft_put_f_double(a, sp));
}

int		ft_put_double_set_k(t_s *sp, int dig)
{
	int	n;

	n = dig + (sp->plus || sp->backsp || sp->sign);
	if (sp->decim > 0)
		n += sp->decim + 1;
	if (sp->hash && sp->decim == 0)
		n += 1;
	return (n);
}

void	ft_put_double_help_pl_mi(double a, t_s *sp, int k)
{
	if (sp->sign)
		write(1, "-", 1);
	else
		write(1, "+", 1);
	ft_put_f_double(a, sp);
	ft_put_n_chars(32, k);
}

void	ft_put_double_help_pl_nsi_ze(double a, t_s *sp, int k)
{
	write(1, "+", 1);
	ft_put_n_chars(48, k);
	ft_put_f_double(a, sp);
}

void	ft_put_double_help_pl_nsi2(double a, t_s *sp, int k)
{
	ft_put_n_chars(32, k);
	write(1, "+", 1);
	ft_put_f_double(a, sp);
}
