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
 * @file DataRaiIn.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace { char dummy; }
#endif

#include "DataRaiIn.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

DataRaiIn::DataRaiIn()
{
    // m_time com.eprosima.idl.parser.typecode.PrimitiveTypeCode@4b4523f8
    m_time = 0;
    // m_senseTime com.eprosima.idl.parser.typecode.PrimitiveTypeCode@731a74c
    m_senseTime = 0.0;
    // m_chnl com.eprosima.idl.parser.typecode.ArrayTypeCode@369f73a2
    memset(&m_chnl, 0, (12) * 2);
    // m_roll com.eprosima.idl.parser.typecode.PrimitiveTypeCode@1f28c152
    m_roll = 0.0;
    // m_pitch com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7d907bac
    m_pitch = 0.0;
    // m_yaw com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7791a895
    m_yaw = 0.0;
    // m_thr com.eprosima.idl.parser.typecode.PrimitiveTypeCode@6325a3ee
    m_thr = 0.0;
    // m_fltMode com.eprosima.idl.parser.typecode.PrimitiveTypeCode@67b92f0a
    m_fltMode = 0;
    // m_fltFunc com.eprosima.idl.parser.typecode.PrimitiveTypeCode@2b9627bc
    m_fltFunc = 0;
    // m_alive com.eprosima.idl.parser.typecode.PrimitiveTypeCode@65e2dbf3
    m_alive = false;

}

DataRaiIn::~DataRaiIn()
{










}

DataRaiIn::DataRaiIn(const DataRaiIn &x)
{
    m_time = x.m_time;
    m_senseTime = x.m_senseTime;
    m_chnl = x.m_chnl;
    m_roll = x.m_roll;
    m_pitch = x.m_pitch;
    m_yaw = x.m_yaw;
    m_thr = x.m_thr;
    m_fltMode = x.m_fltMode;
    m_fltFunc = x.m_fltFunc;
    m_alive = x.m_alive;
}

DataRaiIn::DataRaiIn(DataRaiIn &&x)
{
    m_time = x.m_time;
    m_senseTime = x.m_senseTime;
    m_chnl = std::move(x.m_chnl);
    m_roll = x.m_roll;
    m_pitch = x.m_pitch;
    m_yaw = x.m_yaw;
    m_thr = x.m_thr;
    m_fltMode = x.m_fltMode;
    m_fltFunc = x.m_fltFunc;
    m_alive = x.m_alive;
}

DataRaiIn& DataRaiIn::operator=(const DataRaiIn &x)
{

    m_time = x.m_time;
    m_senseTime = x.m_senseTime;
    m_chnl = x.m_chnl;
    m_roll = x.m_roll;
    m_pitch = x.m_pitch;
    m_yaw = x.m_yaw;
    m_thr = x.m_thr;
    m_fltMode = x.m_fltMode;
    m_fltFunc = x.m_fltFunc;
    m_alive = x.m_alive;

    return *this;
}

DataRaiIn& DataRaiIn::operator=(DataRaiIn &&x)
{

    m_time = x.m_time;
    m_senseTime = x.m_senseTime;
    m_chnl = std::move(x.m_chnl);
    m_roll = x.m_roll;
    m_pitch = x.m_pitch;
    m_yaw = x.m_yaw;
    m_thr = x.m_thr;
    m_fltMode = x.m_fltMode;
    m_fltFunc = x.m_fltFunc;
    m_alive = x.m_alive;

    return *this;
}

size_t DataRaiIn::getMaxCdrSerializedSize(size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += ((12) * 2) + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

size_t DataRaiIn::getCdrSerializedSize(const DataRaiIn& data, size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    if ((12) > 0)
    {
        current_alignment += ((12) * 2) + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);
    }

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

void DataRaiIn::serialize(eprosima::fastcdr::Cdr &scdr) const
{

    scdr << m_time;
    scdr << m_senseTime;
    scdr << m_chnl;

    scdr << m_roll;
    scdr << m_pitch;
    scdr << m_yaw;
    scdr << m_thr;
    scdr << m_fltMode;
    scdr << m_fltFunc;
    scdr << m_alive;
}

void DataRaiIn::deserialize(eprosima::fastcdr::Cdr &dcdr)
{

    dcdr >> m_time;
    dcdr >> m_senseTime;
    dcdr >> m_chnl;

    dcdr >> m_roll;
    dcdr >> m_pitch;
    dcdr >> m_yaw;
    dcdr >> m_thr;
    dcdr >> m_fltMode;
    dcdr >> m_fltFunc;
    dcdr >> m_alive;
}

/*!
 * @brief This function sets a value in member time
 * @param _time New value for member time
 */
void DataRaiIn::time(uint64_t _time)
{
m_time = _time;
}

/*!
 * @brief This function returns the value of member time
 * @return Value of member time
 */
uint64_t DataRaiIn::time() const
{
    return m_time;
}

/*!
 * @brief This function returns a reference to member time
 * @return Reference to member time
 */
uint64_t& DataRaiIn::time()
{
    return m_time;
}

/*!
 * @brief This function sets a value in member senseTime
 * @param _senseTime New value for member senseTime
 */
void DataRaiIn::senseTime(float _senseTime)
{
m_senseTime = _senseTime;
}

/*!
 * @brief This function returns the value of member senseTime
 * @return Value of member senseTime
 */
float DataRaiIn::senseTime() const
{
    return m_senseTime;
}

/*!
 * @brief This function returns a reference to member senseTime
 * @return Reference to member senseTime
 */
float& DataRaiIn::senseTime()
{
    return m_senseTime;
}

/*!
 * @brief This function copies the value in member chnl
 * @param _chnl New value to be copied in member chnl
 */
void DataRaiIn::chnl(const std::array<uint16_t, 12> &_chnl)
{
m_chnl = _chnl;
}

/*!
 * @brief This function moves the value in member chnl
 * @param _chnl New value to be moved in member chnl
 */
void DataRaiIn::chnl(std::array<uint16_t, 12> &&_chnl)
{
m_chnl = std::move(_chnl);
}

/*!
 * @brief This function returns a constant reference to member chnl
 * @return Constant reference to member chnl
 */
const std::array<uint16_t, 12>& DataRaiIn::chnl() const
{
    return m_chnl;
}

/*!
 * @brief This function returns a reference to member chnl
 * @return Reference to member chnl
 */
std::array<uint16_t, 12>& DataRaiIn::chnl()
{
    return m_chnl;
}
/*!
 * @brief This function sets a value in member roll
 * @param _roll New value for member roll
 */
void DataRaiIn::roll(float _roll)
{
m_roll = _roll;
}

/*!
 * @brief This function returns the value of member roll
 * @return Value of member roll
 */
float DataRaiIn::roll() const
{
    return m_roll;
}

/*!
 * @brief This function returns a reference to member roll
 * @return Reference to member roll
 */
float& DataRaiIn::roll()
{
    return m_roll;
}

/*!
 * @brief This function sets a value in member pitch
 * @param _pitch New value for member pitch
 */
void DataRaiIn::pitch(float _pitch)
{
m_pitch = _pitch;
}

/*!
 * @brief This function returns the value of member pitch
 * @return Value of member pitch
 */
float DataRaiIn::pitch() const
{
    return m_pitch;
}

/*!
 * @brief This function returns a reference to member pitch
 * @return Reference to member pitch
 */
float& DataRaiIn::pitch()
{
    return m_pitch;
}

/*!
 * @brief This function sets a value in member yaw
 * @param _yaw New value for member yaw
 */
void DataRaiIn::yaw(float _yaw)
{
m_yaw = _yaw;
}

/*!
 * @brief This function returns the value of member yaw
 * @return Value of member yaw
 */
float DataRaiIn::yaw() const
{
    return m_yaw;
}

/*!
 * @brief This function returns a reference to member yaw
 * @return Reference to member yaw
 */
float& DataRaiIn::yaw()
{
    return m_yaw;
}

/*!
 * @brief This function sets a value in member thr
 * @param _thr New value for member thr
 */
void DataRaiIn::thr(float _thr)
{
m_thr = _thr;
}

/*!
 * @brief This function returns the value of member thr
 * @return Value of member thr
 */
float DataRaiIn::thr() const
{
    return m_thr;
}

/*!
 * @brief This function returns a reference to member thr
 * @return Reference to member thr
 */
float& DataRaiIn::thr()
{
    return m_thr;
}

/*!
 * @brief This function sets a value in member fltMode
 * @param _fltMode New value for member fltMode
 */
void DataRaiIn::fltMode(uint16_t _fltMode)
{
m_fltMode = _fltMode;
}

/*!
 * @brief This function returns the value of member fltMode
 * @return Value of member fltMode
 */
uint16_t DataRaiIn::fltMode() const
{
    return m_fltMode;
}

/*!
 * @brief This function returns a reference to member fltMode
 * @return Reference to member fltMode
 */
uint16_t& DataRaiIn::fltMode()
{
    return m_fltMode;
}

/*!
 * @brief This function sets a value in member fltFunc
 * @param _fltFunc New value for member fltFunc
 */
void DataRaiIn::fltFunc(uint16_t _fltFunc)
{
m_fltFunc = _fltFunc;
}

/*!
 * @brief This function returns the value of member fltFunc
 * @return Value of member fltFunc
 */
uint16_t DataRaiIn::fltFunc() const
{
    return m_fltFunc;
}

/*!
 * @brief This function returns a reference to member fltFunc
 * @return Reference to member fltFunc
 */
uint16_t& DataRaiIn::fltFunc()
{
    return m_fltFunc;
}

/*!
 * @brief This function sets a value in member alive
 * @param _alive New value for member alive
 */
void DataRaiIn::alive(bool _alive)
{
m_alive = _alive;
}

/*!
 * @brief This function returns the value of member alive
 * @return Value of member alive
 */
bool DataRaiIn::alive() const
{
    return m_alive;
}

/*!
 * @brief This function returns a reference to member alive
 * @return Reference to member alive
 */
bool& DataRaiIn::alive()
{
    return m_alive;
}


size_t DataRaiIn::getKeyMaxCdrSerializedSize(size_t current_alignment)
{
    size_t current_align = current_alignment;













    return current_align;
}

bool DataRaiIn::isKeyDefined()
{
   return false;
}

void DataRaiIn::serializeKey(eprosima::fastcdr::Cdr &scdr) const
{
    (void) scdr;
     
     
     
     
     
     
     
     
     
     
}
