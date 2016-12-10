#include "attendantmodel.h"


AttendantModel::AttendantModel(QObject *parent) : QObject(parent)
{

}

bool AttendantModel::setModel(QSqlQuery *model)
{
//Qt TODO :
//    model->exec("select firstName, lastName, date.dueDay"
//                "from person, dueDay, attendant"
//                "inner join ...");


    return true;
}

bool AttendantModel::addAttendant(QSqlQuery *model, QString personId, QString dateId)
{

}

