#include "libft.h"

int		ft_printf(char *fmt, ...)
{
	va_list	ap;
	char	*p;
	int		ret;
	t_s		*sp;

	sp = (t_s *)malloc(sizeof(t_s));
	va_start(ap, fmt);
	p = fmt;
	ret = process_specifier_main(sp, p, ap);
	free(sp);
	va_end(ap);
	return (ret);
}
