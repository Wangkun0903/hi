#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QCamera>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>
#include <QCameraViewfinder>

class LoginWindow : public QDialog
{
    Q_OBJECT
public:
    explicit LoginWindow(QWidget *parent = nullptr);

signals:

private slots:
    void openCamera();
    void startRecognition();
    void recognitionFinished(bool success);

private:
    QCamera *camera;
    QCameraViewfinder *viewFinder;
    QPushButton *openButton;
    QPushButton *startButton;
};

#endif // LOGINWINDOW_H
