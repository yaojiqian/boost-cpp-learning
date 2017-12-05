// Program.cpp
// Boost DateTime Formatted Input and Output
//

#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
#include <locale>

using namespace boost::gregorian;

int main()
{
	/*----------------------------------------------------------------------------------
	//20. A user-defined format for a date
	date dt{ 2014,4,12 };
	date_facet *df = new date_facet{ "%A, %d %m %Y" };
	std::cout.imbue(std::locale{ std::cout.getloc(), df });
	std::cout << dt << std::endl;
	/*----------------------------------------------------------------------------------*/

	/*----------------------------------------------------------------------------------*/
	//21. Changing names of weekdays and months
	std::locale::global(std::locale{ "chs" });
	std::string months[12]{ "y", "e", "s", "4",
		"w", "l", "q", "b", "j", "sh",
		"sy", "se" };
	std::string weekdays[7]{ "xqy", "xqe", "xqs",
		"xqss", "xqw", "xql", "xqt" };
	date d{ 2014, 5, 12 };
	date_facet *df = new date_facet{ "%A, %d. %B %Y" };
	df->long_month_names(std::vector<std::string>{months, months + 12});
	df->long_weekday_names(std::vector<std::string>{weekdays,
		weekdays + 7});
	std::cout.imbue(std::locale{ std::cout.getloc(), df });
	std::cout << d << '\n';
	/*----------------------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}