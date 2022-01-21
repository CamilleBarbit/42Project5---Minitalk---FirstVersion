/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:41:52 by cbarbit           #+#    #+#             */
/*   Updated: 2022/01/21 12:30:55 by cbarbit          ###   ########.fr       */
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


void    ft_handle_signals(int signum, siginfo_t *info, void *useless)
{
    static int  i; //le i correspond au nombre de signaux que je vais recevoir.

    i = 0;
    while (i <= 32)
    {
        //je dois envoyer dans une autre fonction qui va modifier le signal recu et stocker les 32 premiers bits dans un int
    }
}

void    binary_to_int(int signum)
{
    
}
// void    ft_handle_signals(int signum, siginfo_t *info, void *useless)
// {
//     static int  i;
//     static int  j;
//     static char str[100000];
//     (void)info; //je n'utilise pas ce parametre
//     (void)useless; //je n'utilise pas ce parametre

//     if (i = 0)
//         str[j] = '\0';
//     if (i < 8)
//     {
//         str[j] = str[j] << 1;
//         if (signum == SIGUSR2)
//             str[j] = str[j] + 1;
//         if (signum == SIGUSR1)
//             str[j] = str[j] + 0;
//         i++;
//     }
//     if (i == 8)
//     {
//         if (!str[j] || j = 99999)
//         {
//             write(1, str, j);
//             str[0] = '\0';
//             i = 0;
//             j = 0;
//             return ;
//         }
//         i = 0;
//         j++;
//     }
// }

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
