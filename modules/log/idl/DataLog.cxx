// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file DataLog.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace { char dummy; }
#endif

#include "DataLog.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

DataLog::DataLog()
{
    // m_time com.eprosima.idl.parser.typecode.PrimitiveTypeCode@eec5a4a
    m_time = 0;
    // m_alive com.eprosima.idl.parser.typecode.PrimitiveTypeCode@6ddf90b0
    m_alive = false;

}

DataLog::~DataLog()
{


}

DataLog::DataLog(const DataLog &x)
{
    m_time = x.m_time;
    m_alive = x.m_alive;
}

DataLog::DataLog(DataLog &&x)
{
    m_time = x.m_time;
    m_alive = x.m_alive;
}

DataLog& DataLog::operator=(const DataLog &x)
{

    m_time = x.m_time;
    m_alive = x.m_alive;

    return *this;
}

DataLog& DataLog::operator=(DataLog &&x)
{

    m_time = x.m_time;
    m_alive = x.m_alive;

    return *this;
}

size_t DataLog::getMaxCdrSerializedSize(size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

size_t DataLog::getCdrSerializedSize(const DataLog& data, size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

void DataLog::serialize(eprosima::fastcdr::Cdr &scdr) const
{

    scdr << m_time;
    scdr << m_alive;
}

void DataLog::deserialize(eprosima::fastcdr::Cdr &dcdr)
{

    dcdr >> m_time;
    dcdr >> m_alive;
}

/*!
 * @brief This function sets a value in member time
 * @param _time New value for member time
 */
void DataLog::time(uint64_t _time)
{
m_time = _time;
}

/*!
 * @brief This function returns the value of member time
 * @return Value of member time
 */
uint64_t DataLog::time() const
{
    return m_time;
}

/*!
 * @brief This function returns a reference to member time
 * @return Reference to member time
 */
uint64_t& DataLog::time()
{
    return m_time;
}

/*!
 * @brief This function sets a value in member alive
 * @param _alive New value for member alive
 */
void DataLog::alive(bool _alive)
{
m_alive = _alive;
}

/*!
 * @brief This function returns the value of member alive
 * @return Value of member alive
 */
bool DataLog::alive() const
{
    return m_alive;
}

/*!
 * @brief This function returns a reference to member alive
 * @return Reference to member alive
 */
bool& DataLog::alive()
{
    return m_alive;
}


size_t DataLog::getKeyMaxCdrSerializedSize(size_t current_alignment)
{
    size_t current_align = current_alignment;





    return current_align;
}

bool DataLog::isKeyDefined()
{
   return false;
}

void DataLog::serializeKey(eprosima::fastcdr::Cdr &scdr) const
{
    (void) scdr;
     
     
}
