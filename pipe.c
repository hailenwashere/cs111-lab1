#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	// TODO: it's all yours
	for (int i = 1; i < argc; i++)
	{
		char* task = argv[i];
		int fds[2];
		if (pipe(fds) < 0){
			exit(errno);
		}
		

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
			exit(errno);
		} else if (pid > 0)
		{
			int status;
			waitpid(pid, &status, 0);
			if (WEXITSTATUS(status) != 0)
			{
				exit(WEXITSTATUS(status));
			}

			close(fds[1]);
			dup2(fds[0], 0);
		} else {
			exit(errno);
		}
	}

	return 0;
}