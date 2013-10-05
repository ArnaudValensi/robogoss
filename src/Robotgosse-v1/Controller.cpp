#include "Controller.h"
#include "ui_controller.h"

#include "ConnectionController.h"
#include "Serial.h"
#include "UDP.h"
#include "Video.h"
#include <QMessageBox>

Controller::Controller(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Controller),
    communication(NULL),
    video(NULL)
{
    ui->setupUi(this);

    this->controllerConnect = new ConnectionController(this);
    connect(this->controllerConnect, SIGNAL(connect(Communication::Type)),
            this, SLOT(initCommunication(Communication::Type)));
}

Controller::~Controller()
{
    delete ui;
}

void Controller::initCommunication(Communication::Type type)
{
    if (type == Communication::SERIAL)
    {
        this->communication = new Serial(this->controllerConnect->getSerialPort(),
                                         this);
        try
        {
            this->communication->init();
            QMessageBox::information(this, "Connected", "Connected to the device.");
        }
        catch (SerialError &e)
        {
            QMessageBox::warning(this, "Error", e.what());
        }
    }
    else if (type == Communication::UDP)
    {
        this->communication = new UDP(this->controllerConnect->getIp(),
                                         this->controllerConnect->getIpPort(),
                                         this);
        this->communication->init();
        QMessageBox::information(this, "Connected", "Connected to the device.");
    }
}

void Controller::sendToArduino(char pin, char value)
{
    this->communication->transmitCmd(Communication::Buffer(pin, value));
}

void Controller::on_actionConnectRobot_triggered()
{
        this->controllerConnect->show();
}

void Controller::on_pushButtonConnectVideo_clicked()
{
    this->video = new Video(ui->video->winId(),
                            std::string(this->ui->lineEditVideo->text().toStdString()));
    video->start();
}

/////////////////////////////////////////////////////////////////////////////
/// Configuration from here
/////////////////////////////////////////////////////////////////////////////

void Controller::on_pushButtonForward_clicked()
{
    this->sendToArduino(0, 1);
}

void Controller::on_pushButtonLeft_clicked()
{
    this->sendToArduino(1, 1);
}

void Controller::on_pushButtonRight_clicked()
{
    this->sendToArduino(2, 1);
}

void Controller::on_pushButtonBackward_clicked()
{
    this->sendToArduino(3, 1);
}

void Controller::on_pushButtonStop_clicked()
{
    this->sendToArduino(4, 1);
}

void Controller::on_pushButtonDrivingAss_clicked()
{
    this->sendToArduino(5, 1);
}

void Controller::on_pushButtonRedLaser_clicked()
{
    this->sendToArduino(6, 1);
}

void Controller::on_pushButtonGreenLaser_clicked()
{
    this->sendToArduino(7, 1);
}

void Controller::on_pushButtonBuzzer_clicked()
{
    this->sendToArduino(8, 1);
}

void Controller::on_pushButtonProjector_clicked()
{
    this->sendToArduino(9, 1);
}

void Controller::on_pushButtonLights_clicked()
{
    this->sendToArduino(10, 1);
}

void Controller::on_horizontalSliderArm_valueChanged(int value)
{
    this->sendToArduino(11, value);
}

void Controller::on_verticalSliderArm_valueChanged(int value)
{
    this->sendToArduino(12, value);
}
