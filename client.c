/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:07:46 by cbarbit           #+#    #+#             */
/*   Updated: 2022/01/19 15:48:59 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//je definis 0 quand tout va bien et 1 quand il y a une erreur

void	char_to_binary(char c, pid_t pid) // ou int pid?
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1; //cela va decaler de i rangs la version en binaire de ma lettre c.
		if (bit == 0)
			kill(pid, SIGUSR1);
		if (bit == 1)
			kill(pid, SIGUSR2);
		usleep(20);
		i--;
	}
	usleep(100);
}

/* La fonction char_to_binary va convertir chaque caractere de mon argv[2] en binaire.
Avant de lui envoyer chaque caractere, il faut que je parcours mon argv[2].
*/
void	ft_send_each_char_of_argv2(char *str, pid_t pid) //je lui envoie mon argv[2] + le pid du serveur!
{
	int	i;
	while (str[i]) //sous-entendu while (str[i] != '\0'
	{
		char_to_binary(str[i], pid);
		i++;
	}
	char_to_binary(str[i], pid); //je l'appelle une derniere fois pour qu'elle envoie le '\0'
}

int	ft_is_digit(char *str) //cette fonction sert a gerer que mon pid est bien compose uniquement de chiffres!
{
	int	i;

	i = 0;
	while (str[i])
	{
		if(!(i >= 0 && i <= 9))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_parameters(int argc, char **argv)
{
	if (argc < 3)
	{
		ft_printf("Minitalk cannot work: Too few arguments!\n");
		return (1);
	}
	if (argc > 3)
	{
		ft_printf("Minitalk cannot work: Too many arguments!\n");
		return (1);
	}
	if ((ft_is_digit(argv[1]) == 1)|| (ft_atoi(argv[1]) < 0)) //si mon pid contient autre chose que des chiffres ou si pid < 0
	{
		ft_printf("Minitalk cannot work : There is an error with the PID!\n");
		return (1);
	else
		return (0);
}

/*
Peut-etre y-a-t-il d'autres elements a prendre en compte en gestion d'erreur?

A chaque fois que j'utilise la fonction kill, je dois utiliser la fonction usleep.

Dans cette partie, je vais devoir utiliser la fonction kill(pid_t pid, int sig) qui est la fonction qui
permet au client d'envoyer un signal au serveur.
 */

int	main(int argc, char **argv)
{
	if (ft_check_parameters(argc, argv) == 1)
		return (1);
	if (argc == 3)
		ft_send_each_char_of_argv2(agv[2], atoi(argv[1]));
	return (0);
}
