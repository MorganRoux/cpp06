/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:55:49 by mroux             #+#    #+#             */
/*   Updated: 2021/06/29 19:59:56 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
# include <iostream>
# include <string>

class Base
{
	public:
		virtual ~Base();

	protected:
};

class A : public Base
{

};

class B : public Base
{

};

class C : public Base
{

};

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
