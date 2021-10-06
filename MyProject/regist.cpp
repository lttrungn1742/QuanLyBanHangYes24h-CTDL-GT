#include "regist.h"
#include "ui_regist.h"

regist::regist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regist)
{
    ui->setupUi(this);

    ui->existedID->hide(); // lúc mới mở cửa sổ sẽ ẩn
    ui->unID->hide();
    ui->unPass->hide();
    ui->diffPass->hide();
    ui->unNum->hide();
    ui->unMail->hide();
    ui->unGen->hide();
    connect(ui->btnRegist,&QPushButton::clicked,this,&regist::on_pushButton_clicked);
    QPixmap icon("E:/Project/MyProject/photo/yes24.png");
    ui->label->setPixmap(icon);

    Init(regist_er);
}

regist::~regist()
{
    delete ui;
}

void regist::on_pushButton_clicked()
{
    ui->existedID->hide(); // ẩn khi nhấn nút Đăng kí nhiều lần
    ui->unID->hide();
    ui->unPass->hide();
    ui->diffPass->hide();
    ui->unNum->hide();
    ui->unMail->hide();
    ui->unGen->hide();

    std::string ten = ui->name->text().toStdString();
    std::string id = ui->username->text().toStdString();
    std::string mk = ui->password->text().toStdString();
    std::string conf = ui->confirm->text().toStdString();
    std::string sdt = ui->phonenumber->text().toStdString();
    std::string mail = ui->email->text().toStdString();
    int gt = ui->gt1->isChecked() ? 1 : 0;
    int quyen = 0;
    int stt = 1;
    int error = 0;
    if (ten.length() == 0)
        ten = " ";
    if (regist_er.checkID(id) == 1)
    {
        ui->existedID->setStyleSheet("color: #ff3838;");
        ui->existedID->show();
        ui->username->clear();
        error++;
    }
    else if (regist_er.checkID(id) == -1)
    {
        ui->unID->setStyleSheet("color: #ff3838;");
        ui->unID->show();
        ui->username->clear();
        error++;
    }
    if (regist_er.checkPass(mk) == 0)
    {
        ui->unPass->setStyleSheet("color: #ff3838;");
        ui->unPass->show();
        ui->password->clear();
        error++;
    }
    if (regist_er.checkConfPass(mk, conf) == 0)
    {
        ui->diffPass->setStyleSheet("color: #ff3838;");
        ui->diffPass->show();
        ui->confirm->clear();
        ui->password->clear();
        error++;
    }
    if (regist_er.checkNum(sdt) == 0)
    {
        ui->unNum->setStyleSheet("color: #ff3838;");
        ui->unNum->show();
        ui->phonenumber->clear();
        error++;
    }
    if (regist_er.checkMail(mail) == 0)
    {
        ui->unMail->setStyleSheet("color: #ff3838;");
        ui->unMail->show();
        ui->email->clear();
        error++;
    }
    if (regist_er.checkMail(mail) == -1)
        mail = " ";
    if (ui->gt1->isChecked() == 0 && ui->gt0->isChecked() == 0)
    {
        ui->unGen->setStyleSheet("color: #ff3838;");
        ui->unGen->show();
        error++;
    }
    if (error == 0)
    {
        mk = regist_er.convertPass(mk);
        usr* p = newone(ten, id, mk, gt, sdt, mail, quyen, stt);
        regist_er.insert(p);
        QMessageBox::information(this, "Thông báo", "Đăng ký thành công!");
        save(regist_er);
        signin w(NULL);
        w.show();
        this->close();
    }
}

void regist::on_commandLinkButton_clicked()
{
    signin* login = new signin(NULL);
    login->show();
    this->close();
}
