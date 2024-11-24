/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterDisplay.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:16:13 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/24 23:04:47 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

void	displayOtherTypes(std::string s, std::string name, double val)
{
	std::cout << std::fixed << std::showpoint;
	if (val < -FLT_MAX || val > FLT_MAX)
		std::cout << s << ": out of range" << std::endl;
	else
		std::cout << s << ": " << static_cast<float>(val) << "f" << std::endl;
	std::cout << name << ": " << val << std::endl;
	std::cout.unsetf(std::ios::fixed | std::ios::showpoint);
}
