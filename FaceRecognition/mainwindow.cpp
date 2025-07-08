#include "mainwindow.h"
#include "addgroupdialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), camera(nullptr)
{
    setWindowTitle(tr("Main"));
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    viewFinder = new QCameraViewfinder(this);
    userIdEdit = new QLineEdit(this);
    userIdEdit->setPlaceholderText(tr("User ID"));
    groupIdEdit = new QLineEdit(this);
    groupIdEdit->setPlaceholderText(tr("Group ID"));

    openButton = new QPushButton(tr("Open Camera"), this);
    captureButton = new QPushButton(tr("Capture Face"), this);
    addGroupButton = new QPushButton(tr("Add Group"), this);
    statusLabel = new QLabel(this);

    QVBoxLayout *layout = new QVBoxLayout(central);
    layout->addWidget(viewFinder);
    layout->addWidget(openButton);
    layout->addWidget(userIdEdit);
    layout->addWidget(groupIdEdit);
    layout->addWidget(captureButton);
    layout->addWidget(addGroupButton);
    layout->addWidget(statusLabel);

    connect(openButton, &QPushButton::clicked, this, &MainWindow::openCamera);
    connect(captureButton, &QPushButton::clicked, this, &MainWindow::captureFace);
    connect(addGroupButton, &QPushButton::clicked, this, &MainWindow::addGroup);
}

void MainWindow::openCamera()
{
    if (!camera) {
        camera = new QCamera(this);
        camera->setViewfinder(viewFinder);
    }
    camera->start();
    statusLabel->setText(tr("Camera opened"));
}

void MainWindow::captureFace()
{
    if (!camera || camera->state() != QCamera::ActiveState) {
        QMessageBox::warning(this, tr("Error"), tr("Please open camera"));
        return;
    }
    if (userIdEdit->text().isEmpty()) {
        QMessageBox::warning(this, tr("Error"), tr("User ID required"));
        return;
    }
    if (groupIdEdit->text().isEmpty()) {
        QMessageBox::warning(this, tr("Error"), tr("Group ID required"));
        return;
    }
    statusLabel->setText(tr("Face captured (mock)"));
}

void MainWindow::addGroup()
{
    AddGroupDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        QString id = dlg.groupId();
        if (!id.isEmpty())
            QMessageBox::information(this, tr("Group"), tr("Added group %1").arg(id));
    }
}
