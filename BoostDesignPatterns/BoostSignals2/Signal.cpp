// Program.cpp
//
//Boost.Signals2
//Boost.Signals2 implements the signal/slot concept. 
//One or multiple functions – called slots – 
//are linked with an object that can emit a signal.

#include <boost/signals2.hpp>
#include <iostream>

using namespace boost::signals2;

/*------------------------------------------------------------------------
//5. Disconnecting event handlers from boost::signals2::signal
void hello() { std::cout << "Hello"; }
void world() { std::cout << ", World\n"; }
/*------------------------------------------------------------------------*/

/*------------------------------------------------------------------------
//8. Finding the smallest return value with a user-defined combiner
template<typename T>
struct min_element
{
	typedef T result_type;

	template<typename InputIterator>
	T operator()(InputIterator first, InputIterator last)
	{
		std::vector<T> v{ first, last };
		return *std::min_element(v.begin(), v.end());
	}
};
/*------------------------------------------------------------------------*/

/*------------------------------------------------------------------------*/
//9. Receiving all return values with a user-defined combiner
template<typename T>
struct return_all
{
	typedef T result_type;

	template<typename InputIterator>
	T operator()(InputIterator first, InputIterator last)
	{
		return T(first, last);
	}
};
/*------------------------------------------------------------------------*/

int main()
{
	/*------------------------------------------------------------------------
	//1. “Hello, world!” with boost::signals2::signal
	signal<void()> s;
	s.connect([](){std::cout << "Hello World!\n"; });
	s();
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------
	//2. “Hello, world!” with std::function
	std::function<void()> f;
	f = [] {std::cout << "Hello World!\n"; };
	f();
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------
	//3. Multiple event handlers with boost::signals2::signal
	signal<void()> s;
	s.connect([] {std::cout << "Hello"; });
	s.connect([] {std::cout << ", World!\n"; });
	s();
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------
	//4. Event handlers with an explicit order
	signal<void()> s;
	s.connect(1, [] {std::cout << ", World!\n"; });
	s.connect(0, [] {std::cout << "Hello"; });
	s();
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------
	//5. Disconnecting event handlers from boost::signals2::signal
	signal<void()> s;
	s.connect(hello);
	s.connect(world);
	s.disconnect(world);
	s();
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------
	//6. Additional member functions of boost::signals2::signal
	signal<void()> s;
	s.connect([] {std::cout << "Hello"; });
	s.connect([] {std::cout << ", World!\n"; });
	std::cout << s.num_slots() << std::endl;
	if (!s.empty())
		s();
	s.disconnect_all_slots();
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------
	//7. Processing return values from event handlers
	signal<int()> s;
	s.connect([] {return 1; });
	s.connect([] {return 2; });
	std::cout << *s() << std::endl;
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------
	//8. Finding the smallest return value with a user-defined combiner
	signal<int(), min_element<int>> s;
	s.connect([] {return 1; });
	s.connect([] {return 2; });
	std::cout << s() << std::endl;
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------*/
	//9. Receiving all return values with a user-defined combiner
	signal<int(), return_all<std::vector<int>>> s;
	s.connect([] {return 1; });
	s.connect([] {return 2; });
	std::vector<int> t= s();
	std::copy(t.begin(), t.end(), std::ostream_iterator<int>{std::cout, ","});
	/*------------------------------------------------------------------------*/


	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}