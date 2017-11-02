#include <sh.h>

int			init_tab_(t_tab *tab_, int li)
{
	int			len;
	t_file		*tmp;

	len = 0;
	tmp = tab_->file;
	while (tmp)
	{
		len = (ft_strlen(tmp->name) > (size_t)len) ? ft_strlen(tmp->name) : len;
		tmp = tmp->next;
	}
	tab_->len = len + 5;
	if (!tab_->element || !(tab_->co = (tgetco() / tab_->len) * tab_->len))
		return (0);
	tab_->nbr = (tgetco() / tab_->len);
	tab_->li = tgetli();
	tab_->elem_page = (tab_->li - li) * tab_->nbr;
	return (1);
}