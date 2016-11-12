#include "../src/logindialog.h"
#include "../src/ui_logindialog.h"

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
}

loginDialog::~loginDialog()
{
    delete ui;
}

QString loginDialog::sectionNumber() const
{
    if(!ui->no_section_set_checkBox->isChecked())
        return ui->section_number_Line->text();
    else
        return "";
}

bool loginDialog::section_set_checkBox() const
{
    return ui->no_section_set_checkBox->isChecked();
}

void loginDialog::on_no_section_set_checkBox_clicked()
{
    ui->section_number_Line->setEnabled(!ui->no_section_set_checkBox->isChecked());
}
