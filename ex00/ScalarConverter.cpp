/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:16:13 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/24 22:50:34 by eltouma          ###   ########.fr       */
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

int	getInt(std::string s)
{
	long	nb;
	char	*endptr;

	nb = strtol(s.c_str(), &endptr, 10);
	if (*endptr != '\0')
		return (0);
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	return (1);
}

double	getDouble(std::string s)
{
	long double	nb;
	char	*endptr;

	nb = strtod(s.c_str(), &endptr);
	if (*endptr != '\0')
		return (0);
	if (nb < -DBL_MAX || nb > DBL_MAX)
		return (0);
	return (1);
}

float	getFloat(std::string s)
{
	long double	nb;
	char	*endptr;

	nb = strtof(s.c_str(), &endptr);
	if (*endptr != 'f' && *(endptr + 1) != '\0')
		return (0);
	if (nb < -FLT_MAX || nb > FLT_MAX)
		return (0);
	return (1);
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

int	getChar(std::string s)
{
	static size_t	size = s.length();

	if (size == 1 && !isdigit(s[0]) && isprint(s[0]))
		return (handleChar(s), 1);
	return (0);
}

void	displayChar(double val)
{
	if (val < 32 || val > 126)
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(val) << std::endl;
}

void	displayInt(double val)
{
	double	min;
	double	max;

	min = static_cast<double>(INT_MIN);
	max = static_cast<double>(INT_MAX);
	if (val < min || val > max)
		std::cout << "int: out of range" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;
}

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

void	displayDF(std::string s, std::string name, double val)
{
	std::cout << std::fixed << std::showpoint;
	if (val < -FLT_MAX || val > FLT_MAX)
		std::cout << s << ": out of range" << std::endl;
	else
		std::cout << s << ": " << static_cast<float>(val) << "f" << std::endl;
	std::cout << name << ": " << val << std::endl;
	std::cout.unsetf(std::ios::fixed | std::ios::showpoint);
}

void	handleDouble(std::string s)
{
	//float	flt;
	double	dbl;
	char	*endptr;

	dbl = strtod(s.c_str(), &endptr);
	displayChar(dbl);
	displayInt(dbl);
	std::cout << std::fixed << std::showpoint;
	displayDF("float", "double" , dbl);
/*
	if (dbl < -FLT_MAX || dbl > FLT_MAX)
		std::cout << "float: out of range" << std::endl;
	else
	{
		flt = static_cast<float>(dbl);
		std::cout << "float: " << flt << "f" << std::endl;
	}
	std::cout << "double: " << dbl << std::endl;
	std::cout.unsetf(std::ios::fixed | std::ios::showpoint);
*/
}

void	handleFloat(std::string s)
{
	float	flt;
//	double	dbl;
	char	*endptr;

	flt = strtof(s.c_str(), &endptr);
	displayChar(flt);
	displayInt(flt);
	displayDF("double", "float", flt);
/*
	std::cout << std::fixed << std::showpoint;
//	flt = static_cast<float>(flt);
//	if (flt < -FLT_MAX || flt > FLT_MAX)
	std::cout << "float: " << flt << "f" << std::endl;
	if (flt < -FLT_MAX || flt > FLT_MAX)
		std::cout << "double: out of range" << std::endl;
	else
	{
		dbl = static_cast<double>(flt);
		std::cout << "double: " << dbl << std::endl;
	}
	//std::cout << "double: " << dbl << std::endl;
	std::cout.unsetf(std::ios::fixed | std::ios::showpoint);
*/
}

void	ScalarConverter::convert(std::string s)
{
	std::cout << "convert " << s << std::endl;
	std:: cout << std::endl;
	if (isSpecialDouble(s))
		return ;
	if (getChar(s))
		return ;
	if (getInt(s))
	{
		std::cout << "c'est un int\n\n";
		handleInt(s);
		return ;
	}
	if (getDouble(s))
	{
		std::cout << "c'est un double\n\n";
		handleDouble(s);
		return ;
	}
	if (getFloat(s))
	{
		std::cout << "c'est un float\n\n";
		handleFloat(s);
		return ;
	}

}
