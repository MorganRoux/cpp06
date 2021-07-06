/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:04:04 by mroux             #+#    #+#             */
/*   Updated: 2021/07/06 16:57:26 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "limits.h"

typedef enum		e_type
{
	CHAR, INT, FLOAT, DOUBLE, UNKNOWN
}					t_type;

typedef				void (*converter)(std::string const& str);
void				fromInt(std::string const& str);
void				fromChar(std::string const& str);
void				fromFloat(std::string const& str);
void				fromDouble(std::string const& str);

bool				checkChar(std::string str);
bool				checkInt(std::string str);
bool				checkFloat(std::string str);
bool				checkDouble(std::string str);
t_type				getType(std::string str);
