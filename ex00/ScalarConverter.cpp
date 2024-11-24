/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:16:13 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/24 19:50:55 by eltouma          ###   ########.fr       */
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
	int	comma;

	neg = 0;
	comma = 0;
	if (s != nan || s != inf || s != pInf || s != nInf)
	{
		for (int i = 0; s[i] != '\0'; i++)
		{
			if (s[0] == '-')
			{
				i += 1;
				neg = 1;
			}
			for (int j = 0; s[j] != '\0'; j++)
			{
				if (s[j] == '.')
				{
					j += 1;
					comma += 1;
					std::cout << "s[j] " << s[j] << "\n";
				}
			}
			if (!isdigit(s[i]) && s.length() > 1 && !neg && comma > 1)
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
	return (0);
}

int	isSpecialFloat(std::string s)
{
	std::string nanf = "nanf";
	std::string inff = "inff";
	std::string pInff = "+inff";
	std::string nInff = "-inff";

	if (s == nanf || s == inff || s == pInff || s == nInff)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (s == pInff)
			std::cout << "float: " << s.erase(0, 1) << 'f' << std::endl;
		else
			std::cout << "float: " << s << std::endl;
		std::cout << "double: " << s.substr(0, s.length() - 1) << std::endl;
		return (1);
	}
	if (impossibleConversion(s, nanf, inff, pInff, nInff))
		return (1);
	return (0);
}

int	getInt(std::string s)
{
	long	nb;
	char	*endptr;

	nb = strtol(s.c_str(), &endptr, 10);
	if (*endptr != '\0')
		return (false);
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	return (nb);
}

double	getDouble(std::string s)
{
	double	nb;
	char	*endptr;

	nb = strtod(s.c_str(), &endptr);
	if (*endptr != '\0')
		return (0);
	if (nb < -DBL_MAX || nb > DBL_MAX)
		return (0);
	return (nb);
}

float	getFloat(std::string s)
{
	double	nb;
	char	*endptr;

	nb = strtof(s.c_str(), &endptr);
	if (*endptr != 'f' && *(endptr + 1) != '\0')
		return (0);
	if (nb < -FLT_MAX || nb > FLT_MAX)
		return (0);
	return (nb);
}

void	ScalarConverter::convert(std::string s)
{
	std::cout << "convert " << s << std::endl;
	std:: cout << std::endl;
	if (isSpecialDouble(s))
		return ;
	if (getInt(s))
		std::cout << "c'est un int\n";
	if (getDouble(s))
		std::cout << "c'est un double\n";
	if (getFloat(s))
		std::cout << "c'est un float\n";
}
