/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 23:42:29 by mroux             #+#    #+#             */
/*   Updated: 2021/06/29 00:51:12 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

uintptr_t	serialize(Data* data)
{
	uintptr_t 	ptr = reinterpret_cast<uintptr_t> (new char[8 + 4 + 8]);
	for (int i = 0, j = 0; i < 8; i++, j++)
	{
		char *str = reinterpret_cast<char *> (ptr);
		str[i] = data->str1[j];
	}
	for (int i = 8, j = 0; j < 4; i++, j++)
	{
		char *str = reinterpret_cast<char *> (ptr);
		str[i] = data->str2[j];
	}
	for (int i = 12, j = 0 ; j < 2; i++, j++)
	{
		char	*p_i = reinterpret_cast<char *>(&data->sh);
		char 	*str = reinterpret_cast<char *> (ptr);
		str[i] = p_i[j];
	}
	for (int i = 14, j = 0 ; j < 4; i++, j++)
	{
		char	*p_i = reinterpret_cast<char *>(&data->i);
		char 	*str = reinterpret_cast<char *> (ptr);
		str[i] = p_i[j];
	}
	for (int i = 18, j = 0; j < 8; i++, j++)
	{
		char *str = reinterpret_cast<char *> (ptr);
		str[i] = data->str3[j];
	}

	return ptr;
}

Data*		deserialize(uintptr_t ptr)
{
	Data *data = new Data;

	for (int i = 0, j = 0; i < 8; i++, j++)
	{
		data->str1[j] = reinterpret_cast<char *> (ptr)[i];
	}
	for (int i = 8, j = 0; j < 4; i++, j++)
	{
		data->str2[j] = reinterpret_cast<char *> (ptr)[i];
	}
	for (int i = 12, j = 0 ; j < 2; i++, j++)
	{
		char	*p_i = reinterpret_cast<char *>(&data->sh);
		p_i[j] = reinterpret_cast<char *> (ptr)[i];
	}
	for (int i = 14, j = 0 ; j < 4; i++, j++)
	{
		char	*p_i = reinterpret_cast<char *>(&data->i);
		p_i[j] = reinterpret_cast<char *> (ptr)[i];
	}
	for (int i = 18, j = 0; j < 8; i++, j++)
	{
		data->str3[j] = reinterpret_cast<char *> (ptr)[i];
	}
	return data;
}

void		dump(char *str)
{
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

	memcpy(data.str1, "abcdefg", 8);
	memcpy(data.str2, "hij", 4);
	memcpy(data.str3, "klmnopq", 8);
	data.sh = 0x4546;    //FE
	data.i = 0x44434241; //ABCD

	std::cout << data.str1 << " - " << data.str2 << " - " << data.str3 << " - " << data.i << " - " << data.sh << std::endl;
	std::cout << "Dump struct :" << std::endl;
	dump(reinterpret_cast<char *>(&data));

	ptr = serialize(&data);
	std::cout << "Dump serial :" << std::endl;
	dump(reinterpret_cast<char *>(ptr));

	pdata = deserialize(ptr);
	std::cout << "Dump deserialized :" << std::endl;
	dump(reinterpret_cast<char *>(pdata));
	std::cout << pdata->str1 << " - " << pdata->str2 << " - " << pdata->str3 << " - " << pdata->i << " - " << pdata->sh << std::endl;
}
