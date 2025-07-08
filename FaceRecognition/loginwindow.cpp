#include "loginwindow.h"
#include "mainwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent), camera(nullptr)
{
    setWindowTitle(tr("Login"));
    viewFinder = new QCameraViewfinder(this);

    openButton = new QPushButton(tr("Open Camera"), this);
    startButton = new QPushButton(tr("Start Recognition"), this);
    startButton->setEnabled(false);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(viewFinder);
    layout->addWidget(openButton);
    layout->addWidget(startButton);

    connect(openButton, &QPushButton::clicked, this, &LoginWindow::openCamera);
    connect(startButton, &QPushButton::clicked, this, &LoginWindow::startRecognition);
}

void LoginWindow::openCamera()
{
    camera = new QCamera(this);
    camera->setViewfinder(viewFinder);
    camera->start();
    startButton->setEnabled(true);
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
