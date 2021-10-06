#include "informationuser.h"
#include "ui_informationuser.h"

informationUser::informationUser(std::string username,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::informationUser)
{
    ui->setupUi(this);
    Init(DATAuser);
    Username=username;
    alignContent = new QWidget(this);
    alignContent->setGeometry(QRect(330,0,1200,700));
    alignContent->setStyleSheet("background-color:white;");

    QWidget* leftWidget = new QWidget(this);

    leftWidget->setGeometry(0,0,300,300);

    allInformationUser = new QPushButton("Thông tin chung",leftWidget);
    managerAccout = new QPushButton("Quản lý tài khoản",leftWidget);
    purchaseHistory = new QPushButton("Lịch sử mua hàng",leftWidget);

    connect(allInformationUser,&QPushButton::clicked,this,&informationUser::clickAllInfo);
    connect(managerAccout,&QPushButton::clicked,this,&informationUser::clickManageInfo);
    connect(purchaseHistory,&QPushButton::clicked,this,&informationUser::clickHistoryPay);
    this->setStyleSheet("QPushButton:hover{border: 2px solid black; background-color:white; color:black; font: bold 14px;}");

    allInformationUser->setFont(QFont("Arial",10));
    managerAccout->setFont(QFont("Arial",10));
    purchaseHistory->setFont(QFont("Arial",10));


    QLabel* label1 = new QLabel(leftWidget);
    label1->setText("TRANG CÁ NHÂN");
    label1->setFont(QFont("Arial",20));



    QVBoxLayout* leftcontent = new QVBoxLayout(leftWidget);

    leftcontent->addWidget(label1);
    leftcontent->addWidget(allInformationUser);
    leftcontent->addWidget(managerAccout);
    leftcontent->addWidget(purchaseHistory);
    clickAllInfo();


}

void informationUser::clickManageInfo()
{
    qDeleteAll(alignContent->children());

    allInformationUser->setStyleSheet("background-color:#c8d6e5;");
    managerAccout->setStyleSheet("background-color: #2e86de;");
    purchaseHistory->setStyleSheet("background-color:#c8d6e5;");

    auto poiterNode = DATAuser.getpointer(Username);

    QLabel *l1 = new QLabel(alignContent),
            *l2 = new QLabel(alignContent),
            *l3 = new QLabel(alignContent),
            *l4 = new QLabel(alignContent),
            *avt= new QLabel(alignContent),
            *l5 = new QLabel(alignContent),
            *l6 = new QLabel(alignContent),
            *l7 = new QLabel(alignContent);

    QPixmap avatar("E:/Project/MyProject/photo/avatar.png");

    avt->setPixmap(avatar.scaled(200,200,Qt::KeepAspectRatio));
    l1->setText("Tên đăng nhập: ");

    l1->show();
    l2->setText("Hình ảnh: ");
    l2->show();
    l3->setText("Họ tên: ");
    l3->show();
    l4->setText("Mật khẩu");
    l4->show();
    l5->setText("Giới tính: ");
    l5->show();
    l6->setText("Số điện thoại: ");
    l6->show();
    l7->setText("Email: ");
    l7->show();

    QLineEdit *username = new QLineEdit(alignContent),
            *name = new QLineEdit(alignContent),
            *password = new QLineEdit(alignContent),
            *numberPhone = new QLineEdit(QString::fromStdString(poiterNode->phonenumber),alignContent),
            *email = new QLineEdit(QString::fromStdString(poiterNode->email),alignContent);

     QRadioButton* nam = new QRadioButton("Nam",alignContent), *nu = new QRadioButton("Nữ",alignContent);

    username->setText(QString::fromStdString(poiterNode->username));
    username->show();
    username->setEnabled(false);
    name->setText(QString::fromStdString(poiterNode->name));
    name->show();
    password->setText(QString::fromStdString(poiterNode->password));
    password->show();
    password->setEchoMode(QLineEdit::Password);
    password->setEnabled(false);
    numberPhone->show();
    email->show();
    nam->show();
    nu->show();

    l1->setGeometry(QRect(100,100,100,30));
    username->setGeometry(QRect(210,100,200,30));
    username->setFont(QFont("Arial",10));
    l2->setGeometry(QRect(100,140,100,30));
    avt->setGeometry(QRect(210,140,250,200));
    avt->show();

    l3->setGeometry(QRect(100,350,100,30));
    name->setGeometry(QRect(200,340,200,30));

    l4->setGeometry(QRect(100,380,100,30));
    password->setGeometry(QRect(200,380,200,30));
    l5->setGeometry(QRect(100,420,100,30));
    nam->setGeometry(QRect(200,420,50,30));
    nu->setGeometry(QRect(270,420,50,30));

    poiterNode->gender?nam->setChecked(true):nu->setChecked(true);
    l6->setGeometry(QRect(100,450,100,30));
    numberPhone->setGeometry(QRect(200,450,200,30));
    l7->setGeometry(QRect(100,490,100,30));
    email->setGeometry(QRect(200,490,200,30));
}

void informationUser::clickAllInfo()
{

    qDeleteAll(alignContent->children());

    managerAccout->setStyleSheet("background-color:#c8d6e5;");
    allInformationUser->setStyleSheet("background-color: #2e86de;");
    purchaseHistory->setStyleSheet("background-color:#c8d6e5;");

    auto poiterNode = DATAuser.getpointer(Username);
    QPixmap avatar("E:/Project/MyProject/photo/avatar.png");
    QLabel* photoAvatar = new QLabel(alignContent);
    photoAvatar->setPixmap(avatar.scaled(200,200,Qt::KeepAspectRatio));
    photoAvatar->show();
    photoAvatar->setGeometry(30,70,200,200);
    photoAvatar->setStyleSheet("border: 1px solid black; border-right:none;");
    QWidget* formWidget = new QWidget(alignContent);
    formWidget->setGeometry(230,70,400,200);
    formWidget->setStyleSheet("border: 1px solid black; border-left:none;");

    QLabel*name = new QLabel(this),
            *email = new QLabel(this),
            *dt = new QLabel(this),
            *gener = new QLabel(this);

    name->setText(QString::fromStdString(poiterNode->name));
    name->setFont(QFont("Arial",17));
    name->setStyleSheet("border:none;");


    email->setText("Email: "+QString::fromStdString(poiterNode->email));
    email->setFont(QFont("Arial",10));
    email->setStyleSheet("border:none;");
    email->setFont(QFont("Arial",10));

    dt->setText("Số điện thoại: "+QString::fromStdString(poiterNode->phonenumber));
    dt->setFont(QFont("Arial",10));
    dt->setStyleSheet("border:none;");
    dt->setFont(QFont("Arial",10));

    gener->setText("Giới tính: "+ QString( poiterNode->gender?"Nam":"Nữ"));
    gener->setStyleSheet("border:none;");
    gener->setFont(QFont("Arial",10));

    QFormLayout* formLayout = new QFormLayout(formWidget);
    formLayout->addRow(name);
    formLayout->addRow(email);
    formLayout->addRow(dt);
    formLayout->addRow(gener);
    formWidget->show();
    QPushButton* clickBtnEdit = new QPushButton("Chỉnh sửa",alignContent);
    clickBtnEdit->setGeometry(QRect(250,200,100,30));

    clickBtnEdit->setStyleSheet("background-color:#B2BABB;color:white;");
    clickBtnEdit->setFont(QFont("Arial",10));
    clickBtnEdit->show();

    connect(clickBtnEdit,&QPushButton::clicked,this,&informationUser::clickManageInfo);
}

void informationUser::clickHistoryPay()
{
     qDeleteAll(alignContent->children());
    managerAccout->setStyleSheet("background-color:#c8d6e5;");
    allInformationUser->setStyleSheet("background-color:#c8d6e5;");
    purchaseHistory->setStyleSheet("background-color:#2e86de;");

    lsmh *w = new lsmh(QString::fromStdString(Username),alignContent);
    w->show();

}

informationUser::~informationUser()
{
    delete ui;
}
