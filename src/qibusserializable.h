#ifndef __Q_IBUS_SERIALIZABLE_H_
#define __Q_IBUS_SERIALIZABLE_H_

#include "qibusobject.h"
#include <QDBusArgument>
#include <QHash>
#include <QMap>

#define INIT_PRIO_HIGH __attribute__((init_priority(1000)))
// #define INIT_PRIO_LOW  __attribute__((init_priority(2000)))
#define INIT_PRIO_LOW

#define IBUS_SERIALIZABLE                               \
public:                                                 \
    static Serializable *newInstance (void);            \
    static MetaTypeInfo _info;                          \
    virtual const MetaTypeInfo *getMetaInfo (void) const;

#define IBUS_DECLARE_SERIALIZABLE(classname, name)      \
    Serializable *                                      \
    classname::newInstance (void)                       \
    {                                                   \
        return (Serializable *) new classname ();       \
    }                                                   \
    const Serializable::MetaTypeInfo *                  \
    classname::getMetaInfo (void) const                 \
    {                                                   \
        return & (classname::_info);                    \
    }                                                   \
    Serializable::MetaTypeInfo                          \
    classname::_info INIT_PRIO_LOW (QString(#name), classname::newInstance);

namespace IBus {

class Serializable;
/*
class SerializablePointer : public Pointer <Serializable>
{
};
*/

typedef Pointer<Serializable> SerializablePointer;

QDBusArgument& operator<< (QDBusArgument& argument, const SerializablePointer &p);
const QDBusArgument& operator>> (const QDBusArgument& argument, SerializablePointer &p);
QDBusVariant qDBusVariantFromSerializable (const SerializablePointer &p);
SerializablePointer qDBusVariantToSerializable (const QDBusVariant &variant);

class Serializable : public Object
{
    Q_OBJECT;

    friend QDBusArgument& operator<< (QDBusArgument& argument, const SerializablePointer &p);
    friend const QDBusArgument& operator>> (const QDBusArgument& argument, SerializablePointer &p);

    typedef Serializable * (NewInstanceFunc) (void);

protected:
    class MetaTypeInfo
    {
    public:
        MetaTypeInfo(const QString &name, NewInstanceFunc _new) : m_className (name) {
            Serializable::registerObject (m_className, _new);
        }
        ~MetaTypeInfo (void) {
           Serializable::unregisterObject (m_className);
        }
        const QString &getName (void) const {
            return m_className;
        }
    private:
        QString m_className;
    };

public:
    Serializable () {}
    void setAttachment (const QString &key, const SerializablePointer &value);
    SerializablePointer getAttachment (const QString &key) const;
    SerializablePointer removeAttachment (const QString &key);

protected:
    virtual bool serialize (QDBusArgument &argument) const;
    virtual bool deserialize (const QDBusArgument &argument);

private:
   QMap <QString, SerializablePointer> m_attachments;

/* static */
protected:
    static void registerObject (const QString &name, NewInstanceFunc _new);
    static void unregisterObject (const QString &name);

private:
    static SerializablePointer createInstance (const QString &name);
    static QHash<QString, NewInstanceFunc *> type_table;

    IBUS_SERIALIZABLE
};

};

Q_DECLARE_METATYPE (IBus::SerializablePointer);

#endif
