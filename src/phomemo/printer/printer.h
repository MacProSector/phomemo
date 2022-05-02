/*
 * printer.h
 *
 *  Created on: May 1, 2022
 *      Author: simonyu
 */

#ifndef PRINTER_PRINTER_H_
#define PRINTER_PRINTER_H_

#include <string>

#include "common/printing.h"

namespace phomemo
{
class Communication;
class Logger;

/*
 *  https://github.com/theacodes/phomemo_m02s
 *  https://github.com/hkeward/phomemo_printer
 *  https://reference.epson-biz.com/modules/ref_escpos/index.php?content_id=2
 *  https://escpos.readthedocs.io/en/latest/
 */
class Printer
{
public:

    Printer(std::shared_ptr<Logger> logger, std::shared_ptr<Communication> communication);

    std::string
    getBatteryLevel();

    std::string
    getFirmwareVersion();

    std::string
    getPaperLevel();

    std::string
    getSerialNumber();

    void
    setJustification(const Justification& justification);

    void
    initialize();

    void
    reset();

    void
    printLineFeed();

private:

    std::shared_ptr<Logger> logger_;
    std::shared_ptr<Communication> communication_;
};
}	// namespace phomemo

#endif	// PRINTER_PRINTER_H_
