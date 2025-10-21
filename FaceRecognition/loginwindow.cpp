#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QPushButton>

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::LoginWindow), camera(nullptr)
{
    ui->setupUi(this);
    ui->startButton->setEnabled(false);

    connect(ui->openButton, &QPushButton::clicked, this, &LoginWindow::openCamera);
    connect(ui->startButton, &QPushButton::clicked, this, &LoginWindow::startRecognition);
}

LoginWindow::~LoginWindow()
{
    if (camera)
        camera->stop();
    delete camera;
    delete ui;
}

void LoginWindow::openCamera()
{
    if (!camera) {
        camera = new QCamera(this);
        camera->setViewfinder(ui->viewFinder);
    }
    camera->start();
    ui->startButton->setEnabled(true);
}

void LoginWindow::startRecognition()
{
    if (!camera)
        return;
    // For demo we just simulate success after short delay
    QTimer::singleShot(1000, [this]() { recognitionFinished(true); });
}

void LoginWindow::recognitionFinished(bool success)
{
    camera->stop();
    if (success) {
        QMessageBox::information(this, tr("Success"), tr("Face recognized"));
        accept();
        MainWindow *w = new MainWindow();
        w->show();
    } else {
        QMessageBox::warning(this, tr("Failed"), tr("Recognition failed"));
    }
}
