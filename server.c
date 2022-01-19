/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:41:52 by cbarbit           #+#    #+#             */
/*   Updated: 2022/01/19 15:57:23 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Le premier élément à prendre en compte est le fait que le serveur, une fois lancé, doit afficher son PID.
Le PID est un code unique attibué à tout processus lors de son démarrage. Pour pouvoir afficher le PID du processus serveur,
il faut faire appel à la fonction getpid() - elle est définie dans <unistd.h>.
La fonction getpid() est prototypée ainsi: pid_t getpid(void).
Pid_t est un type de variables (qui correspond au 'process IDs'), défini dans #include <sys/types.h>.

Une fois que j'ai récupéré le PID du processus serveur, je dois l'afficher dans la sortie standard.
J'ai deux options: soit je transforme le PID (qui est un nombre) en char via la fonction ITOA, ou je l'affiche via la fonction PUTNBR.
*/

void    ft_handle_signals(int signum, siginfo_t *info, void *notuseful)
{
    static int  i;
    static int  j;
    static char str[100000];
    (void)info; //je n'utilise pas ce parametre
    (void)notuseful; //je n'utilise pas ce parametre

    if (i = 0)
        s[j] = '\0';
    if (i < 8)
    {
        s[j] = s[j] << 1;
        if (signum == SIGUSR2)
            s[j] = s[j] + 1;
        if (signum == SIGUSR1)
            s[j] = s[j] + 0;
        i++;
    }
    if (i == 8)
    {
        if (!s[j] || j = 99999)
        {
            write(1, s, j);
            s[0] = '\0';
            i = 0;
            j = 0;
            return ;
        }
        i = 0;
        j++;
    }
}

int main()
{
    struct sigaction    sa;
    sa.sa_sigaction = ft_handle_signals; //sa_sigaction est defini dans la structure sigaction.
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    printf("The server's PID is the following: %d", getpid()); //j'affiche le PID du server!
    while(1)//mon programme doit tourner en boucle
    {

    }
    return (0);
}
