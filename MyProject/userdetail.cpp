#include "userdetail.h"
#include "ui_userdetail.h"

userdetail::userdetail(/*USERS data,*/ std::string id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userdetail)
{
    ui->setupUi(this);


    Init(data);
    p = data.getpointer(id);

    ui->name->setText(QString::fromStdString(p->name));
    ui->username->setText(QString::fromStdString(p->username));
    ui->gender->setText(p->gender ? "Nam" : "Nữ");
    ui->phonenumber->setText(QString::fromStdString(p->phonenumber));
    ui->email->setText(QString::fromStdString(p->email));
    ui->rights->setCurrentIndex(p->rights);
    p->enable ? ui->stt1->setChecked(true) : ui->stt0->setChecked(true);
}

userdetail::~userdetail()
{
    delete ui;
}


void userdetail::on_pushButton_clicked()
{
   int ret = QMessageBox::warning(this, "Xác nhận", "Bạn có muốn lưu thông tin này?", QMessageBox::Yes|QMessageBox::No);
   if (ret == QMessageBox::No)
       return;
   p->rights = ui->rights->currentIndex();
   p->enable = ui->stt1->isChecked() ? 1 : 0;
   save(data);
   this->accept();
}

void userdetail::on_pushButton_2_clicked()
{
    this->reject();
}
