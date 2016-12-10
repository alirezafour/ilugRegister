#ifndef ATTENDANTMODEL_H
#define ATTENDANTMODEL_H

#include <QObject>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>


class AttendantModel : public QObject
{
    Q_OBJECT
public:
    explicit AttendantModel(QObject *parent = 0);
    bool setModel(QSqlQuery *model);
    bool addAttendant(QSqlQuery *model, QString personId, QString dateId);
    bool deleteAttendant(QSqlQuery *model, QString personId);
    bool updateAttendant(QSqlQuery *model, QString personId);
    bool findAttendant(QSqlQuery *model, QString personId = "", QString dateId = "");

signals:

public slots:
};

#endif // ATTENDANTMODEL_H
