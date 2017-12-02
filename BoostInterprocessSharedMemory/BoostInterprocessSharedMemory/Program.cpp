// Program.cpp
//
//Shared memory is typically the fastest form of interprocess communication. 
//It provides a memory area that is shared between processes. 
//One process can write data to the area and another process can read it.
//

#include <iostream>
//#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/windows_shared_memory.hpp>
#include<boost/interprocess/mapped_region.hpp>


using namespace boost::interprocess;

int main()
{
	/*--------------------------------------------------------------------------------
	//1. Creating shared memory
	shared_memory_object shdmem{ open_or_create, "Boost", read_write };
	shdmem.truncate(1024);

	std::cout << shdmem.get_name() << std::endl;
	offset_t size;
	if (shdmem.get_size(size))
		std::cout << size << std::endl;
	/*--------------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------------
	//2. Mapping shared memory into the address space of a process
	shared_memory_object shdmem{ open_or_create, "Boost", read_write };
	shdmem.truncate(1024);

	mapped_region region{ shdmem, read_write };
	std::cout << std::hex << region.get_address() << std::endl;
	std::cout << std::dec << region.get_size() << std::endl;
	mapped_region region2{ shdmem, read_only };
	std::cout << std::hex << region2.get_address() << std::endl;
	std::cout << std::dec << region2.get_size() << std::endl;
	/*--------------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------------
	//3. Writing and reading a number in shared memory
	shared_memory_object shdmem{ open_or_create,"Boost",read_write };
	shdmem.truncate(1024);

	mapped_region region{ shdmem, read_write };
	int *i1 = static_cast<int*>(region.get_address());
	*i1 = 99;

	mapped_region region2{ shdmem, read_only };
	int *i2 = static_cast<int*>(region2.get_address());
	std::cout << *i2 << std::endl;
	/*--------------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------------
	//4. Deleting shared memory
	bool removed = shared_memory_object::remove("Boost");
	std::cout << std::boolalpha << removed << std::endl;
	/*--------------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------------*/
	//5. Using Windows-specific shared memory
	windows_shared_memory wshdmem{ open_or_create, "Boost", read_write, 1024 };
	mapped_region region{ wshdmem, read_write };
	int *i1 = static_cast<int*>(region.get_address());
	*i1 = 100;

	mapped_region region2{ wshdmem, read_only };
	int *i2 = static_cast<int*>(region2.get_address());
	std::cout << *i2 << std::endl;
	/*--------------------------------------------------------------------------------*/

	std::cout << "press key to exit!";
	getchar();
	return 0;
}