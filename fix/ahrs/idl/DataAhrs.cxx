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
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "DataAhrs.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

DataAhrs::DataAhrs()
{
    // m_time com.eprosima.idl.parser.typecode.PrimitiveTypeCode@543c6f6d
    m_time = 0;
    // m_senseTime com.eprosima.idl.parser.typecode.PrimitiveTypeCode@13eb8acf
    m_senseTime = 0.0;
    // m_gyrX com.eprosima.idl.parser.typecode.PrimitiveTypeCode@51c8530f
    m_gyrX = 0.0;
    // m_gyrY com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7403c468
    m_gyrY = 0.0;
    // m_gyrZ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@43738a82
    m_gyrZ = 0.0;
    // m_accX com.eprosima.idl.parser.typecode.PrimitiveTypeCode@c81cdd1
    m_accX = 0.0;
    // m_accY com.eprosima.idl.parser.typecode.PrimitiveTypeCode@1fc2b765
    m_accY = 0.0;
    // m_accZ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@75881071
    m_accZ = 0.0;
    // m_magX com.eprosima.idl.parser.typecode.PrimitiveTypeCode@2a70a3d8
    m_magX = 0.0;
    // m_magY com.eprosima.idl.parser.typecode.PrimitiveTypeCode@289d1c02
    m_magY = 0.0;
    // m_magZ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@22eeefeb
    m_magZ = 0.0;
    // m_temp com.eprosima.idl.parser.typecode.PrimitiveTypeCode@17d0685f
    m_temp = 0.0;
    // m_press com.eprosima.idl.parser.typecode.PrimitiveTypeCode@3891771e
    m_press = 0.0;
    // m_phi com.eprosima.idl.parser.typecode.PrimitiveTypeCode@78ac1102
    m_phi = 0.0;
    // m_the com.eprosima.idl.parser.typecode.PrimitiveTypeCode@2de8284b
    m_the = 0.0;
    // m_psi com.eprosima.idl.parser.typecode.PrimitiveTypeCode@12c8a2c0
    m_psi = 0.0;
    // m_q0 com.eprosima.idl.parser.typecode.PrimitiveTypeCode@1990a65e
    m_q0 = 0.0;
    // m_q1 com.eprosima.idl.parser.typecode.PrimitiveTypeCode@64485a47
    m_q1 = 0.0;
    // m_q2 com.eprosima.idl.parser.typecode.PrimitiveTypeCode@25bbf683
    m_q2 = 0.0;
    // m_q3 com.eprosima.idl.parser.typecode.PrimitiveTypeCode@6ec8211c
    m_q3 = 0.0;
    // m_alive com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7276c8cd
    m_alive = false;

}

DataAhrs::~DataAhrs()
{





















}

DataAhrs::DataAhrs(
        const DataAhrs& x)
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
    m_q0 = x.m_q0;
    m_q1 = x.m_q1;
    m_q2 = x.m_q2;
    m_q3 = x.m_q3;
    m_alive = x.m_alive;
}

DataAhrs::DataAhrs(
        DataAhrs&& x)
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
    m_q0 = x.m_q0;
    m_q1 = x.m_q1;
    m_q2 = x.m_q2;
    m_q3 = x.m_q3;
    m_alive = x.m_alive;
}

DataAhrs& DataAhrs::operator =(
        const DataAhrs& x)
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
    m_q0 = x.m_q0;
    m_q1 = x.m_q1;
    m_q2 = x.m_q2;
    m_q3 = x.m_q3;
    m_alive = x.m_alive;

    return *this;
}

DataAhrs& DataAhrs::operator =(
        DataAhrs&& x)
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
    m_q0 = x.m_q0;
    m_q1 = x.m_q1;
    m_q2 = x.m_q2;
    m_q3 = x.m_q3;
    m_alive = x.m_alive;

    return *this;
}

size_t DataAhrs::getMaxCdrSerializedSize(
        size_t current_alignment)
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

size_t DataAhrs::getCdrSerializedSize(
        const DataAhrs& data,
        size_t current_alignment)
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

void DataAhrs::serialize(
        eprosima::fastcdr::Cdr& scdr) const
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
    scdr << m_q0;
    scdr << m_q1;
    scdr << m_q2;
    scdr << m_q3;
    scdr << m_alive;

}

void DataAhrs::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
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
    dcdr >> m_q0;
    dcdr >> m_q1;
    dcdr >> m_q2;
    dcdr >> m_q3;
    dcdr >> m_alive;
}

/*!
 * @brief This function sets a value in member time
 * @param _time New value for member time
 */
void DataAhrs::time(
        uint64_t _time)
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
void DataAhrs::senseTime(
        float _senseTime)
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
void DataAhrs::gyrX(
        float _gyrX)
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
void DataAhrs::gyrY(
        float _gyrY)
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
void DataAhrs::gyrZ(
        float _gyrZ)
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
void DataAhrs::accX(
        float _accX)
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
void DataAhrs::accY(
        float _accY)
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
void DataAhrs::accZ(
        float _accZ)
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
void DataAhrs::magX(
        float _magX)
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
void DataAhrs::magY(
        float _magY)
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
void DataAhrs::magZ(
        float _magZ)
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
void DataAhrs::temp(
        float _temp)
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
void DataAhrs::press(
        float _press)
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
void DataAhrs::phi(
        float _phi)
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
void DataAhrs::the(
        float _the)
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
void DataAhrs::psi(
        float _psi)
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
 * @brief This function sets a value in member q0
 * @param _q0 New value for member q0
 */
void DataAhrs::q0(
        float _q0)
{
    m_q0 = _q0;
}

/*!
 * @brief This function returns the value of member q0
 * @return Value of member q0
 */
float DataAhrs::q0() const
{
    return m_q0;
}

/*!
 * @brief This function returns a reference to member q0
 * @return Reference to member q0
 */
float& DataAhrs::q0()
{
    return m_q0;
}

/*!
 * @brief This function sets a value in member q1
 * @param _q1 New value for member q1
 */
void DataAhrs::q1(
        float _q1)
{
    m_q1 = _q1;
}

/*!
 * @brief This function returns the value of member q1
 * @return Value of member q1
 */
float DataAhrs::q1() const
{
    return m_q1;
}

/*!
 * @brief This function returns a reference to member q1
 * @return Reference to member q1
 */
float& DataAhrs::q1()
{
    return m_q1;
}

/*!
 * @brief This function sets a value in member q2
 * @param _q2 New value for member q2
 */
void DataAhrs::q2(
        float _q2)
{
    m_q2 = _q2;
}

/*!
 * @brief This function returns the value of member q2
 * @return Value of member q2
 */
float DataAhrs::q2() const
{
    return m_q2;
}

/*!
 * @brief This function returns a reference to member q2
 * @return Reference to member q2
 */
float& DataAhrs::q2()
{
    return m_q2;
}

/*!
 * @brief This function sets a value in member q3
 * @param _q3 New value for member q3
 */
void DataAhrs::q3(
        float _q3)
{
    m_q3 = _q3;
}

/*!
 * @brief This function returns the value of member q3
 * @return Value of member q3
 */
float DataAhrs::q3() const
{
    return m_q3;
}

/*!
 * @brief This function returns a reference to member q3
 * @return Reference to member q3
 */
float& DataAhrs::q3()
{
    return m_q3;
}

/*!
 * @brief This function sets a value in member alive
 * @param _alive New value for member alive
 */
void DataAhrs::alive(
        bool _alive)
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


size_t DataAhrs::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t current_align = current_alignment;
























    return current_align;
}

bool DataAhrs::isKeyDefined()
{
    return false;
}

void DataAhrs::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
                         
}
