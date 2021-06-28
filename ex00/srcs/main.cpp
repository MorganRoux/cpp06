/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:55:13 by mroux             #+#    #+#             */
/*   Updated: 2021/06/28 22:41:32 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	convert(std::string str)
{
	t_type		t = getType(str);
	converter	converters[4] = {
		&fromChar, &fromInt, &fromFloat, &fromDouble
	};
	if (t == UNKNOWN)
		std::cout << "Unknown" << std::endl;
	else
		converters[t](str);
}

int		main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Erreur" << std::endl;
		return (0);
	}
	std::string str(argv[1]);
	if (str.length() == 0)
	{
		std::cout << "Erreur" << std::endl;
		return (0);
	}
	convert(str);
	return (0);
}
