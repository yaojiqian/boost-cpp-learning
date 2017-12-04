// Program.cpp
//
//Boost.Filesystem
//
//The library Boost.Filesystem makes it easy to work with files and directories. 

#include <iostream>
#include <boost/filesystem/path.hpp>

using namespace boost::filesystem;

int main()
{
	/*--------------------------------------------------------------------------
	//1. Using boost::filesystem::path
	path p1{ "C:\\" };
	path p2{ "C:\\Windows\\" };
	path p3{ L"C:\\Boost C++ \u5E93" };
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------
	//2. Meaningless paths with boost::filesystem::path
	path p1{ "..." };
	path p2{ "\\" };
	path p3{ "@:" };
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------
	//3. Retrieving paths from boost::filesystem::path as strings
	path p{ "C:\\Windows\\System" };
#ifdef BOOST_WINDOWS_API
	std::wcout << p.native() << std::endl;
#else
	std::cout << p.native() << std::endl;
#endif
	std::cout << p.string() << std::endl;
	std::wcout << p.wstring() << std::endl;

	std::cout << p.generic_string() << std::endl;
	std::wcout << p.generic_wstring() << std::endl;
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------
	//4. Initializing boost::filesystem::path with a portable path
	path p{ "/" };

	std::cout << p.string() << std::endl;
	std::cout << p.generic_string() << std::endl;
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------
	//5. Accessing components of a path
	path p{ "C:\\Windows\\System" };

	std::cout << p.root_name() << std::endl;
	std::cout << p.root_path() << std::endl;
	std::cout << p.root_directory() << std::endl;
	std::cout << p.relative_path() << std::endl;
	std::cout << p.parent_path() << std::endl;
	std::cout << p.filename() << std::endl;
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------
	//6. Receiving file name and file extension
	path p{ "photo.jpg" };
	std::cout << p.stem() << std::endl;
	std::cout << p.extension() << std::endl;
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------
	//7. Iterating over components of a path
	path p{ "C:\\Windows\\System" };

	for (const path &pp : p)
		std::cout << pp << std::endl;
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------
	//8. Concatenating paths with operator/=
	path p{ "C:\\" };

	p /= "Windows\\System";
	std::cout << p.string() << std::endl;
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------*/
	//9. Preferred notation with make_preferred()
	path p{ "C:/Windows/System" };

	std::cout << p.make_preferred() << std::endl;
	/*--------------------------------------------------------------------------*/

	//std::wcout << L"\u4E00";
	std::cout << "\npress a key to exit.";
	std::getchar();
	return 0;
}