// Program.cpp
//Boost FileSystem Files Directories
//
//

#include <iostream>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main()
{
	/*------------------------------------------------------------------
	//10. Using boost::filesystem::status()
	path p{ "C:\\" };

	try
	{
		file_status s = status(p);
		std::cout << std::boolalpha << exists(s) << std::endl;
	}
	catch (filesystem_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	/*------------------------------------------------------------------*/

	/*------------------------------------------------------------------
	//11. Using boost::filesystem::file_size()
	path p{ "C:\\Windows\\twain_32.dll" };
	boost::system::error_code ec;
	boost::uintmax_t filesize = file_size(p, ec);
	if (!ec)
		std::cout << filesize << std::endl;
	else
		std::cout << ec << std::endl;
	/*------------------------------------------------------------------*/

	/*------------------------------------------------------------------
	//12. Using boost::filesystem::last_write_time()
	path p{ "C:\\Windows\\win.ini" };
	try
	{
		std::time_t t = last_write_time(p);
		std::cout << std::ctime(&t) << std::endl;
	}
	catch (filesystem_error &er)
	{
		std::cout << er.what() << std::endl;
	}

	/*------------------------------------------------------------------*/

	/*------------------------------------------------------------------
	//13. Using boost::filesystem::space()
	path p{ "D:\\" };
	try
	{
		space_info s = space(p);
		std::cout << s.available << std::endl;
		std::cout << s.capacity << std::endl;
		std::cout << s.free << std::endl;
	}
	catch (filesystem_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	/*------------------------------------------------------------------*/

	/*------------------------------------------------------------------
	//14. Creating, renaming, and deleting directories
	path p{ "D:\\test" };
	try
	{
		if (create_directory(p))
		{
			std::getchar();
			rename(p, "D:\\test2");
			std::getchar();
			boost::filesystem::remove("D:\\test2");
		}
	}
	catch (filesystem_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	/*------------------------------------------------------------------*/

	/*------------------------------------------------------------------
	//15. Using boost::filesystem::absolute()
	try
	{
		std::cout << absolute("photo.jpg") << std::endl;
	}
	catch (filesystem_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	/*------------------------------------------------------------------*/


	/*------------------------------------------------------------------
	//16. Creating an absolute path relative to another directory
	try
	{
		std::cout << absolute("photo.jpg", "D:\\") << std::endl;
	}
	catch (filesystem_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	/*------------------------------------------------------------------*/

	/*------------------------------------------------------------------
	//17. Using boost::filesystem::current_path()
	try
	{
		std::cout << current_path() << std::endl;
		current_path("D:\\");
		std::cout << current_path() << std::endl;
	}
	catch (filesystem_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	/*------------------------------------------------------------------*/

	/*------------------------------------------------------------------
	//18. Iterating over files in a directory
	try 
	{
		path p = current_path();
		directory_iterator it{ p };
		while (it != directory_iterator{})
			std::cout << *it++ << std::endl;
	}
	catch (filesystem_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	/*------------------------------------------------------------------*/

	/*------------------------------------------------------------------*/
	//19. Using boost::filesystem::ofstream
	try
	{
		path p{ "D:\\test.txt" };
		ofstream of{ p };
		of << "Hello World!" << std::endl;
	}
	catch (filesystem_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	/*------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}