#ifndef DUEDAYMODEL_H
#define DUEDAYMODEL_H

#include <QObject>
#include <QSqlTableModel>
#include <QSqlError>
#include <QDate>

class DueDayModel : public QObject
{
    Q_OBJECT
public:
    explicit DueDayModel(QObject *parent = 0);
    bool setModel(QSqlTableModel *model);
    bool setDate(QSqlTableModel *model, QString &date);
    QString Date() const;
    bool findDate(QSqlTableModel *model, QString date);

signals:

public slots:

private:
    QString createFilter(QString &date);
    QDate *m_date;
};

#endif // DUEDAYMODEL_H
