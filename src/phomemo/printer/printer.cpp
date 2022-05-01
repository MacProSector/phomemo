/*
 * printer.cpp
 *
 *  Created on: May 1, 2022
 *      Author: simonyu
 */

#include "utility/logger.h"
#include "common/platform.h"
#include "printer/printer.h"

phomemo::Printer::Printer(std::shared_ptr<Logger> logger) : logger_(logger),
        serial_port_(io_service_)
{
}

void
phomemo::Printer::connect(const std::string& device)
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
phomemo::Printer::connected()
{
    return serial_port_.is_open();
}
