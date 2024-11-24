/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:16:24 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/24 20:45:21 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits.h>
#include <cfloat>

# define MIN_INT -2147483648
# define MAX_INT 2147483647
# define MIN_DBL -9223372036854775807
# define MAX_DBL 9223372036854775807

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
int	getInt(std::string s);
float	getFloat(std::string s);
double	getDouble(std::string s);
