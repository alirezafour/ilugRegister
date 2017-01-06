#include "photomanager.h"
#include <QImage>
#include <QLabel>

PhotoManager::PhotoManager(QObject *parent) : QObject(parent)
{
    m_path = ":/pic/build/Image/empty.jpg";
}

void PhotoManager::show(QString path, QLabel *lbl)
{
    QSize size;
    size.setHeight(150);
    size.setWidth(150);
    if(pathIsValid(path))
    {
        m_path = path;
    }
    QImage image(m_path);
    image = image.scaled(size, Qt::KeepAspectRatio);
    lbl->setPixmap(QPixmap::fromImage(image));
    lbl->setFixedSize(size);
}

bool PhotoManager::pathIsValid(QString path)
{
    QImage image(path);
    if (image.isNull()) return false;
    else return true;
}
