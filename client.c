/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:07:46 by cbarbit           #+#    #+#             */
/*   Updated: 2022/01/14 16:57:29 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* Le client va envoyer un message au server sous forme de signaux a dechiffrer.
Je vais devoir determiner par exemple que mon SIGUSR1 vaut 0 et mon SIGUSR2 vaut 1.
En fonction du chiffre correspond, je vais transmettre le signal qui convient via la fonction kill.

*/

void	char_to_binary(char c, pid_t pid) // ou int pid?
{
	int	i;

}

//il faut gerer les erreurs - lorsque j'execute, je dois avoir trois arguments.
//le pid ne doit contenir que des chiffres. -> penser a faire une fonction qui check si le pid est bien compose uniquement de chiffres.
//Peut-etre y-a-t-il d'autres elements a prendre en compte en gestion d'erreur?

//a chaque fois que j'utilise la fonction kill, je dois utiliser la fonction usleep.
