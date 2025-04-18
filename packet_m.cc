//
// Generated file, do not edit! Created by opp_msgtool 6.1 from packet.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "packet_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(GlobalIn)

GlobalIn::GlobalIn(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

GlobalIn::GlobalIn(const GlobalIn& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

GlobalIn::~GlobalIn()
{
}

GlobalIn& GlobalIn::operator=(const GlobalIn& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void GlobalIn::copy(const GlobalIn& other)
{
    this->inId = other.inId;
    this->bId = other.bId;
}

void GlobalIn::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->inId);
    doParsimPacking(b,this->bId);
}

void GlobalIn::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->inId);
    doParsimUnpacking(b,this->bId);
}

int GlobalIn::getInId() const
{
    return this->inId;
}

void GlobalIn::setInId(int inId)
{
    this->inId = inId;
}

int GlobalIn::getBId() const
{
    return this->bId;
}

void GlobalIn::setBId(int bId)
{
    this->bId = bId;
}

class GlobalInDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_inId,
        FIELD_bId,
    };
  public:
    GlobalInDescriptor();
    virtual ~GlobalInDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(GlobalInDescriptor)

GlobalInDescriptor::GlobalInDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(GlobalIn)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

GlobalInDescriptor::~GlobalInDescriptor()
{
    delete[] propertyNames;
}

bool GlobalInDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<GlobalIn *>(obj)!=nullptr;
}

const char **GlobalInDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *GlobalInDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int GlobalInDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int GlobalInDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_inId
        FD_ISEDITABLE,    // FIELD_bId
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *GlobalInDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "inId",
        "bId",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int GlobalInDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "inId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "bId") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *GlobalInDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_inId
        "int",    // FIELD_bId
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **GlobalInDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *GlobalInDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int GlobalInDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    GlobalIn *pp = omnetpp::fromAnyPtr<GlobalIn>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void GlobalInDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    GlobalIn *pp = omnetpp::fromAnyPtr<GlobalIn>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'GlobalIn'", field);
    }
}

const char *GlobalInDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    GlobalIn *pp = omnetpp::fromAnyPtr<GlobalIn>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string GlobalInDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    GlobalIn *pp = omnetpp::fromAnyPtr<GlobalIn>(object); (void)pp;
    switch (field) {
        case FIELD_inId: return long2string(pp->getInId());
        case FIELD_bId: return long2string(pp->getBId());
        default: return "";
    }
}

void GlobalInDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    GlobalIn *pp = omnetpp::fromAnyPtr<GlobalIn>(object); (void)pp;
    switch (field) {
        case FIELD_inId: pp->setInId(string2long(value)); break;
        case FIELD_bId: pp->setBId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'GlobalIn'", field);
    }
}

omnetpp::cValue GlobalInDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    GlobalIn *pp = omnetpp::fromAnyPtr<GlobalIn>(object); (void)pp;
    switch (field) {
        case FIELD_inId: return pp->getInId();
        case FIELD_bId: return pp->getBId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'GlobalIn' as cValue -- field index out of range?", field);
    }
}

void GlobalInDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    GlobalIn *pp = omnetpp::fromAnyPtr<GlobalIn>(object); (void)pp;
    switch (field) {
        case FIELD_inId: pp->setInId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_bId: pp->setBId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'GlobalIn'", field);
    }
}

const char *GlobalInDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr GlobalInDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    GlobalIn *pp = omnetpp::fromAnyPtr<GlobalIn>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void GlobalInDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    GlobalIn *pp = omnetpp::fromAnyPtr<GlobalIn>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'GlobalIn'", field);
    }
}

Register_Class(DownloadIn)

DownloadIn::DownloadIn(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

DownloadIn::DownloadIn(const DownloadIn& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

DownloadIn::~DownloadIn()
{
}

DownloadIn& DownloadIn::operator=(const DownloadIn& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void DownloadIn::copy(const DownloadIn& other)
{
    this->inId = other.inId;
    this->bId = other.bId;
}

void DownloadIn::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->inId);
    doParsimPacking(b,this->bId);
}

void DownloadIn::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->inId);
    doParsimUnpacking(b,this->bId);
}

int DownloadIn::getInId() const
{
    return this->inId;
}

void DownloadIn::setInId(int inId)
{
    this->inId = inId;
}

int DownloadIn::getBId() const
{
    return this->bId;
}

void DownloadIn::setBId(int bId)
{
    this->bId = bId;
}

class DownloadInDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_inId,
        FIELD_bId,
    };
  public:
    DownloadInDescriptor();
    virtual ~DownloadInDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(DownloadInDescriptor)

DownloadInDescriptor::DownloadInDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DownloadIn)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

DownloadInDescriptor::~DownloadInDescriptor()
{
    delete[] propertyNames;
}

bool DownloadInDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DownloadIn *>(obj)!=nullptr;
}

const char **DownloadInDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DownloadInDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DownloadInDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int DownloadInDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_inId
        FD_ISEDITABLE,    // FIELD_bId
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *DownloadInDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "inId",
        "bId",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int DownloadInDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "inId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "bId") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *DownloadInDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_inId
        "int",    // FIELD_bId
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **DownloadInDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *DownloadInDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int DownloadInDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DownloadIn *pp = omnetpp::fromAnyPtr<DownloadIn>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DownloadInDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DownloadIn *pp = omnetpp::fromAnyPtr<DownloadIn>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DownloadIn'", field);
    }
}

const char *DownloadInDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DownloadIn *pp = omnetpp::fromAnyPtr<DownloadIn>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DownloadInDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DownloadIn *pp = omnetpp::fromAnyPtr<DownloadIn>(object); (void)pp;
    switch (field) {
        case FIELD_inId: return long2string(pp->getInId());
        case FIELD_bId: return long2string(pp->getBId());
        default: return "";
    }
}

void DownloadInDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DownloadIn *pp = omnetpp::fromAnyPtr<DownloadIn>(object); (void)pp;
    switch (field) {
        case FIELD_inId: pp->setInId(string2long(value)); break;
        case FIELD_bId: pp->setBId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DownloadIn'", field);
    }
}

omnetpp::cValue DownloadInDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DownloadIn *pp = omnetpp::fromAnyPtr<DownloadIn>(object); (void)pp;
    switch (field) {
        case FIELD_inId: return pp->getInId();
        case FIELD_bId: return pp->getBId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DownloadIn' as cValue -- field index out of range?", field);
    }
}

void DownloadInDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DownloadIn *pp = omnetpp::fromAnyPtr<DownloadIn>(object); (void)pp;
    switch (field) {
        case FIELD_inId: pp->setInId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_bId: pp->setBId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DownloadIn'", field);
    }
}

const char *DownloadInDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr DownloadInDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DownloadIn *pp = omnetpp::fromAnyPtr<DownloadIn>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DownloadInDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DownloadIn *pp = omnetpp::fromAnyPtr<DownloadIn>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DownloadIn'", field);
    }
}

Register_Class(UploadIn)

UploadIn::UploadIn(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

UploadIn::UploadIn(const UploadIn& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

UploadIn::~UploadIn()
{
}

UploadIn& UploadIn::operator=(const UploadIn& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void UploadIn::copy(const UploadIn& other)
{
    this->inId = other.inId;
    this->bId = other.bId;
}

void UploadIn::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->inId);
    doParsimPacking(b,this->bId);
}

void UploadIn::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->inId);
    doParsimUnpacking(b,this->bId);
}

int UploadIn::getInId() const
{
    return this->inId;
}

void UploadIn::setInId(int inId)
{
    this->inId = inId;
}

int UploadIn::getBId() const
{
    return this->bId;
}

void UploadIn::setBId(int bId)
{
    this->bId = bId;
}

class UploadInDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_inId,
        FIELD_bId,
    };
  public:
    UploadInDescriptor();
    virtual ~UploadInDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(UploadInDescriptor)

UploadInDescriptor::UploadInDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(UploadIn)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

UploadInDescriptor::~UploadInDescriptor()
{
    delete[] propertyNames;
}

bool UploadInDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UploadIn *>(obj)!=nullptr;
}

const char **UploadInDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *UploadInDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int UploadInDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int UploadInDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_inId
        FD_ISEDITABLE,    // FIELD_bId
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *UploadInDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "inId",
        "bId",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int UploadInDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "inId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "bId") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *UploadInDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_inId
        "int",    // FIELD_bId
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **UploadInDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *UploadInDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int UploadInDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    UploadIn *pp = omnetpp::fromAnyPtr<UploadIn>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void UploadInDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    UploadIn *pp = omnetpp::fromAnyPtr<UploadIn>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'UploadIn'", field);
    }
}

const char *UploadInDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    UploadIn *pp = omnetpp::fromAnyPtr<UploadIn>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UploadInDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    UploadIn *pp = omnetpp::fromAnyPtr<UploadIn>(object); (void)pp;
    switch (field) {
        case FIELD_inId: return long2string(pp->getInId());
        case FIELD_bId: return long2string(pp->getBId());
        default: return "";
    }
}

void UploadInDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UploadIn *pp = omnetpp::fromAnyPtr<UploadIn>(object); (void)pp;
    switch (field) {
        case FIELD_inId: pp->setInId(string2long(value)); break;
        case FIELD_bId: pp->setBId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UploadIn'", field);
    }
}

omnetpp::cValue UploadInDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    UploadIn *pp = omnetpp::fromAnyPtr<UploadIn>(object); (void)pp;
    switch (field) {
        case FIELD_inId: return pp->getInId();
        case FIELD_bId: return pp->getBId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'UploadIn' as cValue -- field index out of range?", field);
    }
}

void UploadInDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UploadIn *pp = omnetpp::fromAnyPtr<UploadIn>(object); (void)pp;
    switch (field) {
        case FIELD_inId: pp->setInId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_bId: pp->setBId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UploadIn'", field);
    }
}

const char *UploadInDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr UploadInDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    UploadIn *pp = omnetpp::fromAnyPtr<UploadIn>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void UploadInDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    UploadIn *pp = omnetpp::fromAnyPtr<UploadIn>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UploadIn'", field);
    }
}

Register_Class(GlobalDOut)

GlobalDOut::GlobalDOut(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

GlobalDOut::GlobalDOut(const GlobalDOut& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

GlobalDOut::~GlobalDOut()
{
}

GlobalDOut& GlobalDOut::operator=(const GlobalDOut& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void GlobalDOut::copy(const GlobalDOut& other)
{
    this->inId = other.inId;
    this->bId = other.bId;
}

void GlobalDOut::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->inId);
    doParsimPacking(b,this->bId);
}

void GlobalDOut::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->inId);
    doParsimUnpacking(b,this->bId);
}

int GlobalDOut::getInId() const
{
    return this->inId;
}

void GlobalDOut::setInId(int inId)
{
    this->inId = inId;
}

int GlobalDOut::getBId() const
{
    return this->bId;
}

void GlobalDOut::setBId(int bId)
{
    this->bId = bId;
}

class GlobalDOutDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_inId,
        FIELD_bId,
    };
  public:
    GlobalDOutDescriptor();
    virtual ~GlobalDOutDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(GlobalDOutDescriptor)

GlobalDOutDescriptor::GlobalDOutDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(GlobalDOut)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

GlobalDOutDescriptor::~GlobalDOutDescriptor()
{
    delete[] propertyNames;
}

bool GlobalDOutDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<GlobalDOut *>(obj)!=nullptr;
}

const char **GlobalDOutDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *GlobalDOutDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int GlobalDOutDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int GlobalDOutDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_inId
        FD_ISEDITABLE,    // FIELD_bId
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *GlobalDOutDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "inId",
        "bId",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int GlobalDOutDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "inId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "bId") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *GlobalDOutDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_inId
        "int",    // FIELD_bId
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **GlobalDOutDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *GlobalDOutDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int GlobalDOutDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    GlobalDOut *pp = omnetpp::fromAnyPtr<GlobalDOut>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void GlobalDOutDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    GlobalDOut *pp = omnetpp::fromAnyPtr<GlobalDOut>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'GlobalDOut'", field);
    }
}

const char *GlobalDOutDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    GlobalDOut *pp = omnetpp::fromAnyPtr<GlobalDOut>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string GlobalDOutDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    GlobalDOut *pp = omnetpp::fromAnyPtr<GlobalDOut>(object); (void)pp;
    switch (field) {
        case FIELD_inId: return long2string(pp->getInId());
        case FIELD_bId: return long2string(pp->getBId());
        default: return "";
    }
}

void GlobalDOutDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    GlobalDOut *pp = omnetpp::fromAnyPtr<GlobalDOut>(object); (void)pp;
    switch (field) {
        case FIELD_inId: pp->setInId(string2long(value)); break;
        case FIELD_bId: pp->setBId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'GlobalDOut'", field);
    }
}

omnetpp::cValue GlobalDOutDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    GlobalDOut *pp = omnetpp::fromAnyPtr<GlobalDOut>(object); (void)pp;
    switch (field) {
        case FIELD_inId: return pp->getInId();
        case FIELD_bId: return pp->getBId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'GlobalDOut' as cValue -- field index out of range?", field);
    }
}

void GlobalDOutDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    GlobalDOut *pp = omnetpp::fromAnyPtr<GlobalDOut>(object); (void)pp;
    switch (field) {
        case FIELD_inId: pp->setInId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_bId: pp->setBId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'GlobalDOut'", field);
    }
}

const char *GlobalDOutDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr GlobalDOutDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    GlobalDOut *pp = omnetpp::fromAnyPtr<GlobalDOut>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void GlobalDOutDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    GlobalDOut *pp = omnetpp::fromAnyPtr<GlobalDOut>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'GlobalDOut'", field);
    }
}

Register_Class(DownloadDOut)

DownloadDOut::DownloadDOut(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

DownloadDOut::DownloadDOut(const DownloadDOut& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

DownloadDOut::~DownloadDOut()
{
}

DownloadDOut& DownloadDOut::operator=(const DownloadDOut& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void DownloadDOut::copy(const DownloadDOut& other)
{
    this->inId = other.inId;
    this->bId = other.bId;
}

void DownloadDOut::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->inId);
    doParsimPacking(b,this->bId);
}

void DownloadDOut::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->inId);
    doParsimUnpacking(b,this->bId);
}

int DownloadDOut::getInId() const
{
    return this->inId;
}

void DownloadDOut::setInId(int inId)
{
    this->inId = inId;
}

int DownloadDOut::getBId() const
{
    return this->bId;
}

void DownloadDOut::setBId(int bId)
{
    this->bId = bId;
}

class DownloadDOutDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_inId,
        FIELD_bId,
    };
  public:
    DownloadDOutDescriptor();
    virtual ~DownloadDOutDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(DownloadDOutDescriptor)

DownloadDOutDescriptor::DownloadDOutDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DownloadDOut)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

DownloadDOutDescriptor::~DownloadDOutDescriptor()
{
    delete[] propertyNames;
}

bool DownloadDOutDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DownloadDOut *>(obj)!=nullptr;
}

const char **DownloadDOutDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DownloadDOutDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DownloadDOutDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int DownloadDOutDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_inId
        FD_ISEDITABLE,    // FIELD_bId
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *DownloadDOutDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "inId",
        "bId",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int DownloadDOutDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "inId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "bId") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *DownloadDOutDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_inId
        "int",    // FIELD_bId
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **DownloadDOutDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *DownloadDOutDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int DownloadDOutDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DownloadDOut *pp = omnetpp::fromAnyPtr<DownloadDOut>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DownloadDOutDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DownloadDOut *pp = omnetpp::fromAnyPtr<DownloadDOut>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DownloadDOut'", field);
    }
}

const char *DownloadDOutDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DownloadDOut *pp = omnetpp::fromAnyPtr<DownloadDOut>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DownloadDOutDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DownloadDOut *pp = omnetpp::fromAnyPtr<DownloadDOut>(object); (void)pp;
    switch (field) {
        case FIELD_inId: return long2string(pp->getInId());
        case FIELD_bId: return long2string(pp->getBId());
        default: return "";
    }
}

void DownloadDOutDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DownloadDOut *pp = omnetpp::fromAnyPtr<DownloadDOut>(object); (void)pp;
    switch (field) {
        case FIELD_inId: pp->setInId(string2long(value)); break;
        case FIELD_bId: pp->setBId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DownloadDOut'", field);
    }
}

omnetpp::cValue DownloadDOutDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DownloadDOut *pp = omnetpp::fromAnyPtr<DownloadDOut>(object); (void)pp;
    switch (field) {
        case FIELD_inId: return pp->getInId();
        case FIELD_bId: return pp->getBId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DownloadDOut' as cValue -- field index out of range?", field);
    }
}

void DownloadDOutDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DownloadDOut *pp = omnetpp::fromAnyPtr<DownloadDOut>(object); (void)pp;
    switch (field) {
        case FIELD_inId: pp->setInId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_bId: pp->setBId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DownloadDOut'", field);
    }
}

const char *DownloadDOutDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr DownloadDOutDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DownloadDOut *pp = omnetpp::fromAnyPtr<DownloadDOut>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DownloadDOutDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DownloadDOut *pp = omnetpp::fromAnyPtr<DownloadDOut>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DownloadDOut'", field);
    }
}

Register_Class(UploadDOut)

UploadDOut::UploadDOut(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

UploadDOut::UploadDOut(const UploadDOut& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

UploadDOut::~UploadDOut()
{
}

UploadDOut& UploadDOut::operator=(const UploadDOut& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void UploadDOut::copy(const UploadDOut& other)
{
    this->inId = other.inId;
    this->bId = other.bId;
}

void UploadDOut::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->inId);
    doParsimPacking(b,this->bId);
}

void UploadDOut::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->inId);
    doParsimUnpacking(b,this->bId);
}

int UploadDOut::getInId() const
{
    return this->inId;
}

void UploadDOut::setInId(int inId)
{
    this->inId = inId;
}

int UploadDOut::getBId() const
{
    return this->bId;
}

void UploadDOut::setBId(int bId)
{
    this->bId = bId;
}

class UploadDOutDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_inId,
        FIELD_bId,
    };
  public:
    UploadDOutDescriptor();
    virtual ~UploadDOutDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(UploadDOutDescriptor)

UploadDOutDescriptor::UploadDOutDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(UploadDOut)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

UploadDOutDescriptor::~UploadDOutDescriptor()
{
    delete[] propertyNames;
}

bool UploadDOutDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UploadDOut *>(obj)!=nullptr;
}

const char **UploadDOutDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *UploadDOutDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int UploadDOutDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int UploadDOutDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_inId
        FD_ISEDITABLE,    // FIELD_bId
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *UploadDOutDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "inId",
        "bId",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int UploadDOutDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "inId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "bId") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *UploadDOutDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_inId
        "int",    // FIELD_bId
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **UploadDOutDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *UploadDOutDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int UploadDOutDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    UploadDOut *pp = omnetpp::fromAnyPtr<UploadDOut>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void UploadDOutDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    UploadDOut *pp = omnetpp::fromAnyPtr<UploadDOut>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'UploadDOut'", field);
    }
}

const char *UploadDOutDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    UploadDOut *pp = omnetpp::fromAnyPtr<UploadDOut>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UploadDOutDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    UploadDOut *pp = omnetpp::fromAnyPtr<UploadDOut>(object); (void)pp;
    switch (field) {
        case FIELD_inId: return long2string(pp->getInId());
        case FIELD_bId: return long2string(pp->getBId());
        default: return "";
    }
}

void UploadDOutDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UploadDOut *pp = omnetpp::fromAnyPtr<UploadDOut>(object); (void)pp;
    switch (field) {
        case FIELD_inId: pp->setInId(string2long(value)); break;
        case FIELD_bId: pp->setBId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UploadDOut'", field);
    }
}

omnetpp::cValue UploadDOutDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    UploadDOut *pp = omnetpp::fromAnyPtr<UploadDOut>(object); (void)pp;
    switch (field) {
        case FIELD_inId: return pp->getInId();
        case FIELD_bId: return pp->getBId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'UploadDOut' as cValue -- field index out of range?", field);
    }
}

void UploadDOutDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UploadDOut *pp = omnetpp::fromAnyPtr<UploadDOut>(object); (void)pp;
    switch (field) {
        case FIELD_inId: pp->setInId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_bId: pp->setBId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UploadDOut'", field);
    }
}

const char *UploadDOutDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr UploadDOutDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    UploadDOut *pp = omnetpp::fromAnyPtr<UploadDOut>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void UploadDOutDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    UploadDOut *pp = omnetpp::fromAnyPtr<UploadDOut>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UploadDOut'", field);
    }
}

Register_Class(DownloadReduce)

DownloadReduce::DownloadReduce(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

DownloadReduce::DownloadReduce(const DownloadReduce& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

DownloadReduce::~DownloadReduce()
{
}

DownloadReduce& DownloadReduce::operator=(const DownloadReduce& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void DownloadReduce::copy(const DownloadReduce& other)
{
    this->bId = other.bId;
}

void DownloadReduce::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->bId);
}

void DownloadReduce::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->bId);
}

int DownloadReduce::getBId() const
{
    return this->bId;
}

void DownloadReduce::setBId(int bId)
{
    this->bId = bId;
}

class DownloadReduceDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_bId,
    };
  public:
    DownloadReduceDescriptor();
    virtual ~DownloadReduceDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(DownloadReduceDescriptor)

DownloadReduceDescriptor::DownloadReduceDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DownloadReduce)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

DownloadReduceDescriptor::~DownloadReduceDescriptor()
{
    delete[] propertyNames;
}

bool DownloadReduceDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DownloadReduce *>(obj)!=nullptr;
}

const char **DownloadReduceDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DownloadReduceDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DownloadReduceDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int DownloadReduceDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_bId
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *DownloadReduceDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "bId",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int DownloadReduceDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "bId") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *DownloadReduceDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_bId
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **DownloadReduceDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *DownloadReduceDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int DownloadReduceDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DownloadReduce *pp = omnetpp::fromAnyPtr<DownloadReduce>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DownloadReduceDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DownloadReduce *pp = omnetpp::fromAnyPtr<DownloadReduce>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DownloadReduce'", field);
    }
}

const char *DownloadReduceDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DownloadReduce *pp = omnetpp::fromAnyPtr<DownloadReduce>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DownloadReduceDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DownloadReduce *pp = omnetpp::fromAnyPtr<DownloadReduce>(object); (void)pp;
    switch (field) {
        case FIELD_bId: return long2string(pp->getBId());
        default: return "";
    }
}

void DownloadReduceDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DownloadReduce *pp = omnetpp::fromAnyPtr<DownloadReduce>(object); (void)pp;
    switch (field) {
        case FIELD_bId: pp->setBId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DownloadReduce'", field);
    }
}

omnetpp::cValue DownloadReduceDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DownloadReduce *pp = omnetpp::fromAnyPtr<DownloadReduce>(object); (void)pp;
    switch (field) {
        case FIELD_bId: return pp->getBId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DownloadReduce' as cValue -- field index out of range?", field);
    }
}

void DownloadReduceDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DownloadReduce *pp = omnetpp::fromAnyPtr<DownloadReduce>(object); (void)pp;
    switch (field) {
        case FIELD_bId: pp->setBId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DownloadReduce'", field);
    }
}

const char *DownloadReduceDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr DownloadReduceDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DownloadReduce *pp = omnetpp::fromAnyPtr<DownloadReduce>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DownloadReduceDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DownloadReduce *pp = omnetpp::fromAnyPtr<DownloadReduce>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DownloadReduce'", field);
    }
}

Register_Class(UploadReduce)

UploadReduce::UploadReduce(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

UploadReduce::UploadReduce(const UploadReduce& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

UploadReduce::~UploadReduce()
{
}

UploadReduce& UploadReduce::operator=(const UploadReduce& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void UploadReduce::copy(const UploadReduce& other)
{
    this->bId = other.bId;
}

void UploadReduce::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->bId);
}

void UploadReduce::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->bId);
}

int UploadReduce::getBId() const
{
    return this->bId;
}

void UploadReduce::setBId(int bId)
{
    this->bId = bId;
}

class UploadReduceDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_bId,
    };
  public:
    UploadReduceDescriptor();
    virtual ~UploadReduceDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(UploadReduceDescriptor)

UploadReduceDescriptor::UploadReduceDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(UploadReduce)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

UploadReduceDescriptor::~UploadReduceDescriptor()
{
    delete[] propertyNames;
}

bool UploadReduceDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UploadReduce *>(obj)!=nullptr;
}

const char **UploadReduceDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *UploadReduceDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int UploadReduceDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int UploadReduceDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_bId
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *UploadReduceDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "bId",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int UploadReduceDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "bId") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *UploadReduceDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_bId
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **UploadReduceDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *UploadReduceDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int UploadReduceDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    UploadReduce *pp = omnetpp::fromAnyPtr<UploadReduce>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void UploadReduceDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    UploadReduce *pp = omnetpp::fromAnyPtr<UploadReduce>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'UploadReduce'", field);
    }
}

const char *UploadReduceDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    UploadReduce *pp = omnetpp::fromAnyPtr<UploadReduce>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UploadReduceDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    UploadReduce *pp = omnetpp::fromAnyPtr<UploadReduce>(object); (void)pp;
    switch (field) {
        case FIELD_bId: return long2string(pp->getBId());
        default: return "";
    }
}

void UploadReduceDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UploadReduce *pp = omnetpp::fromAnyPtr<UploadReduce>(object); (void)pp;
    switch (field) {
        case FIELD_bId: pp->setBId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UploadReduce'", field);
    }
}

omnetpp::cValue UploadReduceDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    UploadReduce *pp = omnetpp::fromAnyPtr<UploadReduce>(object); (void)pp;
    switch (field) {
        case FIELD_bId: return pp->getBId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'UploadReduce' as cValue -- field index out of range?", field);
    }
}

void UploadReduceDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UploadReduce *pp = omnetpp::fromAnyPtr<UploadReduce>(object); (void)pp;
    switch (field) {
        case FIELD_bId: pp->setBId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UploadReduce'", field);
    }
}

const char *UploadReduceDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr UploadReduceDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    UploadReduce *pp = omnetpp::fromAnyPtr<UploadReduce>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void UploadReduceDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    UploadReduce *pp = omnetpp::fromAnyPtr<UploadReduce>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UploadReduce'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

