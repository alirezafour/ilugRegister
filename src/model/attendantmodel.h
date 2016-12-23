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
    bool deleteAttendant(QSqlTableModel *model, QString personCode);
    //bool updateAttendant(QSqlTableModel *model, QString personId);
    bool findAttendant(QSqlTableModel *model, int personId, int dueDayId);
    bool findAttendant(QSqlTableModel *model, QString personCode, QString date);

signals:

public slots:

private:
    QString createFilters(int personId, int dueDayId);

private:
    PersonModel personModel;
    DueDayModel dateModel;

};

#endif // ATTENDANTMODEL_H
