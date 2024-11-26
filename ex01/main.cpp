#include "Serializer.hpp"

int	main(void)
{
	Data	dataSerialize;
	Data	*dataDeserialize;
	uintptr_t	raw;

	dataSerialize.intPtr = 5;
	dataSerialize.floatPtr = 2.4f;
	dataSerialize.strPtr = "C'est fou l'art";
	std::cout << "data address before serialization:\t\t" <<  &dataSerialize << std::endl;
	std::cout << "intPtr value before serialization:\t\t" <<  dataSerialize.intPtr << std::endl;
	std::cout << "floatPtr value before serialization:\t\t" <<  dataSerialize.floatPtr << "f" << std::endl;
	std::cout << "strPtr value before serialization:\t\t" <<  dataSerialize.strPtr << std::endl;
	raw = Serializer::serialize(&dataSerialize);
	std::cout << "serialized value:\t\t\t\t" <<  raw << std::endl;

	dataDeserialize = Serializer::deserialize(raw);
	std::cout << "data address after serialization:\t\t" <<  dataDeserialize << std::endl;

	std::cout << "intPtr value after serialization:\t\t" <<  dataDeserialize->intPtr << std::endl;
	std::cout << "floatPtr value after serialization:\t\t" <<  dataDeserialize->floatPtr << "f" << std::endl;
	std::cout << "strPtr value after serialization:\t\t" <<  dataDeserialize->strPtr << std::endl;
	(dataDeserialize == &dataSerialize) ? std::cout << "\nSerialization: \033[1;32msuccess\033[0m" << std::endl : std::cout << "\nSerialization: \033[1;31mfail\033[0m" << std::endl;
}
