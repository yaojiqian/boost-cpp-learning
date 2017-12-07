// Program.cpp
//
#include <boost/thread.hpp>
#include <iostream>

boost::mutex mutex;

/*-------------------------------------------------------------------
//12. Synchronizing multiple threads with static variables
void init()
{
	static bool done = false;
	boost::lock_guard<boost::mutex> lock{ mutex };
	if (!done)
	{
		done = true;
		std::cout << "done" << std::endl;
	}
}

void thread_fun()
{
	init();
	init();
}
/*-------------------------------------------------------------------*/

/*-------------------------------------------------------------------*/
//13. Synchronizing multiple threads with TLS
void init()
{
	static boost::thread_specific_ptr<bool> tls;

	if (!tls.get())
	{
		tls.reset(new bool{ true });
		boost::lock_guard<boost::mutex> lock{ mutex };
		std::cout << "done" << std::endl;
	}
}

void thread_fun()
{
	init();
	init();
}

/*-------------------------------------------------------------------*/

int main()
{
	/*-------------------------------------------------------------------*/
	//12. Synchronizing multiple threads with static variables
	boost::thread t[3];

	for (int i = 0; i < 3; i++)
		t[i] = boost::thread{ thread_fun };

	for (int i = 0; i < 3; i++)
		t[i].join();
	/*-------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}