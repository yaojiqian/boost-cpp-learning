// Program.cpp
//
//Boost.Lockfree
//Boost.Lockfree provides thread-safe and lock-free containers. 
//Containers from this library can be accessed from multiple 
//threads without having to synchronize access.

#include <boost/lockfree/spsc_queue.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/lockfree/policies.hpp>
#include <atomic>
#include <thread>
#include <iostream>

/*-----------------------------------------------------------------------
//1. Using boost::lockfree::spsc_queue
boost::lockfree::spsc_queue<int> q{ 100 };
//the container boost::lockfree::spsc_queue explicitly supports concurrent access from two threads, 
//it isn’t necessary to synchronize the threads.
int sum = 0;

void produce()
{
	for (int i = 1; i <= 100; i++)
		q.push(i);
}

void consume()
{
	int i;
	while (q.pop(i))
		sum += i;
}

int main()
{

	std::thread t1{ produce };
	std::thread t2{ consume };

	t1.join();
	t2.join();
	consume();
	std::cout << sum << std::endl;

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}
/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------
//2. boost::lockfree::spsc_queue with boost::lockfree::capacity

using namespace boost::lockfree;

spsc_queue<int, capacity<100>> q;//size of the circular buffer is set at compile time. 
int sum = 0;

void produce()
{
	for (int i = 1; i <= 100; i++)
		q.push(i);
}

void consume()
{
	while (q.consume_one([](int i) { sum += i; }))
		;
}

int main()
{
	std::thread t1{ produce };
	std::thread t2{ consume };

	t1.join();
	t2.join();
	q.consume_all([](int i) {sum += i; });
	std::cout << sum << std::endl;

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}
/*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------
//3. boost::lockfree::queue with variable container size
// boost::lockfree::queue is not implemented with a circular buffer. 
//If more items are added to the queue than the capacity is set to, it is automatically increased.
boost::lockfree::queue<int> q{ 100 };
std::atomic<int> sum{ 0 };

void produce()
{
	for (int i = 1; i <= 10000; i++)
		q.push(i);
}

void consume()
{
	int i;
	while (q.pop(i))
		sum += i;
}

int main()
{
	std::thread t1{ produce };
	std::thread t2{ consume };
	std::thread t3{ consume };

	t1.join();
	t2.join();
	t3.join();
	consume();
	std::cout << sum << std::endl;

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}

/*-----------------------------------------------------------------------*/


/*-----------------------------------------------------------------------*/
//4. boost::lockfree::queue with constant container size
using namespace boost::lockfree;

queue<int, fixed_sized<true>> q{ 10000 };
std::atomic<int> sum{ 0 };

void produce()
{
	for (int i = 1; i <= 10000; i++)
		q.push(i);
}

void consume()
{
	int i;
	while (q.pop(i))
		sum += i;
}

int main()
{
	std::thread t1{ produce };
	std::thread t2{ consume };
	std::thread t3{ consume };

	t1.join();
	t2.join();
	t3.join();
	consume();
	std::cout << sum << std::endl;

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}
/*-----------------------------------------------------------------------*/