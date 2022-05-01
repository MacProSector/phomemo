/*
 * serial.cpp
 *
 *  Created on: May 1, 2022
 *      Author: simonyu
 */

#include <boost/asio/buffer.hpp>

#include "utility/logger.h"
#include "common/platform.h"
#include "communication/serial.h"

namespace phomemo
{
Serial::Serial(std::shared_ptr<Logger> logger) : logger_(logger), serial_port_(io_service_)
{
}

void
Serial::open(const std::string& device)
{
    try
    {
        serial_port_.open(device);

        boost::asio::serial_port_base::baud_rate baud_rate(SerialOption::baud_rate);
        boost::asio::serial_port_base::character_size character_size(SerialOption::character_size);
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

std::size_t
Serial::read(unsigned char* data, const std::size_t& size)
{
    std::size_t bytes_read = 0;

    try
    {
        bytes_read = serial_port_.read_some(boost::asio::mutable_buffer(data, size));

        if (bytes_read != size)
        {
            logger_->logWarn(
                    std::to_string(bytes_read) + " bytes read. Expected " + std::to_string(size));
        }
    }
    catch (const boost::system::system_error &error)
    {
        logger_->logError(error.code().message());
    }

    return bytes_read;
}

std::size_t
Serial::write(const unsigned char* data, const std::size_t& size)
{
    std::size_t bytes_written = 0;

    try
    {
        bytes_written = serial_port_.write_some(boost::asio::const_buffer(data, size));

        if (bytes_written != size)
        {
            logger_->logWarn(
                    std::to_string(bytes_written) + " bytes written. Expected "
                            + std::to_string(size));
        }
    }
    catch (const boost::system::system_error &error)
    {
        logger_->logError(error.code().message());
    }

    return bytes_written;
}

bool
Serial::is_open()
{
    return serial_port_.is_open();
}
}   // namespace phomemo
