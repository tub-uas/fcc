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
 * @file DataAhrs.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace { char dummy; }
#endif

#include "DataAhrs.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

DataAhrs::DataAhrs()
{
    // m_time com.eprosima.idl.parser.typecode.PrimitiveTypeCode@3b0143d3
    m_time = 0;
    // m_senseTime com.eprosima.idl.parser.typecode.PrimitiveTypeCode@5a8e6209
    m_senseTime = 0.0;
    // m_gyrX com.eprosima.idl.parser.typecode.PrimitiveTypeCode@4b4523f8
    m_gyrX = 0.0;
    // m_gyrY com.eprosima.idl.parser.typecode.PrimitiveTypeCode@731a74c
    m_gyrY = 0.0;
    // m_gyrZ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@369f73a2
    m_gyrZ = 0.0;
    // m_accX com.eprosima.idl.parser.typecode.PrimitiveTypeCode@1f28c152
    m_accX = 0.0;
    // m_accY com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7d907bac
    m_accY = 0.0;
    // m_accZ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7791a895
    m_accZ = 0.0;
    // m_magX com.eprosima.idl.parser.typecode.PrimitiveTypeCode@3a5ed7a6
    m_magX = 0.0;
    // m_magY com.eprosima.idl.parser.typecode.PrimitiveTypeCode@6325a3ee
    m_magY = 0.0;
    // m_magZ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@1d16f93d
    m_magZ = 0.0;
    // m_temp com.eprosima.idl.parser.typecode.PrimitiveTypeCode@67b92f0a
    m_temp = 0.0;
    // m_press com.eprosima.idl.parser.typecode.PrimitiveTypeCode@2b9627bc
    m_press = 0.0;
    // m_phi com.eprosima.idl.parser.typecode.PrimitiveTypeCode@65e2dbf3
    m_phi = 0.0;
    // m_the com.eprosima.idl.parser.typecode.PrimitiveTypeCode@4f970963
    m_the = 0.0;
    // m_psi com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7b49cea0
    m_psi = 0.0;
    // m_p0 com.eprosima.idl.parser.typecode.PrimitiveTypeCode@6e0e048a
    m_p0 = 0.0;
    // m_p1 com.eprosima.idl.parser.typecode.PrimitiveTypeCode@5bc79255
    m_p1 = 0.0;
    // m_p2 com.eprosima.idl.parser.typecode.PrimitiveTypeCode@47ef968d
    m_p2 = 0.0;
    // m_p3 com.eprosima.idl.parser.typecode.PrimitiveTypeCode@23e028a9
    m_p3 = 0.0;
    // m_alive com.eprosima.idl.parser.typecode.PrimitiveTypeCode@3dd4520b
    m_alive = false;

}

DataAhrs::~DataAhrs()
{





















}

DataAhrs::DataAhrs(const DataAhrs &x)
{
    m_time = x.m_time;
    m_senseTime = x.m_senseTime;
    m_gyrX = x.m_gyrX;
    m_gyrY = x.m_gyrY;
    m_gyrZ = x.m_gyrZ;
    m_accX = x.m_accX;
    m_accY = x.m_accY;
    m_accZ = x.m_accZ;
    m_magX = x.m_magX;
    m_magY = x.m_magY;
    m_magZ = x.m_magZ;
    m_temp = x.m_temp;
    m_press = x.m_press;
    m_phi = x.m_phi;
    m_the = x.m_the;
    m_psi = x.m_psi;
    m_p0 = x.m_p0;
    m_p1 = x.m_p1;
    m_p2 = x.m_p2;
    m_p3 = x.m_p3;
    m_alive = x.m_alive;
}

DataAhrs::DataAhrs(DataAhrs &&x)
{
    m_time = x.m_time;
    m_senseTime = x.m_senseTime;
    m_gyrX = x.m_gyrX;
    m_gyrY = x.m_gyrY;
    m_gyrZ = x.m_gyrZ;
    m_accX = x.m_accX;
    m_accY = x.m_accY;
    m_accZ = x.m_accZ;
    m_magX = x.m_magX;
    m_magY = x.m_magY;
    m_magZ = x.m_magZ;
    m_temp = x.m_temp;
    m_press = x.m_press;
    m_phi = x.m_phi;
    m_the = x.m_the;
    m_psi = x.m_psi;
    m_p0 = x.m_p0;
    m_p1 = x.m_p1;
    m_p2 = x.m_p2;
    m_p3 = x.m_p3;
    m_alive = x.m_alive;
}

DataAhrs& DataAhrs::operator=(const DataAhrs &x)
{

    m_time = x.m_time;
    m_senseTime = x.m_senseTime;
    m_gyrX = x.m_gyrX;
    m_gyrY = x.m_gyrY;
    m_gyrZ = x.m_gyrZ;
    m_accX = x.m_accX;
    m_accY = x.m_accY;
    m_accZ = x.m_accZ;
    m_magX = x.m_magX;
    m_magY = x.m_magY;
    m_magZ = x.m_magZ;
    m_temp = x.m_temp;
    m_press = x.m_press;
    m_phi = x.m_phi;
    m_the = x.m_the;
    m_psi = x.m_psi;
    m_p0 = x.m_p0;
    m_p1 = x.m_p1;
    m_p2 = x.m_p2;
    m_p3 = x.m_p3;
    m_alive = x.m_alive;

    return *this;
}

DataAhrs& DataAhrs::operator=(DataAhrs &&x)
{

    m_time = x.m_time;
    m_senseTime = x.m_senseTime;
    m_gyrX = x.m_gyrX;
    m_gyrY = x.m_gyrY;
    m_gyrZ = x.m_gyrZ;
    m_accX = x.m_accX;
    m_accY = x.m_accY;
    m_accZ = x.m_accZ;
    m_magX = x.m_magX;
    m_magY = x.m_magY;
    m_magZ = x.m_magZ;
    m_temp = x.m_temp;
    m_press = x.m_press;
    m_phi = x.m_phi;
    m_the = x.m_the;
    m_psi = x.m_psi;
    m_p0 = x.m_p0;
    m_p1 = x.m_p1;
    m_p2 = x.m_p2;
    m_p3 = x.m_p3;
    m_alive = x.m_alive;

    return *this;
}

size_t DataAhrs::getMaxCdrSerializedSize(size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

size_t DataAhrs::getCdrSerializedSize(const DataAhrs& data, size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

void DataAhrs::serialize(eprosima::fastcdr::Cdr &scdr) const
{

    scdr << m_time;
    scdr << m_senseTime;
    scdr << m_gyrX;
    scdr << m_gyrY;
    scdr << m_gyrZ;
    scdr << m_accX;
    scdr << m_accY;
    scdr << m_accZ;
    scdr << m_magX;
    scdr << m_magY;
    scdr << m_magZ;
    scdr << m_temp;
    scdr << m_press;
    scdr << m_phi;
    scdr << m_the;
    scdr << m_psi;
    scdr << m_p0;
    scdr << m_p1;
    scdr << m_p2;
    scdr << m_p3;
    scdr << m_alive;
}

void DataAhrs::deserialize(eprosima::fastcdr::Cdr &dcdr)
{

    dcdr >> m_time;
    dcdr >> m_senseTime;
    dcdr >> m_gyrX;
    dcdr >> m_gyrY;
    dcdr >> m_gyrZ;
    dcdr >> m_accX;
    dcdr >> m_accY;
    dcdr >> m_accZ;
    dcdr >> m_magX;
    dcdr >> m_magY;
    dcdr >> m_magZ;
    dcdr >> m_temp;
    dcdr >> m_press;
    dcdr >> m_phi;
    dcdr >> m_the;
    dcdr >> m_psi;
    dcdr >> m_p0;
    dcdr >> m_p1;
    dcdr >> m_p2;
    dcdr >> m_p3;
    dcdr >> m_alive;
}

/*!
 * @brief This function sets a value in member time
 * @param _time New value for member time
 */
void DataAhrs::time(uint64_t _time)
{
m_time = _time;
}

/*!
 * @brief This function returns the value of member time
 * @return Value of member time
 */
uint64_t DataAhrs::time() const
{
    return m_time;
}

/*!
 * @brief This function returns a reference to member time
 * @return Reference to member time
 */
uint64_t& DataAhrs::time()
{
    return m_time;
}

/*!
 * @brief This function sets a value in member senseTime
 * @param _senseTime New value for member senseTime
 */
void DataAhrs::senseTime(float _senseTime)
{
m_senseTime = _senseTime;
}

/*!
 * @brief This function returns the value of member senseTime
 * @return Value of member senseTime
 */
float DataAhrs::senseTime() const
{
    return m_senseTime;
}

/*!
 * @brief This function returns a reference to member senseTime
 * @return Reference to member senseTime
 */
float& DataAhrs::senseTime()
{
    return m_senseTime;
}

/*!
 * @brief This function sets a value in member gyrX
 * @param _gyrX New value for member gyrX
 */
void DataAhrs::gyrX(float _gyrX)
{
m_gyrX = _gyrX;
}

/*!
 * @brief This function returns the value of member gyrX
 * @return Value of member gyrX
 */
float DataAhrs::gyrX() const
{
    return m_gyrX;
}

/*!
 * @brief This function returns a reference to member gyrX
 * @return Reference to member gyrX
 */
float& DataAhrs::gyrX()
{
    return m_gyrX;
}

/*!
 * @brief This function sets a value in member gyrY
 * @param _gyrY New value for member gyrY
 */
void DataAhrs::gyrY(float _gyrY)
{
m_gyrY = _gyrY;
}

/*!
 * @brief This function returns the value of member gyrY
 * @return Value of member gyrY
 */
float DataAhrs::gyrY() const
{
    return m_gyrY;
}

/*!
 * @brief This function returns a reference to member gyrY
 * @return Reference to member gyrY
 */
float& DataAhrs::gyrY()
{
    return m_gyrY;
}

/*!
 * @brief This function sets a value in member gyrZ
 * @param _gyrZ New value for member gyrZ
 */
void DataAhrs::gyrZ(float _gyrZ)
{
m_gyrZ = _gyrZ;
}

/*!
 * @brief This function returns the value of member gyrZ
 * @return Value of member gyrZ
 */
float DataAhrs::gyrZ() const
{
    return m_gyrZ;
}

/*!
 * @brief This function returns a reference to member gyrZ
 * @return Reference to member gyrZ
 */
float& DataAhrs::gyrZ()
{
    return m_gyrZ;
}

/*!
 * @brief This function sets a value in member accX
 * @param _accX New value for member accX
 */
void DataAhrs::accX(float _accX)
{
m_accX = _accX;
}

/*!
 * @brief This function returns the value of member accX
 * @return Value of member accX
 */
float DataAhrs::accX() const
{
    return m_accX;
}

/*!
 * @brief This function returns a reference to member accX
 * @return Reference to member accX
 */
float& DataAhrs::accX()
{
    return m_accX;
}

/*!
 * @brief This function sets a value in member accY
 * @param _accY New value for member accY
 */
void DataAhrs::accY(float _accY)
{
m_accY = _accY;
}

/*!
 * @brief This function returns the value of member accY
 * @return Value of member accY
 */
float DataAhrs::accY() const
{
    return m_accY;
}

/*!
 * @brief This function returns a reference to member accY
 * @return Reference to member accY
 */
float& DataAhrs::accY()
{
    return m_accY;
}

/*!
 * @brief This function sets a value in member accZ
 * @param _accZ New value for member accZ
 */
void DataAhrs::accZ(float _accZ)
{
m_accZ = _accZ;
}

/*!
 * @brief This function returns the value of member accZ
 * @return Value of member accZ
 */
float DataAhrs::accZ() const
{
    return m_accZ;
}

/*!
 * @brief This function returns a reference to member accZ
 * @return Reference to member accZ
 */
float& DataAhrs::accZ()
{
    return m_accZ;
}

/*!
 * @brief This function sets a value in member magX
 * @param _magX New value for member magX
 */
void DataAhrs::magX(float _magX)
{
m_magX = _magX;
}

/*!
 * @brief This function returns the value of member magX
 * @return Value of member magX
 */
float DataAhrs::magX() const
{
    return m_magX;
}

/*!
 * @brief This function returns a reference to member magX
 * @return Reference to member magX
 */
float& DataAhrs::magX()
{
    return m_magX;
}

/*!
 * @brief This function sets a value in member magY
 * @param _magY New value for member magY
 */
void DataAhrs::magY(float _magY)
{
m_magY = _magY;
}

/*!
 * @brief This function returns the value of member magY
 * @return Value of member magY
 */
float DataAhrs::magY() const
{
    return m_magY;
}

/*!
 * @brief This function returns a reference to member magY
 * @return Reference to member magY
 */
float& DataAhrs::magY()
{
    return m_magY;
}

/*!
 * @brief This function sets a value in member magZ
 * @param _magZ New value for member magZ
 */
void DataAhrs::magZ(float _magZ)
{
m_magZ = _magZ;
}

/*!
 * @brief This function returns the value of member magZ
 * @return Value of member magZ
 */
float DataAhrs::magZ() const
{
    return m_magZ;
}

/*!
 * @brief This function returns a reference to member magZ
 * @return Reference to member magZ
 */
float& DataAhrs::magZ()
{
    return m_magZ;
}

/*!
 * @brief This function sets a value in member temp
 * @param _temp New value for member temp
 */
void DataAhrs::temp(float _temp)
{
m_temp = _temp;
}

/*!
 * @brief This function returns the value of member temp
 * @return Value of member temp
 */
float DataAhrs::temp() const
{
    return m_temp;
}

/*!
 * @brief This function returns a reference to member temp
 * @return Reference to member temp
 */
float& DataAhrs::temp()
{
    return m_temp;
}

/*!
 * @brief This function sets a value in member press
 * @param _press New value for member press
 */
void DataAhrs::press(float _press)
{
m_press = _press;
}

/*!
 * @brief This function returns the value of member press
 * @return Value of member press
 */
float DataAhrs::press() const
{
    return m_press;
}

/*!
 * @brief This function returns a reference to member press
 * @return Reference to member press
 */
float& DataAhrs::press()
{
    return m_press;
}

/*!
 * @brief This function sets a value in member phi
 * @param _phi New value for member phi
 */
void DataAhrs::phi(float _phi)
{
m_phi = _phi;
}

/*!
 * @brief This function returns the value of member phi
 * @return Value of member phi
 */
float DataAhrs::phi() const
{
    return m_phi;
}

/*!
 * @brief This function returns a reference to member phi
 * @return Reference to member phi
 */
float& DataAhrs::phi()
{
    return m_phi;
}

/*!
 * @brief This function sets a value in member the
 * @param _the New value for member the
 */
void DataAhrs::the(float _the)
{
m_the = _the;
}

/*!
 * @brief This function returns the value of member the
 * @return Value of member the
 */
float DataAhrs::the() const
{
    return m_the;
}

/*!
 * @brief This function returns a reference to member the
 * @return Reference to member the
 */
float& DataAhrs::the()
{
    return m_the;
}

/*!
 * @brief This function sets a value in member psi
 * @param _psi New value for member psi
 */
void DataAhrs::psi(float _psi)
{
m_psi = _psi;
}

/*!
 * @brief This function returns the value of member psi
 * @return Value of member psi
 */
float DataAhrs::psi() const
{
    return m_psi;
}

/*!
 * @brief This function returns a reference to member psi
 * @return Reference to member psi
 */
float& DataAhrs::psi()
{
    return m_psi;
}

/*!
 * @brief This function sets a value in member p0
 * @param _p0 New value for member p0
 */
void DataAhrs::p0(float _p0)
{
m_p0 = _p0;
}

/*!
 * @brief This function returns the value of member p0
 * @return Value of member p0
 */
float DataAhrs::p0() const
{
    return m_p0;
}

/*!
 * @brief This function returns a reference to member p0
 * @return Reference to member p0
 */
float& DataAhrs::p0()
{
    return m_p0;
}

/*!
 * @brief This function sets a value in member p1
 * @param _p1 New value for member p1
 */
void DataAhrs::p1(float _p1)
{
m_p1 = _p1;
}

/*!
 * @brief This function returns the value of member p1
 * @return Value of member p1
 */
float DataAhrs::p1() const
{
    return m_p1;
}

/*!
 * @brief This function returns a reference to member p1
 * @return Reference to member p1
 */
float& DataAhrs::p1()
{
    return m_p1;
}

/*!
 * @brief This function sets a value in member p2
 * @param _p2 New value for member p2
 */
void DataAhrs::p2(float _p2)
{
m_p2 = _p2;
}

/*!
 * @brief This function returns the value of member p2
 * @return Value of member p2
 */
float DataAhrs::p2() const
{
    return m_p2;
}

/*!
 * @brief This function returns a reference to member p2
 * @return Reference to member p2
 */
float& DataAhrs::p2()
{
    return m_p2;
}

/*!
 * @brief This function sets a value in member p3
 * @param _p3 New value for member p3
 */
void DataAhrs::p3(float _p3)
{
m_p3 = _p3;
}

/*!
 * @brief This function returns the value of member p3
 * @return Value of member p3
 */
float DataAhrs::p3() const
{
    return m_p3;
}

/*!
 * @brief This function returns a reference to member p3
 * @return Reference to member p3
 */
float& DataAhrs::p3()
{
    return m_p3;
}

/*!
 * @brief This function sets a value in member alive
 * @param _alive New value for member alive
 */
void DataAhrs::alive(bool _alive)
{
m_alive = _alive;
}

/*!
 * @brief This function returns the value of member alive
 * @return Value of member alive
 */
bool DataAhrs::alive() const
{
    return m_alive;
}

/*!
 * @brief This function returns a reference to member alive
 * @return Reference to member alive
 */
bool& DataAhrs::alive()
{
    return m_alive;
}


size_t DataAhrs::getKeyMaxCdrSerializedSize(size_t current_alignment)
{
    size_t current_align = current_alignment;
























    return current_align;
}

bool DataAhrs::isKeyDefined()
{
   return false;
}

void DataAhrs::serializeKey(eprosima::fastcdr::Cdr &scdr) const
{
    (void) scdr;
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
}
