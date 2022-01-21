/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:07:46 by cbarbit           #+#    #+#             */
/*   Updated: 2022/01/21 11:05:07 by cbarbit          ###   ########.fr       */
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

int	ft_strlen(char *str) //cette fonction me permet de calculer la taille de mon argv[1]
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	int_to_binary(int c, pid_t pid)
{
	int	i;
	int	bit;

	i = 32
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
A chaque fois que j'utilise la fonction kill, je dois utiliser la fonction usleep.

Dans cette partie, je vais devoir utiliser la fonction kill(pid_t pid, int sig) qui est la fonction qui
permet au client d'envoyer un signal au serveur.
 */

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (ft_check_parameters(argc, argv) == 1)
		return (1);
	if (argc == 3)
	{
		while (argv[2][i])
		{
			char_to_binary(argv[2][i], atoi(argv[1])); //-> cette fonction prend chaque char de argv[2] et le PID du server (soit argv[1])
			i++;
		}
		char_to_binary(argv[2][i], atoi(argv[1])); //j'envoie le '\0'
	}
	return (0);
}
