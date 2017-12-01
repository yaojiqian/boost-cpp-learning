// Program.cpp
//

#include <iostream>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/read.hpp>
#include <boost/asio/spawn.hpp>
#include <array>
#include <string>

using namespace boost::asio;
using namespace boost::asio::ip;

io_service ioservice;
address_v4 tcp_address_v4{ std::array<unsigned char, 4>{127,0,0,1} };
tcp::endpoint tcp_endpoint{ tcp_address_v4 , 2012};
tcp::socket tcp_socket{ ioservice };
std::array<char, 4096> bytes;
//std::string bytes{ std::size_t(1024), '\0' };


//void read_handler(const boost::system::error_code &ec, std::size_t bytes_transferred)
//{
//	if (!ec)
//	{
//		std::cout.write(bytes.data(), bytes_transferred);
//	}
//}
//
//void connect_handler(const boost::system::error_code &ec)
//{
//	if (!ec)
//	{
//		tcp_socket.async_read_some(buffer(bytes), read_handler);
//	}
//}


void connect_and_read(yield_context yield)
{
	std::size_t bytes_transferred = 0;
	boost::system::error_code ec;

	tcp_socket.async_connect(tcp_endpoint, yield[ec]);
	if (ec)
	{
		std::cout << "connect failed\n";
		return;
	}
	bytes_transferred = tcp_socket.async_read_some(buffer(bytes), yield[ec]);

	/*std::string kk{ bytes.data() };
	std::cout << kk;*/
	std::cout.write(bytes.data(), bytes_transferred);
}

int main()
{

	//tcp_socket.async_connect(tcp_endpoint, connect_handler);
	spawn(ioservice, connect_and_read);
	ioservice.run();

	std::getchar();
	return 0;
}