#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMainWindow>
#include "Communication.h"

namespace Ui {
class Controller;
}

class ConnectionController;
class Video;

class Controller : public QMainWindow
{
    Q_OBJECT

public:
    explicit Controller(QWidget *parent = 0);
    ~Controller();

private:
    Ui::Controller *ui;
    Communication *communication;
    ConnectionController *controllerConnect;
    Video *video;

    void sendToArduino(char pin, char value);

private slots:
    void initCommunication(Communication::Type type);
    void on_actionConnectRobot_triggered();
    void on_pushButtonForward_clicked();
    void on_pushButtonLeft_clicked();
    void on_pushButtonRight_clicked();
    void on_pushButtonBackward_clicked();
    void on_pushButtonStop_clicked();
    void on_pushButtonDrivingAss_clicked();
    void on_pushButtonRedLaser_clicked();
    void on_pushButtonGreenLaser_clicked();
    void on_pushButtonBuzzer_clicked();
    void on_pushButtonProjector_clicked();
    void on_pushButtonLights_clicked();
    void on_horizontalSliderArm_valueChanged(int value);
    void on_verticalSliderArm_valueChanged(int value);
    void on_pushButtonConnectVideo_clicked();
};

#endif // CONTROLLER_H
