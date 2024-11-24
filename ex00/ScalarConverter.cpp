/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:16:13 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/24 18:55:04 by eltouma          ###   ########.fr       */
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

int	impossibleConversion(std::string s, std::string nan, std::string inf, std::string pInf, std::string nInf)
{
	int	neg;

	neg = 0;
	if (s != nan || s != inf || s != pInf || s != nInf)
	{
			for (int i = 0; s[i] != '\0'; i++)
			{
				if (s[0] == '-')
				{
					i += 1;
					neg = 1;
				}
				if (!isdigit(s[i]) && s.length() > 1 && !neg)
				{
					std::cout << "char: impossible conversion" << std::endl;
					std::cout << "int: impossible conversion" << std::endl;
					std::cout << "float: impossible conversion" << std::endl;
					std::cout << "double: impossible conversion" << std::endl;
					return (1);
				}
			}
	}
	return (0);
}

int	isSpecialDouble(std::string s)
{
	std::string nan = "nan";
	std::string inf = "inf";
	std::string pInf = "+inf";
	std::string nInf = "-inf";

	if (s == nan || s == inf || s == pInf || s == nInf)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (s == pInf)
			std::cout << "float: " << s.erase(0, 1) << 'f' << std::endl;
		else
			std::cout << "float: " << s << 'f' << std::endl;
		std::cout << "double: " << s << std::endl;
		return (1);
	}
	if (isSpecialFloat(s))
		return (1);
	if (impossibleConversion(s, nan, inf, pInf, nInf))
		return (1);
/*
	if (s != nan || s != inf || s != pInf || s != nInf)
	{
			for (int i = 0; s[i] != '\0'; i++)
			{
				if (s[0] == '-')
				{
					i += 1;
					neg = 1;
				}
				if (!isdigit(s[i]) && s.length() > 1 && !neg)
				{
					std::cout << "char: impossible" << std::endl;
					std::cout << "int: impossible" << std::endl;
					std::cout << "float: impossible" << std::endl;
					std::cout << "double: impossible" << std::endl;
					return (1);
				}
			}
	}
*/
	return (0);
}

int	isSpecialFloat(std::string s)
{
	std::string nanf = "nanf";
	std::string inff = "inff";
	std::string pInff = "+inff";
	std::string nInff = "-inff";
	int	neg;

	neg = 0;
	if (s == nanf || s == inff || s == pInff || s == nInff)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (s == pInff)
			std::cout << "float: " << s.erase(0, 1) << 'f' << std::endl;
		else
			std::cout << "float: " << s << 'f' << std::endl;
		std::cout << "double: " << s << std::endl;
		return (1);
	}
	if (impossibleConversion(s, nanf, inff, pInff, nInff))
		return (1);
/*
	if (s != nan || s != inf || s != pInf || s != nInf)
	{
			for (int i = 0; s[i] != '\0'; i++)
			{
				if (s[0] == '-')
				{
					i += 1;
					neg = 1;
				}
				if (!isdigit(s[i]) && s.length() > 1 && !neg)
				{
					std::cout << "char: impossible" << std::endl;
					std::cout << "int: impossible" << std::endl;
					std::cout << "float: impossible" << std::endl;
					std::cout << "double: impossible" << std::endl;
					return (1);
				}
			}
	}
*/
	return (0);
}

void	ScalarConverter::convert(std::string s)
{
	std::cout << "convert " << s << std::endl;
	std:: cout << std::endl;
	if (isSpecialDouble(s))
		return ;
}
