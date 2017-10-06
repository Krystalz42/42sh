//
// Created by Alexandre ROULIN on 10/6/17.
//

#include <sh.h>

void		my_wait(pid_t child, bool foreground)
{
	int			status;
	int 		test;

	log_debug("setpgid(%d, %d)", child, child);
//	setpgid(child, child);
	if (foreground)
	{
		log_info("Child [%d] in foreground", child);
		jobs_control(NEW_CHILD_FG, child, 0, 0);
		if ((test = waitpid(child, &status, WUNTRACED | WCONTINUED)) != -1)
		{
			log_info("child_pid return [%d]", test);
			log_info("Child [%d] will be update", child);
			jobs_control(UPDATE_CHILD, child, status, 0);
		}
	}
	else
	{
		log_info("Child [%d] in background", child);
		jobs_control(NEW_CHILD_BG, child, 0, 0);
		if ((waitpid(child, &status, WNOHANG)) != -1)
		{
			log_info("Child [%d] will be continued", child);
		}
	}
}