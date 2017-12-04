// Program.cpp
//
//Boost.IOStreams.Filters
//
//filters operate in front of devices to filter data read from or written to devices.
//

#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/device/array.hpp>
#include <boost/iostreams/filter/regex.hpp>
#include <boost/iostreams/filter/counter.hpp>
#include <boost/regex.hpp>
#include <iostream>

using namespace boost::iostreams;

int main()
{
	/*---------------------------------------------------------------------------------
	//6. Using boost::iostreams::regex_filter
	char buffer[16];
	array_sink sink{ buffer };
	filtering_ostream os;
	os.push(regex_filter{ boost::regex{"Bo+st"}, "C++" });
	os.push(sink);
	os << "Boooooost" << std::flush;
	os.pop();
	std::cout.write(buffer, 3);
	//os.push(regex_filter{ boost::regex{"Bo+st"}, "KKK" });
	//os.push(sink);
	os << "Hello" << std::flush;
	os.pop();
	std::cout.write(buffer, 3);
	/*---------------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------------*/
	//7. Accessing filters in boost::iostreams::filtering_ostream
	char buffer[16];
	array_sink sink{ buffer };
	filtering_ostream os;
	os.push(counter{});
	os.push(sink);
	os << "Boost" << std::endl << std::flush;
	os.pop();
	counter *c = os.component<counter>(0);
	std::cout << c->characters() << std::endl;
	std::cout << c->lines() << std::endl;
	/*---------------------------------------------------------------------------------*/

	std::cout << "\npress a key to exit.";
	std::getchar();
	return 0;
}