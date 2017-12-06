// Program.cpp
//
//Boost.Thread
//Creating and Managing Threads

#include <boost/thread/thread.hpp>
#include <boost/thread/scoped_thread.hpp>
#include <boost/chrono/chrono.hpp>

#include <iostream>

void wait(int s)
{
	boost::this_thread::sleep_for(boost::chrono::seconds{ s });
}

void thread_fun()
{
	//4. Disabling interruption points with disable_interruption
	//boost::this_thread::disable_interruption no_interruption;
	try
	{
		for (int i = 0; i < 5; i++)
		{
			wait(1);
			std::cout << i << std::endl;
		}
	}
	catch (boost::thread_interrupted &)
	{
		std::cout << "interrupted" << std::endl;
	}
}

int main()
{
	/*-------------------------------------------------------------------
	//1. Using boost::thread
	boost::thread t{ thread_fun };
	t.join();
	/*-------------------------------------------------------------------*/

	/*-------------------------------------------------------------------
	//2. Waiting for a thread with boost::scoped_thread
	{
		boost::scoped_thread<> t{ boost::thread{ thread_fun } };
	}//scoped_thread will call the join() here. in it's destructor.
	/*-------------------------------------------------------------------*/

	/*-------------------------------------------------------------------
	//3. An interruption point with boost::this_thread::sleep_for()
	boost::thread t{ thread_fun };
	wait(3);
	t.interrupt();
	t.join();
	/*-------------------------------------------------------------------*/

	/*-------------------------------------------------------------------
	//4. Disabling interruption points with disable_interruption
	boost::thread t{ thread_fun };
	wait(3);
	t.interrupt();
	t.join();
	/*-------------------------------------------------------------------*/

	/*-------------------------------------------------------------------
	//5. Setting thread attributes with boost::thread::attributes
	boost::thread_attributes attrs;
	attrs.set_stack_size(1024);
	boost::thread t{ attrs,thread_fun };
	t.join();
	/*-------------------------------------------------------------------*/

	/*-------------------------------------------------------------------*/
	//6. Detecting the thread ID and number of available processors
	std::cout << boost::this_thread::get_id() << std::endl;
	std::cout << boost::thread::hardware_concurrency() << std::endl;
	/*-------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}