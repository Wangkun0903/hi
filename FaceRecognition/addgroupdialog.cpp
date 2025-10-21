#include "addgroupdialog.h"
#include "ui_addgroupdialog.h"

AddGroupDialog::AddGroupDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AddGroupDialog)
{
    ui->setupUi(this);
    connect(ui->okButton, &QPushButton::clicked, this, &AddGroupDialog::acceptGroup);
}

AddGroupDialog::~AddGroupDialog()
{
    delete ui;
}

QString AddGroupDialog::groupId() const
{
    return ui->groupIdEdit->text();
}

void AddGroupDialog::acceptGroup()
{
    if (ui->groupIdEdit->text().isEmpty())
        return;
    accept();
}
