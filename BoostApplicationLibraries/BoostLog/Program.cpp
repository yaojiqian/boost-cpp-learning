// Program.cpp
//
//Boost.Log
//Boost.Log is the logging library in Boost. 
//It supports numerous back-ends to log data in various formats.

#include <boost/log/common.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/exceptions.hpp>
#include <boost/utility/empty_deleter.hpp>
#include <boost/log/utility/exception_handler.hpp>
//#include <boost/core/null_deleter.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>

using namespace boost::log;

/*---------------------------------------------------------------------------------
//2. boost::sources::severity_logger with a filter
bool only_warning(const attribute_value_set &set)
{
	return set["Severity"].extract<int>() > 0;
}
/*---------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------
//3. Changing the format of a log entry with set_formatter()
void severity_and_message(const record_view &view, formatting_ostream &os)
{
	os << view.attribute_values()["Severity"].extract<int>() << " : " << view.attribute_values()["Message"].extract<std::string>();
}
/*---------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------
//5. Defining keywords for attributes
BOOST_LOG_ATTRIBUTE_KEYWORD(severity , "Severity", int)
/*---------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------
//6. Defining attributes
//BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", int)
//BOOST_LOG_ATTRIBUTE_KEYWORD(counter, "LineCounter", int)
//BOOST_LOG_ATTRIBUTE_KEYWORD(timestamp, "Timestamp", boost::posix_time::ptime)
BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", int)
BOOST_LOG_ATTRIBUTE_KEYWORD(counter, "LineCounter", int)
BOOST_LOG_ATTRIBUTE_KEYWORD(timestamp, "Timestamp",	boost::posix_time::ptime)
/*---------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------
//7. Helper functions for filters and formats
BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", int)
BOOST_LOG_ATTRIBUTE_KEYWORD(counter, "LineCounter", int)
BOOST_LOG_ATTRIBUTE_KEYWORD(timestamp, "Timestamp", boost::posix_time::ptime)
/*---------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------
//8. Several loggers, front-ends, and back-ends
BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", int)
BOOST_LOG_ATTRIBUTE_KEYWORD(channel, "Channel", std::string)
/*---------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------
//9. Handling exceptions centrally
struct handler
{
	void operator()(const runtime_error &e) const
	{
		std::cerr << "boost::log::runtime_error:" << e.what() << std::endl;
	}

	void operator()(const std::exception &e) const
	{
		std::cerr << "std::exception:" << e.what() << std::endl;
	}
};
/*---------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------*/
//10. A macro to define a global logger
BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(lg, sources::wlogger_mt)
/*---------------------------------------------------------------------------------*/

int main()
{
	/*---------------------------------------------------------------------------------
	//1. Back-end, front-end, core, and logger
	//Back-ends decide where data is written;
	//Front-ends are the connection between the core and a back-end.
	//The core is the central component that all log entries are routed through.
	//The logger is the component in Boost.Log you will use most often.

	typedef sinks::asynchronous_sink<sinks::text_ostream_backend> text_sink;
	boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
	boost::shared_ptr<std::ostream> stream{ &std::clog, boost::empty_deleter{} };

	sink->locked_backend()->add_stream(stream);
	core::get()->add_sink(sink);
	sources::logger lg;

	BOOST_LOG(lg) << "note";
	sink->flush();
	//std::clog << "\nhello log";
	/*---------------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------------
	//2. boost::sources::severity_logger with a filter
	typedef sinks::asynchronous_sink<sinks::text_ostream_backend> text_sink;
	boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
	boost::shared_ptr<std::ostream> stream{ &std::clog, boost::empty_deleter{} };

	sink->locked_backend()->add_stream(stream);
	sink->set_filter(&only_warning);

	core::get()->add_sink(sink);
	sources::severity_logger<int> lg;

	BOOST_LOG(lg) << "note";
	BOOST_LOG_SEV(lg, 0) << "another note";
	BOOST_LOG_SEV(lg, 1) << "warning";
	sink->flush();
	
	/*---------------------------------------------------------------------------------*/


	/*---------------------------------------------------------------------------------
	//3. Changing the format of a log entry with set_formatter()
	typedef sinks::asynchronous_sink<sinks::text_ostream_backend> text_sink;
	boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
	boost::shared_ptr<std::ostream> stream{ &std::clog, boost::empty_deleter{} };

	sink->locked_backend()->add_stream(stream);
	sink->set_formatter(&severity_and_message);

	core::get()->add_sink(sink);
	sources::severity_logger<> lg;
	BOOST_LOG_SEV(lg, 0) << "note";
	BOOST_LOG_SEV(lg, 1) << "warning";
	sink->flush();
	/*---------------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------------
	//4. Filtering log entries and formatting them with lambda functions
	typedef sinks::asynchronous_sink<sinks::text_ostream_backend> text_sink;
	boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
	boost::shared_ptr<std::ostream> stream{ &std::clog, boost::empty_deleter{} };

	sink->locked_backend()->add_stream(stream);
	sink->set_filter(expressions::attr<int>("Severity") > 0);
	sink->set_formatter(expressions::stream << expressions::attr<int>("Severity") << " : " << expressions::smessage);

	core::get()->add_sink(sink);

	sources::severity_logger<int> lg;

	BOOST_LOG_SEV(lg, 0) << "note";
	BOOST_LOG_SEV(lg, 1) << "warning";
	BOOST_LOG_SEV(lg, 2) << "error";
	sink->flush();
	/*---------------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------------
	//5. Defining keywords for attributes
	typedef sinks::asynchronous_sink<sinks::text_ostream_backend> text_sink;
	boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
	boost::shared_ptr<std::ostream> stream{ &std::clog, boost::empty_deleter{} };

	sink->locked_backend()->add_stream(stream);
	sink->set_filter(severity > 0);
	sink->set_formatter(expressions::stream << severity << " : " << expressions::smessage);

	core::get()->add_sink(sink);

	sources::severity_logger<int> lg;

	BOOST_LOG_SEV(lg, 0) << "note";
	BOOST_LOG_SEV(lg, 1) << "warning";
	BOOST_LOG_SEV(lg, 2) << "error";
	sink->flush();

	/*---------------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------------
	//6. Defining attributes
	typedef sinks::asynchronous_sink<sinks::text_ostream_backend> text_sink;
	boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
	boost::shared_ptr<std::ostream> stream{ &std::clog, boost::empty_deleter{} };

	sink->locked_backend()->add_stream(stream);
	sink->set_filter(severity > 0);
	sink->set_formatter(expressions::stream << counter << "-" << severity << " : " << expressions::smessage << "(" << timestamp << ")" );

	core::get()->add_sink(sink);
	core::get()->add_global_attribute("LineCounter", attributes::counter<int>{});
	sources::severity_logger<int> lg;

	BOOST_LOG_SEV(lg, 0) << "note";
	BOOST_LOG_SEV(lg, 1) << "warning";
	//{
		BOOST_LOG_SCOPED_LOGGER_ATTR(lg, "Timestamp", attributes::local_clock());
		BOOST_LOG_SEV(lg, 2) << "error";
	//}
	BOOST_LOG_SEV(lg, 2) << "another error";
	sink->flush();
	/*---------------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------------
	//7. Helper functions for filters and formats
	typedef sinks::asynchronous_sink<sinks::text_ostream_backend> text_sink;
	boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
	boost::shared_ptr<std::ostream> stream{ &std::clog, boost::empty_deleter{} };

	sink->locked_backend()->add_stream(stream);
	sink->set_filter(severity > 0);
	sink->set_formatter(expressions::stream << counter << "-" << std::setw(5) << severity << " :" << expressions::smessage << "(" << expressions::format_date_time(timestamp, "%H:%M:%S") << ")");
	
	core::get()->add_sink(sink);
	core::get()->add_global_attribute("LineCounter", attributes::counter<int>{});
	sources::severity_logger<int> lg;

	BOOST_LOG_SEV(lg, 0) << "note";
	BOOST_LOG_SEV(lg, 1) << "warning";
	{
		BOOST_LOG_SCOPED_LOGGER_ATTR(lg, "Timestamp", attributes::local_clock());
		BOOST_LOG_SEV(lg, 2) << "error";
	}
	BOOST_LOG_SEV(lg, 2) << "another error";
	sink->flush();
	/*---------------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------------
	//8. Several loggers, front-ends, and back-ends
	typedef sinks::asynchronous_sink<sinks::text_ostream_backend> ostream_sink;
	boost::shared_ptr<ostream_sink> ostream = boost::make_shared<ostream_sink>();
	boost::shared_ptr<std::ostream> clog{ &std::clog, boost::empty_deleter{} };
	ostream->locked_backend()->add_stream(clog);
	core::get()->add_sink(ostream);

	typedef sinks::synchronous_sink<sinks::text_multifile_backend> multifile_sink;
	boost::shared_ptr<multifile_sink> multifile = boost::make_shared<multifile_sink>();
	multifile->locked_backend()->set_file_name_composer(sinks::file::as_file_name_composer(expressions::stream <<
		channel.or_default<std::string>("None") << "-" <<
		severity.or_default(0) << ".log"));
	core::get()->add_sink(multifile);

	sources::severity_logger<int> severity_lg;
	sources::channel_logger<> channel_lg{ keywords::channel = "Main" };

	BOOST_LOG_SEV(severity_lg, 1) << "severity message";
	BOOST_LOG(channel_lg) << "channel maessage";
	ostream->flush();
	/*---------------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------------
	//9. Handling exceptions centrally
	typedef sinks::synchronous_sink<sinks::text_ostream_backend> text_sink;
	boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
	boost::shared_ptr<std::ostream> stream{ &std::clog, boost::empty_deleter{} };

	sink->locked_backend()->add_stream(stream);

	core::get()->add_sink(sink);
	core::get()->set_exception_handler(make_exception_handler<runtime_error, std::exception>(handler{}));

	sources::logger lg;

	BOOST_LOG(lg) << "note";
	/*---------------------------------------------------------------------------------*/


	/*---------------------------------------------------------------------------------*/
	//10. A macro to define a global logger
	typedef sinks::synchronous_sink<sinks::text_ostream_backend> text_sink;
	boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();
	boost::shared_ptr<std::ostream> stream{ &std::clog, boost::empty_deleter{} };

	sink->locked_backend()->add_stream(stream);

	core::get()->add_sink(sink);

	BOOST_LOG(lg::get()) << L"note";
	/*---------------------------------------------------------------------------------*/

	std::cout << "\npress a key to exit";
	std::getchar();
	return 0;
}