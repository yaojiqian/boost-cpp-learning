// Program.cpp
//
//Boost Asio Network programming
//
//Network functions are a perfect use for asynchronous operations 
//because the transmission of data over a network may take a long time, 
//which means acknowledgments and errors may not be available 
//as fast as the functions that send or receive data can execute.
//

#include <boost/asio/io_service.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <array>
#include <string>
#include <iostream>

using namespace boost::asio;
using namespace boost::asio::ip;

/*-------------------------------------------------------------------------
//5. A web client with boost::asio::ip::tcp::socket
io_service ioservice;
tcp::resolver resolv{ ioservice };
tcp::socket tcp_socket{ ioservice };
std::array<char, 4096> bytes;

void read_handler(const boost::system::error_code &ec, std::size_t bytes_transferred)
{
	if (!ec)
	{
		std::cout.write(bytes.data(), bytes_transferred);
		tcp_socket.async_read_some(buffer(bytes), read_handler);
	}
}

void connect_handler(const boost::system::error_code &ec)
{
	if (!ec)
	{
		std::string r = "GET /HTTP/1.1\r\nHost: theboostcpplibraries.com\r\n\r\n";
		write(tcp_socket, buffer(r));
		tcp_socket.async_read_some(buffer(bytes), read_handler);
	}
}

void resolve_handler(const boost::system::error_code &ec, tcp::resolver::iterator it)
{
	if (!ec)
		tcp_socket.async_connect(*it, connect_handler);
}
/*-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------*/
//6. A time server with boost::asio::ip::tcp::acceptor
io_service ioservice;
tcp::endpoint tcp_endpoint{ tcp::v4(), 2012 };
tcp::acceptor tcp_acceptor{ ioservice, tcp_endpoint };
tcp::socket tcp_socket{ ioservice };
std::string data;

void write_handler(const boost::system::error_code &ec, std::size_t bytes_transfered)
{
	if (!ec)
		tcp_socket.shutdown(tcp::socket::shutdown_send);
}

void accept_handler(const boost::system::error_code &ec)
{
	if (!ec) 
	{
		std::time_t now = std::time(nullptr);
		data = std::ctime(&now);
		tcp_socket.async_write_some(buffer(data), write_handler);
	}
}
/*-------------------------------------------------------------------------*/

int main()
{
	/*---------------------------------------------------------------------
	//5. A web client with boost::asio::ip::tcp::socket
	tcp::resolver::query q{ "theboostcpplibraries.com", "80" };
	resolv.async_resolve(q, resolve_handler);
	ioservice.run();
	/*---------------------------------------------------------------------*/


	/*---------------------------------------------------------------------*/
	//6. A time server with boost::asio::ip::tcp::acceptor
	tcp_acceptor.listen();
	tcp_acceptor.async_accept(tcp_socket, tcp_endpoint, accept_handler);
	ioservice.run();
	/*---------------------------------------------------------------------*/

	std::getchar();
	return 0;
}