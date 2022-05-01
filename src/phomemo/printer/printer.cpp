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
Printer::getSerialNumber()
{
    if (!communication_->is_open())
    {
        logger_->logError("Communication unavailable");
        return std::string();
    }

    const std::array<unsigned char, 3> request = {ESCPOSCommand::US, 0x11, 0x13};
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

    const std::array<unsigned char, 3> request = {ESCPOSCommand::US, 0x11, 0x07};
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
}   // namespace phomemo
