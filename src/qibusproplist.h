#ifndef __Q_IBUS_PROP_LIST_H_
#define __Q_IBUS_PROP_LIST_H_

#include "qibusserializable.h"
#include "qibusproperty.h"
#include "qibustext.h"

namespace IBus {

class Property;
class PropList;
typedef Pointer<PropList> PropListPointer;
typedef Pointer<Property> PropPointer;

class PropList: public Serializable
{
    Q_OBJECT;

public:
    PropList ()
    {}
    PropList (const QVector<PropPointer> & props): m_props(props)
    {}

    ~PropList ()
    {}

public:
    virtual bool serialize (QDBusArgument &argument) const;
    virtual bool deserialize (const QDBusArgument &argument);

    bool updateProperty (const Property & prop);

private:
    QVector<PropPointer> m_props;

    IBUS_SERIALIZABLE
};

};

#endif
