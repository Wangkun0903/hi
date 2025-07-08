#ifndef ADDGROUPDIALOG_H
#define ADDGROUPDIALOG_H

#include <QDialog>

namespace Ui {
class AddGroupDialog;
}

class AddGroupDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddGroupDialog(QWidget *parent = nullptr);
    ~AddGroupDialog();
    QString groupId() const;

private slots:
    void acceptGroup();

private:
    Ui::AddGroupDialog *ui;
};

#endif // ADDGROUPDIALOG_H
