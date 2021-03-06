#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/algorithm/string.hpp>

using boost::asio::ip::udp;

void udp_receive_thread(void );

struct fVector3
{
	double m_x;
	double m_y;
	double m_z;
};

class udp_receiver
{
	public:
		udp_receiver(boost::asio::io_service& io_service)
			: socket_(io_service, udp::endpoint(udp::v4(), UDP_PORT))
		{
			//constructor start receiver
			start_receive();
		}
		fVector3 vPos;

	private:
		const static int UDP_PORT = 12345;
		udp::socket socket_;
		udp::endpoint remote_endpoint_;

		boost::array<char,2048> recv_buf;

		void start_receive(){
			socket_.async_receive_from(
					boost::asio::buffer(recv_buf), remote_endpoint_,
					boost::bind(&udp_receiver::handle_receive, this,
						boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
			// Waitting event here
			//std::cout << "Waitting" << std::endl;
		}

		void handle_receive(const boost::system::error_code& error, size_t len){
			if (!error || error == boost::asio::error::message_size){
				std::string message(recv_buf.data(), len);
				//any function;
					// show message on terminal
					// std::cout << message << std::endl; // all message
					std::vector<std::string> data_str(3);
					boost::split(data_str, message, boost::is_space());
					vPos.m_x = std::atoi(data_str[0].c_str());
					vPos.m_y = std::atoi(data_str[1].c_str());
					vPos.m_z = std::atoi(data_str[2].c_str());
					std::cout << "x :" << vPos.m_x << " y :" << vPos.m_y << " z :" << vPos.m_z << std::endl;

				start_receive();
			}
		}
};

void udp_receive_thread() {
	try {
		boost::asio::io_service io_service;
		udp_receiver receiver(io_service);
		io_service.run();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

int main()
{
	boost::thread thr_udp(&udp_receive_thread);
	while (1)
	{
		
	}

	return 0;
}

