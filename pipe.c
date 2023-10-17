#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// void pipe_recurse(char *args, int curr_arg)
// {
// 	if (args[curr_arg + 1] == NULL)
// 	{
// 		return;
// 	}
// 	int pid = fork();
// 	if (pid == 0)
// 	{
// 		pipe_recurse
// 	}
// 	// parent executes first arg
// }

int main(int argc, char *argv[])
{
	// TODO: it's all yours
	for (int i = 1; i < argc; i++)
	{
		char* task = argv[i];
		int fds[2];
		// int old_fds[2];
		pipe(fds);
		// old_fds[0] = fds[0];
		// old_fds[1] = fds[1];

		// child process
		int pid = fork();
		if (pid == 0) 
		{
			close(fds[0]);
			if (i != argc - 1)
			{
				dup2(fds[1], 1);
			}
			execlp(task, task, NULL);
		} else if (pid > 0)
		{
			int status;
			waitpid(pid, &status, 0);
			close(fds[1]);
			dup2(fds[0], 0);
		} else {
			perror("failure to fork");
		}
	}

	return 0;
}