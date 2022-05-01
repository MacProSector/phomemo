/*
 *  Copyright (C) 2022  University of Illinois Board of Trustees
 *
 *  Developed by:   Simon Yu (jundayu2@illinois.edu)
 *                  Department of Electrical and Computer Engineering
 *                  https://www.simonyu.net/
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/**
 *  @file   logger.cpp
 *  @author Simon Yu
 *  @date   11/19/2021
 *  @brief  Logger class source.
 *
 *  This file implements the logger class.
 */

/*
 *  External headers.
 */
#include <iostream>

/*
 *  Project headers.
 */
#include "../utility/logger.h"

/*
 *  phomemo namespace.
 */
namespace phomemo
{
Logger::Logger() :
		log_level_(LogLevel::debug)
{
}

void
Logger::setLogLevel(const LogLevel& log_level)
{
	/*
	 *  Set the log level.
	 */
	log_level_ = log_level;
}

void
Logger::logRaw(const std::string& log)
{
	if (log == "")
	{
		/*
		 *  Prints new line if the message is empty.
		 */
		std::cout << std::endl;
	}
	else
	{
		/*
		 *  Prints the message as is with new line.
		 */
		std::cout << log << std::endl;
	}
}

void
Logger::logError(const std::string& log)
{
	/*
	 *  Check log level.
	 */
	if (log_level_ >= LogLevel::error)
	{
		if (log == "")
		{
			/*
			 *  Prints new line if the message is empty.
			 */
			std::cout << std::endl;
		}
		else
		{
			/*
			 *  Prints the message in error format
			 *  with new line and period.
			 */
			std::cout << "[ERROR]: " << log << "." << std::endl;
		}
	}
}

void
Logger::logWarn(const std::string& log)
{
	/*
	 *  Check log level.
	 */
	if (log_level_ >= LogLevel::warn)
	{
		if (log == "")
		{
			/*
			 *  Prints new line if the message is empty.
			 */
			std::cout << std::endl;
		}
		else
		{
			/*
			 *  Prints the message in warning format
			 *  with new line and period.
			 */
			std::cout << "[WARN]: " << log << "." << std::endl;
		}
	}
}

void
Logger::logInfo(const std::string& log)
{
	/*
	 *  Check log level.
	 */
	if (log_level_ >= LogLevel::info)
	{
		if (log == "")
		{
			/*
			 *  Prints new line if the message is empty.
			 */
			std::cout << std::endl;
		}
		else
		{
			/*
			 *  Prints the message in information format
			 *  with new line and period.
			 */
			std::cout << "[INFO]: " << log << "." << std::endl;
		}
	}
}

void
Logger::logDebug(const std::string& log)
{
	/*
	 *  Check log level.
	 */
	if (log_level_ >= LogLevel::debug)
	{
		if (log == "")
		{
			/*
			 *  Prints new line if the message is empty.
			 */
			std::cout << std::endl;
		}
		else
		{
			/*
			 *  Prints the message in debugging format
			 *  with new line and period.
			 */
			std::cout << "[DEBUG]: " << log << "." << std::endl;
		}
	}
}
}   // namespace phomemo
