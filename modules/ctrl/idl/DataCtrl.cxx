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
 * @file DataCtrl.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace { char dummy; }
#endif

#include "DataCtrl.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

DataCtrl::DataCtrl()
{
    // m_time com.eprosima.idl.parser.typecode.PrimitiveTypeCode@6ddf90b0
    m_time = 0;
    // m_xi com.eprosima.idl.parser.typecode.PrimitiveTypeCode@57536d79
    m_xi = 0.0;
    // m_eta com.eprosima.idl.parser.typecode.PrimitiveTypeCode@3b0143d3
    m_eta = 0.0;
    // m_zeta com.eprosima.idl.parser.typecode.PrimitiveTypeCode@5a8e6209
    m_zeta = 0.0;
    // m_etaT com.eprosima.idl.parser.typecode.PrimitiveTypeCode@4b4523f8
    m_etaT = 0.0;
    // m_etaF com.eprosima.idl.parser.typecode.PrimitiveTypeCode@731a74c
    m_etaF = 0.0;
    // m_fltMode com.eprosima.idl.parser.typecode.PrimitiveTypeCode@369f73a2
    m_fltMode = 0;
    // m_alive com.eprosima.idl.parser.typecode.PrimitiveTypeCode@1f28c152
    m_alive = false;

}

DataCtrl::~DataCtrl()
{








}

DataCtrl::DataCtrl(const DataCtrl &x)
{
    m_time = x.m_time;
    m_xi = x.m_xi;
    m_eta = x.m_eta;
    m_zeta = x.m_zeta;
    m_etaT = x.m_etaT;
    m_etaF = x.m_etaF;
    m_fltMode = x.m_fltMode;
    m_alive = x.m_alive;
}

DataCtrl::DataCtrl(DataCtrl &&x)
{
    m_time = x.m_time;
    m_xi = x.m_xi;
    m_eta = x.m_eta;
    m_zeta = x.m_zeta;
    m_etaT = x.m_etaT;
    m_etaF = x.m_etaF;
    m_fltMode = x.m_fltMode;
    m_alive = x.m_alive;
}

DataCtrl& DataCtrl::operator=(const DataCtrl &x)
{

    m_time = x.m_time;
    m_xi = x.m_xi;
    m_eta = x.m_eta;
    m_zeta = x.m_zeta;
    m_etaT = x.m_etaT;
    m_etaF = x.m_etaF;
    m_fltMode = x.m_fltMode;
    m_alive = x.m_alive;

    return *this;
}

DataCtrl& DataCtrl::operator=(DataCtrl &&x)
{

    m_time = x.m_time;
    m_xi = x.m_xi;
    m_eta = x.m_eta;
    m_zeta = x.m_zeta;
    m_etaT = x.m_etaT;
    m_etaF = x.m_etaF;
    m_fltMode = x.m_fltMode;
    m_alive = x.m_alive;

    return *this;
}

size_t DataCtrl::getMaxCdrSerializedSize(size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

size_t DataCtrl::getCdrSerializedSize(const DataCtrl& data, size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

void DataCtrl::serialize(eprosima::fastcdr::Cdr &scdr) const
{

    scdr << m_time;
    scdr << m_xi;
    scdr << m_eta;
    scdr << m_zeta;
    scdr << m_etaT;
    scdr << m_etaF;
    scdr << m_fltMode;
    scdr << m_alive;
}

void DataCtrl::deserialize(eprosima::fastcdr::Cdr &dcdr)
{

    dcdr >> m_time;
    dcdr >> m_xi;
    dcdr >> m_eta;
    dcdr >> m_zeta;
    dcdr >> m_etaT;
    dcdr >> m_etaF;
    dcdr >> m_fltMode;
    dcdr >> m_alive;
}

/*!
 * @brief This function sets a value in member time
 * @param _time New value for member time
 */
void DataCtrl::time(uint64_t _time)
{
m_time = _time;
}

/*!
 * @brief This function returns the value of member time
 * @return Value of member time
 */
uint64_t DataCtrl::time() const
{
    return m_time;
}

/*!
 * @brief This function returns a reference to member time
 * @return Reference to member time
 */
uint64_t& DataCtrl::time()
{
    return m_time;
}

/*!
 * @brief This function sets a value in member xi
 * @param _xi New value for member xi
 */
void DataCtrl::xi(float _xi)
{
m_xi = _xi;
}

/*!
 * @brief This function returns the value of member xi
 * @return Value of member xi
 */
float DataCtrl::xi() const
{
    return m_xi;
}

/*!
 * @brief This function returns a reference to member xi
 * @return Reference to member xi
 */
float& DataCtrl::xi()
{
    return m_xi;
}

/*!
 * @brief This function sets a value in member eta
 * @param _eta New value for member eta
 */
void DataCtrl::eta(float _eta)
{
m_eta = _eta;
}

/*!
 * @brief This function returns the value of member eta
 * @return Value of member eta
 */
float DataCtrl::eta() const
{
    return m_eta;
}

/*!
 * @brief This function returns a reference to member eta
 * @return Reference to member eta
 */
float& DataCtrl::eta()
{
    return m_eta;
}

/*!
 * @brief This function sets a value in member zeta
 * @param _zeta New value for member zeta
 */
void DataCtrl::zeta(float _zeta)
{
m_zeta = _zeta;
}

/*!
 * @brief This function returns the value of member zeta
 * @return Value of member zeta
 */
float DataCtrl::zeta() const
{
    return m_zeta;
}

/*!
 * @brief This function returns a reference to member zeta
 * @return Reference to member zeta
 */
float& DataCtrl::zeta()
{
    return m_zeta;
}

/*!
 * @brief This function sets a value in member etaT
 * @param _etaT New value for member etaT
 */
void DataCtrl::etaT(float _etaT)
{
m_etaT = _etaT;
}

/*!
 * @brief This function returns the value of member etaT
 * @return Value of member etaT
 */
float DataCtrl::etaT() const
{
    return m_etaT;
}

/*!
 * @brief This function returns a reference to member etaT
 * @return Reference to member etaT
 */
float& DataCtrl::etaT()
{
    return m_etaT;
}

/*!
 * @brief This function sets a value in member etaF
 * @param _etaF New value for member etaF
 */
void DataCtrl::etaF(float _etaF)
{
m_etaF = _etaF;
}

/*!
 * @brief This function returns the value of member etaF
 * @return Value of member etaF
 */
float DataCtrl::etaF() const
{
    return m_etaF;
}

/*!
 * @brief This function returns a reference to member etaF
 * @return Reference to member etaF
 */
float& DataCtrl::etaF()
{
    return m_etaF;
}

/*!
 * @brief This function sets a value in member fltMode
 * @param _fltMode New value for member fltMode
 */
void DataCtrl::fltMode(uint16_t _fltMode)
{
m_fltMode = _fltMode;
}

/*!
 * @brief This function returns the value of member fltMode
 * @return Value of member fltMode
 */
uint16_t DataCtrl::fltMode() const
{
    return m_fltMode;
}

/*!
 * @brief This function returns a reference to member fltMode
 * @return Reference to member fltMode
 */
uint16_t& DataCtrl::fltMode()
{
    return m_fltMode;
}

/*!
 * @brief This function sets a value in member alive
 * @param _alive New value for member alive
 */
void DataCtrl::alive(bool _alive)
{
m_alive = _alive;
}

/*!
 * @brief This function returns the value of member alive
 * @return Value of member alive
 */
bool DataCtrl::alive() const
{
    return m_alive;
}

/*!
 * @brief This function returns a reference to member alive
 * @return Reference to member alive
 */
bool& DataCtrl::alive()
{
    return m_alive;
}


size_t DataCtrl::getKeyMaxCdrSerializedSize(size_t current_alignment)
{
    size_t current_align = current_alignment;











    return current_align;
}

bool DataCtrl::isKeyDefined()
{
   return false;
}

void DataCtrl::serializeKey(eprosima::fastcdr::Cdr &scdr) const
{
    (void) scdr;
     
     
     
     
     
     
     
     
}