#include <sh.h>


static void				reset_process(t_jobs **jobs)
{
	t_process	*process;

	while ((*jobs)->process)
	{
		process = (*jobs)->process;
		(*jobs)->process = (*jobs)->process->next;
		ft_memdel((void **)&process->command);
		ft_memdel((void **)&process);
	}
	ft_memdel((void **)jobs);
}

void				memdel_jobs(t_jobs *jobs)
{
	t_jobs		**addr_jobs;
	t_jobs		*temp;

	addr_jobs = jobs_table();
	temp = *addr_jobs;
	if (*addr_jobs == jobs)
	{
		reset_process(addr_jobs);
		log_debug("On est premier ! %d", *jobs_table() ? 1 : 0);
	}
	else
		while (temp)
		{
			if (temp == jobs)
			{
				if (temp->prev)
					temp->prev->next = temp->next;
				if (temp->next)
					temp->next->prev = temp->prev;
				reset_process(&temp);
				return ;
			}
			temp = temp->next;
		}
}
