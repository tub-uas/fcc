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
 * @file DataGps.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _DATAGPS_H_
#define _DATAGPS_H_

// TODO Poner en el contexto.

#include <stdint.h>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <bitset>

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif
#else
#define eProsima_user_DllExport
#endif

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(DataGps_SOURCE)
#define DataGps_DllAPI __declspec( dllexport )
#else
#define DataGps_DllAPI __declspec( dllimport )
#endif // DataGps_SOURCE
#else
#define DataGps_DllAPI
#endif
#else
#define DataGps_DllAPI
#endif // _WIN32

namespace eprosima
{
    namespace fastcdr
    {
        class Cdr;
    }
}


/*!
 * @brief This class represents the structure DataGps defined by the user in the IDL file.
 * @ingroup DATAGPS
 */
class DataGps
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport DataGps();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~DataGps();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object DataGps that will be copied.
     */
    eProsima_user_DllExport DataGps(const DataGps &x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object DataGps that will be copied.
     */
    eProsima_user_DllExport DataGps(DataGps &&x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object DataGps that will be copied.
     */
    eProsima_user_DllExport DataGps& operator=(const DataGps &x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object DataGps that will be copied.
     */
    eProsima_user_DllExport DataGps& operator=(DataGps &&x);

    /*!
     * @brief This function sets a value in member time
     * @param _time New value for member time
     */
    eProsima_user_DllExport void time(uint64_t _time);

    /*!
     * @brief This function returns the value of member time
     * @return Value of member time
     */
    eProsima_user_DllExport uint64_t time() const;

    /*!
     * @brief This function returns a reference to member time
     * @return Reference to member time
     */
    eProsima_user_DllExport uint64_t& time();

    /*!
     * @brief This function sets a value in member senseTime
     * @param _senseTime New value for member senseTime
     */
    eProsima_user_DllExport void senseTime(float _senseTime);

    /*!
     * @brief This function returns the value of member senseTime
     * @return Value of member senseTime
     */
    eProsima_user_DllExport float senseTime() const;

    /*!
     * @brief This function returns a reference to member senseTime
     * @return Reference to member senseTime
     */
    eProsima_user_DllExport float& senseTime();

    /*!
     * @brief This function sets a value in member lat
     * @param _lat New value for member lat
     */
    eProsima_user_DllExport void lat(float _lat);

    /*!
     * @brief This function returns the value of member lat
     * @return Value of member lat
     */
    eProsima_user_DllExport float lat() const;

    /*!
     * @brief This function returns a reference to member lat
     * @return Reference to member lat
     */
    eProsima_user_DllExport float& lat();

    /*!
     * @brief This function sets a value in member lon
     * @param _lon New value for member lon
     */
    eProsima_user_DllExport void lon(float _lon);

    /*!
     * @brief This function returns the value of member lon
     * @return Value of member lon
     */
    eProsima_user_DllExport float lon() const;

    /*!
     * @brief This function returns a reference to member lon
     * @return Reference to member lon
     */
    eProsima_user_DllExport float& lon();

    /*!
     * @brief This function sets a value in member alt
     * @param _alt New value for member alt
     */
    eProsima_user_DllExport void alt(float _alt);

    /*!
     * @brief This function returns the value of member alt
     * @return Value of member alt
     */
    eProsima_user_DllExport float alt() const;

    /*!
     * @brief This function returns a reference to member alt
     * @return Reference to member alt
     */
    eProsima_user_DllExport float& alt();

    /*!
     * @brief This function sets a value in member cog
     * @param _cog New value for member cog
     */
    eProsima_user_DllExport void cog(float _cog);

    /*!
     * @brief This function returns the value of member cog
     * @return Value of member cog
     */
    eProsima_user_DllExport float cog() const;

    /*!
     * @brief This function returns a reference to member cog
     * @return Reference to member cog
     */
    eProsima_user_DllExport float& cog();

    /*!
     * @brief This function sets a value in member dopP
     * @param _dopP New value for member dopP
     */
    eProsima_user_DllExport void dopP(float _dopP);

    /*!
     * @brief This function returns the value of member dopP
     * @return Value of member dopP
     */
    eProsima_user_DllExport float dopP() const;

    /*!
     * @brief This function returns a reference to member dopP
     * @return Reference to member dopP
     */
    eProsima_user_DllExport float& dopP();

    /*!
     * @brief This function sets a value in member dopH
     * @param _dopH New value for member dopH
     */
    eProsima_user_DllExport void dopH(float _dopH);

    /*!
     * @brief This function returns the value of member dopH
     * @return Value of member dopH
     */
    eProsima_user_DllExport float dopH() const;

    /*!
     * @brief This function returns a reference to member dopH
     * @return Reference to member dopH
     */
    eProsima_user_DllExport float& dopH();

    /*!
     * @brief This function sets a value in member dopV
     * @param _dopV New value for member dopV
     */
    eProsima_user_DllExport void dopV(float _dopV);

    /*!
     * @brief This function returns the value of member dopV
     * @return Value of member dopV
     */
    eProsima_user_DllExport float dopV() const;

    /*!
     * @brief This function returns a reference to member dopV
     * @return Reference to member dopV
     */
    eProsima_user_DllExport float& dopV();

    /*!
     * @brief This function sets a value in member sats
     * @param _sats New value for member sats
     */
    eProsima_user_DllExport void sats(uint16_t _sats);

    /*!
     * @brief This function returns the value of member sats
     * @return Value of member sats
     */
    eProsima_user_DllExport uint16_t sats() const;

    /*!
     * @brief This function returns a reference to member sats
     * @return Reference to member sats
     */
    eProsima_user_DllExport uint16_t& sats();

    /*!
     * @brief This function sets a value in member satsInView
     * @param _satsInView New value for member satsInView
     */
    eProsima_user_DllExport void satsInView(uint16_t _satsInView);

    /*!
     * @brief This function returns the value of member satsInView
     * @return Value of member satsInView
     */
    eProsima_user_DllExport uint16_t satsInView() const;

    /*!
     * @brief This function returns a reference to member satsInView
     * @return Reference to member satsInView
     */
    eProsima_user_DllExport uint16_t& satsInView();

    /*!
     * @brief This function sets a value in member fix
     * @param _fix New value for member fix
     */
    eProsima_user_DllExport void fix(uint16_t _fix);

    /*!
     * @brief This function returns the value of member fix
     * @return Value of member fix
     */
    eProsima_user_DllExport uint16_t fix() const;

    /*!
     * @brief This function returns a reference to member fix
     * @return Reference to member fix
     */
    eProsima_user_DllExport uint16_t& fix();

    /*!
     * @brief This function sets a value in member fixMode
     * @param _fixMode New value for member fixMode
     */
    eProsima_user_DllExport void fixMode(uint16_t _fixMode);

    /*!
     * @brief This function returns the value of member fixMode
     * @return Value of member fixMode
     */
    eProsima_user_DllExport uint16_t fixMode() const;

    /*!
     * @brief This function returns a reference to member fixMode
     * @return Reference to member fixMode
     */
    eProsima_user_DllExport uint16_t& fixMode();

    /*!
     * @brief This function sets a value in member second
     * @param _second New value for member second
     */
    eProsima_user_DllExport void second(uint16_t _second);

    /*!
     * @brief This function returns the value of member second
     * @return Value of member second
     */
    eProsima_user_DllExport uint16_t second() const;

    /*!
     * @brief This function returns a reference to member second
     * @return Reference to member second
     */
    eProsima_user_DllExport uint16_t& second();

    /*!
     * @brief This function sets a value in member minute
     * @param _minute New value for member minute
     */
    eProsima_user_DllExport void minute(uint16_t _minute);

    /*!
     * @brief This function returns the value of member minute
     * @return Value of member minute
     */
    eProsima_user_DllExport uint16_t minute() const;

    /*!
     * @brief This function returns a reference to member minute
     * @return Reference to member minute
     */
    eProsima_user_DllExport uint16_t& minute();

    /*!
     * @brief This function sets a value in member hour
     * @param _hour New value for member hour
     */
    eProsima_user_DllExport void hour(uint16_t _hour);

    /*!
     * @brief This function returns the value of member hour
     * @return Value of member hour
     */
    eProsima_user_DllExport uint16_t hour() const;

    /*!
     * @brief This function returns a reference to member hour
     * @return Reference to member hour
     */
    eProsima_user_DllExport uint16_t& hour();

    /*!
     * @brief This function sets a value in member day
     * @param _day New value for member day
     */
    eProsima_user_DllExport void day(uint16_t _day);

    /*!
     * @brief This function returns the value of member day
     * @return Value of member day
     */
    eProsima_user_DllExport uint16_t day() const;

    /*!
     * @brief This function returns a reference to member day
     * @return Reference to member day
     */
    eProsima_user_DllExport uint16_t& day();

    /*!
     * @brief This function sets a value in member month
     * @param _month New value for member month
     */
    eProsima_user_DllExport void month(uint16_t _month);

    /*!
     * @brief This function returns the value of member month
     * @return Value of member month
     */
    eProsima_user_DllExport uint16_t month() const;

    /*!
     * @brief This function returns a reference to member month
     * @return Reference to member month
     */
    eProsima_user_DllExport uint16_t& month();

    /*!
     * @brief This function sets a value in member year
     * @param _year New value for member year
     */
    eProsima_user_DllExport void year(uint16_t _year);

    /*!
     * @brief This function returns the value of member year
     * @return Value of member year
     */
    eProsima_user_DllExport uint16_t year() const;

    /*!
     * @brief This function returns a reference to member year
     * @return Reference to member year
     */
    eProsima_user_DllExport uint16_t& year();

    /*!
     * @brief This function sets a value in member variation
     * @param _variation New value for member variation
     */
    eProsima_user_DllExport void variation(float _variation);

    /*!
     * @brief This function returns the value of member variation
     * @return Value of member variation
     */
    eProsima_user_DllExport float variation() const;

    /*!
     * @brief This function returns a reference to member variation
     * @return Reference to member variation
     */
    eProsima_user_DllExport float& variation();

    /*!
     * @brief This function sets a value in member magX
     * @param _magX New value for member magX
     */
    eProsima_user_DllExport void magX(float _magX);

    /*!
     * @brief This function returns the value of member magX
     * @return Value of member magX
     */
    eProsima_user_DllExport float magX() const;

    /*!
     * @brief This function returns a reference to member magX
     * @return Reference to member magX
     */
    eProsima_user_DllExport float& magX();

    /*!
     * @brief This function sets a value in member magY
     * @param _magY New value for member magY
     */
    eProsima_user_DllExport void magY(float _magY);

    /*!
     * @brief This function returns the value of member magY
     * @return Value of member magY
     */
    eProsima_user_DllExport float magY() const;

    /*!
     * @brief This function returns a reference to member magY
     * @return Reference to member magY
     */
    eProsima_user_DllExport float& magY();

    /*!
     * @brief This function sets a value in member magZ
     * @param _magZ New value for member magZ
     */
    eProsima_user_DllExport void magZ(float _magZ);

    /*!
     * @brief This function returns the value of member magZ
     * @return Value of member magZ
     */
    eProsima_user_DllExport float magZ() const;

    /*!
     * @brief This function returns a reference to member magZ
     * @return Reference to member magZ
     */
    eProsima_user_DllExport float& magZ();

    /*!
     * @brief This function sets a value in member alive
     * @param _alive New value for member alive
     */
    eProsima_user_DllExport void alive(bool _alive);

    /*!
     * @brief This function returns the value of member alive
     * @return Value of member alive
     */
    eProsima_user_DllExport bool alive() const;

    /*!
     * @brief This function returns a reference to member alive
     * @return Reference to member alive
     */
    eProsima_user_DllExport bool& alive();


    /*!
     * @brief This function returns the maximum serialized size of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getMaxCdrSerializedSize(size_t current_alignment = 0);

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(const DataGps& data, size_t current_alignment = 0);


    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serialize(eprosima::fastcdr::Cdr &cdr) const;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void deserialize(eprosima::fastcdr::Cdr &cdr);



    /*!
     * @brief This function returns the maximum serialized size of the Key of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(size_t current_alignment = 0);

    /*!
     * @brief This function tells you if the Key has been defined for this type
     */
    eProsima_user_DllExport static bool isKeyDefined();

    /*!
     * @brief This function serializes the key members of an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serializeKey(eprosima::fastcdr::Cdr &cdr) const;

private:
    uint64_t m_time;
    float m_senseTime;
    float m_lat;
    float m_lon;
    float m_alt;
    float m_cog;
    float m_dopP;
    float m_dopH;
    float m_dopV;
    uint16_t m_sats;
    uint16_t m_satsInView;
    uint16_t m_fix;
    uint16_t m_fixMode;
    uint16_t m_second;
    uint16_t m_minute;
    uint16_t m_hour;
    uint16_t m_day;
    uint16_t m_month;
    uint16_t m_year;
    float m_variation;
    float m_magX;
    float m_magY;
    float m_magZ;
    bool m_alive;
};

#endif // _DATAGPS_H_