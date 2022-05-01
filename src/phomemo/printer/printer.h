/*
 * printer.h
 *
 *  Created on: May 1, 2022
 *      Author: simonyu
 */

#ifndef PRINTER_PRINTER_H_
#define PRINTER_PRINTER_H_

#include <boost/asio/io_service.hpp>
#include <boost/asio/serial_port.hpp>
#include <string>

namespace phomemo
{
class Logger;

class Printer
{
public:

	Printer(std::shared_ptr<Logger> logger);

	int
	getSerialNumber();

	void
	connect(const std::string& device);

	bool
	connected();

private:

	std::shared_ptr<Logger> logger_;

	boost::asio::io_service io_service_;
	boost::asio::serial_port serial_port_;
};
}	// namespace phomemo

#endif	// PRINTER_PRINTER_H_
