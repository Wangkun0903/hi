#include "addgroupdialog.h"

AddGroupDialog::AddGroupDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Add Group"));
    groupIdEdit = new QLineEdit(this);
    groupIdEdit->setPlaceholderText(tr("Group ID"));
    okButton = new QPushButton(tr("OK"), this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(groupIdEdit);
    layout->addWidget(okButton);

    connect(okButton, &QPushButton::clicked, this, &AddGroupDialog::acceptGroup);
}

QString AddGroupDialog::groupId() const
{
    return groupIdEdit->text();
}

void AddGroupDialog::acceptGroup()
{
    if (groupIdEdit->text().isEmpty())
        return;
    accept();
}
