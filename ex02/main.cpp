#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{
	Base	*base;
	for (int i = 0; i < 10; i++)
	{
		try {
			base = generate();
		}
		catch (std::bad_alloc &ba)
		{
			std::cerr << ba.what() << std::endl;
			delete (base);
			return (1);
		}
		identify(base);
		identify(*base);
		delete (base);
	}
	return (0);
}
