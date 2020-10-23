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
 * @file DataGps.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace { char dummy; }
#endif

#include "DataGps.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

DataGps::DataGps()
{
    // m_time com.eprosima.idl.parser.typecode.PrimitiveTypeCode@3b0143d3
    m_time = 0;
    // m_senseTime com.eprosima.idl.parser.typecode.PrimitiveTypeCode@5a8e6209
    m_senseTime = 0.0;
    // m_lat com.eprosima.idl.parser.typecode.PrimitiveTypeCode@4b4523f8
    m_lat = 0.0;
    // m_lon com.eprosima.idl.parser.typecode.PrimitiveTypeCode@731a74c
    m_lon = 0.0;
    // m_alt com.eprosima.idl.parser.typecode.PrimitiveTypeCode@369f73a2
    m_alt = 0.0;
    // m_cog com.eprosima.idl.parser.typecode.PrimitiveTypeCode@1f28c152
    m_cog = 0.0;
    // m_dopP com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7d907bac
    m_dopP = 0.0;
    // m_dopH com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7791a895
    m_dopH = 0.0;
    // m_dopV com.eprosima.idl.parser.typecode.PrimitiveTypeCode@3a5ed7a6
    m_dopV = 0.0;
    // m_sats com.eprosima.idl.parser.typecode.PrimitiveTypeCode@6325a3ee
    m_sats = 0;
    // m_satsInView com.eprosima.idl.parser.typecode.PrimitiveTypeCode@1d16f93d
    m_satsInView = 0;
    // m_fix com.eprosima.idl.parser.typecode.PrimitiveTypeCode@67b92f0a
    m_fix = 0;
    // m_fixMode com.eprosima.idl.parser.typecode.PrimitiveTypeCode@2b9627bc
    m_fixMode = 0;
    // m_second com.eprosima.idl.parser.typecode.PrimitiveTypeCode@65e2dbf3
    m_second = 0;
    // m_minute com.eprosima.idl.parser.typecode.PrimitiveTypeCode@4f970963
    m_minute = 0;
    // m_hour com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7b49cea0
    m_hour = 0;
    // m_day com.eprosima.idl.parser.typecode.PrimitiveTypeCode@6e0e048a
    m_day = 0;
    // m_month com.eprosima.idl.parser.typecode.PrimitiveTypeCode@5bc79255
    m_month = 0;
    // m_year com.eprosima.idl.parser.typecode.PrimitiveTypeCode@47ef968d
    m_year = 0;
    // m_variation com.eprosima.idl.parser.typecode.PrimitiveTypeCode@23e028a9
    m_variation = 0.0;
    // m_magX com.eprosima.idl.parser.typecode.PrimitiveTypeCode@3dd4520b
    m_magX = 0.0;
    // m_magY com.eprosima.idl.parser.typecode.PrimitiveTypeCode@5ae63ade
    m_magY = 0.0;
    // m_magZ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@610694f1
    m_magZ = 0.0;
    // m_alive com.eprosima.idl.parser.typecode.PrimitiveTypeCode@43814d18
    m_alive = false;

}

DataGps::~DataGps()
{
























}

DataGps::DataGps(const DataGps &x)
{
    m_time = x.m_time;
    m_senseTime = x.m_senseTime;
    m_lat = x.m_lat;
    m_lon = x.m_lon;
    m_alt = x.m_alt;
    m_cog = x.m_cog;
    m_dopP = x.m_dopP;
    m_dopH = x.m_dopH;
    m_dopV = x.m_dopV;
    m_sats = x.m_sats;
    m_satsInView = x.m_satsInView;
    m_fix = x.m_fix;
    m_fixMode = x.m_fixMode;
    m_second = x.m_second;
    m_minute = x.m_minute;
    m_hour = x.m_hour;
    m_day = x.m_day;
    m_month = x.m_month;
    m_year = x.m_year;
    m_variation = x.m_variation;
    m_magX = x.m_magX;
    m_magY = x.m_magY;
    m_magZ = x.m_magZ;
    m_alive = x.m_alive;
}

DataGps::DataGps(DataGps &&x)
{
    m_time = x.m_time;
    m_senseTime = x.m_senseTime;
    m_lat = x.m_lat;
    m_lon = x.m_lon;
    m_alt = x.m_alt;
    m_cog = x.m_cog;
    m_dopP = x.m_dopP;
    m_dopH = x.m_dopH;
    m_dopV = x.m_dopV;
    m_sats = x.m_sats;
    m_satsInView = x.m_satsInView;
    m_fix = x.m_fix;
    m_fixMode = x.m_fixMode;
    m_second = x.m_second;
    m_minute = x.m_minute;
    m_hour = x.m_hour;
    m_day = x.m_day;
    m_month = x.m_month;
    m_year = x.m_year;
    m_variation = x.m_variation;
    m_magX = x.m_magX;
    m_magY = x.m_magY;
    m_magZ = x.m_magZ;
    m_alive = x.m_alive;
}

DataGps& DataGps::operator=(const DataGps &x)
{

    m_time = x.m_time;
    m_senseTime = x.m_senseTime;
    m_lat = x.m_lat;
    m_lon = x.m_lon;
    m_alt = x.m_alt;
    m_cog = x.m_cog;
    m_dopP = x.m_dopP;
    m_dopH = x.m_dopH;
    m_dopV = x.m_dopV;
    m_sats = x.m_sats;
    m_satsInView = x.m_satsInView;
    m_fix = x.m_fix;
    m_fixMode = x.m_fixMode;
    m_second = x.m_second;
    m_minute = x.m_minute;
    m_hour = x.m_hour;
    m_day = x.m_day;
    m_month = x.m_month;
    m_year = x.m_year;
    m_variation = x.m_variation;
    m_magX = x.m_magX;
    m_magY = x.m_magY;
    m_magZ = x.m_magZ;
    m_alive = x.m_alive;

    return *this;
}

DataGps& DataGps::operator=(DataGps &&x)
{

    m_time = x.m_time;
    m_senseTime = x.m_senseTime;
    m_lat = x.m_lat;
    m_lon = x.m_lon;
    m_alt = x.m_alt;
    m_cog = x.m_cog;
    m_dopP = x.m_dopP;
    m_dopH = x.m_dopH;
    m_dopV = x.m_dopV;
    m_sats = x.m_sats;
    m_satsInView = x.m_satsInView;
    m_fix = x.m_fix;
    m_fixMode = x.m_fixMode;
    m_second = x.m_second;
    m_minute = x.m_minute;
    m_hour = x.m_hour;
    m_day = x.m_day;
    m_month = x.m_month;
    m_year = x.m_year;
    m_variation = x.m_variation;
    m_magX = x.m_magX;
    m_magY = x.m_magY;
    m_magZ = x.m_magZ;
    m_alive = x.m_alive;

    return *this;
}

size_t DataGps::getMaxCdrSerializedSize(size_t current_alignment)
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


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

size_t DataGps::getCdrSerializedSize(const DataGps& data, size_t current_alignment)
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


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

void DataGps::serialize(eprosima::fastcdr::Cdr &scdr) const
{

    scdr << m_time;
    scdr << m_senseTime;
    scdr << m_lat;
    scdr << m_lon;
    scdr << m_alt;
    scdr << m_cog;
    scdr << m_dopP;
    scdr << m_dopH;
    scdr << m_dopV;
    scdr << m_sats;
    scdr << m_satsInView;
    scdr << m_fix;
    scdr << m_fixMode;
    scdr << m_second;
    scdr << m_minute;
    scdr << m_hour;
    scdr << m_day;
    scdr << m_month;
    scdr << m_year;
    scdr << m_variation;
    scdr << m_magX;
    scdr << m_magY;
    scdr << m_magZ;
    scdr << m_alive;
}

void DataGps::deserialize(eprosima::fastcdr::Cdr &dcdr)
{

    dcdr >> m_time;
    dcdr >> m_senseTime;
    dcdr >> m_lat;
    dcdr >> m_lon;
    dcdr >> m_alt;
    dcdr >> m_cog;
    dcdr >> m_dopP;
    dcdr >> m_dopH;
    dcdr >> m_dopV;
    dcdr >> m_sats;
    dcdr >> m_satsInView;
    dcdr >> m_fix;
    dcdr >> m_fixMode;
    dcdr >> m_second;
    dcdr >> m_minute;
    dcdr >> m_hour;
    dcdr >> m_day;
    dcdr >> m_month;
    dcdr >> m_year;
    dcdr >> m_variation;
    dcdr >> m_magX;
    dcdr >> m_magY;
    dcdr >> m_magZ;
    dcdr >> m_alive;
}

/*!
 * @brief This function sets a value in member time
 * @param _time New value for member time
 */
void DataGps::time(uint64_t _time)
{
m_time = _time;
}

/*!
 * @brief This function returns the value of member time
 * @return Value of member time
 */
uint64_t DataGps::time() const
{
    return m_time;
}

/*!
 * @brief This function returns a reference to member time
 * @return Reference to member time
 */
uint64_t& DataGps::time()
{
    return m_time;
}

/*!
 * @brief This function sets a value in member senseTime
 * @param _senseTime New value for member senseTime
 */
void DataGps::senseTime(float _senseTime)
{
m_senseTime = _senseTime;
}

/*!
 * @brief This function returns the value of member senseTime
 * @return Value of member senseTime
 */
float DataGps::senseTime() const
{
    return m_senseTime;
}

/*!
 * @brief This function returns a reference to member senseTime
 * @return Reference to member senseTime
 */
float& DataGps::senseTime()
{
    return m_senseTime;
}

/*!
 * @brief This function sets a value in member lat
 * @param _lat New value for member lat
 */
void DataGps::lat(float _lat)
{
m_lat = _lat;
}

/*!
 * @brief This function returns the value of member lat
 * @return Value of member lat
 */
float DataGps::lat() const
{
    return m_lat;
}

/*!
 * @brief This function returns a reference to member lat
 * @return Reference to member lat
 */
float& DataGps::lat()
{
    return m_lat;
}

/*!
 * @brief This function sets a value in member lon
 * @param _lon New value for member lon
 */
void DataGps::lon(float _lon)
{
m_lon = _lon;
}

/*!
 * @brief This function returns the value of member lon
 * @return Value of member lon
 */
float DataGps::lon() const
{
    return m_lon;
}

/*!
 * @brief This function returns a reference to member lon
 * @return Reference to member lon
 */
float& DataGps::lon()
{
    return m_lon;
}

/*!
 * @brief This function sets a value in member alt
 * @param _alt New value for member alt
 */
void DataGps::alt(float _alt)
{
m_alt = _alt;
}

/*!
 * @brief This function returns the value of member alt
 * @return Value of member alt
 */
float DataGps::alt() const
{
    return m_alt;
}

/*!
 * @brief This function returns a reference to member alt
 * @return Reference to member alt
 */
float& DataGps::alt()
{
    return m_alt;
}

/*!
 * @brief This function sets a value in member cog
 * @param _cog New value for member cog
 */
void DataGps::cog(float _cog)
{
m_cog = _cog;
}

/*!
 * @brief This function returns the value of member cog
 * @return Value of member cog
 */
float DataGps::cog() const
{
    return m_cog;
}

/*!
 * @brief This function returns a reference to member cog
 * @return Reference to member cog
 */
float& DataGps::cog()
{
    return m_cog;
}

/*!
 * @brief This function sets a value in member dopP
 * @param _dopP New value for member dopP
 */
void DataGps::dopP(float _dopP)
{
m_dopP = _dopP;
}

/*!
 * @brief This function returns the value of member dopP
 * @return Value of member dopP
 */
float DataGps::dopP() const
{
    return m_dopP;
}

/*!
 * @brief This function returns a reference to member dopP
 * @return Reference to member dopP
 */
float& DataGps::dopP()
{
    return m_dopP;
}

/*!
 * @brief This function sets a value in member dopH
 * @param _dopH New value for member dopH
 */
void DataGps::dopH(float _dopH)
{
m_dopH = _dopH;
}

/*!
 * @brief This function returns the value of member dopH
 * @return Value of member dopH
 */
float DataGps::dopH() const
{
    return m_dopH;
}

/*!
 * @brief This function returns a reference to member dopH
 * @return Reference to member dopH
 */
float& DataGps::dopH()
{
    return m_dopH;
}

/*!
 * @brief This function sets a value in member dopV
 * @param _dopV New value for member dopV
 */
void DataGps::dopV(float _dopV)
{
m_dopV = _dopV;
}

/*!
 * @brief This function returns the value of member dopV
 * @return Value of member dopV
 */
float DataGps::dopV() const
{
    return m_dopV;
}

/*!
 * @brief This function returns a reference to member dopV
 * @return Reference to member dopV
 */
float& DataGps::dopV()
{
    return m_dopV;
}

/*!
 * @brief This function sets a value in member sats
 * @param _sats New value for member sats
 */
void DataGps::sats(uint16_t _sats)
{
m_sats = _sats;
}

/*!
 * @brief This function returns the value of member sats
 * @return Value of member sats
 */
uint16_t DataGps::sats() const
{
    return m_sats;
}

/*!
 * @brief This function returns a reference to member sats
 * @return Reference to member sats
 */
uint16_t& DataGps::sats()
{
    return m_sats;
}

/*!
 * @brief This function sets a value in member satsInView
 * @param _satsInView New value for member satsInView
 */
void DataGps::satsInView(uint16_t _satsInView)
{
m_satsInView = _satsInView;
}

/*!
 * @brief This function returns the value of member satsInView
 * @return Value of member satsInView
 */
uint16_t DataGps::satsInView() const
{
    return m_satsInView;
}

/*!
 * @brief This function returns a reference to member satsInView
 * @return Reference to member satsInView
 */
uint16_t& DataGps::satsInView()
{
    return m_satsInView;
}

/*!
 * @brief This function sets a value in member fix
 * @param _fix New value for member fix
 */
void DataGps::fix(uint16_t _fix)
{
m_fix = _fix;
}

/*!
 * @brief This function returns the value of member fix
 * @return Value of member fix
 */
uint16_t DataGps::fix() const
{
    return m_fix;
}

/*!
 * @brief This function returns a reference to member fix
 * @return Reference to member fix
 */
uint16_t& DataGps::fix()
{
    return m_fix;
}

/*!
 * @brief This function sets a value in member fixMode
 * @param _fixMode New value for member fixMode
 */
void DataGps::fixMode(uint16_t _fixMode)
{
m_fixMode = _fixMode;
}

/*!
 * @brief This function returns the value of member fixMode
 * @return Value of member fixMode
 */
uint16_t DataGps::fixMode() const
{
    return m_fixMode;
}

/*!
 * @brief This function returns a reference to member fixMode
 * @return Reference to member fixMode
 */
uint16_t& DataGps::fixMode()
{
    return m_fixMode;
}

/*!
 * @brief This function sets a value in member second
 * @param _second New value for member second
 */
void DataGps::second(uint16_t _second)
{
m_second = _second;
}

/*!
 * @brief This function returns the value of member second
 * @return Value of member second
 */
uint16_t DataGps::second() const
{
    return m_second;
}

/*!
 * @brief This function returns a reference to member second
 * @return Reference to member second
 */
uint16_t& DataGps::second()
{
    return m_second;
}

/*!
 * @brief This function sets a value in member minute
 * @param _minute New value for member minute
 */
void DataGps::minute(uint16_t _minute)
{
m_minute = _minute;
}

/*!
 * @brief This function returns the value of member minute
 * @return Value of member minute
 */
uint16_t DataGps::minute() const
{
    return m_minute;
}

/*!
 * @brief This function returns a reference to member minute
 * @return Reference to member minute
 */
uint16_t& DataGps::minute()
{
    return m_minute;
}

/*!
 * @brief This function sets a value in member hour
 * @param _hour New value for member hour
 */
void DataGps::hour(uint16_t _hour)
{
m_hour = _hour;
}

/*!
 * @brief This function returns the value of member hour
 * @return Value of member hour
 */
uint16_t DataGps::hour() const
{
    return m_hour;
}

/*!
 * @brief This function returns a reference to member hour
 * @return Reference to member hour
 */
uint16_t& DataGps::hour()
{
    return m_hour;
}

/*!
 * @brief This function sets a value in member day
 * @param _day New value for member day
 */
void DataGps::day(uint16_t _day)
{
m_day = _day;
}

/*!
 * @brief This function returns the value of member day
 * @return Value of member day
 */
uint16_t DataGps::day() const
{
    return m_day;
}

/*!
 * @brief This function returns a reference to member day
 * @return Reference to member day
 */
uint16_t& DataGps::day()
{
    return m_day;
}

/*!
 * @brief This function sets a value in member month
 * @param _month New value for member month
 */
void DataGps::month(uint16_t _month)
{
m_month = _month;
}

/*!
 * @brief This function returns the value of member month
 * @return Value of member month
 */
uint16_t DataGps::month() const
{
    return m_month;
}

/*!
 * @brief This function returns a reference to member month
 * @return Reference to member month
 */
uint16_t& DataGps::month()
{
    return m_month;
}

/*!
 * @brief This function sets a value in member year
 * @param _year New value for member year
 */
void DataGps::year(uint16_t _year)
{
m_year = _year;
}

/*!
 * @brief This function returns the value of member year
 * @return Value of member year
 */
uint16_t DataGps::year() const
{
    return m_year;
}

/*!
 * @brief This function returns a reference to member year
 * @return Reference to member year
 */
uint16_t& DataGps::year()
{
    return m_year;
}

/*!
 * @brief This function sets a value in member variation
 * @param _variation New value for member variation
 */
void DataGps::variation(float _variation)
{
m_variation = _variation;
}

/*!
 * @brief This function returns the value of member variation
 * @return Value of member variation
 */
float DataGps::variation() const
{
    return m_variation;
}

/*!
 * @brief This function returns a reference to member variation
 * @return Reference to member variation
 */
float& DataGps::variation()
{
    return m_variation;
}

/*!
 * @brief This function sets a value in member magX
 * @param _magX New value for member magX
 */
void DataGps::magX(float _magX)
{
m_magX = _magX;
}

/*!
 * @brief This function returns the value of member magX
 * @return Value of member magX
 */
float DataGps::magX() const
{
    return m_magX;
}

/*!
 * @brief This function returns a reference to member magX
 * @return Reference to member magX
 */
float& DataGps::magX()
{
    return m_magX;
}

/*!
 * @brief This function sets a value in member magY
 * @param _magY New value for member magY
 */
void DataGps::magY(float _magY)
{
m_magY = _magY;
}

/*!
 * @brief This function returns the value of member magY
 * @return Value of member magY
 */
float DataGps::magY() const
{
    return m_magY;
}

/*!
 * @brief This function returns a reference to member magY
 * @return Reference to member magY
 */
float& DataGps::magY()
{
    return m_magY;
}

/*!
 * @brief This function sets a value in member magZ
 * @param _magZ New value for member magZ
 */
void DataGps::magZ(float _magZ)
{
m_magZ = _magZ;
}

/*!
 * @brief This function returns the value of member magZ
 * @return Value of member magZ
 */
float DataGps::magZ() const
{
    return m_magZ;
}

/*!
 * @brief This function returns a reference to member magZ
 * @return Reference to member magZ
 */
float& DataGps::magZ()
{
    return m_magZ;
}

/*!
 * @brief This function sets a value in member alive
 * @param _alive New value for member alive
 */
void DataGps::alive(bool _alive)
{
m_alive = _alive;
}

/*!
 * @brief This function returns the value of member alive
 * @return Value of member alive
 */
bool DataGps::alive() const
{
    return m_alive;
}

/*!
 * @brief This function returns a reference to member alive
 * @return Reference to member alive
 */
bool& DataGps::alive()
{
    return m_alive;
}


size_t DataGps::getKeyMaxCdrSerializedSize(size_t current_alignment)
{
    size_t current_align = current_alignment;



























    return current_align;
}

bool DataGps::isKeyDefined()
{
   return false;
}

void DataGps::serializeKey(eprosima::fastcdr::Cdr &scdr) const
{
    (void) scdr;
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
}
