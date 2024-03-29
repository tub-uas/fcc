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
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "DataCtrl.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

DataCtrl::DataCtrl()
{
    // m_time com.eprosima.idl.parser.typecode.PrimitiveTypeCode@1d371b2d
    m_time = 0;
    // m_xi_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@543c6f6d
    m_xi_setpoint = 0.0;
    // m_eta_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@13eb8acf
    m_eta_setpoint = 0.0;
    // m_zeta_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@51c8530f
    m_zeta_setpoint = 0.0;
    // m_throttle_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7403c468
    m_throttle_setpoint = 0.0;
    // m_flaps_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@43738a82
    m_flaps_setpoint = 0.0;
    // m_roll_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@c81cdd1
    m_roll_setpoint = 0.0;
    // m_roll_rate_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@1fc2b765
    m_roll_rate_setpoint = 0.0;
    // m_pitch_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@75881071
    m_pitch_setpoint = 0.0;
    // m_pitch_rate_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@2a70a3d8
    m_pitch_rate_setpoint = 0.0;
    // m_yaw_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@289d1c02
    m_yaw_setpoint = 0.0;
    // m_yaw_rate_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@22eeefeb
    m_yaw_rate_setpoint = 0.0;
    // m_tas_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@17d0685f
    m_tas_setpoint = 0.0;
    // m_tas_rate_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@3891771e
    m_tas_rate_setpoint = 0.0;
    // m_hgt_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@78ac1102
    m_hgt_setpoint = 0.0;
    // m_hgt_rate_setpoint com.eprosima.idl.parser.typecode.PrimitiveTypeCode@a74868d
    m_hgt_rate_setpoint = 0.0;
    // m_flight_mode com.eprosima.idl.parser.typecode.PrimitiveTypeCode@782663d3
    m_flight_mode = 0;
    // m_flight_fct com.eprosima.idl.parser.typecode.PrimitiveTypeCode@1990a65e
    m_flight_fct = 0;
    // m_alive com.eprosima.idl.parser.typecode.PrimitiveTypeCode@64485a47
    m_alive = false;

}

DataCtrl::~DataCtrl()
{



















}

DataCtrl::DataCtrl(
        const DataCtrl& x)
{
    m_time = x.m_time;
    m_xi_setpoint = x.m_xi_setpoint;
    m_eta_setpoint = x.m_eta_setpoint;
    m_zeta_setpoint = x.m_zeta_setpoint;
    m_throttle_setpoint = x.m_throttle_setpoint;
    m_flaps_setpoint = x.m_flaps_setpoint;
    m_roll_setpoint = x.m_roll_setpoint;
    m_roll_rate_setpoint = x.m_roll_rate_setpoint;
    m_pitch_setpoint = x.m_pitch_setpoint;
    m_pitch_rate_setpoint = x.m_pitch_rate_setpoint;
    m_yaw_setpoint = x.m_yaw_setpoint;
    m_yaw_rate_setpoint = x.m_yaw_rate_setpoint;
    m_tas_setpoint = x.m_tas_setpoint;
    m_tas_rate_setpoint = x.m_tas_rate_setpoint;
    m_hgt_setpoint = x.m_hgt_setpoint;
    m_hgt_rate_setpoint = x.m_hgt_rate_setpoint;
    m_flight_mode = x.m_flight_mode;
    m_flight_fct = x.m_flight_fct;
    m_alive = x.m_alive;
}

DataCtrl::DataCtrl(
        DataCtrl&& x)
{
    m_time = x.m_time;
    m_xi_setpoint = x.m_xi_setpoint;
    m_eta_setpoint = x.m_eta_setpoint;
    m_zeta_setpoint = x.m_zeta_setpoint;
    m_throttle_setpoint = x.m_throttle_setpoint;
    m_flaps_setpoint = x.m_flaps_setpoint;
    m_roll_setpoint = x.m_roll_setpoint;
    m_roll_rate_setpoint = x.m_roll_rate_setpoint;
    m_pitch_setpoint = x.m_pitch_setpoint;
    m_pitch_rate_setpoint = x.m_pitch_rate_setpoint;
    m_yaw_setpoint = x.m_yaw_setpoint;
    m_yaw_rate_setpoint = x.m_yaw_rate_setpoint;
    m_tas_setpoint = x.m_tas_setpoint;
    m_tas_rate_setpoint = x.m_tas_rate_setpoint;
    m_hgt_setpoint = x.m_hgt_setpoint;
    m_hgt_rate_setpoint = x.m_hgt_rate_setpoint;
    m_flight_mode = x.m_flight_mode;
    m_flight_fct = x.m_flight_fct;
    m_alive = x.m_alive;
}

DataCtrl& DataCtrl::operator =(
        const DataCtrl& x)
{

    m_time = x.m_time;
    m_xi_setpoint = x.m_xi_setpoint;
    m_eta_setpoint = x.m_eta_setpoint;
    m_zeta_setpoint = x.m_zeta_setpoint;
    m_throttle_setpoint = x.m_throttle_setpoint;
    m_flaps_setpoint = x.m_flaps_setpoint;
    m_roll_setpoint = x.m_roll_setpoint;
    m_roll_rate_setpoint = x.m_roll_rate_setpoint;
    m_pitch_setpoint = x.m_pitch_setpoint;
    m_pitch_rate_setpoint = x.m_pitch_rate_setpoint;
    m_yaw_setpoint = x.m_yaw_setpoint;
    m_yaw_rate_setpoint = x.m_yaw_rate_setpoint;
    m_tas_setpoint = x.m_tas_setpoint;
    m_tas_rate_setpoint = x.m_tas_rate_setpoint;
    m_hgt_setpoint = x.m_hgt_setpoint;
    m_hgt_rate_setpoint = x.m_hgt_rate_setpoint;
    m_flight_mode = x.m_flight_mode;
    m_flight_fct = x.m_flight_fct;
    m_alive = x.m_alive;

    return *this;
}

DataCtrl& DataCtrl::operator =(
        DataCtrl&& x)
{

    m_time = x.m_time;
    m_xi_setpoint = x.m_xi_setpoint;
    m_eta_setpoint = x.m_eta_setpoint;
    m_zeta_setpoint = x.m_zeta_setpoint;
    m_throttle_setpoint = x.m_throttle_setpoint;
    m_flaps_setpoint = x.m_flaps_setpoint;
    m_roll_setpoint = x.m_roll_setpoint;
    m_roll_rate_setpoint = x.m_roll_rate_setpoint;
    m_pitch_setpoint = x.m_pitch_setpoint;
    m_pitch_rate_setpoint = x.m_pitch_rate_setpoint;
    m_yaw_setpoint = x.m_yaw_setpoint;
    m_yaw_rate_setpoint = x.m_yaw_rate_setpoint;
    m_tas_setpoint = x.m_tas_setpoint;
    m_tas_rate_setpoint = x.m_tas_rate_setpoint;
    m_hgt_setpoint = x.m_hgt_setpoint;
    m_hgt_rate_setpoint = x.m_hgt_rate_setpoint;
    m_flight_mode = x.m_flight_mode;
    m_flight_fct = x.m_flight_fct;
    m_alive = x.m_alive;

    return *this;
}

size_t DataCtrl::getMaxCdrSerializedSize(
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


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

size_t DataCtrl::getCdrSerializedSize(
        const DataCtrl& data,
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


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

void DataCtrl::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_time;
    scdr << m_xi_setpoint;
    scdr << m_eta_setpoint;
    scdr << m_zeta_setpoint;
    scdr << m_throttle_setpoint;
    scdr << m_flaps_setpoint;
    scdr << m_roll_setpoint;
    scdr << m_roll_rate_setpoint;
    scdr << m_pitch_setpoint;
    scdr << m_pitch_rate_setpoint;
    scdr << m_yaw_setpoint;
    scdr << m_yaw_rate_setpoint;
    scdr << m_tas_setpoint;
    scdr << m_tas_rate_setpoint;
    scdr << m_hgt_setpoint;
    scdr << m_hgt_rate_setpoint;
    scdr << m_flight_mode;
    scdr << m_flight_fct;
    scdr << m_alive;

}

void DataCtrl::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_time;
    dcdr >> m_xi_setpoint;
    dcdr >> m_eta_setpoint;
    dcdr >> m_zeta_setpoint;
    dcdr >> m_throttle_setpoint;
    dcdr >> m_flaps_setpoint;
    dcdr >> m_roll_setpoint;
    dcdr >> m_roll_rate_setpoint;
    dcdr >> m_pitch_setpoint;
    dcdr >> m_pitch_rate_setpoint;
    dcdr >> m_yaw_setpoint;
    dcdr >> m_yaw_rate_setpoint;
    dcdr >> m_tas_setpoint;
    dcdr >> m_tas_rate_setpoint;
    dcdr >> m_hgt_setpoint;
    dcdr >> m_hgt_rate_setpoint;
    dcdr >> m_flight_mode;
    dcdr >> m_flight_fct;
    dcdr >> m_alive;
}

/*!
 * @brief This function sets a value in member time
 * @param _time New value for member time
 */
void DataCtrl::time(
        uint64_t _time)
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
 * @brief This function sets a value in member xi_setpoint
 * @param _xi_setpoint New value for member xi_setpoint
 */
void DataCtrl::xi_setpoint(
        double _xi_setpoint)
{
    m_xi_setpoint = _xi_setpoint;
}

/*!
 * @brief This function returns the value of member xi_setpoint
 * @return Value of member xi_setpoint
 */
double DataCtrl::xi_setpoint() const
{
    return m_xi_setpoint;
}

/*!
 * @brief This function returns a reference to member xi_setpoint
 * @return Reference to member xi_setpoint
 */
double& DataCtrl::xi_setpoint()
{
    return m_xi_setpoint;
}

/*!
 * @brief This function sets a value in member eta_setpoint
 * @param _eta_setpoint New value for member eta_setpoint
 */
void DataCtrl::eta_setpoint(
        double _eta_setpoint)
{
    m_eta_setpoint = _eta_setpoint;
}

/*!
 * @brief This function returns the value of member eta_setpoint
 * @return Value of member eta_setpoint
 */
double DataCtrl::eta_setpoint() const
{
    return m_eta_setpoint;
}

/*!
 * @brief This function returns a reference to member eta_setpoint
 * @return Reference to member eta_setpoint
 */
double& DataCtrl::eta_setpoint()
{
    return m_eta_setpoint;
}

/*!
 * @brief This function sets a value in member zeta_setpoint
 * @param _zeta_setpoint New value for member zeta_setpoint
 */
void DataCtrl::zeta_setpoint(
        double _zeta_setpoint)
{
    m_zeta_setpoint = _zeta_setpoint;
}

/*!
 * @brief This function returns the value of member zeta_setpoint
 * @return Value of member zeta_setpoint
 */
double DataCtrl::zeta_setpoint() const
{
    return m_zeta_setpoint;
}

/*!
 * @brief This function returns a reference to member zeta_setpoint
 * @return Reference to member zeta_setpoint
 */
double& DataCtrl::zeta_setpoint()
{
    return m_zeta_setpoint;
}

/*!
 * @brief This function sets a value in member throttle_setpoint
 * @param _throttle_setpoint New value for member throttle_setpoint
 */
void DataCtrl::throttle_setpoint(
        double _throttle_setpoint)
{
    m_throttle_setpoint = _throttle_setpoint;
}

/*!
 * @brief This function returns the value of member throttle_setpoint
 * @return Value of member throttle_setpoint
 */
double DataCtrl::throttle_setpoint() const
{
    return m_throttle_setpoint;
}

/*!
 * @brief This function returns a reference to member throttle_setpoint
 * @return Reference to member throttle_setpoint
 */
double& DataCtrl::throttle_setpoint()
{
    return m_throttle_setpoint;
}

/*!
 * @brief This function sets a value in member flaps_setpoint
 * @param _flaps_setpoint New value for member flaps_setpoint
 */
void DataCtrl::flaps_setpoint(
        double _flaps_setpoint)
{
    m_flaps_setpoint = _flaps_setpoint;
}

/*!
 * @brief This function returns the value of member flaps_setpoint
 * @return Value of member flaps_setpoint
 */
double DataCtrl::flaps_setpoint() const
{
    return m_flaps_setpoint;
}

/*!
 * @brief This function returns a reference to member flaps_setpoint
 * @return Reference to member flaps_setpoint
 */
double& DataCtrl::flaps_setpoint()
{
    return m_flaps_setpoint;
}

/*!
 * @brief This function sets a value in member roll_setpoint
 * @param _roll_setpoint New value for member roll_setpoint
 */
void DataCtrl::roll_setpoint(
        double _roll_setpoint)
{
    m_roll_setpoint = _roll_setpoint;
}

/*!
 * @brief This function returns the value of member roll_setpoint
 * @return Value of member roll_setpoint
 */
double DataCtrl::roll_setpoint() const
{
    return m_roll_setpoint;
}

/*!
 * @brief This function returns a reference to member roll_setpoint
 * @return Reference to member roll_setpoint
 */
double& DataCtrl::roll_setpoint()
{
    return m_roll_setpoint;
}

/*!
 * @brief This function sets a value in member roll_rate_setpoint
 * @param _roll_rate_setpoint New value for member roll_rate_setpoint
 */
void DataCtrl::roll_rate_setpoint(
        double _roll_rate_setpoint)
{
    m_roll_rate_setpoint = _roll_rate_setpoint;
}

/*!
 * @brief This function returns the value of member roll_rate_setpoint
 * @return Value of member roll_rate_setpoint
 */
double DataCtrl::roll_rate_setpoint() const
{
    return m_roll_rate_setpoint;
}

/*!
 * @brief This function returns a reference to member roll_rate_setpoint
 * @return Reference to member roll_rate_setpoint
 */
double& DataCtrl::roll_rate_setpoint()
{
    return m_roll_rate_setpoint;
}

/*!
 * @brief This function sets a value in member pitch_setpoint
 * @param _pitch_setpoint New value for member pitch_setpoint
 */
void DataCtrl::pitch_setpoint(
        double _pitch_setpoint)
{
    m_pitch_setpoint = _pitch_setpoint;
}

/*!
 * @brief This function returns the value of member pitch_setpoint
 * @return Value of member pitch_setpoint
 */
double DataCtrl::pitch_setpoint() const
{
    return m_pitch_setpoint;
}

/*!
 * @brief This function returns a reference to member pitch_setpoint
 * @return Reference to member pitch_setpoint
 */
double& DataCtrl::pitch_setpoint()
{
    return m_pitch_setpoint;
}

/*!
 * @brief This function sets a value in member pitch_rate_setpoint
 * @param _pitch_rate_setpoint New value for member pitch_rate_setpoint
 */
void DataCtrl::pitch_rate_setpoint(
        double _pitch_rate_setpoint)
{
    m_pitch_rate_setpoint = _pitch_rate_setpoint;
}

/*!
 * @brief This function returns the value of member pitch_rate_setpoint
 * @return Value of member pitch_rate_setpoint
 */
double DataCtrl::pitch_rate_setpoint() const
{
    return m_pitch_rate_setpoint;
}

/*!
 * @brief This function returns a reference to member pitch_rate_setpoint
 * @return Reference to member pitch_rate_setpoint
 */
double& DataCtrl::pitch_rate_setpoint()
{
    return m_pitch_rate_setpoint;
}

/*!
 * @brief This function sets a value in member yaw_setpoint
 * @param _yaw_setpoint New value for member yaw_setpoint
 */
void DataCtrl::yaw_setpoint(
        double _yaw_setpoint)
{
    m_yaw_setpoint = _yaw_setpoint;
}

/*!
 * @brief This function returns the value of member yaw_setpoint
 * @return Value of member yaw_setpoint
 */
double DataCtrl::yaw_setpoint() const
{
    return m_yaw_setpoint;
}

/*!
 * @brief This function returns a reference to member yaw_setpoint
 * @return Reference to member yaw_setpoint
 */
double& DataCtrl::yaw_setpoint()
{
    return m_yaw_setpoint;
}

/*!
 * @brief This function sets a value in member yaw_rate_setpoint
 * @param _yaw_rate_setpoint New value for member yaw_rate_setpoint
 */
void DataCtrl::yaw_rate_setpoint(
        double _yaw_rate_setpoint)
{
    m_yaw_rate_setpoint = _yaw_rate_setpoint;
}

/*!
 * @brief This function returns the value of member yaw_rate_setpoint
 * @return Value of member yaw_rate_setpoint
 */
double DataCtrl::yaw_rate_setpoint() const
{
    return m_yaw_rate_setpoint;
}

/*!
 * @brief This function returns a reference to member yaw_rate_setpoint
 * @return Reference to member yaw_rate_setpoint
 */
double& DataCtrl::yaw_rate_setpoint()
{
    return m_yaw_rate_setpoint;
}

/*!
 * @brief This function sets a value in member tas_setpoint
 * @param _tas_setpoint New value for member tas_setpoint
 */
void DataCtrl::tas_setpoint(
        double _tas_setpoint)
{
    m_tas_setpoint = _tas_setpoint;
}

/*!
 * @brief This function returns the value of member tas_setpoint
 * @return Value of member tas_setpoint
 */
double DataCtrl::tas_setpoint() const
{
    return m_tas_setpoint;
}

/*!
 * @brief This function returns a reference to member tas_setpoint
 * @return Reference to member tas_setpoint
 */
double& DataCtrl::tas_setpoint()
{
    return m_tas_setpoint;
}

/*!
 * @brief This function sets a value in member tas_rate_setpoint
 * @param _tas_rate_setpoint New value for member tas_rate_setpoint
 */
void DataCtrl::tas_rate_setpoint(
        double _tas_rate_setpoint)
{
    m_tas_rate_setpoint = _tas_rate_setpoint;
}

/*!
 * @brief This function returns the value of member tas_rate_setpoint
 * @return Value of member tas_rate_setpoint
 */
double DataCtrl::tas_rate_setpoint() const
{
    return m_tas_rate_setpoint;
}

/*!
 * @brief This function returns a reference to member tas_rate_setpoint
 * @return Reference to member tas_rate_setpoint
 */
double& DataCtrl::tas_rate_setpoint()
{
    return m_tas_rate_setpoint;
}

/*!
 * @brief This function sets a value in member hgt_setpoint
 * @param _hgt_setpoint New value for member hgt_setpoint
 */
void DataCtrl::hgt_setpoint(
        double _hgt_setpoint)
{
    m_hgt_setpoint = _hgt_setpoint;
}

/*!
 * @brief This function returns the value of member hgt_setpoint
 * @return Value of member hgt_setpoint
 */
double DataCtrl::hgt_setpoint() const
{
    return m_hgt_setpoint;
}

/*!
 * @brief This function returns a reference to member hgt_setpoint
 * @return Reference to member hgt_setpoint
 */
double& DataCtrl::hgt_setpoint()
{
    return m_hgt_setpoint;
}

/*!
 * @brief This function sets a value in member hgt_rate_setpoint
 * @param _hgt_rate_setpoint New value for member hgt_rate_setpoint
 */
void DataCtrl::hgt_rate_setpoint(
        double _hgt_rate_setpoint)
{
    m_hgt_rate_setpoint = _hgt_rate_setpoint;
}

/*!
 * @brief This function returns the value of member hgt_rate_setpoint
 * @return Value of member hgt_rate_setpoint
 */
double DataCtrl::hgt_rate_setpoint() const
{
    return m_hgt_rate_setpoint;
}

/*!
 * @brief This function returns a reference to member hgt_rate_setpoint
 * @return Reference to member hgt_rate_setpoint
 */
double& DataCtrl::hgt_rate_setpoint()
{
    return m_hgt_rate_setpoint;
}

/*!
 * @brief This function sets a value in member flight_mode
 * @param _flight_mode New value for member flight_mode
 */
void DataCtrl::flight_mode(
        uint16_t _flight_mode)
{
    m_flight_mode = _flight_mode;
}

/*!
 * @brief This function returns the value of member flight_mode
 * @return Value of member flight_mode
 */
uint16_t DataCtrl::flight_mode() const
{
    return m_flight_mode;
}

/*!
 * @brief This function returns a reference to member flight_mode
 * @return Reference to member flight_mode
 */
uint16_t& DataCtrl::flight_mode()
{
    return m_flight_mode;
}

/*!
 * @brief This function sets a value in member flight_fct
 * @param _flight_fct New value for member flight_fct
 */
void DataCtrl::flight_fct(
        uint16_t _flight_fct)
{
    m_flight_fct = _flight_fct;
}

/*!
 * @brief This function returns the value of member flight_fct
 * @return Value of member flight_fct
 */
uint16_t DataCtrl::flight_fct() const
{
    return m_flight_fct;
}

/*!
 * @brief This function returns a reference to member flight_fct
 * @return Reference to member flight_fct
 */
uint16_t& DataCtrl::flight_fct()
{
    return m_flight_fct;
}

/*!
 * @brief This function sets a value in member alive
 * @param _alive New value for member alive
 */
void DataCtrl::alive(
        bool _alive)
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


size_t DataCtrl::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t current_align = current_alignment;






















    return current_align;
}

bool DataCtrl::isKeyDefined()
{
    return false;
}

void DataCtrl::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
                       
}
