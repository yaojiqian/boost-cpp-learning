// Program.cpp
//
//Almost all classes provided by Boost.Signals2 are thread safe 
//and can be used in multithreaded applications. 

#include <boost/signals2.hpp>
#include <thread>
#include <mutex>
#include <iostream>

using namespace boost::signals2;

signal<void(int)> s;
//std::mutex m;

void loop()
{
	for (int i = 0; i < 100; i++)
		s(i);
}

int main()
{
	/*--------------------------------------------------------------------------
	//17. boost::signals2::signal is thread safe
	s.connect([](int i) {
		std::lock_guard<std::mutex> lock{ m };
		std::thread::id this_id = std::this_thread::get_id();
		std::cout << this_id << ":" <<  i << std::endl;
	});
	std::thread t1{ loop };
	std::thread t2{ loop };
	t1.join();
	t2.join();
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------*/
	//18. boost::signals2::signal without thread safety
	typedef keywords::mutex_type<dummy_mutex> dummy_mutex;
	signal_type<void(), dummy_mutex>::type s;
	s.connect([] { std::cout << "Hello, world!\n"; });
	s();
	/*--------------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}