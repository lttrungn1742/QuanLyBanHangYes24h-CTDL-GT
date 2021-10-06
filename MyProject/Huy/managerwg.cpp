#include "managerwg.h"
#include"purchasehst.h"
#include "ui_managerwg.h"
#include "addstatus.h"
#include <QIcon>
managerwg::managerwg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::managerwg)
{
    initphlist(phlist);
    ui->setupUi(this);
    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window, QRgb(0xcee7f0));
    pal.setColor(QPalette::WindowText, QRgb(0x404044));

    qApp->setPalette(pal);
    ui->back->setIcon(QIcon("E:/Project/MyProject/Huy/Icon/back.png"));
    ui->table->setGeometry(50,100,1200,700);
    ui->table->setColumnCount(8);
    printTable();
    connect(ui->table,&QTableWidget::cellDoubleClicked,this,&managerwg::tableItemClicked);
    ListItem = {};
//  connect(ui->thongke,&QPushButton::clicked,this,&managerwg::on_thongke_clicked);
}
managerwg::~managerwg()
{
    delete ui;
}
void managerwg::printTable(){
      ui->table->clear();
      ui->table->resize(1085,700);
      ui->table->setRowCount(phlist.countlist());
      QTableWidgetItem* col0=new QTableWidgetItem(QString("Đơn hàng"));
      QTableWidgetItem* col1 =new QTableWidgetItem(QString("Tên sản phẩm"));
      QTableWidgetItem* col2 =new QTableWidgetItem(QString("Tên người dùng"));
      QTableWidgetItem* col3 =new QTableWidgetItem(QString("Giá tiền"));
      QTableWidgetItem* col4 =new QTableWidgetItem(QString("Ngày tháng"));
      QTableWidgetItem* col6 =new QTableWidgetItem(QString("Hình thức thanh toán"));
      QTableWidgetItem* col7 =new QTableWidgetItem(QString("Trạng thái"));
      QTableWidgetItem* col8 =new QTableWidgetItem(QString("Thời gian cập nhật "));
      ui->table->setHorizontalHeaderItem(0, col0);
      ui->table->setHorizontalHeaderItem(1, col1);
      ui->table->setHorizontalHeaderItem(2, col2);
      ui->table->setHorizontalHeaderItem(3, col3);
      ui->table->setHorizontalHeaderItem(4, col4);
      ui->table->setHorizontalHeaderItem(5, col6);
      ui->table->setHorizontalHeaderItem(6, col7);
      ui->table->setHorizontalHeaderItem(7, col8);
      ui->table->setColumnWidth(0,100);
      ui->table->setColumnWidth(1,200);
      ui->table->setColumnWidth(2,120);
      ui->table->setColumnWidth(3,100);
      ui->table->setColumnWidth(4,120);
      ui->table->setColumnWidth(5,150);
      ui->table->setColumnWidth(6,150);
      ui->table->setColumnWidth(7,120);
      int i=0;
      for(auto p=phlist.gettail();p!=NULL;p=p->prev){
          ui->table->setItem(i,0,new QTableWidgetItem(p->code));
          ui->table->setItem(i,1,new QTableWidgetItem(p->nameProduct));
          ui->table->setItem(i,2,new QTableWidgetItem(p->username));
          ui->table->setItem(i,3,new QTableWidgetItem(p->price));
          ui->table->setItem(i,4,new QTableWidgetItem(p->datetime.toString("dd/MM/yyyy")));
          ui->table->setItem(i,5,new QTableWidgetItem(p->payments));
          ui->table->setItem(i,6,new QTableWidgetItem(p->status));
          ui->table->setItem(i,7,new QTableWidgetItem(p->updatetime.toString("dd/MM/yyyy")));
          i++;
      }
}
void managerwg::renewtb(){
    ListItem.clear();
    phlist.~purchasehst();
    initphlist(phlist);
    printTable();
}
void managerwg::tableItemClicked(int row)
{
   QString x=ui->table->item(row,0)->text();
   phselect* phselect1 = new phselect(x,NULL);
   phselect1->show();
   if(phselect1->exec()==phselect::Rejected)renewtb();
}

void managerwg::on_thongke_clicked()
{
    //chartforph *chartwg= new chartforph(NULL);
   // chartwg->show();
}

void managerwg::on_pushButton_clicked()
{
    Addstatus *themstt = new Addstatus;
    themstt->show();
}

void managerwg::on_pushButton_2_clicked()
{
    report *reportx=new report;
    reportx->show();
}

void managerwg::on_searchbt_clicked()
{
    QString search = ui->search->text();

}


void managerwg::on_search_textChanged(const QString &arg1)
{
    foreach(QTableWidgetItem *row, ListItem){
        row->setBackground(QColor("white"));
    }
    if(arg1== "")return;
    ListItem = ui->table->findItems(arg1,Qt:: MatchContains);

    foreach(QTableWidgetItem* row, ListItem){
        row->setBackground(QColor("blue"));
    }
}


void managerwg::on_back_clicked()
{
    renewtb();
}
