#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "minitalk.h"

void sig_handler(int sig, siginfo_t *info, void *context)
{ 
    static int bit = 0;
    static char death = 0;
    static pid_t client_corpse =0;

    (void)sig;
    (void)context;
    if (!client_corpse)
    client_corpse = info ->si_pid;

    death |= (sig == SIGUSR2) <<bit;
    bit++;

    if (bit==8)
    {
    if ( death == '\0') 
    {
    ft_putchar_fd('\n', 1);
    kill(client_corpse, SIGUSR2);
    client_corpse =0; 
    }  

else 
        {
    ft_putchar_fd(death, 1);
    kill(client_corpse, SIGUSR1);
        }
bit = 0; 
death = 0;
    }
}   

int main(void)
{
    struct sigaction sa0;
    struct sigaction sa1;

    ft_putstr_fd(" Your servers PID is:", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putchar_fd( '\n', 1);

    sa0.sa_sigaction = sig_handler;
    sa0.sa_flags = SA_SIGINFO;
    sa1.sa_sigaction = sig_handler;
    sa1.sa_flags = SA_SIGINFO; 
    sigaction(SIGUSR1, &sa0, NULL);
    sigaction(SIGUSR2, &sa1, NULL);
    while(1)
    pause();
    return(0);
}
