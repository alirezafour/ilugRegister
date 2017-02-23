#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString code READ getCode WRITE setCode NOTIFY codeChanged)
    Q_PROPERTY(QString firstName READ getFirstName WRITE setFirstName NOTIFY firstNameChanged)
    Q_PROPERTY(QString lastName READ getLastName WRITE setLastName NOTIFY lastNameChanged)
    Q_PROPERTY(int sessionCounter READ getSessionCounter WRITE setSessionCounter NOTIFY sessionCounterChanged)
    Q_PROPERTY(QString email READ getEmail WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(QString registerDay READ getRegisterDay WRITE setRegisterDay NOTIFY registerDayChanged)

    int m_id;
    QString m_code;
    QString m_firstName;
    QString m_lastName;
    int m_sessionCounter;
    QString m_email;
    QString m_registerDay;

public:
    explicit Person(QObject *parent = 0);
    virtual ~Person();
    Person(const Person &person, QObject *parent = 0);
    Person(Person &&person);
    Person &operator =(const Person &person);
    Person &operator =(Person &&person);

    //Getter Methods
    virtual int getId() const;
    virtual QString getCode() const;
    virtual QString getFirstName() const;
    virtual QString getLastName() const;
    virtual int getSessionCounter() const;
    virtual QString getEmail() const;
    virtual QString getRegisterDay() const;

signals:
    //Setter Signals
    void idChanged(int id);
    void codeChanged(QString code);
    void firstNameChanged(QString firstName);
    void lastNameChanged(QString lastName);
    void sessionCounterChanged(int sessionCounter);
    void emailChanged(QString email);
    void registerDayChanged(QString registerDay);

public slots:
    //Setter Methods
    virtual void setId(const int &id);
    virtual void setCode(const QString &code);
    virtual void setFirstName(const QString &firstName);
    virtual void setLastName(const QString &lastName);
    virtual void setSessionCounter(const int &sessionCounter);
    virtual void setEmail(const QString &email);
    virtual void setRegisterDay(const QString &registerDay);

private:
    void setPerson(const Person &person);
};

#endif // PERSON_H
