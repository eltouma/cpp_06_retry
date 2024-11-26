#pragma once

#include <iostream>
#include <stdint.h>

typedef struct s_Data
{
	int	intPtr;
	float	floatPtr;
	std::string	strPtr;
}	Data;

class Serializer
{
	Serializer(void);
	Serializer(const Serializer& obj);
	Serializer& operator=(const Serializer& rhs);
	~Serializer(void);

public:
	static uintptr_t	serialize(Data* ptr);
	static Data*	deserialize(uintptr_t raw);
};
