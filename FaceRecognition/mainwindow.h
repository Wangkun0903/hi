#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCamera>
#include <QCameraViewfinder>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void openCamera();
    void captureFace();
    void addGroup();

private:
    QCamera *camera;
    QCameraViewfinder *viewFinder;
    QLineEdit *userIdEdit;
    QLineEdit *groupIdEdit;
    QLabel *statusLabel;
    QPushButton *openButton;
    QPushButton *captureButton;
    QPushButton *addGroupButton;
};

#endif // MAINWINDOW_H
