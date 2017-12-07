// Program.cpp
//
//Boost.Thread
//Futures and Promises

#define BOOST_THREAD_PROVIDES_FUTURE
#include <boost/thread.hpp>
#include <boost/thread/future.hpp>
#include <functional>
#include <iostream>

/*-----------------------------------------------
//14. Using boost::future and boost::promise
void accumulate(boost::promise<int> &p)
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
		sum += i;
	p.set_value(sum);
}
/*-----------------------------------------------*/

/*-----------------------------------------------
//15. Using boost::packaged_task
int accumulate()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
		sum += i;

	return sum;
}
/*-----------------------------------------------*/

/*-----------------------------------------------*/
//16. Using boost::async()
int accumulate()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
		sum += i;
	return sum;
}
/*-----------------------------------------------*/

int main()
{
	/*-----------------------------------------------
	//14. Using boost::future and boost::promise
	boost::promise<int> p;
	boost::future<int> f = p.get_future();
	boost::thread t{ accumulate, std::ref(p) };
	std::cout << f.get() << std::endl;
	/*-----------------------------------------------*/

	/*-----------------------------------------------
	//15. Using boost::packaged_task
	boost::packaged_task<int> task{ accumulate };
	boost::future<int> f = task.get_future();
	boost::thread t{ std::move(task) };
	std::cout << f.get() << std::endl;
	/*-----------------------------------------------*/

	/*-----------------------------------------------*/
	//16. Using boost::async()
	boost::future<int> f = boost::async(accumulate);
	std::cout << f.get() << std::endl;
	/*-----------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}