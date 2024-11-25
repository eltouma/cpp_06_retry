/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:16:13 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/24 23:10:52 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	*this = obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return (*this);
}

void	handleChar(std::string s)
{
	char	c;
	long	nb;
	float	flt;
	double	dbl;

	c = s.c_str()[0];
	std::cout << "char: " << c << std::endl;
	nb = static_cast<int>(c);
	std::cout << "int: " << nb << std::endl;
	flt = static_cast<float>(c);
	std::cout << std::fixed << std::setprecision(1) << "float: " << flt << "f";
	dbl = static_cast<double>(c);
	std::cout << "\ndouble: " << dbl << std::endl;
	std::cout.unsetf(std::ios::fixed);
}

void	handleInt(long nb)
{
	float	f;
	double	d;

	displayChar(nb);
	std::cout << "int: " << nb << std::endl;
	f = static_cast<float>(nb);
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f";
	d = static_cast<double>(nb);
	std::cout << "\ndouble: " << d << std::endl;
	std::cout.unsetf(std::ios::fixed);
}
/*
void	handleInt(std::string s)
{
	long	nb;
	float	f;
	double	d;
	char	*endptr;

	nb = strtol(s.c_str(), &endptr, 10);
	displayChar(nb);
	std::cout << "int: " << nb << std::endl;
	f = static_cast<float>(nb);
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f";
	d = static_cast<double>(nb);
	std::cout << "\ndouble: " << d << std::endl;
	std::cout.unsetf(std::ios::fixed);
}


void	handleDouble(std::string s)
{
	double	dbl;
	char	*endptr;

	dbl = strtod(s.c_str(), &endptr);
	displayChar(dbl);
	displayInt(dbl);
	std::cout << std::fixed << std::showpoint;
	displayOtherTypes("float", "double" , dbl);
}

void	handleFloat(std::string s)
{
	float	flt;
	char	*endptr;

	flt = strtof(s.c_str(), &endptr);
	displayChar(flt);
	displayInt(flt);
	displayOtherTypes("double", "float", flt);
}
*/


void	handleDouble(double dbl)
{
	displayChar(dbl);
	displayInt(dbl);
	displayOtherTypes("float", "double" , dbl);
}

void	handleFloat(float flt)
{
	displayChar(flt);
	displayInt(flt);
	displayOtherTypes("double", "float", flt);
}

void	ScalarConverter::convert(std::string s)
{
	if (isSpecialDouble(s))
		return ;
	if (getChar(s))
		return ;
	if (getInt(s))
		return ;
	if (getDouble(s))
		return ;
	if (getFloat(s))
		return ;
}
