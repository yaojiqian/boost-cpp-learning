// Program.cpp
//
//Connections
//connect() returns an object of type boost::signals2::connection

#include <boost/signals2.hpp>
#include <iostream>

int main()
{
	/*--------------------------------------------------------------------------
	//10. Managing connections with boost::signals2::connection
	boost::signals2::signal<void()> s;
	boost::signals2::connection c = s.connect([] {std::cout << "Hello World!\n"; });
	s();
	c.disconnect();
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------
	//11. Blocking connections with shared_connection_block
	using namespace boost::signals2;
	signal<void()> s;
	connection c = s.connect([] {std::cout << "Hello World!\n"; });
	s();
	shared_connection_block b{ c };
	s();
	b.unblock();
	s();
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------
	//12. Blocking a connection multiple times
	using namespace boost::signals2;
	signal<void()> s;
	connection c = s.connect([] {std::cout << "Hello World!\n"; });
	shared_connection_block b1{ c, false };
	{
		shared_connection_block b2{ c };
		std::cout << std::boolalpha << b1.blocking() << std::endl;
		std::cout << std::boolalpha << b2.blocking() << std::endl;
		s();
	}
	s();
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------*/
	//13. Member functions as event handlers
	using namespace boost::signals2;
	struct world 
	{
		void hello()
		{
			std::cout << "Hello World!\n";
		}
	};
	signal<void()> s;
	{
		std::unique_ptr<world> w{ new world() };
		s.connect(std::bind(&world::hello, w.get()));
	}
	s();
	/*--------------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}