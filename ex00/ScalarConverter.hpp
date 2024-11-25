/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:16:24 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/24 23:02:43 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits.h>
#include <cfloat>

class	ScalarConverter
{
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &obj);
	ScalarConverter& operator=(const ScalarConverter &rhs);
	~ScalarConverter(void);

public:
	static void convert(std::string s);
};

int	isSpecialDouble(std::string s);
int	isSpecialFloat(std::string s);
int	getChar(std::string s);
int	getInt(std::string s);
float	getFloat(std::string s);
double	getDouble(std::string s);
void	handleChar(std::string s);
void	handleInt(long nb);
void	handleDouble(double dbl);
void	handleFloat(float flt);
void	displayChar(double val);
void	displayInt(double val);
void	displayOtherTypes(std::string s, std::string name, double val);
