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
 * @file DataDownlink.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _DATADOWNLINK_H_
#define _DATADOWNLINK_H_

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
#if defined(DataDownlink_SOURCE)
#define DataDownlink_DllAPI __declspec( dllexport )
#else
#define DataDownlink_DllAPI __declspec( dllimport )
#endif // DataDownlink_SOURCE
#else
#define DataDownlink_DllAPI
#endif
#else
#define DataDownlink_DllAPI
#endif // _WIN32

namespace eprosima
{
    namespace fastcdr
    {
        class Cdr;
    }
}


/*!
 * @brief This class represents the structure DataDownlink defined by the user in the IDL file.
 * @ingroup DATADOWNLINK
 */
class DataDownlink
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport DataDownlink();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~DataDownlink();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object DataDownlink that will be copied.
     */
    eProsima_user_DllExport DataDownlink(const DataDownlink &x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object DataDownlink that will be copied.
     */
    eProsima_user_DllExport DataDownlink(DataDownlink &&x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object DataDownlink that will be copied.
     */
    eProsima_user_DllExport DataDownlink& operator=(const DataDownlink &x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object DataDownlink that will be copied.
     */
    eProsima_user_DllExport DataDownlink& operator=(DataDownlink &&x);

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
    eProsima_user_DllExport static size_t getCdrSerializedSize(const DataDownlink& data, size_t current_alignment = 0);


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
    bool m_alive;
};

#endif // _DATADOWNLINK_H_