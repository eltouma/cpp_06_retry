#pragma once

#include <iostream>
#include <cstdint>

typedef struct s_Data
{
	int	ptr;
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
