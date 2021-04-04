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
 * @file DataRaiOut.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _DATARAIOUT_H_
#define _DATARAIOUT_H_


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
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define eProsima_user_DllExport
#endif  // _WIN32

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(DataRaiOut_SOURCE)
#define DataRaiOut_DllAPI __declspec( dllexport )
#else
#define DataRaiOut_DllAPI __declspec( dllimport )
#endif // DataRaiOut_SOURCE
#else
#define DataRaiOut_DllAPI
#endif  // EPROSIMA_USER_DLL_EXPORT
#else
#define DataRaiOut_DllAPI
#endif // _WIN32

namespace eprosima {
namespace fastcdr {
class Cdr;
} // namespace fastcdr
} // namespace eprosima


/*!
 * @brief This class represents the structure DataRaiOut defined by the user in the IDL file.
 * @ingroup DATARAIOUT
 */
class DataRaiOut
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport DataRaiOut();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~DataRaiOut();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object DataRaiOut that will be copied.
     */
    eProsima_user_DllExport DataRaiOut(
            const DataRaiOut& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object DataRaiOut that will be copied.
     */
    eProsima_user_DllExport DataRaiOut(
            DataRaiOut&& x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object DataRaiOut that will be copied.
     */
    eProsima_user_DllExport DataRaiOut& operator =(
            const DataRaiOut& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object DataRaiOut that will be copied.
     */
    eProsima_user_DllExport DataRaiOut& operator =(
            DataRaiOut&& x);

    /*!
     * @brief This function sets a value in member time
     * @param _time New value for member time
     */
    eProsima_user_DllExport void time(
            uint64_t _time);

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
     * @brief This function copies the value in member chnl
     * @param _chnl New value to be copied in member chnl
     */
    eProsima_user_DllExport void chnl(
            const std::array<uint16_t, 12>& _chnl);

    /*!
     * @brief This function moves the value in member chnl
     * @param _chnl New value to be moved in member chnl
     */
    eProsima_user_DllExport void chnl(
            std::array<uint16_t, 12>&& _chnl);

    /*!
     * @brief This function returns a constant reference to member chnl
     * @return Constant reference to member chnl
     */
    eProsima_user_DllExport const std::array<uint16_t, 12>& chnl() const;

    /*!
     * @brief This function returns a reference to member chnl
     * @return Reference to member chnl
     */
    eProsima_user_DllExport std::array<uint16_t, 12>& chnl();
    /*!
     * @brief This function sets a value in member roll
     * @param _roll New value for member roll
     */
    eProsima_user_DllExport void roll(
            float _roll);

    /*!
     * @brief This function returns the value of member roll
     * @return Value of member roll
     */
    eProsima_user_DllExport float roll() const;

    /*!
     * @brief This function returns a reference to member roll
     * @return Reference to member roll
     */
    eProsima_user_DllExport float& roll();

    /*!
     * @brief This function sets a value in member pitch
     * @param _pitch New value for member pitch
     */
    eProsima_user_DllExport void pitch(
            float _pitch);

    /*!
     * @brief This function returns the value of member pitch
     * @return Value of member pitch
     */
    eProsima_user_DllExport float pitch() const;

    /*!
     * @brief This function returns a reference to member pitch
     * @return Reference to member pitch
     */
    eProsima_user_DllExport float& pitch();

    /*!
     * @brief This function sets a value in member yaw
     * @param _yaw New value for member yaw
     */
    eProsima_user_DllExport void yaw(
            float _yaw);

    /*!
     * @brief This function returns the value of member yaw
     * @return Value of member yaw
     */
    eProsima_user_DllExport float yaw() const;

    /*!
     * @brief This function returns a reference to member yaw
     * @return Reference to member yaw
     */
    eProsima_user_DllExport float& yaw();

    /*!
     * @brief This function sets a value in member thr
     * @param _thr New value for member thr
     */
    eProsima_user_DllExport void thr(
            float _thr);

    /*!
     * @brief This function returns the value of member thr
     * @return Value of member thr
     */
    eProsima_user_DllExport float thr() const;

    /*!
     * @brief This function returns a reference to member thr
     * @return Reference to member thr
     */
    eProsima_user_DllExport float& thr();

    /*!
     * @brief This function sets a value in member fltMode
     * @param _fltMode New value for member fltMode
     */
    eProsima_user_DllExport void fltMode(
            uint16_t _fltMode);

    /*!
     * @brief This function returns the value of member fltMode
     * @return Value of member fltMode
     */
    eProsima_user_DllExport uint16_t fltMode() const;

    /*!
     * @brief This function returns a reference to member fltMode
     * @return Reference to member fltMode
     */
    eProsima_user_DllExport uint16_t& fltMode();

    /*!
     * @brief This function sets a value in member fltFunc
     * @param _fltFunc New value for member fltFunc
     */
    eProsima_user_DllExport void fltFunc(
            uint16_t _fltFunc);

    /*!
     * @brief This function returns the value of member fltFunc
     * @return Value of member fltFunc
     */
    eProsima_user_DllExport uint16_t fltFunc() const;

    /*!
     * @brief This function returns a reference to member fltFunc
     * @return Reference to member fltFunc
     */
    eProsima_user_DllExport uint16_t& fltFunc();

    /*!
     * @brief This function sets a value in member alive
     * @param _alive New value for member alive
     */
    eProsima_user_DllExport void alive(
            bool _alive);

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
    eProsima_user_DllExport static size_t getMaxCdrSerializedSize(
            size_t current_alignment = 0);

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(
            const DataRaiOut& data,
            size_t current_alignment = 0);


    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serialize(
            eprosima::fastcdr::Cdr& cdr) const;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void deserialize(
            eprosima::fastcdr::Cdr& cdr);



    /*!
     * @brief This function returns the maximum serialized size of the Key of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(
            size_t current_alignment = 0);

    /*!
     * @brief This function tells you if the Key has been defined for this type
     */
    eProsima_user_DllExport static bool isKeyDefined();

    /*!
     * @brief This function serializes the key members of an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serializeKey(
            eprosima::fastcdr::Cdr& cdr) const;

private:

    uint64_t m_time;
    std::array<uint16_t, 12> m_chnl;
    float m_roll;
    float m_pitch;
    float m_yaw;
    float m_thr;
    uint16_t m_fltMode;
    uint16_t m_fltFunc;
    bool m_alive;
};

#endif // _DATARAIOUT_H_