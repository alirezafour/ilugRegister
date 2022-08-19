#ifndef DUEDAYMODEL_H
#define DUEDAYMODEL_H

#include <QObject>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QString>
#include <QDebug>
#include <QDate>

class DueDayModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit DueDayModel(QObject *parent = 0);
    ~DueDayModel();
    void setHeaders();
    int findDueDay(const QString &day) const;
    int addNewDay(const QString &day = QDate::currentDate().toString(Qt::ISODate), const QString &dayNumber = "0", const QString &persianDay = "");
    bool deleteDueDay(const QString &day, const QString &dayNumber = "0", const QString &persianDay = "");
//    int updateDueDay(const QString &oldDay, const QString &newDay);
//    int dateID(const QString &day) const;
};

#endif // DUEDAYMODEL_H
