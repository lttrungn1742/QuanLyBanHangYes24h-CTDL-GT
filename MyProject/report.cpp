#include "report.h"
#include "ui_report.h"
#include<qdebug.h>
report::report(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::report)
{
    init(thongke.cllist);
    initphlist(thongke.phlist);
    inittimelist(thanghd);
    ui->setupUi(this);
    populateclbox();
    populateyearbox();
    populatemonthbox();
    printtablerp();
}

report::~report()
{
    delete ui;
}
void report::printtablerp(){
    ui->viewreport->clear();
    ui->viewreport->setColumnCount(5);

    QTableWidgetItem* col0 = new QTableWidgetItem(QString("Tháng"));
    QTableWidgetItem* col1 = new QTableWidgetItem(QString("Năm"));
    QTableWidgetItem* col2 = new QTableWidgetItem(QString("Mặt hàng"));
    QTableWidgetItem* col3 = new QTableWidgetItem(QString("Số lượng"));
    QTableWidgetItem* col4 = new QTableWidgetItem(QString("Doanh thu"));

    ui->viewreport->setHorizontalHeaderItem(0, col0);
    ui->viewreport->setHorizontalHeaderItem(1, col1);
    ui->viewreport->setHorizontalHeaderItem(2, col2);
    ui->viewreport->setHorizontalHeaderItem(3, col3);
    ui->viewreport->setHorizontalHeaderItem(4, col4);

    QString year=ui->yearcombobox->currentText();
    QString month=ui->thangcombobox->currentText();
    QString danhmuc=ui->categorycombo->currentText();
    int i=0;
    if(month=="All time"){
        for(auto p=thanghd.gettail();p!=NULL;p=p->prev){
            if(danhmuc=="ALL"){
                ui->viewreport->setRowCount(thongke.cllist.getRows()*thanghd.monthcount());
                for(auto l=thongke.cllist.getHead();l!=NULL;l=l->next){
                    if(QString::number(QDate::fromString(p->monthyear,"MM/yyyy").year())==ui->yearcombobox->currentText()){
                    ui->viewreport->setItem(i,0,new QTableWidgetItem(QString::number(QDate::fromString(p->monthyear,"MM/yyyy").month())));
                    ui->viewreport->setItem(i,1,new QTableWidgetItem(QString::number(QDate::fromString(p->monthyear,"MM/yyyy").year())));
                    ui->viewreport->setItem(i,2,new QTableWidgetItem(QString::fromStdString(l->name)));
                    ui->viewreport->setItem(i,3,new QTableWidgetItem(QString::number(thongke.number_product_category(QString::fromStdString(l->name),p->monthyear))));
                    ui->viewreport->setItem(i,4,new QTableWidgetItem(QLocale(QLocale::English).toString(thongke.money_category(QString::fromStdString(l->name),p->monthyear))+" VND"));
                    if(thongke.money_category(QString::fromStdString(l->name),p->monthyear)!=0){
                    i++;}
                    }
                }
            }else{
                ui->viewreport->setRowCount(thanghd.monthcount());
                if(QString::number(QDate::fromString(p->monthyear,"MM/yyyy").year())==ui->yearcombobox->currentText()){
                ui->viewreport->setItem(i,0,new QTableWidgetItem(QString::number(QDate::fromString(p->monthyear,"MM/yyyy").month())));
                ui->viewreport->setItem(i,1,new QTableWidgetItem(QString::number(QDate::fromString(p->monthyear,"MM/yyyy").year())));
                ui->viewreport->setItem(i,2,new QTableWidgetItem(ui->categorycombo->currentText()));
                ui->viewreport->setItem(i,3,new QTableWidgetItem(QString::number(thongke.number_product_category(ui->categorycombo->currentText(),p->monthyear))));
                ui->viewreport->setItem(i,4,new QTableWidgetItem(QLocale(QLocale::English).toString(thongke.money_category(ui->categorycombo->currentText(),p->monthyear))+" VND"));
                if(thongke.money_category(ui->categorycombo->currentText(),p->monthyear)!=0){
                i++;}
                }
            }
        }

    }else{
        for(auto p=thanghd.gettail();p!=NULL;p=p->prev){
            if(danhmuc=="ALL"){
                ui->viewreport->setRowCount(thongke.cllist.getRows());
                for(auto l=thongke.cllist.getHead();l!=NULL;l=l->next){
                    if(QString::number(QDate::fromString(p->monthyear,"MM/yyyy").year())==ui->yearcombobox->currentText()){
                        if(QString::number(QDate::fromString(p->monthyear,"MM/yyyy").month())==ui->thangcombobox->currentText()){
                             ui->viewreport->setItem(i,0,new QTableWidgetItem(QString::number(QDate::fromString(p->monthyear,"MM/yyyy").month())));
                             ui->viewreport->setItem(i,1,new QTableWidgetItem(QString::number(QDate::fromString(p->monthyear,"MM/yyyy").year())));
                             ui->viewreport->setItem(i,2,new QTableWidgetItem(QString::fromStdString(l->name)));
                             ui->viewreport->setItem(i,3,new QTableWidgetItem(QString::number(thongke.number_product_category(QString::fromStdString(l->name),p->monthyear))));
                             ui->viewreport->setItem(i,4,new QTableWidgetItem(QLocale(QLocale::English).toString(thongke.money_category(QString::fromStdString(l->name),p->monthyear))+" VND"));
                             if(thongke.money_category(QString::fromStdString(l->name),p->monthyear)!=0){i++;}
                            }
                    }
                }
            }else{
                ui->viewreport->setRowCount(1);
                if(QString::number(QDate::fromString(p->monthyear,"MM/yyyy").year())==year){
                    if(QString::number(QDate::fromString(p->monthyear,"MM/yyyy").month())==ui->thangcombobox->currentText()){
                        ui->viewreport->setItem(i,0,new QTableWidgetItem(QString::number(QDate::fromString(p->monthyear,"MM/yyyy").month())));
                        ui->viewreport->setItem(i,1,new QTableWidgetItem(QString::number(QDate::fromString(p->monthyear,"MM/yyyy").year())));
                        ui->viewreport->setItem(i,2,new QTableWidgetItem(ui->categorycombo->currentText()));
                        ui->viewreport->setItem(i,3,new QTableWidgetItem(QString::number(thongke.number_product_category(ui->categorycombo->currentText(),p->monthyear))));
                        ui->viewreport->setItem(i,4,new QTableWidgetItem(QLocale(QLocale::English).toString(thongke.money_category(ui->categorycombo->currentText(),p->monthyear))+" VND"));
                    if(thongke.money_category(ui->categorycombo->currentText(),p->monthyear)!=0){i++;}
                }
                }
            }
        }


    }
}
void report::populateyearbox(){
    QString temp;
    for(auto p=thanghd.gethead();p!=NULL;p=p->next){
        if((QDate::fromString(p->monthyear,"MM/yyyy").year())!=temp){
        ui->yearcombobox->addItem(QString::number(QDate::fromString(p->monthyear,"MM/yyyy").year()),QString::number(QDate::fromString(thanghd.gethead()->monthyear,"MM/yyyy").year()));
        }
        temp=QString(QDate::fromString(p->monthyear,"MM/yyyy").year());

    }
}
void report::populatemonthbox(){
    ui->thangcombobox->addItem("All time",0);
    for(auto p=thanghd.gethead();p!=NULL;p=p->next){
        if(QDate::fromString(p->monthyear,"MM/yyyy").year()==ui->yearcombobox->currentText().toInt()){
        ui->thangcombobox->addItem(QString::number(QDate::fromString(p->monthyear,"MM/yyyy").month()),QString::number(QDate::fromString(p->monthyear,"MM/yyyy").month()));

    }
    }
}
void report::populateclbox(){
    ui->categorycombo->addItem("ALL",0);
    for(auto p=thongke.cllist.getHead();p!=NULL;p=p->next){
        ui->categorycombo->addItem(QString::fromStdString(p->name),QString::fromStdString(p->name));
    }
}


void report::on_okbutton_clicked()
{
    printtablerp();

}
