/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 23:42:48 by mroux             #+#    #+#             */
/*   Updated: 2021/07/06 17:05:36 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdint.h>

typedef struct		s_data {
		char 	str1[8];
		char 	str2[4];
		short	sh;
		int		i;
		char 	str3[8];
}					Data;

uintptr_t			serialize(Data* ptr);
Data*				deserialize(uintptr_t raw);
