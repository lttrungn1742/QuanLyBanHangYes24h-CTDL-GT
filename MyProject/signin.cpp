#include "signin.h"
#include "ui_signin.h"
#include"regist.h"
#include<QPixmap>

signin::signin(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::signin)
{
    ui->setupUi(this);
    ui->incorrect->hide();
    ui->disable->hide();
    QPixmap icon("E:/Project/MyProject/photo/yes24.png");
    ui->yes24->setPixmap(icon.scaled(300,160,Qt::KeepAspectRatio));
    Init(signin_er);
}

signin::~signin()
{
    delete ui;
}

void signin::on_pushButton_clicked()
{
    int ret = signin_er.checksignin(ui->username->text().toStdString(), ui->password->text().toStdString());
    if(ret == -1)
    {
        ui->incorrect->setStyleSheet("color: #ff3838;");
        ui->incorrect->show();
    }
    else if (ret==-2)
    {
        ui->disable->setStyleSheet("color: #ff3838;");
        ui->disable->show();
    }
    else if(ret ==1)
    {
        program* w = new program(NULL);
        w->show();
        this->close();
    }


}


void signin::on_pushButton_2_clicked()
{
    regist* registWindows = new regist(NULL);
    registWindows->show();
    this->close();
}
