#include "managerPd.h"
#include "ui_managerPd.h"
#include"categorydialog.h"

managerPd::managerPd(QWidget *parent) :    QWidget(parent),   ui(new Ui::managerPd)
{
    init(DATA);
    ui->setupUi(this);
    ui->table->setGeometry(170,50,1200,800);
    printTable();
    ui->brand->setGeometry(QRect(1380,100,150,30));
    ui->madein->setGeometry(QRect(1380,140,150,30));
    ui->category->setGeometry(QRect(1380,180,150,30));
    ui->addPd->setGeometry(QRect(1380,60,150,30));

    connect(ui->brand,&QPushButton::clicked,this,&managerPd::clickBrand);
    connect(ui->madein,&QPushButton::clicked,this,&managerPd::clickMadein);
    connect(ui->category,&QPushButton::clicked,this,&managerPd::clickCategory);
    connect(ui->table,&QTableWidget::cellDoubleClicked,this, &managerPd::cellSelected);
    ListItem = {};
}

void managerPd::printTable()
{
    ui->table->clear();
    ui->table->setRowCount(DATA.length());
    ui->table->setColumnCount(9);
    QTableWidgetItem* col0 = new QTableWidgetItem("Hình ảnh"),
            *col1 = new QTableWidgetItem("Mã sản phẩm"),
            *col2 = new QTableWidgetItem("Tên sản phẩm"),
            *col3 = new QTableWidgetItem("Danh mục"),
            *col4 = new QTableWidgetItem("Phân loại"),
            *col5 = new QTableWidgetItem("Thương hiệu / Xuất xứ"),
            *col6 = new QTableWidgetItem("Sản xuất"),
            *col7 = new QTableWidgetItem("Đơn giá"),
            *col8 = new QTableWidgetItem("Số lượng tồn kho"),
            *col9 = new QTableWidgetItem("Kinh doanh");

    ui->table->setHorizontalHeaderItem(0,col0);
    ui->table->setHorizontalHeaderItem(1,col1);
    ui->table->setHorizontalHeaderItem(2,col2);
    ui->table->setHorizontalHeaderItem(3,col3);
    ui->table->setHorizontalHeaderItem(4,col4);
    ui->table->setHorizontalHeaderItem(5,col5);
    ui->table->setHorizontalHeaderItem(6,col6);
    ui->table->setHorizontalHeaderItem(7,col7);
    ui->table->setHorizontalHeaderItem(8,col8);
    ui->table->setHorizontalHeaderItem(9,col9);
    int row = 0;
    for (auto p = DATA.getHead();p!=NULL;p=p->next)
    {

        QString  photoFile = QString::fromStdString("E:\\Project\\MyProject\\photoProducts\\"+p->id+".png");
      if(!QFile::exists(photoFile)) photoFile = "E:\\Project\\MyProject\\photo\\imageNotFound.png";
                QTableWidgetItem *item0 = new QTableWidgetItem(QIcon(photoFile),QString()),
                                *item1 = new QTableWidgetItem(QString::fromStdString(p->id)),
                                *item2 = new QTableWidgetItem(QString::fromStdString(p->name)),
                                *item3 = new QTableWidgetItem(QString::fromStdString(p->category)),
                                *item4 = new QTableWidgetItem(QString::fromStdString(p->kind)),
                                *item5 = new QTableWidgetItem(QString::fromStdString(p->brand)),
                                *item6 = new QTableWidgetItem(QString::fromStdString(p->madein)),
                                *item7 = new QTableWidgetItem(QString::number(std::stoi(p->price))),
                                *item8 = new QTableWidgetItem(QString::number(p->quanity)),
                                *item9 = new QTableWidgetItem(QString(p->disable?"không":"tiếp tục"));



                if(p->disable)
                {
                    item1->setBackgroundColor("#EBF5FB");
                    item2->setBackgroundColor("#EBF5FB");
                    item3->setBackgroundColor("#EBF5FB");
                    item4->setBackgroundColor("#EBF5FB");
                    item5->setBackgroundColor("#EBF5FB");
                    item6->setBackgroundColor("#EBF5FB");
                    item7->setBackgroundColor("#EBF5FB");
                    item8->setBackgroundColor("#EBF5FB");
                    item9->setBackgroundColor("#EBF5FB");
                }
                else if(p->quanity==0)
                {
                     item1->setBackgroundColor("#F52A15");
                     item2->setBackgroundColor("#F52A15");
                     item3->setBackgroundColor("#F52A15");
                     item4->setBackgroundColor("#F52A15");
                     item5->setBackgroundColor("#F52A15");
                     item6->setBackgroundColor("#F52A15");
                     item7->setBackgroundColor("#F52A15");
                     item8->setBackgroundColor("#F52A15");
                     item9->setBackgroundColor("#F52A15");
                }
                ui->table->setRowHeight(row,80);
                        int col = 0;
                        ui->table->setItem(row,col,item0);     col++;
                        ui->table->setItem(row,col,item1);     col++;
                        ui->table->setItem(row,col,item2);     col++;
                        ui->table->setItem(row,col,item3);     col++;
                        ui->table->setItem(row,col,item4);     col++;
                        ui->table->setItem(row,col,item5);     col++;
                        ui->table->setItem(row,col,item6);     col++;
                        ui->table->setItem(row,col,item7);     col++;
                        ui->table->setItem(row,col,item8);     col++;
                        ui->table->setItem(row,col,item9);     row++;
    }
}

managerPd::~managerPd()
{
    delete ui;
}

void managerPd::refesh()
{
    ListItem.clear();
    DATA.~Products();
    init(DATA);
    printTable();
}

void managerPd::clickBrand()
{
    if(checkBrandDialog) return;
    checkBrandDialog=true;
    brandDialog* newDialog = new brandDialog(NULL);
    newDialog->show();
    if(newDialog->exec()  == brandDialog::Rejected)
    {
         refesh();
         checkBrandDialog = false;
    }
}

void managerPd::clickMadein()
{
    if(checkMadeinDialog) return;
    checkMadeinDialog = true;
    madeinDialog* newDialog = new madeinDialog(NULL);
    newDialog->show();
    if(newDialog->exec()  ==brandDialog::Rejected)
    {
        refesh();
        checkMadeinDialog = false;
    }
}

void managerPd::clickCategory()
{

    categoryDialog* newDialog = new categoryDialog(NULL);
    newDialog->show();
    if(newDialog->exec()  ==categoryDialog::Rejected)
    {
        refesh();
    }

}

void managerPd::on_addPd_clicked()
{
        addPd* newDialog = new addPd(NULL);
        newDialog->show();
        int ret = newDialog->exec();
        if(ret==addPd::Rejected  || ret ==addPd::Accepted) {
            refesh();
        }
}

void managerPd::cellSelected(int nRow,int nCol)
{
    std::string str = ui->table->item(nRow,1)->text().toStdString();
    EditProduct* newDialog = new EditProduct(str,NULL);
    newDialog->show();
    if(newDialog->exec() == EditProduct::Accepted) refesh();
}

void managerPd::on_find_textChanged(const QString &arg1)
{
    foreach(QTableWidgetItem * rowptr, ListItem)
    {
        rowptr->setBackgroundColor(QColor("white"));
    }
    if (arg1 == "") return;
     ListItem = ui->table->findItems(arg1, Qt::MatchEndsWith);

    foreach(QTableWidgetItem* rowptr,ListItem)
    {
        rowptr->setBackgroundColor(QColor("yellow"));
    }
}
