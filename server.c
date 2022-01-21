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

void    binary_to_int(int signum, i)
{
    static int  len = 0;

    if (i < 32)
    {
        len = len << 1; 
        if (signum == SIGUSR1)
            len = len + 0;
        if (signum == SIGUSR2)
            len = len + 1;
    }
    if (i == 31)
    {
        str = malloc(sizeof(char) * (len + 1));
        if (!str)
            return ;
        ft_memset(str, 0, len); //je mets des \0 dans ma string pour que ca soit propre.
    }
}
   

void    binary_to_char(int signum, int bit, int index)
{
    if (bit < 7)
    {
        str[index] = str[index] << 1; //dans cette partie je traduis mon char en binaire
        if (signum == SIGUSR2)
            str[index] = str[index] + 1;
        if (signum == SIGUSR1)
            str[index] = str[index] + 0;
    }
}

unsigned char   *str = NULL; //je cree une variable globale dans laquelle je stocke tous mes chars.

void    ft_handle_signals(int signum, siginfo_t *info, void *useless)
{
    static int  i = 0; //le i correspond au nombre de signaux que je vais recevoir.

    if (i < 32)
        binary_to_int(signum, i);//je dois envoyer dans une autre fonction qui va modifier le signal recu et stocker les 32 premiers bits dans un int.  
    else
        binary_to_char(signum, (i % 8), (i - 32) / 8); 
    i++;
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
