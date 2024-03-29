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
    // m_time com.eprosima.idl.parser.typecode.PrimitiveTypeCode@4e718207
    m_time = 0;
    // m_senseTime com.eprosima.idl.parser.typecode.PrimitiveTypeCode@1d371b2d
    m_senseTime = 0.0;
    // m_gyrX com.eprosima.idl.parser.typecode.PrimitiveTypeCode@543c6f6d
    m_gyrX = 0.0;
    // m_gyrY com.eprosima.idl.parser.typecode.PrimitiveTypeCode@13eb8acf
    m_gyrY = 0.0;
    // m_gyrZ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@51c8530f
    m_gyrZ = 0.0;
    // m_accX com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7403c468
    m_accX = 0.0;
    // m_accY com.eprosima.idl.parser.typecode.PrimitiveTypeCode@43738a82
    m_accY = 0.0;
    // m_accZ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@c81cdd1
    m_accZ = 0.0;
    // m_magX com.eprosima.idl.parser.typecode.PrimitiveTypeCode@1fc2b765
    m_magX = 0.0;
    // m_magY com.eprosima.idl.parser.typecode.PrimitiveTypeCode@75881071
    m_magY = 0.0;
    // m_magZ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@2a70a3d8
    m_magZ = 0.0;
    // m_temperature com.eprosima.idl.parser.typecode.PrimitiveTypeCode@289d1c02
    m_temperature = 0.0;
    // m_barometric_pressure com.eprosima.idl.parser.typecode.PrimitiveTypeCode@22eeefeb
    m_barometric_pressure = 0.0;
    // m_phi com.eprosima.idl.parser.typecode.PrimitiveTypeCode@17d0685f
    m_phi = 0.0;
    // m_the com.eprosima.idl.parser.typecode.PrimitiveTypeCode@3891771e
    m_the = 0.0;
    // m_psi com.eprosima.idl.parser.typecode.PrimitiveTypeCode@396e2f39
    m_psi = 0.0;
    // m_alive com.eprosima.idl.parser.typecode.PrimitiveTypeCode@42607a4f
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
    m_temperature = x.m_temperature;
    m_barometric_pressure = x.m_barometric_pressure;
    m_phi = x.m_phi;
    m_the = x.m_the;
    m_psi = x.m_psi;
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
    m_temperature = x.m_temperature;
    m_barometric_pressure = x.m_barometric_pressure;
    m_phi = x.m_phi;
    m_the = x.m_the;
    m_psi = x.m_psi;
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
    m_temperature = x.m_temperature;
    m_barometric_pressure = x.m_barometric_pressure;
    m_phi = x.m_phi;
    m_the = x.m_the;
    m_psi = x.m_psi;
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
    m_temperature = x.m_temperature;
    m_barometric_pressure = x.m_barometric_pressure;
    m_phi = x.m_phi;
    m_the = x.m_the;
    m_psi = x.m_psi;
    m_alive = x.m_alive;

    return *this;
}

size_t DataAhrs::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


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


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


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
    scdr << m_temperature;
    scdr << m_barometric_pressure;
    scdr << m_phi;
    scdr << m_the;
    scdr << m_psi;
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
    dcdr >> m_temperature;
    dcdr >> m_barometric_pressure;
    dcdr >> m_phi;
    dcdr >> m_the;
    dcdr >> m_psi;
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
        double _senseTime)
{
    m_senseTime = _senseTime;
}

/*!
 * @brief This function returns the value of member senseTime
 * @return Value of member senseTime
 */
double DataAhrs::senseTime() const
{
    return m_senseTime;
}

/*!
 * @brief This function returns a reference to member senseTime
 * @return Reference to member senseTime
 */
double& DataAhrs::senseTime()
{
    return m_senseTime;
}

/*!
 * @brief This function sets a value in member gyrX
 * @param _gyrX New value for member gyrX
 */
void DataAhrs::gyrX(
        double _gyrX)
{
    m_gyrX = _gyrX;
}

/*!
 * @brief This function returns the value of member gyrX
 * @return Value of member gyrX
 */
double DataAhrs::gyrX() const
{
    return m_gyrX;
}

/*!
 * @brief This function returns a reference to member gyrX
 * @return Reference to member gyrX
 */
double& DataAhrs::gyrX()
{
    return m_gyrX;
}

/*!
 * @brief This function sets a value in member gyrY
 * @param _gyrY New value for member gyrY
 */
void DataAhrs::gyrY(
        double _gyrY)
{
    m_gyrY = _gyrY;
}

/*!
 * @brief This function returns the value of member gyrY
 * @return Value of member gyrY
 */
double DataAhrs::gyrY() const
{
    return m_gyrY;
}

/*!
 * @brief This function returns a reference to member gyrY
 * @return Reference to member gyrY
 */
double& DataAhrs::gyrY()
{
    return m_gyrY;
}

/*!
 * @brief This function sets a value in member gyrZ
 * @param _gyrZ New value for member gyrZ
 */
void DataAhrs::gyrZ(
        double _gyrZ)
{
    m_gyrZ = _gyrZ;
}

/*!
 * @brief This function returns the value of member gyrZ
 * @return Value of member gyrZ
 */
double DataAhrs::gyrZ() const
{
    return m_gyrZ;
}

/*!
 * @brief This function returns a reference to member gyrZ
 * @return Reference to member gyrZ
 */
double& DataAhrs::gyrZ()
{
    return m_gyrZ;
}

/*!
 * @brief This function sets a value in member accX
 * @param _accX New value for member accX
 */
void DataAhrs::accX(
        double _accX)
{
    m_accX = _accX;
}

/*!
 * @brief This function returns the value of member accX
 * @return Value of member accX
 */
double DataAhrs::accX() const
{
    return m_accX;
}

/*!
 * @brief This function returns a reference to member accX
 * @return Reference to member accX
 */
double& DataAhrs::accX()
{
    return m_accX;
}

/*!
 * @brief This function sets a value in member accY
 * @param _accY New value for member accY
 */
void DataAhrs::accY(
        double _accY)
{
    m_accY = _accY;
}

/*!
 * @brief This function returns the value of member accY
 * @return Value of member accY
 */
double DataAhrs::accY() const
{
    return m_accY;
}

/*!
 * @brief This function returns a reference to member accY
 * @return Reference to member accY
 */
double& DataAhrs::accY()
{
    return m_accY;
}

/*!
 * @brief This function sets a value in member accZ
 * @param _accZ New value for member accZ
 */
void DataAhrs::accZ(
        double _accZ)
{
    m_accZ = _accZ;
}

/*!
 * @brief This function returns the value of member accZ
 * @return Value of member accZ
 */
double DataAhrs::accZ() const
{
    return m_accZ;
}

/*!
 * @brief This function returns a reference to member accZ
 * @return Reference to member accZ
 */
double& DataAhrs::accZ()
{
    return m_accZ;
}

/*!
 * @brief This function sets a value in member magX
 * @param _magX New value for member magX
 */
void DataAhrs::magX(
        double _magX)
{
    m_magX = _magX;
}

/*!
 * @brief This function returns the value of member magX
 * @return Value of member magX
 */
double DataAhrs::magX() const
{
    return m_magX;
}

/*!
 * @brief This function returns a reference to member magX
 * @return Reference to member magX
 */
double& DataAhrs::magX()
{
    return m_magX;
}

/*!
 * @brief This function sets a value in member magY
 * @param _magY New value for member magY
 */
void DataAhrs::magY(
        double _magY)
{
    m_magY = _magY;
}

/*!
 * @brief This function returns the value of member magY
 * @return Value of member magY
 */
double DataAhrs::magY() const
{
    return m_magY;
}

/*!
 * @brief This function returns a reference to member magY
 * @return Reference to member magY
 */
double& DataAhrs::magY()
{
    return m_magY;
}

/*!
 * @brief This function sets a value in member magZ
 * @param _magZ New value for member magZ
 */
void DataAhrs::magZ(
        double _magZ)
{
    m_magZ = _magZ;
}

/*!
 * @brief This function returns the value of member magZ
 * @return Value of member magZ
 */
double DataAhrs::magZ() const
{
    return m_magZ;
}

/*!
 * @brief This function returns a reference to member magZ
 * @return Reference to member magZ
 */
double& DataAhrs::magZ()
{
    return m_magZ;
}

/*!
 * @brief This function sets a value in member temperature
 * @param _temperature New value for member temperature
 */
void DataAhrs::temperature(
        double _temperature)
{
    m_temperature = _temperature;
}

/*!
 * @brief This function returns the value of member temperature
 * @return Value of member temperature
 */
double DataAhrs::temperature() const
{
    return m_temperature;
}

/*!
 * @brief This function returns a reference to member temperature
 * @return Reference to member temperature
 */
double& DataAhrs::temperature()
{
    return m_temperature;
}

/*!
 * @brief This function sets a value in member barometric_pressure
 * @param _barometric_pressure New value for member barometric_pressure
 */
void DataAhrs::barometric_pressure(
        double _barometric_pressure)
{
    m_barometric_pressure = _barometric_pressure;
}

/*!
 * @brief This function returns the value of member barometric_pressure
 * @return Value of member barometric_pressure
 */
double DataAhrs::barometric_pressure() const
{
    return m_barometric_pressure;
}

/*!
 * @brief This function returns a reference to member barometric_pressure
 * @return Reference to member barometric_pressure
 */
double& DataAhrs::barometric_pressure()
{
    return m_barometric_pressure;
}

/*!
 * @brief This function sets a value in member phi
 * @param _phi New value for member phi
 */
void DataAhrs::phi(
        double _phi)
{
    m_phi = _phi;
}

/*!
 * @brief This function returns the value of member phi
 * @return Value of member phi
 */
double DataAhrs::phi() const
{
    return m_phi;
}

/*!
 * @brief This function returns a reference to member phi
 * @return Reference to member phi
 */
double& DataAhrs::phi()
{
    return m_phi;
}

/*!
 * @brief This function sets a value in member the
 * @param _the New value for member the
 */
void DataAhrs::the(
        double _the)
{
    m_the = _the;
}

/*!
 * @brief This function returns the value of member the
 * @return Value of member the
 */
double DataAhrs::the() const
{
    return m_the;
}

/*!
 * @brief This function returns a reference to member the
 * @return Reference to member the
 */
double& DataAhrs::the()
{
    return m_the;
}

/*!
 * @brief This function sets a value in member psi
 * @param _psi New value for member psi
 */
void DataAhrs::psi(
        double _psi)
{
    m_psi = _psi;
}

/*!
 * @brief This function returns the value of member psi
 * @return Value of member psi
 */
double DataAhrs::psi() const
{
    return m_psi;
}

/*!
 * @brief This function returns a reference to member psi
 * @return Reference to member psi
 */
double& DataAhrs::psi()
{
    return m_psi;
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
