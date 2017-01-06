#ifndef PHOTOMANAGER_H
#define PHOTOMANAGER_H

#include <QObject>

class QLabel;
class PhotoManager : public QObject
{
    Q_OBJECT
public:
    explicit PhotoManager(QObject *parent = 0);
    void show(QString path, QLabel *lbl);

private:
    bool pathIsValid(QString path);
private:
    QString m_path;
};

#endif // PHOTOMANAGER_H
