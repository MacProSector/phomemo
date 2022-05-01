/*
 * serial.h
 *
 *  Created on: May 1, 2022
 *      Author: simonyu
 */

#ifndef COMMUNICATION_SERIAL_H_
#define COMMUNICATION_SERIAL_H_

#include <boost/asio/io_service.hpp>
#include <boost/asio/serial_port.hpp>

#include "communication/communication.h"

namespace phomemo
{
class Logger;

class Serial : public Communication
{
public:

    Serial(std::shared_ptr<Logger> logger);

    void
    open(const std::string& device) override;

    std::size_t
    read(unsigned char* data, const std::size_t& size) override;

    std::size_t
    write(const unsigned char* data, const std::size_t& size) override;

    bool
    is_open() override;

private:

    std::shared_ptr<Logger> logger_;

    boost::asio::io_service io_service_;
    boost::asio::serial_port serial_port_;
};
}   // namespace phomemo

#endif  // COMMUNICATION_SERIAL_H_
