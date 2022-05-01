/*
 * test.cpp
 *
 *  Created on: May 1, 2022
 *      Author: simonyu
 */

#include <memory>

#include "utility/logger.h"
#include "printer/printer.h"

using namespace phomemo;

int
main()
{
    const std::string device = "/dev/tty.usbmodem14102";
    std::shared_ptr<Logger> logger = std::make_shared<Logger>();
    std::shared_ptr<Printer> printer = std::make_shared<Printer>(logger);

    printer->connect(device);

    logger->logInfo("Connected: " + std::to_string(printer->connected()));
    logger->logInfo("Serial Number: " + std::to_string(printer->getSerialNumber()));

    return 0;
}
