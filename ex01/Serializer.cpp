/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:16:13 by eltouma           #+#    #+#             */
/*   Updated: 2024/11/24 23:10:52 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
}

Serializer::~Serializer(void)
{
}

Serializer::Serializer(const Serializer &obj)
{
	*this = obj;
}

Serializer& Serializer::operator=(const Serializer &rhs)
{
	(void)rhs;
	return (*this);
}

uintptr_t Serializer::serialize(Data *p)
{
	uintptr_t serialize;

	serialize = reinterpret_cast<uintptr_t>(p);
	return (serialize);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	Data *deserialize;

	deserialize = reinterpret_cast<Data*>(raw);
	return (deserialize);
}
