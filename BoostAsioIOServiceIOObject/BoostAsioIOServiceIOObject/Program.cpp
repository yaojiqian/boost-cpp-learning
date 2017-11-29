// Program.cpp
//
//Asio stands for asynchronous input/output. This library makes it possible to process data asynchronously.
//


#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>

#include <chrono>
#include <thread>

using namespace boost::asio;

int main()
{

	/*------------------------------------------------------------------------------------
	//1. Using boost::asio::steady_timer
	io_service ioservice;

	steady_timer timer{ ioservice, std::chrono::seconds{3} };
	timer.async_wait([](const boost::system::error_code &ec) { std::cout << "3 sec" << std::endl; });
	//async_wait() returns immediately. Instead of waiting three seconds until the alarm clock rings, 
	//the lambda function is called after three seconds. 
	ioservice.run();
	/*------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------
	//2. Two asynchronous operations with boost::asio::steady_timer
	io_service ioservice;
	int sec = 3;

	steady_timer timer1{ ioservice,std::chrono::seconds{3} };
	timer1.async_wait([sec](const boost::system::error_code &ec) {std::cout << "3 sec" << sec << std::endl; });

	steady_timer timer2{ ioservice, std::chrono::seconds{6} };
	timer2.async_wait([](const boost::system::error_code &ec) {std::cout << "6 sec" << std::endl; });

	ioservice.run();
	//run() is called on the only I/O service object in this example. 
	//This call passes control to the operating system functions that execute asynchronous operations.
	//With their help, the first lambda function is called after three seconds and the second lambda function after four seconds.
	/*------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------
	//3. Two threads for the I/O service object to execute handlers concurrently
	io_service ioservice;

	steady_timer timer1{ ioservice, std::chrono::seconds{3} };
	timer1.async_wait([](const boost::system::error_code &ec) {std::cout << "3 sec 1" << std::endl; });

	steady_timer timer2{ ioservice,std::chrono::seconds{3} };
	timer2.async_wait([](const boost::system::error_code &ec) {std::cout << "3 sec 2" << std::endl; });

	std::thread thread1{ [&ioservice]() {ioservice.run(); } };
	std::thread thread2{ [&ioservice]() {ioservice.run(); } };

	thread1.join();
	thread2.join();
	/*------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------*/
	//4. One thread for each of two I/O service objects to execute handlers concurrently
	io_service ioservice1, ioservice2;
	
	steady_timer timer1{ ioservice1, std::chrono::seconds{3} };
	timer1.async_wait([](const boost::system::error_code &ec) {std::cout << "3 sec 1\n"; });

	steady_timer timer2{ ioservice2, std::chrono::seconds{3} };
	timer2.async_wait([](const boost::system::error_code &ec) {std::cout << "3 sec 2\n"; });

	std::thread thread1{ [&ioservice1]() {ioservice1.run(); } };
	std::thread thread2{ [&ioservice2]() {ioservice2.run(); } };

	thread1.join();
	thread2.join();
	/*------------------------------------------------------------------------------------*/

	std::getchar();
	return 0;
}