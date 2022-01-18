/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:07:46 by cbarbit           #+#    #+#             */
/*   Updated: 2022/01/18 14:43:51 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//je definis 0 quand tout va bien et 1 quand il y a une erreur

/* Le client va envoyer un message au server sous forme de signaux a dechiffrer.
Je vais devoir determiner par exemple que mon SIGUSR1 vaut 0 et mon SIGUSR2 vaut 1.
En fonction du chiffre correspond, je vais transmettre le signal qui convient via la fonction kill.

*/

void	char_to_binary(char c, pid_t pid) // ou int pid?
{
	int	i;

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
		ft_printf("Minitalk cannot work: Too few arguments!");
		return (1);
	}
	if (argc > 3)
	{
		ft_printf("Minitalk cannot work: Too many arguments!");
		return (1);
	}
	if ((ft_is_digit(argv[1]) == 1)|| (ft_atoi(argv[1]) < 0)) //si mon pid contient autre chose que des chiffres ou si pid < 0
	{
		ft_printf("Minitalk cannot work : There is an error with the PID!");
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
	{

	}
}
