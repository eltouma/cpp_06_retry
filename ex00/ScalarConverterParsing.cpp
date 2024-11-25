/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterParsing.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:16:13 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/24 21:03:21 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	impossibleConversion(std::string s, std::string nan, std::string inf, std::string pInf, std::string nInf)
{
	static size_t size = s.length();
	int comma;

	comma = 0;
	if (s == nan || s == inf || s == pInf || s == nInf)
		return (0); 
	for (size_t i = 0; i < size; i++)
	{
		if (s[i] == '-')
		{
			if (i != 0)
				return (1); 
		}
	 	else if (s[i] == '.')
		{
			comma++;
			if (comma > 1)
				return (1); 
		}
		else if (s[i] == 'f')
		{
			if (i != size - 1)
				return (1); 
		}
		else if (!isdigit(s[i]) && size > 1)
			return (1); 
	}
	return (0);
}

void	error(void)
{
	std::cout << "char: impossible conversion\n";
	std::cout << "int: impossible conversion\n";
        std::cout << "float: impossible conversion\n";
        std::cout << "double: impossible conversion\n";
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
		return (error(), 1);
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
			std::cout << "float: " << s.erase(0, 1) << std::endl;
		else
			std::cout << "float: " << s << std::endl;
		std::cout << "double: " << s.substr(0, s.length() - 1) << std::endl;
		return (1);
	}
	if (impossibleConversion(s, nanf, inff, pInff, nInff))
		return (error(), 1);
	return (0);
}
