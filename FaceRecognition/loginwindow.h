#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QCamera>
#include <QCameraViewfinder>
#include <QTimer>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT
public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

signals:

private slots:
    void openCamera();
    void startRecognition();
    void recognitionFinished(bool success);

private:
    Ui::LoginWindow *ui;
    QCamera *camera;
};

#endif // LOGINWINDOW_H
