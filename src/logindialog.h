#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QtWidgets/QDialog>

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = 0);
    ~loginDialog();

    QString sectionNumber() const;
    bool section_set_checkBox() const;

private slots:
    void on_no_section_set_checkBox_clicked();

private:
    Ui::loginDialog *ui;
};

#endif // LOGINDIALOG_H
