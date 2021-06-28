/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 23:42:29 by mroux             #+#    #+#             */
/*   Updated: 2021/06/29 00:03:01 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

uintptr_t	serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t> (ptr);
}

Data*		deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *> (raw);
}

void		dump(char *str)
{
	std::cout << "Dump:" << std::endl;
	for (size_t i = 0; i < 30; i++)
	{
		if (static_cast<int> (str[i]) < 32 || static_cast<int> (str[i])  > 126)
			std::cout << '?';
		else
			std::cout << str[i];
	}
	std::cout << std::endl;
}

int main()
{
	Data		data, *pdata;
	uintptr_t	ptr;

	data.name = "Essai";
	data.i = 100;

	ptr = serialize(&data);
	dump(reinterpret_cast<char *>(ptr));
	pdata = deserialize(ptr);

	std::cout << pdata->name << " - " << pdata->i << std::endl;
}
