#include <QtGui>
#include "widget.h"
#include "ui_widget.h"
#include "qtservice.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

    justOneCount=0;

    mouseX=this->geometry().x();
    mouseY=this->geometry().y();
    absY=this->geometry().y();
    absX=this->geometry().x();

    QtServiceController mamController(mamService);
    if(mamController.isInstalled() == false){
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
    } else {
        ui->pushButton_2->setEnabled(!mamController.isRunning());
        ui->pushButton_3->setEnabled(mamController.isRunning());
    }

    QtServiceController masController(masService);
    if(masController.isInstalled() == false){
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
    } else {
        ui->pushButton_5->setEnabled(!masController.isRunning());
        ui->pushButton_6->setEnabled(masController.isRunning());
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *mouse)
{
  mouseX=QCursor::pos().x();
  mouseY=QCursor::pos().y();

  if(justOneCount==0){
      absX=mouse->pos().x();
      absY=mouse->pos().y();
      justOneCount++;
  }

  this->move(mouseX-absX,mouseY-absY);
}

void Widget::mouseReleaseEvent(QMouseEvent *)
{
  justOneCount=0;
}

void Widget::on_pushButton_4_clicked()
{
    QApplication::exit(0);
}

void Widget::on_pushButton_2_clicked()
{
    QtServiceController controller(mamService);
    controller.start();
    ui->pushButton_2->setEnabled(!controller.isRunning());
    ui->pushButton_3->setEnabled(controller.isRunning());
}

void Widget::on_pushButton_3_clicked()
{
    QtServiceController controller(mamService);
    controller.stop();
    ui->pushButton_2->setEnabled(!controller.isRunning());
    ui->pushButton_3->setEnabled(controller.isRunning());
}

void Widget::on_pushButton_5_clicked()
{
    QtServiceController controller(masService);
    controller.start();
    ui->pushButton_5->setEnabled(!controller.isRunning());
    ui->pushButton_6->setEnabled(controller.isRunning());
}

void Widget::on_pushButton_6_clicked()
{
    QtServiceController controller(masService);
    controller.stop();
    ui->pushButton_5->setEnabled(!controller.isRunning());
    ui->pushButton_6->setEnabled(controller.isRunning());
}
