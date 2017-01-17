#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString code READ code WRITE setCode NOTIFY codeChanged)
    Q_PROPERTY(QString firstName READ firstName WRITE setFirstName NOTIFY firstNameChanged)
    Q_PROPERTY(QString lastName READ lastName WRITE setLastName NOTIFY lastNameChanged)
    Q_PROPERTY(int sessionCounter READ sessionCounter WRITE setSessionCounter NOTIFY sessionCounterChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(QString registerDay READ registerDay WRITE setRegisterDay NOTIFY registerDayChanged)

    int m_id;
    QString m_code;
    QString m_firstName;
    QString m_lastName;
    int m_sessionCounter;
    QString m_email;
    QString m_registerDay;

public:
    explicit Person(QObject *parent = 0);
    ~Person();
    explicit Person(const Person &person, QObject *parent = 0);
    Person(Person &&person);
    Person &operator =(const Person &person);
    Person &operator =(Person &&person);

    int id() const;
    QString code() const;
    QString firstName() const;
    QString lastName() const;
    int sessionCounter() const;
    QString email() const;
    QString registerDay() const;

signals:

    void idChanged(int id);
    void codeChanged(QString code);
    void firstNameChanged(QString firstName);
    void lastNameChanged(QString lastName);
    void sessionCounterChanged(int sessionCounter);
    void emailChanged(QString email);
    void registerDayChanged(QString registerDay);

public slots:
    void setId(int id);
    void setCode(QString code);
    void setFirstName(QString firstName);
    void setLastName(QString lastName);
    void setSessionCounter(int sessionCounter);
    void setEmail(QString email);
    void setRegisterDay(QString registerDay);

private:
    void setPerson(const Person &person);
};

#endif // PERSON_H
