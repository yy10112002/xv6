#include "types.h"
#include "user.h"

#define WNOHANG 1

int main(void)
{
    int ret_pid, exit_status;
    int pid_one = 0, pid_two = 0;

    pid_one = fork();
    if (pid_one == 0)
    {
        printf(1, "\n Son with PID: %d, status of exit: %d\n", getpid(), getpid() + 1);
        exit(getpid() + 1);
    }
    pid_two = fork();
    if (pid_two == 0)
    { 
        printf(1, "\n Son with PID: %d, status of exit: %d\n", getpid(), getpid() + 1);
        exit(getpid() + 1);
    }


    sleep(5);
    printf(1, "\n This is the parent: Now waiting for child with PID# %d\n", pid_one);
    ret_pid = waitpid(pid_one, &exit_status, 0);
    printf(1, "\n This is the parent: Child# %d has exited with status %d\n", ret_pid, exit_status);
    sleep(5);
    printf(1, "\n This is the parent: Now waiting for child with PID# %d\n", pid_two);
    ret_pid = waitpid(pid_two, &exit_status, 0);
    printf(1, "\n This is the parent: Child# %d has exited with status %d\n", ret_pid, exit_status);
    sleep(5);
    return 0;
}