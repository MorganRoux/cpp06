/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:51:09 by mroux             #+#    #+#             */
/*   Updated: 2021/06/28 22:05:07 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

bool	checkChar(std::string str)
{
	return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

bool	checkInt(std::string str)
{
	if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return (false);
	if ((str[0] == '+' || str[0] == '-') && str.length() <= 1)
		return (false);
	for (size_t i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool	checkFloat(std::string str)
{
	size_t	i;
	bool	d = false;

	if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return (false);
	if ((str[0] == '+' || str[0] == '-') && str.length() <= 1)
		return (false);
	for (i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if (i == str.length() - 1)
				return (str[i] == 'f');
			if (str[i] == '.')
			{
				if (d)
					return (false);
				d = true;
			}
			else
				return (false);
		}
	}
	return (false);
}

bool	checkDouble(std::string str)
{
	size_t	i;
	bool	d = false;

	if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return (false);
	if ((str[0] == '+' || str[0] == '-') && str.length() <= 1)
		return (false);
	for (i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if (str[i] == '.')
			{
				if (d)
					return (false);
				d = true;
			}
			else
				return (false);
		}
	}
	return (true);
}

t_type	checkException(std::string str)
{
	if (!str.compare("-inff") || !str.compare("+inff") || !str.compare("nanf"))
		return (FLOAT);
	if (!str.compare("-inf") || !str.compare("+inf") || !str.compare("nan"))
		return (DOUBLE);
	return (UNKNOWN);
}

t_type getType(std::string str)
{
	t_type i;

	if ((i = checkException(str)) != UNKNOWN)
		return (i);
	if (checkChar(str))
		return CHAR;
	if (checkInt(str))
		return INT;
	if (checkFloat(str))
		return FLOAT;
	if (checkDouble(str))
		return DOUBLE;
	return UNKNOWN;
}
