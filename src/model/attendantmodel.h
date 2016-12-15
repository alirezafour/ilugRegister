#ifndef ATTENDANTMODEL_H
#define ATTENDANTMODEL_H

#include <QObject>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include "personmodel.h"
#include "duedaymodel.h"


class AttendantModel : public QObject
{
    Q_OBJECT
public:
    explicit AttendantModel(QObject *parent = 0);
    bool setModel(QSqlTableModel *model);
    bool addAttendant(QSqlTableModel *model, QString personCode, QString date);
    bool deleteAttendant(QSqlTableModel *model, QString personId);
    bool updateAttendant(QSqlTableModel *model, QString personId);
    bool findAttendant(QSqlTableModel *model, QString personId = "", QString dateId = "");

signals:

public slots:

private:
    PersonModel personModel;
    DueDayModel dateModel;

};

#endif // ATTENDANTMODEL_H
