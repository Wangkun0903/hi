#ifndef ADDGROUPDIALOG_H
#define ADDGROUPDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class AddGroupDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddGroupDialog(QWidget *parent = nullptr);
    QString groupId() const;

private slots:
    void acceptGroup();

private:
    QLineEdit *groupIdEdit;
    QPushButton *okButton;
};

#endif // ADDGROUPDIALOG_H
