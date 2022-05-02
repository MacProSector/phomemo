/*
 * test.cpp
 *
 *  Created on: May 1, 2022
 *      Author: simonyu
 */

#include <memory>

#include "communication/serial.h"
#include "utility/logger.h"
#include "printer/printer.h"

using namespace phomemo;

int
main()
{
    const std::string device = "/dev/tty.usbmodem14102";
    std::shared_ptr<Logger> logger = std::make_shared<Logger>();
    std::shared_ptr<Serial> communication = std::make_shared<Serial>(logger);
    std::shared_ptr<Printer> printer = std::make_shared<Printer>(logger, communication);

    communication->open(device);

    if (!communication->is_open())
    {
        logger->logError("Communication unavailable");
        return 1;
    }

    printer->initialize();
    printer->reset();
    printer->setJustification(Justification::left);

    logger->logInfo("Battery Level: " + printer->getBatteryLevel());
    logger->logInfo("Firmware Version: " + printer->getFirmwareVersion());
    logger->logInfo("Paper Level: " + printer->getPaperLevel());
    logger->logInfo("Serial Number: " + printer->getSerialNumber());

    return 0;
}
