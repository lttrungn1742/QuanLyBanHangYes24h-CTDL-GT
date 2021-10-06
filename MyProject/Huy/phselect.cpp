#include "phselect.h"
#include "ui_phselect.h"

phselect::phselect(QString x,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::phselect)
{
    initphlist(phlist);
    ui->setupUi(this);
    auto p=phlist.nodeph(x);
    ui->code->setText(p->code);
    ui->username->setText(p->username);
    ui->productname->setText(p->nameProduct);
    ui->price->setText(p->price);
    ui->datetime->setText(p->datetime.toString("dd/MM/yyyy"));
    ui->address->setText(p->address);
    ui->payment->setText(p->payments);
    for(auto n=phlist.sttlist.gethead();n!=NULL;n=n->next){
        ui->status->addItem(n->status);
    }
    ui->status->setCurrentText(p->status);
    ph=x;
}

phselect::~phselect()
{
    delete ui;
}
void phselect::on_close_clicked()
{
    this->close();
}
void phselect::on_apply_clicked()
{
    int check=QMessageBox::information(this,"","Are you sure?",QMessageBox::Yes|QMessageBox::No);
    if(check==QMessageBox::No){
        return;
    }
    QString status=ui->status->currentText();
    QString updatetime= QDate::currentDate().toString("dd/MM/yyyy");
    phlist.changstatus(ph,status);
    phlist.changeupdatetime(ph,updatetime);
    outitphlist(phlist);

}
