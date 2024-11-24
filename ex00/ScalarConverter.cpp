/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:16:13 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/24 20:53:54 by eltouma          ###   ########.fr       */
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
	{
		std::cout << "c'est un int\n";
		return ;
	}
	if (getDouble(s))
	{
		std::cout << "c'est un double\n";
		return ;
	}
	if (getFloat(s))
	{
		std::cout << "c'est un float\n";
		return ;
	}

}
