// Program.cpp
//
//Synchronization
//
//
//

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>

#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/sync/interprocess_condition.hpp>

#include <boost/interprocess/sync/scoped_lock.hpp>
#include <boost/interprocess/sync/named_condition.hpp>

#include <iostream>
#include <thread>

using namespace boost::interprocess;

int main()
{
	/*----------------------------------------------------------------------------------
	//12. Using a named mutex with boost::interprocess::named_mutex
	
	managed_shared_memory managed_shm{ open_or_create, "Boost", 1024 };
	int *i = managed_shm.find_or_construct<int>("Integer")();
	named_mutex named_mtx{ open_or_create, "shm" };
	for (int k = 0; k < 100; k++)
	{
		named_mtx.lock();
		++(*i);
		std::cout << *i << std::endl;
		named_mtx.unlock();
		winapi::sleep(500);
	}
	//shared_memory_object::remove("Boost");
	/*----------------------------------------------------------------------------------*/

	/*----------------------------------------------------------------------------------
	//13. Using an anonymous mutex with interprocess_mutex
	managed_shared_memory managed_shm{ open_or_create, "Boost", 1024 };
	int *i = managed_shm.find_or_construct<int>("Integer")();
	interprocess_mutex *mtx = managed_shm.find_or_construct<interprocess_mutex>("mtx")();
	for (int k = 0; k < 100; k++)
	{
		mtx->lock();
		++(*i);
		std::cout << *i << std::endl;
		mtx->unlock();
		winapi::sleep(500);
	}
	/*----------------------------------------------------------------------------------*/

	/*----------------------------------------------------------------------------------
	//14. Using a named condition with boost::interprocess::named_condition
	managed_shared_memory managed_shm{ open_or_create, "Boost", 1024 };
	int *i = managed_shm.find_or_construct<int>("Integer")(0);
	named_mutex named_mtx{ open_or_create, "mtx" };
	named_condition named_cnd{ open_or_create, "cnd" };
	std::cout << "before scoped_lock\n";
	scoped_lock<named_mutex> lock{ named_mtx };//takes ownership of the mutex for the entire execution of the program.
	while (*i < 10)
	{
		if (*i % 2 == 0)
		{
			(*i)++;
			std::cout << "before noity_all\n";
			named_cnd.notify_all();
			std::cout << "before wait\n";
			named_cnd.wait(lock); //ownership of the corresponding mutex is released.
			//The program then waits until notify_all() is called on the same condition variable.
		}
		else
		{
			std::cout << *i << std::endl;
			(*i)++;
			named_cnd.notify_all();
			named_cnd.wait(lock);
		}
	}
	named_cnd.notify_all();
	shared_memory_object::remove("Boost");
	named_mutex::remove("mtx");
	named_condition::remove("cnd");
	/*----------------------------------------------------------------------------------*/

	/*----------------------------------------------------------------------------------*/
	//15. Using an anonymous condition with interprocess_condition
	managed_shared_memory managed_shm{ open_or_create, "Boost", 1024 };
	int *i = managed_shm.find_or_construct<int>("Integer")(0);
	interprocess_mutex *mtx = managed_shm.find_or_construct<interprocess_mutex>("mtx")();
	interprocess_condition *cnd = managed_shm.find_or_construct<interprocess_condition>("cnd")();
	scoped_lock<interprocess_mutex> lock{ *mtx };

	while (*i < 10)
	{
		if (*i % 2 == 0)
		{
			(*i)++;
			cnd->notify_all();
			cnd->wait(lock);
		}
		else
		{
			std::cout << *i << std::endl;
			(*i)++;
			cnd->notify_all();
			cnd->wait(lock);
		}
	}
	cnd->notify_all();
	shared_memory_object::remove("Boost");
	/*----------------------------------------------------------------------------------*/

	std::cout << "press a key to exit" << std::endl;
	std::getchar();
	return 0;
}