#include "dialogaddbrand.h"
#include "ui_dialogaddbrand.h"

dialogAddBrand::dialogAddBrand(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogAddBrand)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&dialogAddBrand::add);
    init(DataBrand);
    QPixmap avt("E:/Project/MyProject/photo/yes24.png");
    ui->icon->setPixmap(avt);
    QPixmap icon("E:/Project/MyProject/photo/warning.png");
    ui->icon_2->setPixmap(icon);
    ui->icon_2->hide();
    ui->label_3->hide();
    newBrand = new QLineEdit(this);
    newBrand->setGeometry(QRect(200,90,250,30));
}

dialogAddBrand::~dialogAddBrand()
{
    delete ui;
}

void dialogAddBrand::add()
{
    if(DataBrand.check(newBrand->text().toStdString()))
    {
        ui->icon_2->show();
        ui->label_3->show();
        return;
    }
    DataBrand.add(newBrand->text().toStdString());
    save(DataBrand);

    this->accept();

}
