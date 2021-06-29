/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:59:09 by mroux             #+#    #+#             */
/*   Updated: 2021/06/29 20:16:06 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base	*generate(void)
{
	Base*	p;
	int i = rand() % 3;
	std::cout << i << std::endl;
	switch(i)
	{
		case 0:
			p = new A();
			break;
		case 1:
			p = new B();
			break;
		case 2:
			p = new C();
			break;
	}
	return p;
}

void	identify(Base* p)
{
	std::cout << "*" << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p)
{
	A a;
	B b;
	C c;

	std::cout << "&" << std::endl;
	try {
		a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::bad_cast & e) {
	try {
		b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::bad_cast & e) {
	try {
		c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::bad_cast & e){

	}}}
}

int main(void)
{
	Base *p;

	srand(time(NULL));
	p = generate();
	identify(p);
	identify(*p);
}
