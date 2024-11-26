/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterDisplay.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:16:13 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/26 13:54:06 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	displayChar(double val)
{
	if (val < 32 || val > 126)
		std::cout << "char:\tnon displayable" << std::endl;
	else
		std::cout << "char:\t" << static_cast<char>(val) << std::endl;
}

void	displayInt(double val)
{
	double	min;
	double	max;

	min = static_cast<double>(INT_MIN);
	max = static_cast<double>(INT_MAX);
	if (val < min || val > max)
		std::cout << "int:\tout of range" << std::endl;
	else
		std::cout << "int:\t" << static_cast<int>(val) << std::endl;
}

void	displayOtherTypes(std::string s, std::string name, double val)
{
	std::cout << std::fixed << std::showpoint;
	if (val < -FLT_MAX || val > FLT_MAX)
		std::cout << s << ":\tout of range" << std::endl;
	else
		std::cout << s << ":\t" << static_cast<float>(val) << "f" << std::endl;
	std::cout << name << ":\t" << val << std::endl;
	std::cout.unsetf(std::ios::fixed | std::ios::showpoint);
}
