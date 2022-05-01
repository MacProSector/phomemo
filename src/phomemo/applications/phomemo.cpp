/*
 * phomemo.cpp
 *
 *  Created on: May 1, 2022
 *      Author: simonyu
 */

#include <memory>

#include "utility/logger.h"

using namespace phomemo;

int
main()
{
    std::shared_ptr<Logger> logger = std::make_shared<Logger>();

    logger->logInfo("Hello world");

    return 0;
}
