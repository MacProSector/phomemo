/*
 * printer.cpp
 *
 *  Created on: May 1, 2022
 *      Author: simonyu
 */

#include <array>

#include "communication/communication.h"
#include "utility/logger.h"
#include "common/platform.h"
#include "printer/printer.h"

namespace phomemo
{
Printer::Printer(std::shared_ptr<Logger> logger, std::shared_ptr<Communication> communication) :
        logger_(logger), communication_(communication)
{
}

std::string
Printer::getBatteryLevel()
{
    if (!communication_->is_open())
    {
        logger_->logError("Communication unavailable");
        return std::string();
    }

    const std::array<unsigned char, 3> request = {ESCPOSCommand::US, ESCPOSCommand::DC1,
            ESCPOSCommand::BS};
    std::array<unsigned char, 3> response;

    communication_->write(request.data(), request.size());
    communication_->read(response.data(), response.size());

    return std::to_string(static_cast<int>(response[2]));
}

std::string
Printer::getFirmwareVersion()
{
    if (!communication_->is_open())
    {
        logger_->logError("Communication unavailable");
        return std::string();
    }

    const std::array<unsigned char, 3> request = {ESCPOSCommand::US, ESCPOSCommand::DC1,
            ESCPOSCommand::BEL};
    std::array<unsigned char, 5> response;
    std::string firmware_version = "";

    communication_->write(request.data(), request.size());
    communication_->read(response.data(), response.size());

    firmware_version += std::to_string(static_cast<int>(response[4]));
    firmware_version += ".";
    firmware_version += std::to_string(static_cast<int>(response[3]));
    firmware_version += ".";
    firmware_version += std::to_string(static_cast<int>(response[2]));

    return firmware_version;
}

std::string
Printer::getPaperLevel()
{
    if (!communication_->is_open())
    {
        logger_->logError("Communication unavailable");
        return std::string();
    }

    const std::array<unsigned char, 3> request = {ESCPOSCommand::US, ESCPOSCommand::DC1,
            ESCPOSCommand::DC1};
    std::array<unsigned char, 3> response;

    communication_->write(request.data(), request.size());
    communication_->read(response.data(), response.size());

    return std::to_string(static_cast<int>(response[2]));
}

std::string
Printer::getSerialNumber()
{
    if (!communication_->is_open())
    {
        logger_->logError("Communication unavailable");
        return std::string();
    }

    const std::array<unsigned char, 3> request = {ESCPOSCommand::US, ESCPOSCommand::DC1,
            ESCPOSCommand::DC3};
    std::array<unsigned char, 3> response;

    communication_->write(request.data(), request.size());
    communication_->read(response.data(), response.size());

    return std::to_string(static_cast<int>(response[2]));
}

void
Printer::setJustification(const Justification& justification)
{
    if (!communication_->is_open())
    {
        logger_->logError("Communication unavailable");
        return;
    }

    const std::array<unsigned char, 3> request = {ESCPOSCommand::ESC, 'a',
            static_cast<unsigned char>(justification)};

    communication_->write(request.data(), request.size());
}

void
Printer::initialize()
{
    if (!communication_->is_open())
    {
        logger_->logError("Communication unavailable");
        return;
    }

    const std::array<unsigned char, 2> request = {ESCPOSCommand::ESC, '@'};

    communication_->write(request.data(), request.size());
}

void
Printer::reset()
{
    if (!communication_->is_open())
    {
        logger_->logError("Communication unavailable");
        return;
    }

    const std::array<unsigned char, 3> request = {ESCPOSCommand::ESC, '@', ESCPOSCommand::STX};

    communication_->write(request.data(), request.size());
}

void
Printer::printLineFeed()
{
    if (!communication_->is_open())
    {
        logger_->logError("Communication unavailable");
        return;
    }

    const std::array<unsigned char, 1> request = {ESCPOSCommand::LF};

    communication_->write(request.data(), request.size());
}
}   // namespace phomemo
