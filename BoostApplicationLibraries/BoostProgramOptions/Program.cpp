// Program.cpp
//
//Boost.ProgramOptions
//
#include <boost/program_options.hpp>
#include <string>
#include <fstream>
#include <iostream>

/*--------------------------------------------------------------------------
//1. Basic approach with Boost.ProgramOptions
using namespace boost::program_options;

void on_age(int age)
{
	std::cout << "on age:" << age << std::endl;
}
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
//2. Special configuration settings with Boost.ProgramOptions
//3. Positional options with Boost.ProgramOptions
using namespace boost::program_options;

void to_count(const std::vector<std::string> &v)
{
	std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>{std::cout, "\n"});
}
/*--------------------------------------------------------------------------*/

int main(int argc, char *argv[])
{
	/*--------------------------------------------------------------------------
	//1. Basic approach with Boost.ProgramOptions
	try
	{
		options_description desc{ "Options" };
		desc.add_options()
			("help,p", "Help screen")
			("pi", value<float>()->default_value(3.14f), "Pi")
			("age", value<int>()->notifier(on_age), "Age")
			("name", value<std::string>(), "Name");
		variables_map vm;
		store(parse_command_line(argc, argv, desc), vm);
		notify(vm);

		if (vm.count("help"))
			std::cout << desc << std::endl;
		else if (vm.count("age"))
			std::cout << "Age:" << vm["age"].as<int>() << std::endl;
		else if (vm.count("name"))
			std::cout << "Name:" << vm["name"].as<std::string>() << std::endl;
		else if (vm.count("pi"))
			std::cout << "Pi:" << vm["pi"].as<float>() << std::endl;

		//notify(vm);
	}
	catch (const error &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	/*--------------------------------------------------------------------------*/


	/*--------------------------------------------------------------------------
	//2. Special configuration settings with Boost.ProgramOptions
	try
	{
		int age;
		options_description desc{ "Options" };
		desc.add_options()
			("help,h", "Help Screen")
			("pi", value<float>()->implicit_value(3.14f), "Pi")
			("age", value<int>(&age), "Age")
			("phone", value<std::vector<std::string>>()->multitoken()->zero_tokens()->composing(), "Phone")
			("unreg", "Unrecognized Option");

		command_line_parser parser{ argc, argv };
		parser.options(desc).allow_unregistered().style(command_line_style::default_style | command_line_style::allow_slash_for_short);
		parsed_options parsed_options = parser.run();

		variables_map vm;
		store(parsed_options, vm);
		notify(vm);

		if (vm.count("help"))
			std::cout << desc << std::endl;
		else if (vm.count("age"))
			std::cout << "Age:" << age << std::endl;
		else if (vm.count("phone"))
			to_count(vm["phone"].as<std::vector<std::string>>());
		else if (vm.count("unreg"))
			to_count(collect_unrecognized(parsed_options.options, exclude_positional));
		else if (vm.count("pi"))
			std::cout << "Pi:" << vm["pi"].as<float>() << std::endl;

	}
	catch (const error &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------
	//3. Positional options with Boost.ProgramOptions
	try
	{
		options_description desc{ "Options" };
		desc.add_options()
			("help,h", "help screen")
			("phone", value<std::vector<std::string>>()->multitoken()->zero_tokens()->composing(), "Phone");
		positional_options_description pos_desc;
		pos_desc.add("phone", -1);

		command_line_parser parser{ argc,argv };
		parser.options(desc).positional(pos_desc).allow_unregistered();
		parsed_options parsed = parser.run();

		variables_map vm;
		store(parsed, vm);
		notify(vm);

		if (vm.count("help"))
			std::cout << desc << std::endl;
		else if (vm.count("phone"))
			to_count(vm["phone"].as<std::vector<std::string>>());
	}
	catch (const error &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------*/
	//4. Loading options from a configuration file
	try
	{
		options_description generalOptions{ "General" };
		generalOptions.add_options()
			("help,h", "Help Screen")
			("config", value<std::string>(), "Config File");

		options_description fileOptions{ "File" };
		fileOptions.add_options()
			("age", value<int>(), "Age")
			("name", value<std::string>(), "Name");

		variables_map vm;
		store(parse_command_line(argc, argv, generalOptions), vm);
		if (vm.count("config"))
		{
			std::ifstream ifs{ vm["config"].as<std::string>().c_str() };
			if (ifs)
				store(parse_config_file(ifs, fileOptions), vm);
		}
		notify(vm);

		if (vm.count("help"))
			std::cout << generalOptions << std::endl;
		else if (vm.count("age"))
			std::cout << "Your age :" << vm["age"].as<int>() << std::endl;

		if (vm.count("name"))
			std::cout << "Your name: " << vm["name"].as<std::string>() << std::endl;
	}
	catch (const error &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	/*--------------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}