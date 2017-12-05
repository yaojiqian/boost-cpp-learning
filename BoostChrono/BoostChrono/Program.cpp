// Program.cpp
//
//Boost Chrono
//
//The library Boost.Chrono provides a variety of clocks. 

#define BOOST_CHRONO_VERSION 2
#include <iostream>
#include <boost/chrono.hpp>
#include <boost/chrono/chrono_io.hpp>

using namespace boost::chrono;

int main()
{
	/*----------------------------------------------------------------------
	//1. All clocks from Boost.Chrono
	std::cout << system_clock::now() << std::endl;
#ifdef BOOST_CHRONO_HAS_CLOCK_STEADY
	std::cout << steady_clock::now() << std::endl;
#endif
	std::cout << high_resolution_clock::now() << std::endl;

#ifdef BOOST_CHRONO_HAS_PROCESS_CLOCKS
	std::cout << process_real_cpu_clock::now() << std::endl;
	std::cout << process_user_cpu_clock::now() << std::endl;
	std::cout << process_system_cpu_clock::now() << std::endl;
	std::cout << process_cpu_clock::now() << std::endl;
#endif

#ifdef BOOST_CHRONO_HAS_THREAD_CLOCK
	std::cout << thread_clock::now() << std::endl;
#endif
	/*----------------------------------------------------------------------*/

	/*----------------------------------------------------------------------
	//2. Adding and subtracting durations using Boost.Chrono
	process_real_cpu_clock::time_point pt = process_real_cpu_clock::now();
	std::cout << pt << std::endl;
	std::cout << pt - nanoseconds{ 1 } << std::endl;
	std::cout << pt + seconds{ 1 } << std::endl;
	std::cout << pt + minutes{ 1 } << std::endl;
	std::cout << pt + hours{ 1 } << std::endl;
	
	/*----------------------------------------------------------------------*/

	/*----------------------------------------------------------------------
	//3. Casting timepoints with boost::chrono::time_point_cast()
	process_real_cpu_clock::time_point pt = process_real_cpu_clock::now();

	std::cout << pt << std::endl;
	std::cout << time_point_cast<nanoseconds>(pt) << std::endl;
	/*----------------------------------------------------------------------*/

	/*----------------------------------------------------------------------
	//4. Casting durations with boost::chrono::duration_cast()
	minutes m{ 1 };
	seconds s{ 85 };
	std::cout << m + s << std::endl;
	std::cout << duration_cast<minutes>(m + s) << std::endl;
	/*----------------------------------------------------------------------*/

	/*----------------------------------------------------------------------
	//5. Rounding durations
	std::cout << floor<minutes>(minutes{ 1 }+seconds{ 35 }) << std::endl;
	std::cout << round<minutes>(minutes{ 2 }+ seconds{ 31 }) << std::endl;
	std::cout << ceil<minutes>(minutes{ 1 }+seconds{ 10 }) << std::endl;
	/*----------------------------------------------------------------------*/

	/*----------------------------------------------------------------------*/
	//6. Stream manipulators for user-defined output
	std::cout << symbol_format << minutes{ 10 } << std::endl;
	std::cout << time_fmt(boost::chrono::timezone::local, "%H:%M:%S") << system_clock::now() << std::endl;
	/*----------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}