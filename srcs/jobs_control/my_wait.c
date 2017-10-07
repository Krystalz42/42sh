//
// Created by Alexandre ROULIN on 10/6/17.
//

#include <sh.h>

void		my_wait(pid_t child, bool foreground)
{
	int			status;


	setpgid(child, child);
	log_debug("setpgid(%d, %d)", child, child);
	if (foreground)
	{
		log_info("Child [%d] in foreground", child);
		jobs_control(NEW_CHILD_FG, child, 0, 0);
		if ((waitpid(child, &status, WUNTRACED | WCONTINUED)) != -1)
		{
			log_info("Child [%d] will be update", child);
			jobs_control(UPDATE_CHILD, child, status, 0);
		}
		else
		{
			log_error("Waitpid return -1 nothing to do");
		}
	}
	else
	{
		if ((waitpid(child, &status, WUNTRACED | WNOHANG)) != -1)
		{
			log_info("Child [%d] in background", child);
			jobs_control(NEW_CHILD_BG, child, status, 0);
		}

	}
}