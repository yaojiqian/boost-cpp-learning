// Program.cpp
//
//Managed Shared Memory
//The managed shared memory lets you instantiate objects that have their memory located in shared memory, 
//making the objects automatically available to any program that accesses the same shared memory.
//

#include <iostream>
#include <array>
#include <functional>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/string.hpp>

using namespace boost::interprocess;


/*---------------------------------------------------------------------------------*/
//11. Atomic access on a managed shared memory
void construct_objects(managed_shared_memory &shm)
{
	shm.find_or_construct<int>("Integer")(99);
	shm.find_or_construct<float>("Float")(3.14);
}
/*---------------------------------------------------------------------------------*/

int main()
{
	/*---------------------------------------------------------------------------------
	//6. Using managed shared memory
	shared_memory_object::remove("Boost");
	managed_shared_memory mshdmem{ open_or_create, "Boost", 1024};
	int *i1 = mshdmem.construct<int>("Integer1")(99);
	std::cout << *i1 << std::endl;
	float *f = mshdmem.construct<float>("FloatNumber")(3.14f);
	std::pair<int*, std::size_t> p = mshdmem.find<int>("Integer1");
	if (p.first)
		std::cout << *p.first << std::endl;//display the Integer1's value fetched from managed shared memory.
	*p.first = 100;//change the value;
	std::pair<float*, std::size_t> p2 = mshdmem.find<float>("FloatNumber");
	if (p2.first)
		std::cout << *p2.first << std::endl;

	std::pair<int*, std::size_t> p3 = mshdmem.find<int>("Integer1");
	if (p3.first)
		std::cout << *p3.first << std::endl;
	/*---------------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------------
	//7. Creating arrays in managed shared memory
	shared_memory_object::remove("Boost");
	managed_shared_memory managed_shm{ open_or_create, "Boost", 1024 };
	std::array<int, 10> a{ 1,2,3,4,5,6,7,8,9,0 };
	int *i = managed_shm.construct<int>("IntegerArray")[10](99);
	std::cout << *i << std::endl;

	std::pair<int*, std::size_t> p = managed_shm.find<int>("IntegerArray");
	if (p.first)
	{
		std::cout << *p.first << std::endl;
		std::cout << p.second << std::endl;
		for (int i = 0; i < p.second; i++)
			std::cout << *(p.first + 1) << " ";
		//std::copy<int>(p.first.begin(), p.first.end(), std::ostream_iterator<int>( );
	}
	/*---------------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------------
	//8. An exception of type boost::interprocess::bad_alloc
	try 
	{
		shared_memory_object::remove("Boost");
		managed_shared_memory managed_shm{ open_or_create, "Boost", 1024 };
		int *i = managed_shm.construct<int>("IntegerArray")[1024](99);
	}
	catch (boost::interprocess::bad_alloc &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	/*---------------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------------
	//9. Removing objects in shared memory
	shared_memory_object::remove("Boost");
	managed_shared_memory managed_shm{ open_or_create, "Boost", 1024 };

	int *i = managed_shm.construct<int>("Integer")(99);
	std::pair<int*, std::size_t> p1 = managed_shm.find<int>("Integer");
	std::cout << p1.first << std::endl;
	bool ok = managed_shm.destroy<int>("Integer");
	std::pair<int*, std::size_t> p = managed_shm.find<int>("Integer");
	std::cout << p.first << std::endl;
	/*---------------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------------
	//10. Putting strings into shared memory
	shared_memory_object::remove("Boost");
	managed_shared_memory managed_shm{ open_or_create,"Boost", 1024 };
	typedef allocator<char, managed_shared_memory::segment_manager> CharAllocator;
	typedef basic_string<char, std::char_traits<char>, CharAllocator> string;
	string *s = managed_shm.find_or_construct<string>("String")("Hello!", managed_shm.get_segment_manager());
	s->insert(5, " World");
	std::cout << *s << std::endl;
	/*---------------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------------*/
	//11. Atomic access on a managed shared memory
	shared_memory_object::remove("Boost");
	managed_shared_memory managed_shm{ open_or_create, "Boost", 1024 };

	auto atomic_contruct = std::bind(construct_objects, std::ref(managed_shm));
	managed_shm.atomic_func(atomic_contruct);
	std::cout << *managed_shm.find<int>("Integer").first << std::endl;
	std::cout << *managed_shm.find<float>("Float").first << std::endl;
	/*---------------------------------------------------------------------------------*/

	std::cout << "press a key to exit" << std::endl;
	std::getchar();
	return 0;
}