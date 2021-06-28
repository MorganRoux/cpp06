/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 23:42:48 by mroux             #+#    #+#             */
/*   Updated: 2021/06/28 23:52:28 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

typedef struct		s_data {
		std::string	name;
		int			i;
}					Data;

uintptr_t			serialize(Data* ptr);
Data*				deserialize(uintptr_t raw);
