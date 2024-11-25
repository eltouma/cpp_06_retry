#include "Serializer.hpp"

int	main(void)
{
	Data	dataSerialize;
	Data	*dataDeserialize;
	uintptr_t	raw;

	dataSerialize.ptr = 5;
	std::cout << "data address before serialization:\t" <<  &dataSerialize << std::endl;
	std::cout << "ptr value before serialization:\t\t" <<  dataSerialize.ptr << std::endl;
	raw = Serializer::serialize(&dataSerialize);
	std::cout << "serialized value:\t\t\t" <<  raw << std::endl;

	dataDeserialize = Serializer::deserialize(raw);
	std::cout << "data address after serialization:\t" <<  dataDeserialize << std::endl;

	std::cout << "ptr value after serialization:\t\t" <<  dataDeserialize->ptr << std::endl;
	(dataDeserialize == &dataSerialize) ? std::cout << "\nSerialization: \033[1;32msuccess\033[0m" << std::endl : std::cout << "\nSerialization: \033[1;31mfail\033[0m" << std::endl;
}
