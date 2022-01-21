/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:07:46 by cbarbit           #+#    #+#             */
/*   Updated: 2022/01/21 12:14:13 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//je definis 0 quand tout va bien et 1 quand il y a une erreur

int	ft_strlen(char *str) //cette fonction me permet de calculer la taille de mon argv[1]
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	char_to_binary(char c, pid_t pid)
{
	int				i;
	unsigned int	bit;

	i = 7;
	bit = 0;
	while (i >= 0)
	{
		bit = (c >> i) & 1; //cela va decaler de i rangs la version en binaire de ma lettre c.
		if (bit == 1)
			kill(pid, SIGUSR2);
		else 
			kill(pid, SIGUSR1);
		usleep(20);
		i--;
	}
	usleep(100);
}


void	int_to_binary(int c, pid_t pid) //testons en envoyant la longueur de ma chaine de caractere, soit de mon argv[2].
{
	int				i;
	unsigned int	bit;

	i = 32;
	bit = 0;
	while (i >= 0)
	{
		bit = (c >> i) & 1; //cela va decaler de i rangs la version en binaire de ma lettre c.
		if (bit == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(20);
		i--;
	}
	usleep(100);
	}
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

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (ft_check_parameters(argc, argv) == 1)
		return (1);
	if (argc == 3)
	{
		int_to_binary(ft_strlen(argv[2]), atoi(argv[1])); //je lui envoie la taille de mon argv[2]
		while (argv[2][i]) // soit while (argv[2][i] != '\0')
		{
			char_to_binary(argv[2][i], atoi(argv[1])); //-> cette fonction prend chaque char de argv[2] et le PID du server (soit argv[1])
			i++;
		}
		char_to_binary(argv[2][i], atoi(argv[1])); //j'apelle la fonction une derniere fois pour envoyer le '\0'
	}
	return (0);
}
