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
 * @file BasicPubSubTypes.h
 * This header file contains the declaration of the serialization functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#ifndef _BASIC_PUBSUBTYPES_H_
#define _BASIC_PUBSUBTYPES_H_

#include <fastrtps/config.h>
#include <fastrtps/TopicDataType.h>

#include "Basic.h"

#if !defined(GEN_API_VER) || (GEN_API_VER != 1)
#error Generated Basic is not compatible with current installed Fast-RTPS. Please, regenerate it with fastrtpsgen.
#endif


typedef MyEnum MyAliasEnum;
typedef MyAliasEnum MyAliasAliasEnum;
/*!
 * @brief This class represents the TopicDataType of the type EnumStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class EnumStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef EnumStruct type;

EnumStructPubSubType();

virtual ~EnumStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type AliasStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class AliasStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef AliasStruct type;

AliasStructPubSubType();

virtual ~AliasStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type AliasAliasStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class AliasAliasStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef AliasAliasStruct type;

AliasAliasStructPubSubType();

virtual ~AliasAliasStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type BoolStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class BoolStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef BoolStruct type;

BoolStructPubSubType();

virtual ~BoolStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type OctetStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class OctetStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef OctetStruct type;

OctetStructPubSubType();

virtual ~OctetStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type ShortStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class ShortStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef ShortStruct type;

ShortStructPubSubType();

virtual ~ShortStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type LongStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class LongStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef LongStruct type;

LongStructPubSubType();

virtual ~LongStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type LongLongStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class LongLongStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef LongLongStruct type;

LongLongStructPubSubType();

virtual ~LongLongStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type UShortStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class UShortStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef UShortStruct type;

UShortStructPubSubType();

virtual ~UShortStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type ULongStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class ULongStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef ULongStruct type;

ULongStructPubSubType();

virtual ~ULongStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type ULongLongStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class ULongLongStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef ULongLongStruct type;

ULongLongStructPubSubType();

virtual ~ULongLongStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type FloatStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class FloatStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef FloatStruct type;

FloatStructPubSubType();

virtual ~FloatStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type DoubleStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class DoubleStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef DoubleStruct type;

DoubleStructPubSubType();

virtual ~DoubleStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type LongDoubleStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class LongDoubleStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef LongDoubleStruct type;

LongDoubleStructPubSubType();

virtual ~LongDoubleStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type CharStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class CharStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef CharStruct type;

CharStructPubSubType();

virtual ~CharStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type WCharStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class WCharStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef WCharStruct type;

WCharStructPubSubType();

virtual ~WCharStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type StringStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class StringStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef StringStruct type;

StringStructPubSubType();

virtual ~StringStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type WStringStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class WStringStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef WStringStruct type;

WStringStructPubSubType();

virtual ~WStringStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type LargeStringStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class LargeStringStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef LargeStringStruct type;

LargeStringStructPubSubType();

virtual ~LargeStringStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type LargeWStringStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class LargeWStringStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef LargeWStringStruct type;

LargeWStringStructPubSubType();

virtual ~LargeWStringStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type ArraytStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class ArraytStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef ArraytStruct type;

ArraytStructPubSubType();

virtual ~ArraytStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
typedef std::array<std::array<int32_t, 2>, 2> MyArray;
/*!
 * @brief This class represents the TopicDataType of the type ArrayArrayStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class ArrayArrayStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef ArrayArrayStruct type;

ArrayArrayStructPubSubType();

virtual ~ArrayArrayStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type SequenceStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class SequenceStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef SequenceStruct type;

SequenceStructPubSubType();

virtual ~SequenceStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type SequenceSequenceStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class SequenceSequenceStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef SequenceSequenceStruct type;

SequenceSequenceStructPubSubType();

virtual ~SequenceSequenceStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type MapStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class MapStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef MapStruct type;

MapStructPubSubType();

virtual ~MapStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type MapMapStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class MapMapStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef MapMapStruct type;

MapMapStructPubSubType();

virtual ~MapMapStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};

/*!
 * @brief This class represents the TopicDataType of the type BitsetStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class BitsetStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef BitsetStruct type;

BitsetStructPubSubType();

virtual ~BitsetStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type StructStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class StructStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef StructStruct type;

StructStructPubSubType();

virtual ~StructStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type StructStructStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class StructStructStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef StructStructStruct type;

StructStructStructPubSubType();

virtual ~StructStructStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};



/*!
 * @brief This class represents the TopicDataType of the type SimpleUnionStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class SimpleUnionStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef SimpleUnionStruct type;

SimpleUnionStructPubSubType();

virtual ~SimpleUnionStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type UnionUnionUnionStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class UnionUnionUnionStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef UnionUnionUnionStruct type;

UnionUnionUnionStructPubSubType();

virtual ~UnionUnionUnionStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*!
 * @brief This class represents the TopicDataType of the type WCharUnionStruct defined by the user in the IDL file.
 * @ingroup BASIC
 */
class WCharUnionStructPubSubType : public eprosima::fastrtps::TopicDataType {
public:
    typedef WCharUnionStruct type;

WCharUnionStructPubSubType();

virtual ~WCharUnionStructPubSubType();
virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
        bool force_md5 = false) override;
virtual void* createData() override;
virtual void deleteData(void * data) override;
    MD5 m_md5;
    unsigned char* m_keyBuffer;
};

#endif // _BASIC_PUBSUBTYPES_H_