#include "madeindialog.h"
#include"ui_madeindialog.h"

madeinDialog::madeinDialog(QWidget *parent) : QDialog(parent), ui(new Ui::madeinDialog)
{
    init(DATA);
    ui->setupUi(this);
    print();
    connect(ui->add,&QPushButton::clicked,this,&madeinDialog::add);
    connect(ui->remove,&QPushButton::clicked,this,&madeinDialog::remove);
    connect(ui->table,&QListWidget::itemPressed,this,&madeinDialog::select);
    connect(ui->edit,&QPushButton::clicked,this,&madeinDialog::edit);
    itemSelect = new QListWidgetItem("");
}

madeinDialog::~madeinDialog()
{
    delete ui;
}

void madeinDialog::edit()
{
    if(itemSelect->text()=="")
    {
        return;
    }
    if(QMessageBox::information(this,"Thông báo","Bạn có chắc chắn muốn sửa "+strSelect,QMessageBox::Yes| QMessageBox::No)==QMessageBox::No)
    {
        return;
    }

    editDialog = new QDialog(this);
    editDialog->show();
    editDialog->resize(600,350);

    QLabel* icon = new QLabel(editDialog);
    icon->setGeometry(0,0,500,200);
    QPixmap ICON("E:/Project/MyProject/photo/yes24.png");
    icon->setPixmap(ICON);
    icon->show();


    auto p = DATA.getPoiter(strSelect.toStdString());

    newEdit = new QLineEdit(strSelect,editDialog);
    newEdit->show();
    newEdit->setGeometry(200,200,200,30);
    QLabel* l1 = new QLabel(editDialog);
    l1->setGeometry(30,200,200,30);
    l1->setText("Tên thương hiệu mới: ");
    l1->show();
    l1->setFont(QFont("Arial",10));

    QPushButton * btnOk = new QPushButton("Đồng ý",editDialog),
            *btnCancel = new QPushButton("Hủy",editDialog);
    btnOk->setGeometry(QRect(300,250,100,30));
    btnOk->show();
    btnCancel->show();
    btnCancel->setGeometry(QRect(400,250,100,30));

    connect(btnCancel,&QPushButton::clicked,[this]{editDialog->reject();});
    connect(btnOk,&QPushButton::clicked,[this]{
       if(DATA.check(newEdit->text().toStdString()))
       {
           QMessageBox::warning(this,"Báo lỗi","Tên của nơi sản xuất này đã tồn tại");
           return;
       }
       if(QMessageBox::information(this,"Thông báo","Bạn có chắc chắn chưa?" , QMessageBox::No|QMessageBox::Yes) == QMessageBox::No)
       {
           return;
       }
       strSelect = newEdit->text();
       editDialog->accept();
    });
    if(editDialog->exec() == QDialog::Accepted)
    {
        p->name = strSelect.toStdString();
        save(DATA);
        print();
    }
}

void madeinDialog::print()
{
    ui->table->clear();
    int i =0;
    for (auto p = DATA.getHead();p!=NULL;p=p->next) {
        QListWidgetItem* Item0 = new QListWidgetItem(QString::number(p->id)+" "+QString::fromStdString(p->name));

        Item0->setFont(QFont("Arial",10));
        ui->table->insertItem(i,Item0);
        i++;
    }
}

void madeinDialog::select(QListWidgetItem* temp)
{
    itemSelect = temp;
    strSelect = itemSelect->text();

    for(int i =0 ;i<strSelect.length();i++)
    {
        if(strSelect[i] == ' ')
        {
            strSelect.remove(0,i+1);
            break;
        }
    }
}

void madeinDialog::remove()
{
    if(itemSelect->text() == " ")
    {
        return;
    }
    Products dataProduct;
    init(dataProduct);
    QString s = itemSelect->text();
    for(int i = 0 ;i<s.length();++i)
    {
        if(s[i] == ' ')
        {
            s.remove(0,i+1);
            break;
        }
    }

    if(dataProduct.checkMadein(s.toInt()))
    {
        QMessageBox::warning(this,"Báo lỗi","Đã có sản phẩm đang sử dụng mã sản xuất "+strSelect+", xóa thất bại");
        return;
    }

    auto p = DATA.getPoiter(strSelect.toStdString());
    DATA.remove(p);
    ui->table->removeItemWidget(itemSelect);
    save(DATA);
    print();
    QMessageBox::information(this,"Thông báo","Đã xóa thành công "+ strSelect);
}

void madeinDialog::add()
{


    addDialog = new QDialog(this);
    addDialog->show();
    addDialog->resize(600,350);

    QLabel* icon = new QLabel(addDialog);
    icon->setGeometry(0,0,500,200);
    QPixmap ICON("E:/Project/MyProject/photo/yes24.png");
    icon->setPixmap(ICON);
    icon->show();


    auto p = DATA.getPoiter(strSelect.toStdString());

    QLineEdit* addMadein = new QLineEdit(addDialog);
    addMadein->show();
    addMadein->setGeometry(200,200,200,30);
    QLabel* l1 = new QLabel(addDialog);
    l1->setGeometry(30,200,200,30);
    l1->setText("Tên sản xuất mới: ");
    l1->show();
    l1->setFont(QFont("Arial",10));

    QPushButton * btnOk = new QPushButton("Đồng ý",addDialog),
            *btnCancel = new QPushButton("Hủy",addDialog);
    btnOk->setGeometry(QRect(300,250,100,30));
    btnOk->show();
    btnCancel->show();
    btnCancel->setGeometry(QRect(400,250,100,30));

    connect(btnCancel,&QPushButton::clicked,[this]{addDialog->reject();});
    connect(btnOk,&QPushButton::clicked,[this]{

       if(QMessageBox::information(this,"Thông báo","Bạn có chắc chắn chưa?" , QMessageBox::No|QMessageBox::Yes) == QMessageBox::No)
       {
           return;
       }
       addDialog->accept();
    });
    if(addDialog->exec() == QDialog::Accepted)
    {
        DATA.add(addMadein->text().toStdString());
        save(DATA);
        print();
    }
}



