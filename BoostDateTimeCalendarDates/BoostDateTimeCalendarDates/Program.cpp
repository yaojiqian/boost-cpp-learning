// Program.cpp
//

#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

//using namespace boost::gregorian;

//9. Iterating over dates
using namespace boost;

int main()
{
	/*-----------------------------------------------------------------
	//1. Creating a date with boost::gregorian::date
	boost::gregorian::date d{ 2014, 10, 1 };
	std::cout << d.year() << std::endl;
	std::cout << d.month() << std::endl;
	std::cout << d.day() << std::endl;
	std::cout << d.day_of_year() << std::endl;
	std::cout << d.day_of_week() << std::endl;
	std::cout << d.end_of_month() << std::endl;
	/*-----------------------------------------------------------------*/

	/*-----------------------------------------------------------------
	//2. Getting a date from a clock or a string
	date d = day_clock::universal_day();
	std::cout << d.year() << std::endl;
	std::cout << d.month() << std::endl;
	std::cout << d.day() << std::endl;

	d = date_from_iso_string("20140131");
	std::cout << d.year() << std::endl;
	std::cout << d.month() << std::endl;
	std::cout << d.day() << std::endl;
	/*-----------------------------------------------------------------*/

	/*-----------------------------------------------------------------
	//3. Using boost::gregorian::date_duration
	date d1{ 2014, 2, 15 };
	date d2{ 2014,3,15 };
	date_duration dd = d1 - d2;
	std::cout << dd.days() << std::endl;
	/*-----------------------------------------------------------------*/

	/*-----------------------------------------------------------------
	//4. Specialized durations
	date_duration ds{ 4 };
	std::cout << ds.days() << std::endl;
	weeks ws{ 4 };
	std::cout << ws.days() << std::endl;
	months ms{ 4 };
	std::cout << ms.number_of_months() << std::endl;
	years ys{ 4 };
	std::cout << ys.number_of_years() << std::endl;
	/*-----------------------------------------------------------------*/

	/*-----------------------------------------------------------------
	//5. Processing specialized durations
	date d{ 2014, 1, 31 };
	months ms{ 1 };
	date d1 = d + ms;
	std::cout << d1 << std::endl;
	date d2 = d - ms;//boost::gregorian::months always arrives at the last day of another month
	std::cout << d2 << std::endl;
	/*-----------------------------------------------------------------*/

	/*-----------------------------------------------------------------
	//6. Surprises when processing specialized durations
	date d{ 2014, 1, 30 };
	months ms{ 1 };
	date d1 = d + ms;
	std::cout << d1 << std::endl;
	date d2 = d1 - ms;
	std::cout << d2 << std::endl;
	//jumping backwards by one month again results in d2 becoming January 31, 2014. 
	//Since February 28, 2014, is the last day in February, 
	//jumping backwards returns to the last day in January.
	/*-----------------------------------------------------------------*/

	/*-----------------------------------------------------------------
	//7. Using boost::gregorian::date_period
	date d1{ 2014,1,1 };
	date d2{ 2014,2,28 };
	date_period dp{ d1, d2 };
	date_duration dd = dp.length();
	std::cout << dd.days() << std::endl;

	/*-----------------------------------------------------------------*/


	/*-----------------------------------------------------------------
	//8. Testing whether a period contains dates
	date d1{ 2014,1,1 };
	date d2{ 2014,2,28 };
	date_period dp{ d1, d2 };//start date is included in the period, but end sate is not included.
	std::cout.setf(std::ios::boolalpha);
	std::cout << dp.contains(d1) << std::endl;
	std::cout << dp.contains(d2) << std::endl;//display flase;
	/*-----------------------------------------------------------------*/

	/*-----------------------------------------------------------------*/
	//9. Iterating over dates
	gregorian::date d{ 2017, 12,2 };
	gregorian::day_iterator it{ d };
	std::cout << *++it << std::endl;
	std::cout << date_time::next_weekday(*it, gregorian::greg_weekday(date_time::Wednesday)) << std::endl;
	/*-----------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}