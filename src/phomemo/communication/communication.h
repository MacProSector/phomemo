/*
 * communication.h
 *
 *  Created on: May 1, 2022
 *      Author: simonyu
 */

#ifndef COMMUNICATION_COMMUNICATION_H_
#define COMMUNICATION_COMMUNICATION_H_

#include <string>

namespace phomemo
{
class Communication
{
public:

    virtual
    ~Communication() = default;

    virtual void
    open(const std::string& device) = 0;

    virtual std::size_t
    read(unsigned char* data, const std::size_t& size) = 0;

    virtual std::size_t
    write(const unsigned char* data, const std::size_t& size) = 0;

    virtual bool
    is_open() = 0;
};
}   // namespace phomemo

#endif  // COMMUNICATION_COMMUNICATION_H_
