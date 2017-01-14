#ifndef ILUGAPICONTROLLER_H
#define ILUGAPICONTROLLER_H

#include <QObject>
#include <QDate>
#include "src/model/duedaymodel.h"
#include "src/model/personmodel.h"
#include "src/model/attendantmodel.h"
#include "src/database/mydatabase.h"
#include "src/model/person.h"

class ILugApiController : public QObject
{
    Q_OBJECT
    MyDatabase m_db;
    AttendantModel m_attendantModel;
    PersonModel m_personModel;
    DueDayModel m_dueDayModel;
    QDate curentDate;
    QString curentDate_Str;
public:
    explicit ILugApiController(QObject *parent = 0);
    Person findCode(QString code);

signals:

public slots:
};

#endif // ILUGAPICONTROLLER_H
