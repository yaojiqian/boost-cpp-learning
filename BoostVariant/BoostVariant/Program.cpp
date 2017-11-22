// Program.cpp
//
//exercise Boost.Variant
//
//Boost.Variant provides a class called boost::variant that resembles union.
//

#include <iostream>

#include <boost/variant.hpp>


//struct output : public boost::static_visitor<>
//{
//	void operator()(double a) const { std::cout << a << std::endl; }
//	void operator()(char a) const { std::cout << a << std::endl; }
//	void operator()(std::string a) const { std::cout << a << std::endl; }
//};

struct output : public boost::static_visitor<>
{
	template <typename T>
	void operator()(T t) const { std::cout << t << std::endl; }
};

int main()
{
	/*------------------------------------------------------------------
	//1. Using boost::variant
	boost::variant<double, char, std::string> v;

	v = 3.14;
	v = 'B';
	v = "Hello";
	/*------------------------------------------------------------------*/

	/*------------------------------------------------------------------
	//2. Accessing values in boost::variant with boost::get()
	boost::variant<double, char, std::string> v;

	v = 3.14;
	std::cout << boost::get<double>(v) << std::endl;
	v = 'B';
	std::cout << boost::get<char>(v) << std::endl;
	v = "Hello";
	std::cout << boost::get<std::string>(v) << std::endl;
	/*------------------------------------------------------------------*/

	/*------------------------------------------------------------------
	//3. Direct output of boost::variant on a stream
	boost::variant<double, char, std::string> v;

	v = 3.14;
	std::cout << v) << std::endl;
	v = 'B';
	std::cout << v << std::endl;
	v = "Hello";
	std::cout << v << std::endl;
	/*------------------------------------------------------------------*/

	/*------------------------------------------------------------------
	//4. Using a visitor for boost::variant
	boost::variant<double, char, std::string> v;

	v = 3.14;
	boost::apply_visitor(output{}, v);
	v = 'B';
	boost::apply_visitor(output{}, v);
	v = "Hello";
	boost::apply_visitor(output{}, v);
	/*------------------------------------------------------------------*/

	/*------------------------------------------------------------------*/
	//5. Using a visitor with a function template for boost::variant
	boost::variant<double, char, std::string> v;

	v = 3.14;
	boost::apply_visitor(output{}, v);
	v = 'B';
	boost::apply_visitor(output{}, v);
	v = "Hello";
	boost::apply_visitor(output{}, v);
	/*------------------------------------------------------------------*/

	std::getchar();
	return 0;
}