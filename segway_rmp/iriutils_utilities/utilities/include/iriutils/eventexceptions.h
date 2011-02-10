// Copyright (C) 2009-2010 Institut de Robòtica i Informàtica Industrial, CSIC-UPC.
// Author Sergi Hernandez  (shernand@iri.upc.edu)
// All rights reserved.
//
// This file is part of iriutils
// iriutils is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef EVENT_EXCEPTIONS
#define EVENT_EXCEPTIONS

#include "exceptions.h"

/**
 * \brief Event exception class
 *
 * This class implements the exceptions for the CEvent class. In addition
 * to the basic error message provided by the base class CException, this
 * exception class provides also the unique identifier of the event that
 * generated the exception.
 *
 * Also, similarly to other exception classes, it appends a class identifer
 * string ("[CEvent class] - ") to the error message in order to identify the
 * class that generated the exception.
 *
 * The base class can be used to catch any exception thrown by the application
 * or also, this class can be used in order to catch only exceptions generated 
 * by CEvent objects.
 */
class CEventException : public CException
{
  public:
    /**
     * \brief Constructor
     *
     * The constructor calls the base class constructor to add the general
     * exception identifier and then adds the class identifier string 
     * "[CEvent class]" and the supplied error message. 
     *
     * It also appends the unique identifier of the event that generated the
     * exception. So, the total exception message will look like this:
     *
     * \verbatim
     * [Exception caught] - <where>
     * [CEvent class] - <error message> - <event id>
     * \endverbatim
     *
     * \param where a null terminated string with the information about the name
     *              of the function, the source code filename and the line where
     *              the exception was generated. This string must be generated 
     *              by the _HERE_ macro.
     *
     * \param error_msg a null terminated string that contains the error message.
     *                  This string may have any valid character and there is no
     *                  limit on its length.
     *
     * \param event_id a null terminated string that contains the event unique
     *                 identifier. This string must be the one used to access
     *                 the corresponding event.
     *
     */
    CEventException(const std::string& where,const std::string& error_msg,const std::string& event_id);
};

/**
 * \brief Event server exception class
 *
 * This class implements the exceptions for the CEventServer class. In addition
 * to the basic error message provided by the base class CException, this
 * exception class provides also the unique identifier of the event that
 * generated the exception.
 *
 * Also, similarly to other exception classes, it appends a class identifer
 * string ("[CEventServer class] - ") to the error message in order to identify 
 * the class that generated the exception.
 *
 * The base class can be used to catch any exception thrown by the application
 * or also, this class can be used in order to catch only exceptions generated 
 * by CEventServer objects.
 *
 */
class CEventServerException : public CException
{
  public:
    /**
     * \brief Constructor
     *
     * The constructor calls the base class constructor to add the general
     * exception identifier and then adds the class identifier string 
     * "[CEventServer class]" and the supplied error message. 
     *
     * It also appends the unique identifier of the event that generated the
     * exception. So, the total exception message will look like this:
     *
     * \verbatim
     * [Exception caught] - <where>
     * [CEventServer class] - <error message> - <event id>
     * \endverbatim
     *
     * \param where a null terminated string with the information about the name
     *              of the function, the source code filename and the line where
     *              the exception was generated. This string must be generated 
     *              by the _HERE_ macro.
     *
     * \param error_msg a null terminated string that contains the error message.
     *                  This string may have any valid character and there is no
     *                  limit on its length.
     *
     * \param event_id a null terminated string that contains the event unique
     *                 identifier. This string must be the one used to access
     *                 the corresponding event.
     *
     *
     */  
    CEventServerException(const std::string& where,const std::string& error_msg,const std::string& event_id);
};

/**
 * \brief Event timeout exception class
 *
 * This class implements a special exception for the event server which indicates
 * a timeout. These is actually not an error because a timeout on the activation 
 * of an event can be handled by the application and even expected.
 * In addition to the basic error message provided by the base class CException, 
 * this exception class provides also the unique identifier of the event that
 * generated the exception.
 *
 * Also, similarly to other exception classes, it appends a class identifer
 * string ("[Timout] - ") to the error message in order to identify the
 * class that generated the exception.
 *
 * The base class can be used to catch any exception thrown by the application
 * or also, this class can be used in order to catch only exceptions generated 
 * by CEvent objects.
 */
class CEventTimeoutException : public CException
{
  public:
    /**
     * \brief Constructor
     *
     * The constructor calls the base class constructor to add the general
     * exception identifier and then adds the class identifier string 
     * "[Timeout]" and the supplied error message. 
     *
     * It also appends the unique identifier of the event that generated the
     * exception. So, the total exception message will look like this:
     *
     * \verbatim
     * [Exception caught] - 
     * [Timeout] - <event id>
     * \endverbatim
     *
     * \param event_id a null terminated string that contains the event unique
     *                 identifier. This string must be the one used to access
     *                 the corresponding event.
     *
     */
    CEventTimeoutException(const std::string& event_id);
};

#endif
