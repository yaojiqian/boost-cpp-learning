// Program.cpp
//Location-independent Times

#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::posix_time;
using namespace boost::gregorian;

int main()
{
	/*------------------------------------------------------------------------
	//10. Using boost::posix_time::ptime
	ptime pt{ date{2014,5,12}, time_duration{12, 0,0} };
	date d = pt.date();
	std::cout << d << std::endl;
	time_duration td = pt.time_of_day();
	std::cout << td << std::endl;
	std::cout << pt << std::endl;
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------
	//11. Creating a timepoint with a clock or a string
	ptime pt = second_clock::universal_time();
	std::cout << pt.date() << std::endl;
	std::cout << pt.time_of_day() << std::endl;

	pt = from_iso_string("20140131T120000");
	std::cout << pt.date() << std::endl;
	std::cout << pt.time_of_day() << std::endl;
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------
	//12. Using boost::posix_time::time_duration
	time_duration td{ 16, 30, 0 };
	std::cout << td.hours() << std::endl;
	std::cout << td.minutes() << std::endl;
	std::cout << td.seconds() << std::endl;
	std::cout << td.total_seconds() << std::endl;
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------
	//13. Processing timepoints
	ptime pt1{ date{2014,5,12}, time_duration{12,0,30} };
	ptime pt2{ date{2014,5,12},time_duration{18,30,0} };

	time_duration td = pt2 - pt1;
	std::cout << td.hours() << std::endl;
	std::cout << td.minutes() << std::endl;
	std::cout << td.seconds() << std::endl;
	/*------------------------------------------------------------------------*/
	
	/*------------------------------------------------------------------------
	//14. Processing time durations
	ptime pt{ date{2014,5,12}, time_duration{12,0,0} };
	time_duration td{ 6,30,0 };
	ptime pt2 = pt + td;
	std::cout << pt2 << std::endl;
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------
	//15. Using boost::posix_time::time_period
	ptime pt1{ date{2014,5,12},time_duration{12,0,0} };
	ptime pt2{ date{2014,5,12},time_duration{18,30,0} };
	time_period tp{ pt1, pt2 };
	std::cout.setf(std::ios::boolalpha);
	std::cout << tp.contains(pt1) << std::endl;
	std::cout << tp.contains(pt2) << std::endl;
	/*------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------*/
	//16. Iterating over points in time
	ptime pt{ date{2014, 5,12},time_duration{12, 0,0} };
	time_iterator it{ pt, time_duration{6,30,0} };
	std::cout << *++it << std::endl;
	std::cout << *++it << std::endl;
	/*------------------------------------------------------------------------*/

	std::cout << "\npress a key to exit.";
	std::getchar();
	return 0;
}