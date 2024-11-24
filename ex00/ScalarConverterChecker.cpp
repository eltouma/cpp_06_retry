/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterGetters.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:16:13 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/24 23:00:02 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	getChar(std::string s)
{
	static size_t	size = s.length();

	if (size == 1 && !isdigit(s[0]) && isprint(s[0]))
		return (handleChar(s), 1);
	return (0);
}

int	isInt(std::string s)
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

double	isDouble(std::string s)
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

float	isFloat(std::string s)
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
