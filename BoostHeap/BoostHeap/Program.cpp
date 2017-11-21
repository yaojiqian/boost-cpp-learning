// Program.cpp
//
//Boost.Heap could have also been called Boost.PriorityQueue 
//since the library provides several priority queues. However,
//the priority queues in Boost.Heap differ from std::priority_queue 
//by supporting more functions.
//


#include <iostream>

//#include <boost/heap/priority_queue.hpp>
#include <boost/heap/binomial_heap.hpp>

using namespace boost::heap;

int main()
{
	/*------------------------------------------------------
	//1. Using boost::heap::priority_queue
	//
	priority_queue<int> pq;

	pq.push(3);
	pq.push(2);
	pq.push(1);

	for (int i : pq)
		std::cout << i << std::endl;
	//output:
	//3
	//2
	//1

	priority_queue<int> pq2;
	pq2.push(4);
	std::cout << std::boolalpha << (pq > pq2) << std::endl;
	//pq has more elements than pq2, so pq > pq2;
	//output:
	//true
	------------------------------------------------------*/

	/*------------------------------------------------------
	//2. Using boost::heap::binomial_heap
	//
	binomial_heap<int> bh;

	bh.push(2);
	bh.push(3);
	bh.push(1);

	binomial_heap<int> bh2;
	bh2.push(4);
	bh.merge(bh2);

	for (auto it = bh.ordered_begin(); it != bh.ordered_end(); it++)
		std::cout << *it << std::endl;
	//output:
	//4
	//3
	//2
	//1
	std::cout << std::boolalpha << bh2.empty() << std::endl;
	//output:
	//true
	/*------------------------------------------------------*/

	/*------------------------------------------------------*/
	// 3. Changing elements in boost::heap::binomial_heap
	//
	binomial_heap<int> bh;
	auto handle = bh.push(2);
	bh.push(3);
	bh.push(1);

	std::cout << bh.top() << std::endl;//output:3
	bh.update(handle, 4);
	std::cout << bh.top() << std::endl;//output:4
	/*------------------------------------------------------*/

	std::getchar();
	return 0;
}