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
 * @file DataRaiOut.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace { char dummy; }
#endif

#include "DataRaiOut.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

DataRaiOut::DataRaiOut()
{
    // m_time com.eprosima.idl.parser.typecode.PrimitiveTypeCode@4b4523f8
    m_time = 0;
    // m_chnl com.eprosima.idl.parser.typecode.ArrayTypeCode@731a74c
    memset(&m_chnl, 0, (12) * 2);
    // m_roll com.eprosima.idl.parser.typecode.PrimitiveTypeCode@369f73a2
    m_roll = 0.0;
    // m_pitch com.eprosima.idl.parser.typecode.PrimitiveTypeCode@1f28c152
    m_pitch = 0.0;
    // m_yaw com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7d907bac
    m_yaw = 0.0;
    // m_thr com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7791a895
    m_thr = 0.0;
    // m_fltMode com.eprosima.idl.parser.typecode.PrimitiveTypeCode@3a5ed7a6
    m_fltMode = 0;
    // m_alive com.eprosima.idl.parser.typecode.PrimitiveTypeCode@6325a3ee
    m_alive = false;

}

DataRaiOut::~DataRaiOut()
{








}

DataRaiOut::DataRaiOut(const DataRaiOut &x)
{
    m_time = x.m_time;
    m_chnl = x.m_chnl;
    m_roll = x.m_roll;
    m_pitch = x.m_pitch;
    m_yaw = x.m_yaw;
    m_thr = x.m_thr;
    m_fltMode = x.m_fltMode;
    m_alive = x.m_alive;
}

DataRaiOut::DataRaiOut(DataRaiOut &&x)
{
    m_time = x.m_time;
    m_chnl = std::move(x.m_chnl);
    m_roll = x.m_roll;
    m_pitch = x.m_pitch;
    m_yaw = x.m_yaw;
    m_thr = x.m_thr;
    m_fltMode = x.m_fltMode;
    m_alive = x.m_alive;
}

DataRaiOut& DataRaiOut::operator=(const DataRaiOut &x)
{

    m_time = x.m_time;
    m_chnl = x.m_chnl;
    m_roll = x.m_roll;
    m_pitch = x.m_pitch;
    m_yaw = x.m_yaw;
    m_thr = x.m_thr;
    m_fltMode = x.m_fltMode;
    m_alive = x.m_alive;

    return *this;
}

DataRaiOut& DataRaiOut::operator=(DataRaiOut &&x)
{

    m_time = x.m_time;
    m_chnl = std::move(x.m_chnl);
    m_roll = x.m_roll;
    m_pitch = x.m_pitch;
    m_yaw = x.m_yaw;
    m_thr = x.m_thr;
    m_fltMode = x.m_fltMode;
    m_alive = x.m_alive;

    return *this;
}

size_t DataRaiOut::getMaxCdrSerializedSize(size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += ((12) * 2) + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

size_t DataRaiOut::getCdrSerializedSize(const DataRaiOut& data, size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    if ((12) > 0)
    {
        current_alignment += ((12) * 2) + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);
    }

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

void DataRaiOut::serialize(eprosima::fastcdr::Cdr &scdr) const
{

    scdr << m_time;
    scdr << m_chnl;

    scdr << m_roll;
    scdr << m_pitch;
    scdr << m_yaw;
    scdr << m_thr;
    scdr << m_fltMode;
    scdr << m_alive;
}

void DataRaiOut::deserialize(eprosima::fastcdr::Cdr &dcdr)
{

    dcdr >> m_time;
    dcdr >> m_chnl;

    dcdr >> m_roll;
    dcdr >> m_pitch;
    dcdr >> m_yaw;
    dcdr >> m_thr;
    dcdr >> m_fltMode;
    dcdr >> m_alive;
}

/*!
 * @brief This function sets a value in member time
 * @param _time New value for member time
 */
void DataRaiOut::time(uint64_t _time)
{
m_time = _time;
}

/*!
 * @brief This function returns the value of member time
 * @return Value of member time
 */
uint64_t DataRaiOut::time() const
{
    return m_time;
}

/*!
 * @brief This function returns a reference to member time
 * @return Reference to member time
 */
uint64_t& DataRaiOut::time()
{
    return m_time;
}

/*!
 * @brief This function copies the value in member chnl
 * @param _chnl New value to be copied in member chnl
 */
void DataRaiOut::chnl(const std::array<uint16_t, 12> &_chnl)
{
m_chnl = _chnl;
}

/*!
 * @brief This function moves the value in member chnl
 * @param _chnl New value to be moved in member chnl
 */
void DataRaiOut::chnl(std::array<uint16_t, 12> &&_chnl)
{
m_chnl = std::move(_chnl);
}

/*!
 * @brief This function returns a constant reference to member chnl
 * @return Constant reference to member chnl
 */
const std::array<uint16_t, 12>& DataRaiOut::chnl() const
{
    return m_chnl;
}

/*!
 * @brief This function returns a reference to member chnl
 * @return Reference to member chnl
 */
std::array<uint16_t, 12>& DataRaiOut::chnl()
{
    return m_chnl;
}
/*!
 * @brief This function sets a value in member roll
 * @param _roll New value for member roll
 */
void DataRaiOut::roll(float _roll)
{
m_roll = _roll;
}

/*!
 * @brief This function returns the value of member roll
 * @return Value of member roll
 */
float DataRaiOut::roll() const
{
    return m_roll;
}

/*!
 * @brief This function returns a reference to member roll
 * @return Reference to member roll
 */
float& DataRaiOut::roll()
{
    return m_roll;
}

/*!
 * @brief This function sets a value in member pitch
 * @param _pitch New value for member pitch
 */
void DataRaiOut::pitch(float _pitch)
{
m_pitch = _pitch;
}

/*!
 * @brief This function returns the value of member pitch
 * @return Value of member pitch
 */
float DataRaiOut::pitch() const
{
    return m_pitch;
}

/*!
 * @brief This function returns a reference to member pitch
 * @return Reference to member pitch
 */
float& DataRaiOut::pitch()
{
    return m_pitch;
}

/*!
 * @brief This function sets a value in member yaw
 * @param _yaw New value for member yaw
 */
void DataRaiOut::yaw(float _yaw)
{
m_yaw = _yaw;
}

/*!
 * @brief This function returns the value of member yaw
 * @return Value of member yaw
 */
float DataRaiOut::yaw() const
{
    return m_yaw;
}

/*!
 * @brief This function returns a reference to member yaw
 * @return Reference to member yaw
 */
float& DataRaiOut::yaw()
{
    return m_yaw;
}

/*!
 * @brief This function sets a value in member thr
 * @param _thr New value for member thr
 */
void DataRaiOut::thr(float _thr)
{
m_thr = _thr;
}

/*!
 * @brief This function returns the value of member thr
 * @return Value of member thr
 */
float DataRaiOut::thr() const
{
    return m_thr;
}

/*!
 * @brief This function returns a reference to member thr
 * @return Reference to member thr
 */
float& DataRaiOut::thr()
{
    return m_thr;
}

/*!
 * @brief This function sets a value in member fltMode
 * @param _fltMode New value for member fltMode
 */
void DataRaiOut::fltMode(uint16_t _fltMode)
{
m_fltMode = _fltMode;
}

/*!
 * @brief This function returns the value of member fltMode
 * @return Value of member fltMode
 */
uint16_t DataRaiOut::fltMode() const
{
    return m_fltMode;
}

/*!
 * @brief This function returns a reference to member fltMode
 * @return Reference to member fltMode
 */
uint16_t& DataRaiOut::fltMode()
{
    return m_fltMode;
}

/*!
 * @brief This function sets a value in member alive
 * @param _alive New value for member alive
 */
void DataRaiOut::alive(bool _alive)
{
m_alive = _alive;
}

/*!
 * @brief This function returns the value of member alive
 * @return Value of member alive
 */
bool DataRaiOut::alive() const
{
    return m_alive;
}

/*!
 * @brief This function returns a reference to member alive
 * @return Reference to member alive
 */
bool& DataRaiOut::alive()
{
    return m_alive;
}


size_t DataRaiOut::getKeyMaxCdrSerializedSize(size_t current_alignment)
{
    size_t current_align = current_alignment;











    return current_align;
}

bool DataRaiOut::isKeyDefined()
{
   return false;
}

void DataRaiOut::serializeKey(eprosima::fastcdr::Cdr &scdr) const
{
    (void) scdr;
     
     
     
     
     
     
     
     
}
