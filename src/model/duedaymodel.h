#ifndef DUEDAYMODEL_H
#define DUEDAYMODEL_H

#include <QObject>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QDate>

class DueDayModel : public QObject
{
    Q_OBJECT
public:
    explicit DueDayModel(QObject *parent = 0);
    bool setModel(QSqlTableModel *model);
    void setDate(QString &date);
    QString Date() const;
    bool findDate(QSqlTableModel *model, QString date);
    bool addNewDay(QSqlTableModel *model, QString day = QDate::currentDate().toString(Qt::ISODate));
    int dateID(QString &date);
    QString date() const;

signals:

public slots:

private:
    QString createFilter(QString &date);
    QString m_date;
};

#endif // DUEDAYMODEL_H
