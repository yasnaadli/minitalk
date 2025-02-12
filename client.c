#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "minitalk.h"

void send_char(pid_t server_pid, char c)
{
int bit;
int kill_result;

bit =7;
while (bit >=0)
{
    if((c >> bit) & 1 )
    kill_result = kill( server_pid, SIGUSR2);
    else
    kill_result = kill (server_pid, SIGUSR1);
    if( kill_result == -1)
    { 
    error_messaage("ohno. Error:failed to send signal.\n");
    exit(EXIT_FAILURE);
    }
    usleep(100);
    bit--; 
}
}
void send_message(pid_t server_pid, char *message)
{
    while (*message)
    {
    send_char(server_pid, *message);
    message++; 
    }
    send_char(server_pid, '\0');
}
void error_message(char *msg)
{
    ft_putstr_fd(msg, 2);
}
int main (int argc, char **argv)
{
    {
        pid_t server_pid;
        char *message;
        if (argc != 3 || !argv[2][0])
        {
            error_message("Usage: ./client <server_pid> <message>\n");
            return (1);
        }

        server_pid = ft_atoi(argv[1]);
        if (server_pid <= 0)
        {
            error_message("ohno error, PID is invalid.\n");
            return (1);
        }
        message = argv[2];
        send_message(server_pid, message);
        while (1)
            pause();
    
        return (0);
    }
}
