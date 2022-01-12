/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:07:46 by cbarbit           #+#    #+#             */
/*   Updated: 2022/01/12 16:14:07 by cbarbit          ###   ########.fr       */
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
