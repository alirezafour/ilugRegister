#ifndef ATTENDANTMODEL_H
#define ATTENDANTMODEL_H

#include <QObject>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include "personmodel.h"
#include "duedaymodel.h"


class AttendantModel : public QSqlTableModel
{
    Q_OBJECT
public:
    explicit AttendantModel(QObject *parent = 0);
    ~AttendantModel();
    void setHeaders();
    int findAttendant(const QString &id);
    int findAttendant(const QString &personId, const QString &dueDayId);
    int addAttendant(const QString &personId, const QString &dueDayId);
    bool deleteAttendant(const QString &personId, const QString &dueDayId);

};

#endif // ATTENDANTMODEL_H
