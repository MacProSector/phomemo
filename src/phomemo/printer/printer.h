/*
 * printer.h
 *
 *  Created on: May 1, 2022
 *      Author: simonyu
 */

#ifndef PRINTER_PRINTER_H_
#define PRINTER_PRINTER_H_

#include <string>

namespace phomemo
{
class Communication;
class Logger;

class Printer
{
public:

    Printer(std::shared_ptr<Logger> logger, std::shared_ptr<Communication> communication);

    std::string
    getSerialNumber();

    std::string
    getFirmwareVersion();

private:

    std::shared_ptr<Logger> logger_;
    std::shared_ptr<Communication> communication_;
};
}	// namespace phomemo

#endif	// PRINTER_PRINTER_H_
