#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addgroupdialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), camera(nullptr)
{
    ui->setupUi(this);

    connect(ui->openButton, &QPushButton::clicked, this, &MainWindow::openCamera);
    connect(ui->captureButton, &QPushButton::clicked, this, &MainWindow::captureFace);
    connect(ui->addGroupButton, &QPushButton::clicked, this, &MainWindow::addGroup);
}

MainWindow::~MainWindow()
{
    if (camera)
        camera->stop();
    delete camera;
    delete ui;
}

void MainWindow::openCamera()
{
    if (!camera) {
        camera = new QCamera(this);
        camera->setViewfinder(ui->viewFinder);
    }
    camera->start();
    ui->statusLabel->setText(tr("Camera opened"));
}

void MainWindow::captureFace()
{
    if (!camera || camera->state() != QCamera::ActiveState) {
        QMessageBox::warning(this, tr("Error"), tr("Please open camera"));
        return;
    }
    if (ui->userIdEdit->text().isEmpty()) {
        QMessageBox::warning(this, tr("Error"), tr("User ID required"));
        return;
    }
    if (ui->groupIdEdit->text().isEmpty()) {
        QMessageBox::warning(this, tr("Error"), tr("Group ID required"));
        return;
    }
    ui->statusLabel->setText(tr("Face captured (mock)"));
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
