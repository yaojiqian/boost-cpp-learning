// Program.cpp
//Boost.Conversion
//

#include <boost/cast.hpp>
#include <iostream>

/*-----------------------------------------------------------------------------
//1. Down and cross casts with dynamic_cast
struct base1 { virtual ~base1() = default; };
struct base2 { virtual ~base2() = default; };
struct derived :public base1, public base2 {};

void downcast(base1 *b1)
{
	derived *d1 = dynamic_cast<derived*>(b1);
}

void crosscast(base1 *b1)
{
	base2 *b2 = dynamic_cast<base2*>(b1);
}
/*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------*/
//2. Down and cross casts with polymorphic_downcast and polymorphic_cast
struct base1 { virtual ~base1() = default; };
struct base2 { virtual ~base2() = default; };
struct derived :public base1, public base2 {};

void downcast(base1 * b1)
{
	derived *d = boost::polymorphic_downcast<derived*>(b1);
}

void crosscast(base1 * b1) 
{
	base2 *b2 = boost::polymorphic_cast<base2*>(b1);
}

/*-----------------------------------------------------------------------------*/
int main()
{
	/*-----------------------------------------------------------------------------
	//1. Down and cross casts with dynamic_cast
	derived *d = new derived();
	downcast(d);

	base1 *b1 = new derived();
	crosscast(b1);
	/*-----------------------------------------------------------------------------*/

	/*-----------------------------------------------------------------------------*/
	//2. Down and cross casts with polymorphic_downcast and polymorphic_cast
	derived *d = new derived();
	downcast(d);

	base1 *b1 = new derived();
	crosscast(b1);
	/*-----------------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}