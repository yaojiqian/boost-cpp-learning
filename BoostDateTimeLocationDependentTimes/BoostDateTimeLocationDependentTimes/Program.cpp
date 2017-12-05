// Program.cpp
//
//Location-dependent Times
//

#include <boost/date_time/local_time/local_time.hpp>
#include <iostream>

using namespace boost::local_time;
using namespace boost::gregorian;
using namespace boost::posix_time;

int main()
{
	/*----------------------------------------------------------------------
	//17. Using boost::local_time::local_date_time
	time_zone_ptr tz{ new posix_time_zone{"EST+1"} };
	ptime pt{ date{2014,5,12},time_duration{12,0,0} };
	local_date_time dt{ pt, tz };
	std::cout << dt.utc_time() << std::endl;
	std::cout << dt << std::endl;
	std::cout << dt.local_time() << std::endl;
	std::cout << dt.zone_name() << std::endl;
	/*----------------------------------------------------------------------*/

	/*----------------------------------------------------------------------
	//18. Location-dependent points in time and different time zones
	time_zone_ptr tz{ new posix_time_zone{"CET+1"} };
	ptime pt{ date{2014,5,12},time_duration{12,0,0} };
	local_date_time dt{ pt,tz };
	std::cout << dt << std::endl;

	time_zone_ptr tz2{ new posix_time_zone{"EET+2"} };
	std::cout << dt.local_time_in(tz2) << std::endl;
	/*----------------------------------------------------------------------*/

	/*----------------------------------------------------------------------*/
	//19. Using boost::local_time::local_time_period
	time_zone_ptr tz{ new posix_time_zone("CET+0") };

	ptime pt1{ date{2014,5,12},time_duration{12,0,0} };
	ptime pt2{ date{2014,5,12},time_duration{18,0,0} };
	local_date_time dt1{ pt1, tz };
	local_date_time dt2{ pt2, tz };
	local_time_period tp{ dt1, dt2 };
	std::cout.setf(std::ios::boolalpha);
	std::cout << tp.contains(dt1) << std::endl;
	std::cout << tp.contains(dt2) << std::endl;
	/*----------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}