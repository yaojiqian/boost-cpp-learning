// Program.cpp
//
//Boost.Timer
//Boost.Timer measures the time it takes to execute code. 
//Although Boost.Timer uses Boost.Chrono, 
//when you want to measure code performance, 
//you should use Boost.Timer rather than Boost.Chrono.

#include <boost/chrono/chrono.hpp>
//Error	LNK2019	unresolved external symbol "public: static class boost::chrono::time_point<class boost::chrono::steady_clock,class boost::chrono::duration<__int64,class boost::ratio<1,1000000000> > > 
//__cdecl boost::chrono::steady_clock::now(void)" (? now@steady_clock@chrono@boost@@SA?AV ? $time_point@Vsteady_clock@chrono@boost@@V?$duration@_JV?$ratio@$00$0DLJKMKAA@@boost@@@23@@23@XZ) 

#include <boost/timer/timer.hpp>
#include <iostream>
#include <cmath>

using namespace boost::timer;

int main()
{
	/*--------------------------------------------------------------------
	//1. Measuring time with boost::timer::cpu_timer
	cpu_timer timer;

	for (int i = 0; i < 1000000; ++i)
		std::pow(1.234, i);
	std::cout << timer.format() << '\n';
	/*--------------------------------------------------------------------*/

	/*--------------------------------------------------------------------
	//2. Stopping and resuming timers
	cpu_timer timer;

	for (int i = 0; i < 1000000; ++i)
		std::pow(1.234, i);
	std::cout << timer.format() << '\n';

	timer.stop();

	for (int i = 0; i < 1000000; ++i)
		std::pow(1.234, i);
	std::cout << timer.format() << '\n';

	timer.resume();

	for (int i = 0; i < 1000000; ++i)
		std::pow(1.234, i);
	std::cout << timer.format() << '\n';
	
	/*--------------------------------------------------------------------*/

	/*--------------------------------------------------------------------
	//3. Getting wall and CPU time as a tuple
	cpu_timer timer;

	for (int i = 0; i < 1000000; i++)
		std::pow(1.234, i);

	cpu_times times = timer.elapsed();
	std::cout << times.wall << std::endl;
	std::cout << times.user << std::endl;
	std::cout << times.system << std::endl;
	/*--------------------------------------------------------------------*/

	/*--------------------------------------------------------------------*/
	//4. Measuring times automatically with boost::timer::auto_cpu_timer
	{
		auto_cpu_timer timer;

		for (int i = 0; i < 1000000; i++)
			std::pow(1.234, i);
	}
	/*--------------------------------------------------------------------*/

	std::cout << "\npress a key to exit.";
	std::getchar();
	return 0;
}