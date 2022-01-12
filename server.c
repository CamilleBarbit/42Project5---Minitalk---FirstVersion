/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:41:52 by cbarbit           #+#    #+#             */
/*   Updated: 2022/01/12 15:30:55 by cbarbit          ###   ########.fr       */
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

//première option
void    get_server_pid(void)
{
    pid_t   pid;
    char    *str_pid;

    pid = getpid();
    str_pid = itoa(pid);
    ft_putendel_fd(str_pid, 1); //je l'affiche dans stdout
    free(str_pid); //toute mémoi allouée doit être free
}

//deuxième option
void   get_server_pid(void)
{
    pid_t   pid;

    pid = getpid();
    ft_putnbr_fd(pid, 1); //je l'affiche dans stdout sans allouer de mémoire
}

//troisieme option
void   get_server_pid(void)
{
    ft_putnbr_fd(getpid(), 1); //je l'affiche dans stdout sans allouer de mémoire
}

int main()
{
    
    while(1)
    {

    }
}
