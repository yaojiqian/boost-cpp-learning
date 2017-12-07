// Program.cpp
//
//Boost.Thread Synchronizing
//

#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

void wait(int s)
{
	boost::this_thread::sleep_for(boost::chrono::seconds{ s });
}


/*-----------------------------------------------------------
//7. Exclusive access with boost::mutex
//boost::mutex mutex;
void thread_fun()
{
	using namespace boost::this_thread;
	for (int i = 0; i < 5; i++)
	{
		wait(1);
		mutex.lock();//Because std::cout is a global object shared by the threads, access must be synchronized.
		std::cout << get_id() << ":" << i << std::endl;
		mutex.unlock();
	}
}
/*-----------------------------------------------------------*/

/*-----------------------------------------------------------
//8. boost::lock_guard with guaranteed mutex release
//boost::mutex mutex;
void thread_fun()
{
	using namespace boost::this_thread;
	for (int i = 0; i < 5; i++)
	{
		wait(1);
		boost::lock_guard<boost::mutex> lock{ mutex };
		std::cout << "Thread " << get_id() << ":" << i << std::endl;
	}
}
/*-----------------------------------------------------------*/

/*-----------------------------------------------------------
//9. The versatile lock boost::unique_lock
boost::timed_mutex mutex;
void thread1()
{
	using namespace boost::this_thread;
	for (int i = 0; i < 5; i++)
	{
		wait(1);
		boost::unique_lock<boost::timed_mutex> lock{ mutex };
		std::cout << "thread " << get_id << ":" << i << std::endl;
		boost::timed_mutex *m = lock.release();
		m->unlock();
	}
}

void thread2()
{
	using namespace boost::this_thread;
	for (int i = 0; i < 5; i++)
	{
		wait(1);
		boost::unique_lock<boost::timed_mutex> lock{ mutex, boost::try_to_lock };
		if (lock.owns_lock() || lock.try_lock_for(boost::chrono::seconds{ 1 }))
		{
			std::cout << "thread " << get_id() << ":" << i << std::endl;
		}
	}
}
/*-----------------------------------------------------------*/


/*-----------------------------------------------------------
//10. Shared locks with boost::shared_lock
boost::shared_mutex mutex;
std::vector<int> random_numbers;

void fill()
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	for (int i = 0; i < 3; i++)
	{
		boost::unique_lock<boost::shared_mutex> lock{ mutex };//exclusive lock 
		random_numbers.push_back(std::rand());
		lock.unlock();
		wait(1);
	}
}

void print()
{
	for (int i = 0; i < 3; i++)
	{
		wait(1);
		boost::shared_lock<boost::shared_mutex> lock{ mutex };//non-exclusive lock
		std::cout << random_numbers.back() << std::endl;
	}
}

int sum = 0;
void count()
{
	for (int i = 0; i < 3; i++)
	{
		wait(1);
		boost::shared_lock<boost::shared_mutex> lock{ mutex };//non-exclusive lock
		sum += random_numbers.back();
	}
}

/*-----------------------------------------------------------*/

/*-----------------------------------------------------------*/
//11. Condition variables with boost::condition_variable_any
boost::mutex mutex;
boost::condition_variable_any cond;
std::vector<int> random_numbers;

void fill()
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	for (int i = 0; i < 3; i++)
	{
		boost::unique_lock<boost::mutex> lock{ mutex };
		random_numbers.push_back(std::rand());
		cond.notify_all();
		cond.wait(mutex);
	}
}

void print()
{
	std::size_t next_size = 1;
	for (int i = 0; i < 3; i++)
	{
		boost::unique_lock<boost::mutex> lock{ mutex };
		while (random_numbers.size() != next_size)
			cond.wait(mutex);
		std::cout << random_numbers.back() << std::endl;
		++next_size;
		cond.notify_all();
	}
}
/*-----------------------------------------------------------*/

int main()
{
	/*-----------------------------------------------------------
	//7. Exclusive access with boost::mutex
	boost::thread t1{ thread_fun };
	boost::thread t2{ thread_fun };

	t1.join();
	t2.join();
	/*-----------------------------------------------------------*/

	/*-----------------------------------------------------------
	//8. boost::lock_guard with guaranteed mutex release
	boost::thread t1{ thread_fun };
	boost::thread t2{ thread_fun };

	t1.join();
	t2.join();
	/*-----------------------------------------------------------*/

	/*-----------------------------------------------------------
	//9. The versatile lock boost::unique_lock
	boost::thread t1{ thread1 };
	boost::thread t2{ thread2 };
	t1.join();
	t2.join();
	/*-----------------------------------------------------------*/

	/*-----------------------------------------------------------*/
	//9. The versatile lock boost::unique_lock
	boost::thread t1{ fill };
	boost::thread t2{ print };
	t1.join();
	t2.join();
	/*-----------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}