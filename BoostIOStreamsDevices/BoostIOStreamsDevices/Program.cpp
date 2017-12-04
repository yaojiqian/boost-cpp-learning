// Program.cpp
//
// Boost.IOStreams.Devices
//
//Devices are classes that provide read and write access to objects 
//that are usually outside of a process – for example, files. However, 
//you can also access internal objects, such as arrays, as devices.
//

#include <boost/iostreams/device/array.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <vector>
#include <iostream>
#include <windows.h>

using namespace boost::iostreams;

int main()
{
	/*------------------------------------------------------------------------------------
	//1. Using an array as a device with boost::iostreams::array_sink
	char buffer[16];
	array_sink sink{ buffer };
	stream<array_sink> os{ sink };
	os << "Boost" << std::flush;
	std::cout.write(buffer, 5); // << buffer << std::endl;
	/*------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------
	//2. Using an array as a device with boost::iostreams::array_source
	char buffer[16];
	array_sink sink{ buffer };
	stream<array_sink> os{ sink };
	os << "boost" << std::endl;// std::flush;

	array_source  source{ buffer };
	stream<array_source> is{ source };
	std::string s;
	is >> s;
	std::cout << s << std::endl;
	/*------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------
	//3. Using a vector as a device with boost::iostreams::back_insert_device
	std::vector<char> v;
	back_insert_device<std::vector<char>> sink{ v };
	stream<back_insert_device<std::vector<char>>> os{ sink };

	os << "Boost" << std::endl;

	array_source source{ v.data(), v.size() };
	stream<array_source> is{ source };
	std::string s;
	is >> s;
	std::cout << s << std::endl;
	/*------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------
	//4. Using a file as a device with boost::iostreams::file_source
	file_source f{ "Program.cpp" };
	if (f.is_open())
	{
		stream<file_source> is{ f };
		std::cout << is.rdbuf() << std::endl;
		f.close();
	}
	/*------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------*/
	//5. Using file_descriptor_source and file_descriptor_sink
	HANDLE handles[2];
	if (CreatePipe(&handles[0], &handles[1], nullptr, 0))
	{
		file_descriptor_source src{ handles[0], close_handle };
		stream<file_descriptor_source> is{ src };

		file_descriptor_sink snk{ handles[1], close_handle };
		stream<file_descriptor_sink> os{ snk };

		os << "Boost" << std::endl;
		std::string s;
		std::getline(is, s);
		std::cout << s << std::endl;
	}
	/*------------------------------------------------------------------------------------*/

	std::cout << "\npress a key to exit\n";
	std::getchar();
	return 0;
}