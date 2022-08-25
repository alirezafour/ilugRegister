#ifndef ATTENDANTMODEL_H
#define ATTENDANTMODEL_H

#include <QObject>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QString>
#include <QDebug>
#include <QDate>

class AttendantModel : public QSqlTableModel
{
    Q_OBJECT
public:
    explicit AttendantModel(QObject *parent = 0);
    ~AttendantModel();
    void setHeaders();
    int findAttendant(int id);
    int findAttendant(int personId, int dueDayId);
    bool addAttendant(int personId, int dueDayId);
    bool deleteAttendant(int personId, int dueDayId);
    /* delete every record of the person */
    bool deleteAttendant(int personId);

};

#endif // ATTENDANTMODEL_H
