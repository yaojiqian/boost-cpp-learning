// Program.cpp
//
//Exercise Boost.PropertyTree
//
//

#include <iostream>
#include <utility>
#include <boost/property_tree/ptree.hpp>
#include <boost/optional.hpp>
#include <boost/property_tree/json_parser.hpp>
//#include <boost/property_tree/xml_parser.hpp>
//#include <boost/property_tree/ini_parser.hpp>


struct string_to_int_translator
{
	typedef std::string internal_type;
	typedef int external_type;

	boost::optional<int> get_value(const std::string &s)
	{
		char *c;
		long l = std::strtol(s.c_str(), &c, 10);
		return boost::make_optional((c != s.c_str()), static_cast<int>(l));
	}
};


int main()
{
	/*---------------------------------------------------------------
	//1. Accessing data in boost::property_tree::ptree
	ptree pt;
	pt.put("C:.Windows.System", "20 files");//by default, the path's separator is dot.

	ptree &c = pt.get_child("C:");
	ptree &windows = c.get_child("Windows");
	ptree &system = windows.get_child("System");
	std::string v = system.get_value<std::string>();
	std::cout << v << std::endl;
	/*---------------------------------------------------------------*/

	/*---------------------------------------------------------------
	//2. Accessing data in basic_ptree<std::string, int>
	typedef boost::property_tree::basic_ptree<std::string, int> ptree;
	ptree pt;
	pt.put(ptree::path_type{ "C:\\Windows\\System", '\\' }, 20);
	pt.put(ptree::path_type{ "C:\\Windows\\Cursors", '\\' }, 50);
	pt.put(ptree::path_type{ "C:\\Windows", '\\' }, 40);



	ptree &windows = pt.get_child(ptree::path_type{ "C:\\Windows", '\\' });
	std::cout << windows.get_value<int>() << std::endl;
	int files = 0;
	for (const std::pair<std::string, ptree> &p : windows)
		files += p.second.get_value<int>();
	
	std::cout << files << std::endl;
	/*---------------------------------------------------------------*/

	/*---------------------------------------------------------------
	//3. Accessing data with a translator
	//boost::property_tree::iptree another predefined tree from Boost.PropertyTree. 
	//In general, this type behaves like boost::property_tree::ptree. 
	//The only difference is that boost::property_tree::iptree doesn’t distinguish between lower and upper case. 
	typedef boost::property_tree::iptree ptree;
	ptree pt;
	pt.put(ptree::path_type{ "C:\\Windows\\System", '\\' }, "20 files");
	pt.put(ptree::path_type{ "C:\\Windows\\Cursors", '\\' }, "50 files");


	ptree &windows = pt.get_child(ptree::path_type{ "C:\\Windows", '\\' });
	string_to_int_translator tr;
	int files = pt.get<int>(ptree::path_type{ "C:\\Windows\\System", '\\' }, tr)
		+ pt.get<int>(ptree::path_type{ "C:\\Windows\\Cursors",'\\' }, tr);

	std::cout << files << std::endl;
	/*---------------------------------------------------------------*/

	/*---------------------------------------------------------------
	//4. Various member functions of boost::property_tree::ptree
	using boost::property_tree::ptree;
	ptree pt;
	pt.put("C:.Windows.System", "20 files");

	boost::optional<std::string> c = pt.get_optional<std::string>("C:.Windows");
	std::cout << std::boolalpha << c.is_initialized() << std::endl;

	pt.put_child("D:.Program Files", ptree{ "50 files" });
	pt.add_child("D:.Program Files", ptree{ "60 files" });

	ptree d = pt.get_child("D:");
	for (std::pair<std::string, ptree> p : d)
		std::cout << p.second.get_value<std::string>() << std::endl;
	boost::optional<ptree&> e = pt.get_child_optional("E:");
	std::cout << std::boolalpha << e.is_initialized() << std::endl;
	/*---------------------------------------------------------------*/

	/*---------------------------------------------------------------*/
	//5. Serializing a boost::property_tree::ptree in the JSON format
	using namespace boost::property_tree;
	ptree pt;
	pt.put("C:.Windows.System", "20 files");
	pt.put("C:.Windows.Cursors", "50 files");

	pt.put_child("D:.Program Files", ptree{ "50 files" });
	pt.add_child("D:.Program Files", ptree{ "60 files" });

	json_parser::write_json("json.file", pt);
	//xml_parser::write_xml("ptree.xml", pt);

	ptree pt2;
	json_parser::read_json("json.file", pt2);
	std::cout << std::boolalpha << (pt == pt2) << std::endl;
	/*---------------------------------------------------------------*/


	std::getchar();
	return 0;
}