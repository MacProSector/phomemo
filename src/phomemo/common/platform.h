/*
 * platform.h
 *
 *  Created on: May 1, 2022
 *      Author: simonyu
 */

#ifndef COMMON_PLATFORM_H_
#define COMMON_PLATFORM_H_

namespace phomemo
{
/*
 *	https://www.asciitable.com
 */
enum ESCPOSCommand : int
{
    NUL = 0x00,	//!< Null.
    SOH = 0x01,	//!< Start of heading.
    STX = 0x02, //!< Start of text.
    ETX = 0x03, //!< End of text.
    EOT = 0x04, //!< End of transmission.
    ENQ = 0x05, //!< Enquiry.
    ACK = 0x06,	//!< Acknowledge.
    BEL = 0x07,	//!< Bell.
    BS = 0x08,	//!< Backspace.
    TAB = 0x09,	//!< Horizontal tab.
    LF = 0x0A,	//!< Line feed.
    VT = 0x0B,	//!< Vertical tab.
    FF = 0x0C,	//!< Form feed.
    CR = 0x0D,	//!< Carriage return.
    SO = 0x0E,	//!< Shift out.
    SI = 0x0F,	//!< Shift in.
    DLE = 0x10,	//!< Data link escape.
    DC1 = 0x11,	//!< Device control 1.
    DC2 = 0x12,	//!< Device control 2.
    DC3 = 0x13,	//!< Device control 3.
    DC4 = 0x14,	//!< Device control 4.
    NAK = 0x15,	//!< Negative acknowledge.
    SYN = 0x16,	//!< Synchronous idle.
    ETB = 0x17,	//!< End of transmission block.
    CAN = 0x18,	//!< Cancel.
    EM = 0x19,	//!< End of medium.
    SUB = 0x1A,	//!< Substitude.
    ESC = 0x1B, //!< Escape.
    FS = 0x1C,	//!< File separator.
    GS = 0x1D,	//!< Group separator.
    RS = 0x1E,	//!< Record separator.
    US = 0x1F	//!< Unit separator.
};

enum SerialOption : int
{
    baud_rate = 9600,   //!< Baud rate.
    character_size = 8  //!< Character size.
};
}	// namespace tumbller

#endif	// COMMON_PLATFORM_H_
