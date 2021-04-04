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
 * @file DataSFusion.cpp
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

#include "DataSFusion.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

DataSFusion::DataSFusion()
{
    // m_time com.eprosima.idl.parser.typecode.PrimitiveTypeCode@cb0ed20
    m_time = 0;
    // m_gyrX com.eprosima.idl.parser.typecode.PrimitiveTypeCode@8e24743
    m_gyrX = 0.0;
    // m_gyrY com.eprosima.idl.parser.typecode.PrimitiveTypeCode@74a10858
    m_gyrY = 0.0;
    // m_gyrZ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@23fe1d71
    m_gyrZ = 0.0;
    // m_accX com.eprosima.idl.parser.typecode.PrimitiveTypeCode@28ac3dc3
    m_accX = 0.0;
    // m_accY com.eprosima.idl.parser.typecode.PrimitiveTypeCode@32eebfca
    m_accY = 0.0;
    // m_accZ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@4e718207
    m_accZ = 0.0;
    // m_magX com.eprosima.idl.parser.typecode.PrimitiveTypeCode@1d371b2d
    m_magX = 0.0;
    // m_magY com.eprosima.idl.parser.typecode.PrimitiveTypeCode@543c6f6d
    m_magY = 0.0;
    // m_magZ com.eprosima.idl.parser.typecode.PrimitiveTypeCode@13eb8acf
    m_magZ = 0.0;
    // m_temp com.eprosima.idl.parser.typecode.PrimitiveTypeCode@51c8530f
    m_temp = 0.0;
    // m_press com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7403c468
    m_press = 0.0;
    // m_phi com.eprosima.idl.parser.typecode.PrimitiveTypeCode@43738a82
    m_phi = 0.0;
    // m_the com.eprosima.idl.parser.typecode.PrimitiveTypeCode@c81cdd1
    m_the = 0.0;
    // m_psi com.eprosima.idl.parser.typecode.PrimitiveTypeCode@1fc2b765
    m_psi = 0.0;
    // m_q0 com.eprosima.idl.parser.typecode.PrimitiveTypeCode@289d1c02
    m_q0 = 0.0;
    // m_q1 com.eprosima.idl.parser.typecode.PrimitiveTypeCode@a74868d
    m_q1 = 0.0;
    // m_q2 com.eprosima.idl.parser.typecode.PrimitiveTypeCode@12c8a2c0
    m_q2 = 0.0;
    // m_q3 com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7e0e6aa2
    m_q3 = 0.0;
    // m_posN com.eprosima.idl.parser.typecode.PrimitiveTypeCode@365185bd
    m_posN = 0.0;
    // m_posE com.eprosima.idl.parser.typecode.PrimitiveTypeCode@18bf3d14
    m_posE = 0.0;
    // m_posD com.eprosima.idl.parser.typecode.PrimitiveTypeCode@4fb64261
    m_posD = 0.0;
    // m_speedN com.eprosima.idl.parser.typecode.PrimitiveTypeCode@42607a4f
    m_speedN = 0.0;
    // m_speedE com.eprosima.idl.parser.typecode.PrimitiveTypeCode@782663d3
    m_speedE = 0.0;
    // m_speedD com.eprosima.idl.parser.typecode.PrimitiveTypeCode@1990a65e
    m_speedD = 0.0;
    // m_windN com.eprosima.idl.parser.typecode.PrimitiveTypeCode@64485a47
    m_windN = 0.0;
    // m_windE com.eprosima.idl.parser.typecode.PrimitiveTypeCode@25bbf683
    m_windE = 0.0;
    // m_windD com.eprosima.idl.parser.typecode.PrimitiveTypeCode@6ec8211c
    m_windD = 0.0;
    // m_ssa com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7276c8cd
    m_ssa = 0.0;
    // m_aoa com.eprosima.idl.parser.typecode.PrimitiveTypeCode@544a2ea6
    m_aoa = 0.0;
    // m_gamma com.eprosima.idl.parser.typecode.PrimitiveTypeCode@2e3fc542
    m_gamma = 0.0;
    // m_alive com.eprosima.idl.parser.typecode.PrimitiveTypeCode@150c158
    m_alive = false;

}

DataSFusion::~DataSFusion()
{
































}

DataSFusion::DataSFusion(
        const DataSFusion& x)
{
    m_time = x.m_time;
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
    m_posN = x.m_posN;
    m_posE = x.m_posE;
    m_posD = x.m_posD;
    m_speedN = x.m_speedN;
    m_speedE = x.m_speedE;
    m_speedD = x.m_speedD;
    m_windN = x.m_windN;
    m_windE = x.m_windE;
    m_windD = x.m_windD;
    m_ssa = x.m_ssa;
    m_aoa = x.m_aoa;
    m_gamma = x.m_gamma;
    m_alive = x.m_alive;
}

DataSFusion::DataSFusion(
        DataSFusion&& x)
{
    m_time = x.m_time;
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
    m_posN = x.m_posN;
    m_posE = x.m_posE;
    m_posD = x.m_posD;
    m_speedN = x.m_speedN;
    m_speedE = x.m_speedE;
    m_speedD = x.m_speedD;
    m_windN = x.m_windN;
    m_windE = x.m_windE;
    m_windD = x.m_windD;
    m_ssa = x.m_ssa;
    m_aoa = x.m_aoa;
    m_gamma = x.m_gamma;
    m_alive = x.m_alive;
}

DataSFusion& DataSFusion::operator =(
        const DataSFusion& x)
{

    m_time = x.m_time;
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
    m_posN = x.m_posN;
    m_posE = x.m_posE;
    m_posD = x.m_posD;
    m_speedN = x.m_speedN;
    m_speedE = x.m_speedE;
    m_speedD = x.m_speedD;
    m_windN = x.m_windN;
    m_windE = x.m_windE;
    m_windD = x.m_windD;
    m_ssa = x.m_ssa;
    m_aoa = x.m_aoa;
    m_gamma = x.m_gamma;
    m_alive = x.m_alive;

    return *this;
}

DataSFusion& DataSFusion::operator =(
        DataSFusion&& x)
{

    m_time = x.m_time;
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
    m_posN = x.m_posN;
    m_posE = x.m_posE;
    m_posD = x.m_posD;
    m_speedN = x.m_speedN;
    m_speedE = x.m_speedE;
    m_speedD = x.m_speedD;
    m_windN = x.m_windN;
    m_windE = x.m_windE;
    m_windD = x.m_windD;
    m_ssa = x.m_ssa;
    m_aoa = x.m_aoa;
    m_gamma = x.m_gamma;
    m_alive = x.m_alive;

    return *this;
}

size_t DataSFusion::getMaxCdrSerializedSize(
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

size_t DataSFusion::getCdrSerializedSize(
        const DataSFusion& data,
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

void DataSFusion::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_time;
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
    scdr << m_posN;
    scdr << m_posE;
    scdr << m_posD;
    scdr << m_speedN;
    scdr << m_speedE;
    scdr << m_speedD;
    scdr << m_windN;
    scdr << m_windE;
    scdr << m_windD;
    scdr << m_ssa;
    scdr << m_aoa;
    scdr << m_gamma;
    scdr << m_alive;

}

void DataSFusion::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_time;
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
    dcdr >> m_posN;
    dcdr >> m_posE;
    dcdr >> m_posD;
    dcdr >> m_speedN;
    dcdr >> m_speedE;
    dcdr >> m_speedD;
    dcdr >> m_windN;
    dcdr >> m_windE;
    dcdr >> m_windD;
    dcdr >> m_ssa;
    dcdr >> m_aoa;
    dcdr >> m_gamma;
    dcdr >> m_alive;
}

/*!
 * @brief This function sets a value in member time
 * @param _time New value for member time
 */
void DataSFusion::time(
        uint64_t _time)
{
    m_time = _time;
}

/*!
 * @brief This function returns the value of member time
 * @return Value of member time
 */
uint64_t DataSFusion::time() const
{
    return m_time;
}

/*!
 * @brief This function returns a reference to member time
 * @return Reference to member time
 */
uint64_t& DataSFusion::time()
{
    return m_time;
}

/*!
 * @brief This function sets a value in member gyrX
 * @param _gyrX New value for member gyrX
 */
void DataSFusion::gyrX(
        float _gyrX)
{
    m_gyrX = _gyrX;
}

/*!
 * @brief This function returns the value of member gyrX
 * @return Value of member gyrX
 */
float DataSFusion::gyrX() const
{
    return m_gyrX;
}

/*!
 * @brief This function returns a reference to member gyrX
 * @return Reference to member gyrX
 */
float& DataSFusion::gyrX()
{
    return m_gyrX;
}

/*!
 * @brief This function sets a value in member gyrY
 * @param _gyrY New value for member gyrY
 */
void DataSFusion::gyrY(
        float _gyrY)
{
    m_gyrY = _gyrY;
}

/*!
 * @brief This function returns the value of member gyrY
 * @return Value of member gyrY
 */
float DataSFusion::gyrY() const
{
    return m_gyrY;
}

/*!
 * @brief This function returns a reference to member gyrY
 * @return Reference to member gyrY
 */
float& DataSFusion::gyrY()
{
    return m_gyrY;
}

/*!
 * @brief This function sets a value in member gyrZ
 * @param _gyrZ New value for member gyrZ
 */
void DataSFusion::gyrZ(
        float _gyrZ)
{
    m_gyrZ = _gyrZ;
}

/*!
 * @brief This function returns the value of member gyrZ
 * @return Value of member gyrZ
 */
float DataSFusion::gyrZ() const
{
    return m_gyrZ;
}

/*!
 * @brief This function returns a reference to member gyrZ
 * @return Reference to member gyrZ
 */
float& DataSFusion::gyrZ()
{
    return m_gyrZ;
}

/*!
 * @brief This function sets a value in member accX
 * @param _accX New value for member accX
 */
void DataSFusion::accX(
        float _accX)
{
    m_accX = _accX;
}

/*!
 * @brief This function returns the value of member accX
 * @return Value of member accX
 */
float DataSFusion::accX() const
{
    return m_accX;
}

/*!
 * @brief This function returns a reference to member accX
 * @return Reference to member accX
 */
float& DataSFusion::accX()
{
    return m_accX;
}

/*!
 * @brief This function sets a value in member accY
 * @param _accY New value for member accY
 */
void DataSFusion::accY(
        float _accY)
{
    m_accY = _accY;
}

/*!
 * @brief This function returns the value of member accY
 * @return Value of member accY
 */
float DataSFusion::accY() const
{
    return m_accY;
}

/*!
 * @brief This function returns a reference to member accY
 * @return Reference to member accY
 */
float& DataSFusion::accY()
{
    return m_accY;
}

/*!
 * @brief This function sets a value in member accZ
 * @param _accZ New value for member accZ
 */
void DataSFusion::accZ(
        float _accZ)
{
    m_accZ = _accZ;
}

/*!
 * @brief This function returns the value of member accZ
 * @return Value of member accZ
 */
float DataSFusion::accZ() const
{
    return m_accZ;
}

/*!
 * @brief This function returns a reference to member accZ
 * @return Reference to member accZ
 */
float& DataSFusion::accZ()
{
    return m_accZ;
}

/*!
 * @brief This function sets a value in member magX
 * @param _magX New value for member magX
 */
void DataSFusion::magX(
        float _magX)
{
    m_magX = _magX;
}

/*!
 * @brief This function returns the value of member magX
 * @return Value of member magX
 */
float DataSFusion::magX() const
{
    return m_magX;
}

/*!
 * @brief This function returns a reference to member magX
 * @return Reference to member magX
 */
float& DataSFusion::magX()
{
    return m_magX;
}

/*!
 * @brief This function sets a value in member magY
 * @param _magY New value for member magY
 */
void DataSFusion::magY(
        float _magY)
{
    m_magY = _magY;
}

/*!
 * @brief This function returns the value of member magY
 * @return Value of member magY
 */
float DataSFusion::magY() const
{
    return m_magY;
}

/*!
 * @brief This function returns a reference to member magY
 * @return Reference to member magY
 */
float& DataSFusion::magY()
{
    return m_magY;
}

/*!
 * @brief This function sets a value in member magZ
 * @param _magZ New value for member magZ
 */
void DataSFusion::magZ(
        float _magZ)
{
    m_magZ = _magZ;
}

/*!
 * @brief This function returns the value of member magZ
 * @return Value of member magZ
 */
float DataSFusion::magZ() const
{
    return m_magZ;
}

/*!
 * @brief This function returns a reference to member magZ
 * @return Reference to member magZ
 */
float& DataSFusion::magZ()
{
    return m_magZ;
}

/*!
 * @brief This function sets a value in member temp
 * @param _temp New value for member temp
 */
void DataSFusion::temp(
        float _temp)
{
    m_temp = _temp;
}

/*!
 * @brief This function returns the value of member temp
 * @return Value of member temp
 */
float DataSFusion::temp() const
{
    return m_temp;
}

/*!
 * @brief This function returns a reference to member temp
 * @return Reference to member temp
 */
float& DataSFusion::temp()
{
    return m_temp;
}

/*!
 * @brief This function sets a value in member press
 * @param _press New value for member press
 */
void DataSFusion::press(
        float _press)
{
    m_press = _press;
}

/*!
 * @brief This function returns the value of member press
 * @return Value of member press
 */
float DataSFusion::press() const
{
    return m_press;
}

/*!
 * @brief This function returns a reference to member press
 * @return Reference to member press
 */
float& DataSFusion::press()
{
    return m_press;
}

/*!
 * @brief This function sets a value in member phi
 * @param _phi New value for member phi
 */
void DataSFusion::phi(
        float _phi)
{
    m_phi = _phi;
}

/*!
 * @brief This function returns the value of member phi
 * @return Value of member phi
 */
float DataSFusion::phi() const
{
    return m_phi;
}

/*!
 * @brief This function returns a reference to member phi
 * @return Reference to member phi
 */
float& DataSFusion::phi()
{
    return m_phi;
}

/*!
 * @brief This function sets a value in member the
 * @param _the New value for member the
 */
void DataSFusion::the(
        float _the)
{
    m_the = _the;
}

/*!
 * @brief This function returns the value of member the
 * @return Value of member the
 */
float DataSFusion::the() const
{
    return m_the;
}

/*!
 * @brief This function returns a reference to member the
 * @return Reference to member the
 */
float& DataSFusion::the()
{
    return m_the;
}

/*!
 * @brief This function sets a value in member psi
 * @param _psi New value for member psi
 */
void DataSFusion::psi(
        float _psi)
{
    m_psi = _psi;
}

/*!
 * @brief This function returns the value of member psi
 * @return Value of member psi
 */
float DataSFusion::psi() const
{
    return m_psi;
}

/*!
 * @brief This function returns a reference to member psi
 * @return Reference to member psi
 */
float& DataSFusion::psi()
{
    return m_psi;
}

/*!
 * @brief This function sets a value in member q0
 * @param _q0 New value for member q0
 */
void DataSFusion::q0(
        float _q0)
{
    m_q0 = _q0;
}

/*!
 * @brief This function returns the value of member q0
 * @return Value of member q0
 */
float DataSFusion::q0() const
{
    return m_q0;
}

/*!
 * @brief This function returns a reference to member q0
 * @return Reference to member q0
 */
float& DataSFusion::q0()
{
    return m_q0;
}

/*!
 * @brief This function sets a value in member q1
 * @param _q1 New value for member q1
 */
void DataSFusion::q1(
        float _q1)
{
    m_q1 = _q1;
}

/*!
 * @brief This function returns the value of member q1
 * @return Value of member q1
 */
float DataSFusion::q1() const
{
    return m_q1;
}

/*!
 * @brief This function returns a reference to member q1
 * @return Reference to member q1
 */
float& DataSFusion::q1()
{
    return m_q1;
}

/*!
 * @brief This function sets a value in member q2
 * @param _q2 New value for member q2
 */
void DataSFusion::q2(
        float _q2)
{
    m_q2 = _q2;
}

/*!
 * @brief This function returns the value of member q2
 * @return Value of member q2
 */
float DataSFusion::q2() const
{
    return m_q2;
}

/*!
 * @brief This function returns a reference to member q2
 * @return Reference to member q2
 */
float& DataSFusion::q2()
{
    return m_q2;
}

/*!
 * @brief This function sets a value in member q3
 * @param _q3 New value for member q3
 */
void DataSFusion::q3(
        float _q3)
{
    m_q3 = _q3;
}

/*!
 * @brief This function returns the value of member q3
 * @return Value of member q3
 */
float DataSFusion::q3() const
{
    return m_q3;
}

/*!
 * @brief This function returns a reference to member q3
 * @return Reference to member q3
 */
float& DataSFusion::q3()
{
    return m_q3;
}

/*!
 * @brief This function sets a value in member posN
 * @param _posN New value for member posN
 */
void DataSFusion::posN(
        float _posN)
{
    m_posN = _posN;
}

/*!
 * @brief This function returns the value of member posN
 * @return Value of member posN
 */
float DataSFusion::posN() const
{
    return m_posN;
}

/*!
 * @brief This function returns a reference to member posN
 * @return Reference to member posN
 */
float& DataSFusion::posN()
{
    return m_posN;
}

/*!
 * @brief This function sets a value in member posE
 * @param _posE New value for member posE
 */
void DataSFusion::posE(
        float _posE)
{
    m_posE = _posE;
}

/*!
 * @brief This function returns the value of member posE
 * @return Value of member posE
 */
float DataSFusion::posE() const
{
    return m_posE;
}

/*!
 * @brief This function returns a reference to member posE
 * @return Reference to member posE
 */
float& DataSFusion::posE()
{
    return m_posE;
}

/*!
 * @brief This function sets a value in member posD
 * @param _posD New value for member posD
 */
void DataSFusion::posD(
        float _posD)
{
    m_posD = _posD;
}

/*!
 * @brief This function returns the value of member posD
 * @return Value of member posD
 */
float DataSFusion::posD() const
{
    return m_posD;
}

/*!
 * @brief This function returns a reference to member posD
 * @return Reference to member posD
 */
float& DataSFusion::posD()
{
    return m_posD;
}

/*!
 * @brief This function sets a value in member speedN
 * @param _speedN New value for member speedN
 */
void DataSFusion::speedN(
        float _speedN)
{
    m_speedN = _speedN;
}

/*!
 * @brief This function returns the value of member speedN
 * @return Value of member speedN
 */
float DataSFusion::speedN() const
{
    return m_speedN;
}

/*!
 * @brief This function returns a reference to member speedN
 * @return Reference to member speedN
 */
float& DataSFusion::speedN()
{
    return m_speedN;
}

/*!
 * @brief This function sets a value in member speedE
 * @param _speedE New value for member speedE
 */
void DataSFusion::speedE(
        float _speedE)
{
    m_speedE = _speedE;
}

/*!
 * @brief This function returns the value of member speedE
 * @return Value of member speedE
 */
float DataSFusion::speedE() const
{
    return m_speedE;
}

/*!
 * @brief This function returns a reference to member speedE
 * @return Reference to member speedE
 */
float& DataSFusion::speedE()
{
    return m_speedE;
}

/*!
 * @brief This function sets a value in member speedD
 * @param _speedD New value for member speedD
 */
void DataSFusion::speedD(
        float _speedD)
{
    m_speedD = _speedD;
}

/*!
 * @brief This function returns the value of member speedD
 * @return Value of member speedD
 */
float DataSFusion::speedD() const
{
    return m_speedD;
}

/*!
 * @brief This function returns a reference to member speedD
 * @return Reference to member speedD
 */
float& DataSFusion::speedD()
{
    return m_speedD;
}

/*!
 * @brief This function sets a value in member windN
 * @param _windN New value for member windN
 */
void DataSFusion::windN(
        float _windN)
{
    m_windN = _windN;
}

/*!
 * @brief This function returns the value of member windN
 * @return Value of member windN
 */
float DataSFusion::windN() const
{
    return m_windN;
}

/*!
 * @brief This function returns a reference to member windN
 * @return Reference to member windN
 */
float& DataSFusion::windN()
{
    return m_windN;
}

/*!
 * @brief This function sets a value in member windE
 * @param _windE New value for member windE
 */
void DataSFusion::windE(
        float _windE)
{
    m_windE = _windE;
}

/*!
 * @brief This function returns the value of member windE
 * @return Value of member windE
 */
float DataSFusion::windE() const
{
    return m_windE;
}

/*!
 * @brief This function returns a reference to member windE
 * @return Reference to member windE
 */
float& DataSFusion::windE()
{
    return m_windE;
}

/*!
 * @brief This function sets a value in member windD
 * @param _windD New value for member windD
 */
void DataSFusion::windD(
        float _windD)
{
    m_windD = _windD;
}

/*!
 * @brief This function returns the value of member windD
 * @return Value of member windD
 */
float DataSFusion::windD() const
{
    return m_windD;
}

/*!
 * @brief This function returns a reference to member windD
 * @return Reference to member windD
 */
float& DataSFusion::windD()
{
    return m_windD;
}

/*!
 * @brief This function sets a value in member ssa
 * @param _ssa New value for member ssa
 */
void DataSFusion::ssa(
        float _ssa)
{
    m_ssa = _ssa;
}

/*!
 * @brief This function returns the value of member ssa
 * @return Value of member ssa
 */
float DataSFusion::ssa() const
{
    return m_ssa;
}

/*!
 * @brief This function returns a reference to member ssa
 * @return Reference to member ssa
 */
float& DataSFusion::ssa()
{
    return m_ssa;
}

/*!
 * @brief This function sets a value in member aoa
 * @param _aoa New value for member aoa
 */
void DataSFusion::aoa(
        float _aoa)
{
    m_aoa = _aoa;
}

/*!
 * @brief This function returns the value of member aoa
 * @return Value of member aoa
 */
float DataSFusion::aoa() const
{
    return m_aoa;
}

/*!
 * @brief This function returns a reference to member aoa
 * @return Reference to member aoa
 */
float& DataSFusion::aoa()
{
    return m_aoa;
}

/*!
 * @brief This function sets a value in member gamma
 * @param _gamma New value for member gamma
 */
void DataSFusion::gamma(
        float _gamma)
{
    m_gamma = _gamma;
}

/*!
 * @brief This function returns the value of member gamma
 * @return Value of member gamma
 */
float DataSFusion::gamma() const
{
    return m_gamma;
}

/*!
 * @brief This function returns a reference to member gamma
 * @return Reference to member gamma
 */
float& DataSFusion::gamma()
{
    return m_gamma;
}

/*!
 * @brief This function sets a value in member alive
 * @param _alive New value for member alive
 */
void DataSFusion::alive(
        bool _alive)
{
    m_alive = _alive;
}

/*!
 * @brief This function returns the value of member alive
 * @return Value of member alive
 */
bool DataSFusion::alive() const
{
    return m_alive;
}

/*!
 * @brief This function returns a reference to member alive
 * @return Reference to member alive
 */
bool& DataSFusion::alive()
{
    return m_alive;
}


size_t DataSFusion::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t current_align = current_alignment;



































    return current_align;
}

bool DataSFusion::isKeyDefined()
{
    return false;
}

void DataSFusion::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
                                    
}
