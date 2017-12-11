// Program.cpp
//
//Boost Error Handling, Boost.System
//

#include <boost/system/error_code.hpp>
#include <string>
#include <iostream>


/*---------------------------------------------------------------------------------
//1. Using boost::system::error_code
using namespace boost::system;
void failed(error_code &ec)
{
	ec = errc::make_error_code(errc::not_supported);
}
/*---------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------
//2. Using boost::system::error_category
using namespace boost::system;
void failed(error_code &ec)
{
	ec = errc::make_error_code(errc::not_supported);
}
/*---------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------
//3. Creating error categories

class application_category : public boost::system::error_category
{
public:
	const char* name() const noexcept { return "error name"; }
	std::string message(int ev) const { return "error message"; }
};

application_category app_cat;

/*---------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------
//4. Using boost::system::error_condition
using namespace boost::system;
void failed(error_code &ec)
{
	ec = errc::make_error_code(errc::not_supported);
}
/*---------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------*/
//5. Using boost::system::system_error
#include <boost/system/system_error.hpp>
using namespace boost::system;
void failed()
{
	throw system_error{ errc::make_error_code(errc::not_supported) };
}
/*---------------------------------------------------------------------------------*/

int main()
{
	/*---------------------------------------------------------------------------------
	//1. Using boost::system::error_code
	error_code ec;
	failed(ec);
	std::cout << ec.value() << " " << std::endl;
	/*---------------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------------
	//2. Using boost::system::error_category
	error_code ec;
	failed(ec);
	std::cout << ec.value() << std::endl;
	std::cout << ec.category().name() << std::endl;
	/*---------------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------------
	//3. Creating error categories
	boost::system::error_code ec{ 129, app_cat };
	std::cout << ec.value() << std::endl;
	std::cout << ec.category().name() << std::endl;
	/*---------------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------------
	//4. Using boost::system::error_condition
	error_code ec;
	failed(ec);
	error_condition econd = ec.default_error_condition();
	std::cout << econd.value() << std::endl;
	std::cout << econd.category().name() << std::endl;
	/*---------------------------------------------------------------------------------*/


	/*---------------------------------------------------------------------------------*/
	//5. Using boost::system::system_error
	try
	{
		failed();
	}
	catch (system_error &e)
	{
		error_code ec = e.code();
		std::cout << ec.value() << std::endl;
		std::cout << ec.category().name() << std::endl;
	}
	/*---------------------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}