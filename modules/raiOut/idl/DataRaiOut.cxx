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
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "DataRaiOut.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

DataRaiOut::DataRaiOut()
{
    // m_time com.eprosima.idl.parser.typecode.PrimitiveTypeCode@78ac1102
    m_time = 0;
    // m_senseTime com.eprosima.idl.parser.typecode.PrimitiveTypeCode@2de8284b
    m_senseTime = 0.0;
    // m_chnl com.eprosima.idl.parser.typecode.ArrayTypeCode@396e2f39
    memset(&m_chnl, 0, (12) * 2);
    // m_xi_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@a74868d
    m_xi_setpoint = 0.0;
    // m_eta_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@12c8a2c0
    m_eta_setpoint = 0.0;
    // m_zeta_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@18bf3d14
    m_zeta_setpoint = 0.0;
    // m_throttle_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@782663d3
    m_throttle_setpoint = 0.0;
    // m_flaps_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@1990a65e
    m_flaps_setpoint = 0.0;
    // m_flight_mode com.eprosima.idl.parser.typecode.PrimitiveTypeCode@64485a47
    m_flight_mode = 0;
    // m_flight_fct com.eprosima.idl.parser.typecode.PrimitiveTypeCode@25bbf683
    m_flight_fct = 0;
    // m_alive com.eprosima.idl.parser.typecode.PrimitiveTypeCode@6ec8211c
    m_alive = false;

}

DataRaiOut::~DataRaiOut()
{











}

DataRaiOut::DataRaiOut(
        const DataRaiOut& x)
{
    m_time = x.m_time;
    m_senseTime = x.m_senseTime;
    m_chnl = x.m_chnl;
    m_xi_setpoint = x.m_xi_setpoint;
    m_eta_setpoint = x.m_eta_setpoint;
    m_zeta_setpoint = x.m_zeta_setpoint;
    m_throttle_setpoint = x.m_throttle_setpoint;
    m_flaps_setpoint = x.m_flaps_setpoint;
    m_flight_mode = x.m_flight_mode;
    m_flight_fct = x.m_flight_fct;
    m_alive = x.m_alive;
}

DataRaiOut::DataRaiOut(
        DataRaiOut&& x)
{
    m_time = x.m_time;
    m_senseTime = x.m_senseTime;
    m_chnl = std::move(x.m_chnl);
    m_xi_setpoint = x.m_xi_setpoint;
    m_eta_setpoint = x.m_eta_setpoint;
    m_zeta_setpoint = x.m_zeta_setpoint;
    m_throttle_setpoint = x.m_throttle_setpoint;
    m_flaps_setpoint = x.m_flaps_setpoint;
    m_flight_mode = x.m_flight_mode;
    m_flight_fct = x.m_flight_fct;
    m_alive = x.m_alive;
}

DataRaiOut& DataRaiOut::operator =(
        const DataRaiOut& x)
{

    m_time = x.m_time;
    m_senseTime = x.m_senseTime;
    m_chnl = x.m_chnl;
    m_xi_setpoint = x.m_xi_setpoint;
    m_eta_setpoint = x.m_eta_setpoint;
    m_zeta_setpoint = x.m_zeta_setpoint;
    m_throttle_setpoint = x.m_throttle_setpoint;
    m_flaps_setpoint = x.m_flaps_setpoint;
    m_flight_mode = x.m_flight_mode;
    m_flight_fct = x.m_flight_fct;
    m_alive = x.m_alive;

    return *this;
}

DataRaiOut& DataRaiOut::operator =(
        DataRaiOut&& x)
{

    m_time = x.m_time;
    m_senseTime = x.m_senseTime;
    m_chnl = std::move(x.m_chnl);
    m_xi_setpoint = x.m_xi_setpoint;
    m_eta_setpoint = x.m_eta_setpoint;
    m_zeta_setpoint = x.m_zeta_setpoint;
    m_throttle_setpoint = x.m_throttle_setpoint;
    m_flaps_setpoint = x.m_flaps_setpoint;
    m_flight_mode = x.m_flight_mode;
    m_flight_fct = x.m_flight_fct;
    m_alive = x.m_alive;

    return *this;
}

size_t DataRaiOut::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += ((12) * 2) + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

size_t DataRaiOut::getCdrSerializedSize(
        const DataRaiOut& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    if ((12) > 0)
    {
        current_alignment += ((12) * 2) + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);
    }

    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

void DataRaiOut::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_time;
    scdr << m_senseTime;
    scdr << m_chnl;

    scdr << m_xi_setpoint;
    scdr << m_eta_setpoint;
    scdr << m_zeta_setpoint;
    scdr << m_throttle_setpoint;
    scdr << m_flaps_setpoint;
    scdr << m_flight_mode;
    scdr << m_flight_fct;
    scdr << m_alive;

}

void DataRaiOut::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_time;
    dcdr >> m_senseTime;
    dcdr >> m_chnl;

    dcdr >> m_xi_setpoint;
    dcdr >> m_eta_setpoint;
    dcdr >> m_zeta_setpoint;
    dcdr >> m_throttle_setpoint;
    dcdr >> m_flaps_setpoint;
    dcdr >> m_flight_mode;
    dcdr >> m_flight_fct;
    dcdr >> m_alive;
}

/*!
 * @brief This function sets a value in member time
 * @param _time New value for member time
 */
void DataRaiOut::time(
        uint64_t _time)
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
 * @brief This function sets a value in member senseTime
 * @param _senseTime New value for member senseTime
 */
void DataRaiOut::senseTime(
        double _senseTime)
{
    m_senseTime = _senseTime;
}

/*!
 * @brief This function returns the value of member senseTime
 * @return Value of member senseTime
 */
double DataRaiOut::senseTime() const
{
    return m_senseTime;
}

/*!
 * @brief This function returns a reference to member senseTime
 * @return Reference to member senseTime
 */
double& DataRaiOut::senseTime()
{
    return m_senseTime;
}

/*!
 * @brief This function copies the value in member chnl
 * @param _chnl New value to be copied in member chnl
 */
void DataRaiOut::chnl(
        const std::array<uint16_t, 12>& _chnl)
{
    m_chnl = _chnl;
}

/*!
 * @brief This function moves the value in member chnl
 * @param _chnl New value to be moved in member chnl
 */
void DataRaiOut::chnl(
        std::array<uint16_t, 12>&& _chnl)
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
 * @brief This function sets a value in member xi_setpoint
 * @param _xi_setpoint New value for member xi_setpoint
 */
void DataRaiOut::xi_setpoint(
        double _xi_setpoint)
{
    m_xi_setpoint = _xi_setpoint;
}

/*!
 * @brief This function returns the value of member xi_setpoint
 * @return Value of member xi_setpoint
 */
double DataRaiOut::xi_setpoint() const
{
    return m_xi_setpoint;
}

/*!
 * @brief This function returns a reference to member xi_setpoint
 * @return Reference to member xi_setpoint
 */
double& DataRaiOut::xi_setpoint()
{
    return m_xi_setpoint;
}

/*!
 * @brief This function sets a value in member eta_setpoint
 * @param _eta_setpoint New value for member eta_setpoint
 */
void DataRaiOut::eta_setpoint(
        double _eta_setpoint)
{
    m_eta_setpoint = _eta_setpoint;
}

/*!
 * @brief This function returns the value of member eta_setpoint
 * @return Value of member eta_setpoint
 */
double DataRaiOut::eta_setpoint() const
{
    return m_eta_setpoint;
}

/*!
 * @brief This function returns a reference to member eta_setpoint
 * @return Reference to member eta_setpoint
 */
double& DataRaiOut::eta_setpoint()
{
    return m_eta_setpoint;
}

/*!
 * @brief This function sets a value in member zeta_setpoint
 * @param _zeta_setpoint New value for member zeta_setpoint
 */
void DataRaiOut::zeta_setpoint(
        double _zeta_setpoint)
{
    m_zeta_setpoint = _zeta_setpoint;
}

/*!
 * @brief This function returns the value of member zeta_setpoint
 * @return Value of member zeta_setpoint
 */
double DataRaiOut::zeta_setpoint() const
{
    return m_zeta_setpoint;
}

/*!
 * @brief This function returns a reference to member zeta_setpoint
 * @return Reference to member zeta_setpoint
 */
double& DataRaiOut::zeta_setpoint()
{
    return m_zeta_setpoint;
}

/*!
 * @brief This function sets a value in member throttle_setpoint
 * @param _throttle_setpoint New value for member throttle_setpoint
 */
void DataRaiOut::throttle_setpoint(
        double _throttle_setpoint)
{
    m_throttle_setpoint = _throttle_setpoint;
}

/*!
 * @brief This function returns the value of member throttle_setpoint
 * @return Value of member throttle_setpoint
 */
double DataRaiOut::throttle_setpoint() const
{
    return m_throttle_setpoint;
}

/*!
 * @brief This function returns a reference to member throttle_setpoint
 * @return Reference to member throttle_setpoint
 */
double& DataRaiOut::throttle_setpoint()
{
    return m_throttle_setpoint;
}

/*!
 * @brief This function sets a value in member flaps_setpoint
 * @param _flaps_setpoint New value for member flaps_setpoint
 */
void DataRaiOut::flaps_setpoint(
        double _flaps_setpoint)
{
    m_flaps_setpoint = _flaps_setpoint;
}

/*!
 * @brief This function returns the value of member flaps_setpoint
 * @return Value of member flaps_setpoint
 */
double DataRaiOut::flaps_setpoint() const
{
    return m_flaps_setpoint;
}

/*!
 * @brief This function returns a reference to member flaps_setpoint
 * @return Reference to member flaps_setpoint
 */
double& DataRaiOut::flaps_setpoint()
{
    return m_flaps_setpoint;
}

/*!
 * @brief This function sets a value in member flight_mode
 * @param _flight_mode New value for member flight_mode
 */
void DataRaiOut::flight_mode(
        uint16_t _flight_mode)
{
    m_flight_mode = _flight_mode;
}

/*!
 * @brief This function returns the value of member flight_mode
 * @return Value of member flight_mode
 */
uint16_t DataRaiOut::flight_mode() const
{
    return m_flight_mode;
}

/*!
 * @brief This function returns a reference to member flight_mode
 * @return Reference to member flight_mode
 */
uint16_t& DataRaiOut::flight_mode()
{
    return m_flight_mode;
}

/*!
 * @brief This function sets a value in member flight_fct
 * @param _flight_fct New value for member flight_fct
 */
void DataRaiOut::flight_fct(
        uint16_t _flight_fct)
{
    m_flight_fct = _flight_fct;
}

/*!
 * @brief This function returns the value of member flight_fct
 * @return Value of member flight_fct
 */
uint16_t DataRaiOut::flight_fct() const
{
    return m_flight_fct;
}

/*!
 * @brief This function returns a reference to member flight_fct
 * @return Reference to member flight_fct
 */
uint16_t& DataRaiOut::flight_fct()
{
    return m_flight_fct;
}

/*!
 * @brief This function sets a value in member alive
 * @param _alive New value for member alive
 */
void DataRaiOut::alive(
        bool _alive)
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


size_t DataRaiOut::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t current_align = current_alignment;














    return current_align;
}

bool DataRaiOut::isKeyDefined()
{
    return false;
}

void DataRaiOut::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
               
}
