/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -p qibusinputcontextproxy -c IBusInputContextProxy -v org.freedesktop.IBus.InputContext.xml org.freedesktop.IBus.InputContext
 *
 * qdbusxml2cpp is Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef QIBUSINPUTCONTEXTPROXY_H_1268726783
#define QIBUSINPUTCONTEXTPROXY_H_1268726783

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.freedesktop.IBus.InputContext
 */
class IBusInputContextProxy: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freedesktop.IBus.InputContext"; }

public:
    IBusInputContextProxy(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~IBusInputContextProxy();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> Destroy()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("Destroy"), argumentList);
    }

    inline QDBusPendingReply<> Disable()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("Disable"), argumentList);
    }

    inline QDBusPendingReply<> Enable()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("Enable"), argumentList);
    }

    inline QDBusPendingReply<> FocusIn()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("FocusIn"), argumentList);
    }

    inline QDBusPendingReply<> FocusOut()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("FocusOut"), argumentList);
    }

    inline QDBusPendingReply<QDBusVariant> GetEngine()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("GetEngine"), argumentList);
    }

    inline QDBusPendingReply<bool> IsEnabled()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("IsEnabled"), argumentList);
    }

    inline QDBusPendingReply<bool> ProcessKeyEvent(uint keyval, uint keycode, uint state)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(keyval) << qVariantFromValue(keycode) << qVariantFromValue(state);
        return asyncCallWithArgumentList(QLatin1String("ProcessKeyEvent"), argumentList);
    }

    inline QDBusPendingReply<> PropertyActivate(const QString &name, int state)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(name) << qVariantFromValue(state);
        return asyncCallWithArgumentList(QLatin1String("PropertyActivate"), argumentList);
    }

    inline QDBusPendingReply<> Reset()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("Reset"), argumentList);
    }

    inline QDBusPendingReply<> SetCapabilities(uint caps)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(caps);
        return asyncCallWithArgumentList(QLatin1String("SetCapabilities"), argumentList);
    }

    inline QDBusPendingReply<> SetCursorLocation(int x, int y, int w, int h)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(x) << qVariantFromValue(y) << qVariantFromValue(w) << qVariantFromValue(h);
        return asyncCallWithArgumentList(QLatin1String("SetCursorLocation"), argumentList);
    }

    inline QDBusPendingReply<> SetEngine(const QString &name)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(name);
        return asyncCallWithArgumentList(QLatin1String("SetEngine"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void CommitText(const QDBusVariant &text);
    void CursorDownLookupTable();
    void CursorUpLookupTable();
    void DeleteSurroundingText(int offset, uint nchars);
    void Disabled();
    void Enabled();
    void ForwardKeyEvent(uint keyval, uint keycode, uint state);
    void HideAuxiliaryText();
    void HideLookupTable();
    void HidePreeditText();
    void PageDownLookupTable();
    void PageUpLookupTable();
    void RegisterProperties(const QDBusVariant &props);
    void ShowAuxiliaryText();
    void ShowLookupTable();
    void ShowPreeditText();
    void UpdateAuxiliaryText(const QDBusVariant &text, bool visible);
    void UpdateLookupTable(const QDBusVariant &table, bool visible);
    void UpdatePreeditText(const QDBusVariant &text, uint cursor_pos, bool visible);
    void UpdateProperty(const QDBusVariant &prop);
};

namespace org {
  namespace freedesktop {
    namespace IBus {
      typedef ::IBusInputContextProxy InputContext;
    }
  }
}
#endif
