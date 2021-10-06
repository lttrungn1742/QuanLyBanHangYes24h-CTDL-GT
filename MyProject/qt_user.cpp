#include "qt_user.h"
#include "ui_qt_user.h"

qt_user::qt_user(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qt_user)
{
    Init(dataUser);
    ui->setupUi(this);
    this->resize(1920, 1000);
    ui->table->setGeometry(200,60,1200,800);
    print();
    find = new QLineEdit(this);
    find->setGeometry(QRect(500,20,500,30));
    QLabel* labelText = new QLabel(this);
    labelText->setText("Tìm kiếm");
    labelText->setGeometry(QRect(370,20,130,30));
    labelText->setFont(QFont("Arial",17));
    connect(find,&QLineEdit::textChanged,this,&qt_user::on_find_textChanged);
    ListItem = {};
}

void qt_user::on_find_textChanged(const QString &arg1)
{
    foreach(QTableWidgetItem * rowptr, ListItem)
    {
        rowptr->setBackgroundColor(QColor("white"));
    }
    if(arg1 == "") return;
    ListItem = ui->table->findItems(arg1, Qt::MatchEndsWith);

    foreach(QTableWidgetItem* rowptr,ListItem)
    {
        rowptr->setBackgroundColor(QColor("yellow"));
    }
}

void qt_user::print()
{
    ui->table->clear();
    ui->table->setRowCount(dataUser.getRows());
    ui->table->setColumnCount(7);
    ui->table->setColumnWidth(0,250);
    QTableWidgetItem* col0 = new QTableWidgetItem("Tên");
    QTableWidgetItem* col1 = new QTableWidgetItem("Tên đăng nhập");
    QTableWidgetItem* col2 = new QTableWidgetItem("Giới tính");
    QTableWidgetItem* col3 = new QTableWidgetItem("Số điện thoại");
    QTableWidgetItem* col4 = new QTableWidgetItem("Email");
    QTableWidgetItem* col5 = new QTableWidgetItem("Cấp bậc");
    QTableWidgetItem* col6 = new QTableWidgetItem("Trạng thái");


    ui->table->setHorizontalHeaderItem(0, col0);
    ui->table->setHorizontalHeaderItem(1, col1);
    ui->table->setHorizontalHeaderItem(2, col2);
    ui->table->setHorizontalHeaderItem(3, col3);
    ui->table->setHorizontalHeaderItem(4, col4);
    ui->table->setHorizontalHeaderItem(5, col5);
    ui->table->setHorizontalHeaderItem(6, col6);

    int i = 0;
    for (usr* p = dataUser.gethead(); p != NULL; p = p->right)
    {
            QTableWidgetItem* Item0 = new QTableWidgetItem(QString::fromStdString(p->name));
            QTableWidgetItem* Item1 = new QTableWidgetItem(QString::fromStdString(p->username));
            QTableWidgetItem* Item2 = new QTableWidgetItem(QString(p->gender == 1 ? "Nam" : "Nữ"));
            QTableWidgetItem* Item3 = new QTableWidgetItem(QString::fromStdString(p->phonenumber));
            QTableWidgetItem* Item4 = new QTableWidgetItem(QString::fromStdString(p->email));
            QTableWidgetItem* Item5 = new QTableWidgetItem(QString::fromStdString((p->rights==4 ? "Admin":
                                                                                                  p->rights==3? "Chuyên viên quản lý\ndữ liệu lịch sử mua bán":
                                                                                                         p->rights==2? "Chuyên viên quản lý\ndữ liệu người dùng":
                                                                                                                    p->rights==1? "Chuyên viên quản lý\ndữ liệu sản phẩm" : "Khách hàng")));
            QTableWidgetItem* Item6 = new QTableWidgetItem(QString(p->enable ? "Hoạt động" : "Chặn"));
            // 0 là khách hàng, người sử dụng nghiệp vụ quản lý người dùng, người sử dụng nghiệp vụ quản lý sản phẩm
            // là những người đăng tải sản phẩm lên hệ thống , người sử dụng nv quản lý cái lịch sử mua hàng (in ra báo cáo)

            int j = 0;
            ui->table->setItem(i, j, Item0);	j++;
            ui->table->setItem(i, j, Item1);	j++;
            ui->table->setItem(i, j, Item2);	j++;
            ui->table->setItem(i, j, Item3);	j++;
            ui->table->setItem(i, j, Item4);	j++;
            ui->table->setItem(i, j, Item5);	j++;
            ui->table->setItem(i, j, Item6);    i++;


            if(p->rights==4)
            {
                Item0->setBackgroundColor("red");
                Item1->setBackgroundColor("red");
                Item2->setBackgroundColor("red");
                Item3->setBackgroundColor("red");
                Item4->setBackgroundColor("red");
                Item5->setBackgroundColor("red");

                Item6->setBackgroundColor("red");
            }
            else if(p->rights==3)
            {
                Item0->setBackgroundColor("#B7F91F");
                Item1->setBackgroundColor("#B7F91F");
                Item2->setBackgroundColor("#B7F91F");
                Item3->setBackgroundColor("#B7F91F");
                Item4->setBackgroundColor("#B7F91F");
                Item5->setBackgroundColor("#B7F91F");

                Item6->setBackgroundColor("#B7F91F");
            }
            else if(p->rights ==2)
            {
                Item0->setBackgroundColor("#1FF938");
                Item1->setBackgroundColor("#1FF938");
                Item2->setBackgroundColor("#1FF938");
                Item3->setBackgroundColor("#1FF938");
                Item4->setBackgroundColor("#1FF938");
                Item5->setBackgroundColor("#1FF938");

                Item6->setBackgroundColor("#1FF938");
            }
            else if(p->rights == 1)
            {
                Item0->setBackgroundColor("#0F9CE9");
                Item1->setBackgroundColor("#0F9CE9");
                Item2->setBackgroundColor("#0F9CE9");
                Item3->setBackgroundColor("#0F9CE9");
                Item4->setBackgroundColor("#0F9CE9");
                Item5->setBackgroundColor("#0F9CE9");

                Item6->setBackgroundColor("#0F9CE9");
            }
    }
}

qt_user::~qt_user()
{
    delete ui;
}

void qt_user::refresh()
{
    ListItem.clear();
    dataUser.~USERS();
    Init(dataUser);
    print();
}

void qt_user::on_table_cellDoubleClicked(int row, int column)
{
    std::string id = ui->table->item(row, 1)->text().toStdString();
    userdetail* newWindows = new userdetail(id,NULL);
    newWindows->show();

    if(newWindows->exec()==userdetail::Accepted)
        refresh();
}
