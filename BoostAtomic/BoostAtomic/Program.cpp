// Program.cpp
//
//Boost.Atomic
//
//Boost.Atomic is used in multithreaded programs when access to a variable in one thread 
//shouldn’t be interrupted by another thread accessing the same variable. 
//Without boost::atomic, attempts to access shared variables from multiple 
//threads would need to be synchronized with locks.

#include <boost/atomic.hpp>
#include <thread>
#include <iostream>

/*-----------------------------------------------------------------------------
//1. Using boost::atomic
boost::atomic<int> a{ 0 };

void thread_fun()
{
	++a;
}
/*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------*/
//3. boost::atomic with boost::memory_order_seq_cst
boost::atomic<int> a{ 0 };

void thread_fun()
{
	a.fetch_add(1, boost::memory_order_seq_cst);
}
/*-----------------------------------------------------------------------------*/


int main()
{
	/*-----------------------------------------------------------------------------
	//1. Using boost::atomic
	std::thread t1{ thread_fun };
	std::thread t2{ thread_fun };

	t1.join();
	t2.join();
	std::cout << a << std::endl;
	/*-----------------------------------------------------------------------------*/

	/*-----------------------------------------------------------------------------
	//2. boost::atomic with or without lock
	std::cout.setf(std::ios::boolalpha);

	boost::atomic<short> s{ 0 };
	std::cout << s.is_lock_free() << std::endl;

	boost::atomic<int> i{ 0 };
	std::cout << i.is_lock_free() << std::endl;

	boost::atomic<long> l{ 0 };
	std::cout << l.is_lock_free() << std::endl;
	/*-----------------------------------------------------------------------------*/

	/*-----------------------------------------------------------------------------*/
	//3. boost::atomic with boost::memory_order_seq_cst
	std::thread t1{ thread_fun };
	std::thread t2{ thread_fun };
	t1.join();
	t2.join();
	std::cout << a << std::endl;
	/*-----------------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}