#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void)
{
}

Base* generate(void)
{
	int	random;
	static int	initialized = 0;

	if (!initialized)
	{
		srand(time(NULL));
		initialized = 1;
	}
	random = rand() % 3;
	if (random == 1)
		return (new(std::nothrow) A());
	else if (random == 2)
		return (new(std::nothrow) B());
	else
		return (new(std::nothrow) C());
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "The actual type of the object pointed to by p is 'A'"  << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "The actual type of the object pointed to by p is 'B'"  << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "The actual type of the object pointed to by p is 'C'"  << std::endl;
}

void	identify(Base& p)
{
	A	a;
	B	b;
	C	c;

	try {
		a = dynamic_cast<A&>(p);
		std::cout << __func__ << ":\tthe actual type of the object pointed to by p is 'A'\n" << std::endl;
	}
	catch (const std::exception &e)
	{
		try {
			b = dynamic_cast<B&>(p);
			std::cout << __func__ << ":\tthe actual type of the object pointed to by p is 'b'\n" << std::endl;
		}
		catch (const std::exception &e)
		{
			try {
				c = dynamic_cast<C&>(p);
				std::cout << __func__ << ":\tthe actual type of the object pointed to by p is 'C'\n" << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cerr << "Cast fail " << e.what() << std::endl;
			}
		}
	}
}
