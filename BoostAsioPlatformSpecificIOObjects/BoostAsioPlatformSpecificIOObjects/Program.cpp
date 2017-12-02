// Program.cpp
//
//Platform-specific I/O Objects
//
//Boost.Asio also provides platform-specific I/O objects 
//because some asynchronous operations are only available 
//on certain platforms, for example, Windows or Linux.
//


#include <iostream>
#include <boost/asio/io_service.hpp>
//#include <boost/asio/windows/object_handle.hpp>
#include <boost/system/error_code.hpp>

#include <boost/asio/windows/overlapped_ptr.hpp>

#include <Windows.h>


using namespace boost::asio;
using namespace boost::system;


int main()
{
	/*-----------------------------------------------------------------------------------
	//8. Using boost::asio::windows::object_handle
	io_service ioservice;

	HANDLE file_handle = CreateFileA(".", FILE_LIST_DIRECTORY, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL,
		OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED, NULL);

	char buffer[1024];
	DWORD transferred;
	OVERLAPPED overlapped;
	ZeroMemory(&overlapped, sizeof(overlapped));
	overlapped.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	ReadDirectoryChangesW(file_handle, buffer, sizeof(buffer), FALSE, FILE_NOTIFY_CHANGE_FILE_NAME, &transferred, &overlapped, NULL);

	windows::object_handle obj_handle{ ioservice, overlapped.hEvent };
	obj_handle.async_wait([&buffer, &overlapped](const error_code &ec) {
		if (!ec)
		{
			DWORD transferred = 0;
			GetOverlappedResult(overlapped.hEvent, &overlapped, &transferred, FALSE);
			auto notification = reinterpret_cast<FILE_NOTIFY_INFORMATION *>(buffer);
			std::wcout << notification->Action << std::endl;
			std::streamsize size = notification->FileNameLength / sizeof(wchar_t);
			std::wcout.write( notification->FileName,size);
		}
	});

	ioservice.run();
	/*------------------------------------------------------------------------------------*/

	/*------------------------------------------------------------------------------------*/
	//9. Using boost::asio::windows::overlapped_ptr
	io_service ioservice;

	HANDLE file_handle = CreateFileA(".", FILE_LIST_DIRECTORY, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
		NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED, NULL);

	error_code ec;
	auto &io_service_impl = use_service<detail::io_service_impl>(ioservice);
	io_service_impl.register_handle(file_handle, ec);

	char buffer[1024];
	auto handler = [&buffer](const error_code &ec, std::size_t) {
		auto notification = reinterpret_cast<FILE_NOTIFY_INFORMATION*>(buffer);
		std::cout << notification->Action << std::endl;
		std::size_t size = notification->FileNameLength / sizeof(wchar_t);
		std::wcout << notification->FileName << '\n';
	};

	windows::overlapped_ptr overlapped{ ioservice, handler };
	DWORD transferred = 0;
	BOOL ok = ReadDirectoryChangesW(file_handle, buffer, sizeof(buffer), FALSE, FILE_NOTIFY_CHANGE_FILE_NAME, &transferred, overlapped.get(), NULL);
	int last_error = GetLastError();
	if (!ok && last_error != ERROR_IO_PENDING)
	{
		error_code ec1{ last_error, error::get_system_category() };
		overlapped.complete(ec1, 0);
	}
	else
	{
		overlapped.release();
	}
	ioservice.run();
	/*------------------------------------------------------------------------------------*/

	std::cout << "\npress a key to exit." << std::endl;
	std::getchar();
	return 0;
}