#include "person.h"

Person::Person(QObject *parent) : QObject(parent)
{

}

Person::~Person()
{

}

Person::Person(const Person &person, QObject *parent) : QObject(parent)
{
    this->setPerson(person);
}

Person::Person(Person &&person)
{
    this->setPerson(person);
    person.m_id = 0;
    person.m_code.clear();
    person.m_firstName.clear();
    person.m_lastName.clear();
    person.m_sessionCounter = 0;
    person.m_email.clear();
}

Person &Person::operator =(const Person &person)
{
    this->setPerson(person);
    return *this;
}

Person &Person::operator =(Person &&person)
{
    this->setPerson(person);
    person.m_id = 0;
    person.m_code.clear();
    person.m_firstName.clear();
    person.m_lastName.clear();
    person.m_sessionCounter = 0;
    person.m_email.clear();
    return *this;
}

int Person::getId() const
{
    return m_id;
}

QString Person::getCode() const
{
    return m_code;
}

QString Person::getFirstName() const
{
    return m_firstName;
}

QString Person::getLastName() const
{
    return m_lastName;
}

int Person::getSessionCounter() const
{
    return m_sessionCounter;
}

QString Person::getEmail() const
{
    return m_email;
}

QString Person::getRegisterDay() const
{
    return m_registerDay;
}


void Person::setId(const int &id)
{
    if (m_id == id)
        return;

    m_id = id;
    emit idChanged(id);
}

void Person::setCode(const QString &code)
{
    if (m_code == code)
        return;

    m_code = code;
    emit codeChanged(code);
}

void Person::setFirstName(const QString &firstName)
{
    if (m_firstName == firstName)
        return;

    m_firstName = firstName;
    emit firstNameChanged(firstName);
}

void Person::setLastName(const QString &lastName)
{
    if (m_lastName == lastName)
        return;

    m_lastName = lastName;
    emit lastNameChanged(lastName);
}

void Person::setSessionCounter(const int &sessionCounter)
{
    if (m_sessionCounter == sessionCounter)
        return;

    m_sessionCounter = sessionCounter;
    emit sessionCounterChanged(sessionCounter);
}

void Person::setEmail(const QString &email)
{
    if (m_email == email)
        return;

    m_email = email;
    emit emailChanged(email);
}

void Person::setRegisterDay(const QString &registerDay)
{
    if (m_registerDay == registerDay)
        return;

    m_registerDay = registerDay;
    emit registerDayChanged(registerDay);
}

void Person::setPerson(const Person &person)
{
    this->setId(person.m_id);
    this->setFirstName(person.m_firstName);
    this->setLastName(person.m_lastName);
    this->setSessionCounter(person.m_sessionCounter);
    this->setEmail(person.m_email);
}
