/*
 * printer.cpp
 *
 *  Created on: May 1, 2022
 *      Author: simonyu
 */

#include <array>
#include <boost/asio/buffer.hpp>

#include "utility/logger.h"
#include "common/platform.h"
#include "printer/printer.h"

namespace phomemo
{
Printer::Printer(std::shared_ptr<Logger> logger) : logger_(logger), serial_port_(io_service_)
{
}

int
Printer::getSerialNumber()
{
    const unsigned char request[3] = {ESCPOSCommand::US, 0x11, 0x13};
    unsigned char response[3];

    try
    {
        const auto bytes_written = serial_port_.write_some(
                boost::asio::const_buffer(request, sizeof(request)));
        logger_->logDebug("Bytes written: " + std::to_string(bytes_written));
    }
    catch (const boost::system::system_error &error)
    {
        logger_->logError(error.code().message());
    }

    try
    {
        const auto bytes_read = serial_port_.read_some(
                boost::asio::mutable_buffer(response, sizeof(response)));
        logger_->logDebug("Bytes read: " + std::to_string(bytes_read));
    }
    catch (const boost::system::system_error &error)
    {
        logger_->logError(error.code().message());
    }

    return static_cast<int>(response[2]);
}

void
Printer::connect(const std::string& device)
{
    try
    {
        serial_port_.open(device);

        boost::asio::serial_port_base::baud_rate baud_rate(Serial::baud_rate);
        boost::asio::serial_port_base::character_size character_size(Serial::character_size);
        boost::asio::serial_port_base::parity parity(
                boost::asio::serial_port_base::parity::type::none);
        boost::asio::serial_port_base::stop_bits stop_bits(
                boost::asio::serial_port_base::stop_bits::type::one);

        serial_port_.set_option(baud_rate);
        serial_port_.set_option(character_size);
        serial_port_.set_option(parity);
        serial_port_.set_option(stop_bits);
    }
    catch (const boost::system::system_error &error)
    {
        logger_->logError(error.code().message());
    }
}

bool
Printer::connected()
{
    return serial_port_.is_open();
}
}   // namespace phomemo
