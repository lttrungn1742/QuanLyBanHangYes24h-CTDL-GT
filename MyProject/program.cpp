#include "program.h"
#include "ui_program.h"

program::program(std::string username,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::program)
{

    QWidget* backgroundWidget = new QWidget(this);
    backgroundWidget->setStyleSheet("background-color:#F4F6F7;");
    backgroundWidget->setGeometry(QRect(0,0,1980,1100));

    ui->setupUi(this);
    this->resize(1980,1000);
    init(DATApd);
    Username = username;

// begin
    topWidget = new QWidget(this);
    topWidget->setGeometry(QRect(0,28,1920,250));
    topWidget->setStyleSheet("background-color:white;");

    QPixmap photo0("E:/Project/MyProject/photo/header.png");
    QLabel* header = new QLabel(topWidget);
    header->setGeometry(QRect(0,0,1980,100));
    header->setPixmap(photo0.scaled(1920,100));
    header->show();

    QPixmap photo2("E:/Project/MyProject/photo/header3.png"); // --------- ????? ------ //
    QLabel* header2 = new QLabel(topWidget);
    header2->setGeometry(QRect(0,100,1920,150));
    header2->setPixmap(photo2);

    QPushButton* infoUser = new QPushButton(QIcon("E:\\Project\\MyProject\\photo\\user.png"),QString(""),topWidget);
    infoUser->setGeometry(QRect(1560,130,50,50));
    infoUser->setIconSize(QSize(48,48));
    infoUser->setCursor(Qt::PointingHandCursor);
    connect(infoUser,&QPushButton::clicked,this,&program::clickInfo);

    QLabel* userName_label = new QLabel(topWidget);
    userName_label->setText(QString::fromStdString(username));
    userName_label->setFont(QFont("Arial",14));
    userName_label->setGeometry(QRect(1615,150,120,30));

    QPushButton* cartBtn = new QPushButton(QIcon("E:\\Project\\MyProject\\photo\\iconCart.png"),"",topWidget);
    cartBtn->setGeometry(QRect(1733,127,50,50));
    cartBtn->setIconSize(QSize(50,50));
    cartBtn->setCursor(Qt::PointingHandCursor);
    connect(cartBtn,&QPushButton::clicked,this,&program::clickCart);


    QPushButton* btnLogOut = new QPushButton(topWidget);
    btnLogOut->setGeometry(QRect(1890,100,30,30));
    connect(btnLogOut,&QPushButton::clicked,this,&program::clickLogOut);
    btnLogOut->setStyleSheet("border:none;");
    btnLogOut->setIcon(QIcon("E:/Project/MyProject/photo/dangxuat.png"));
    btnLogOut->setIconSize(QSize(30,30));
    btnLogOut->setCursor(Qt::PointingHandCursor);


    ui->scrollArea->setGeometry(QRect(300,270,1620,690));
    ui->scrollArea->setStyleSheet("border:none;");
    ui->scrollAreaWidgetContents ->setStyleSheet("background-color:#F7F9F9;");
    ui->scrollArea->show();
    this->setStyleSheet("QPushButton:hover:!pressed { border: 1px solid #5DADE2; background-color:#D6EAF8;}");

    // widget ở chính giữa
            alignContent= new QWidget(this);
            alignContent->hide();
            alignContent->setStyleSheet("background-color:#F4F6F7;");
            alignContent->setGeometry(QRect(0,28,1920,9000));

            QWidget* tempWidget = new QWidget(alignContent);
            tempWidget->setObjectName("exist");

            QWidget* topOfAlign = new QWidget(alignContent);
            topOfAlign->setGeometry(0,0,1920,70);
            topOfAlign->setStyleSheet("background-color:white;");
            topOfAlign->show();

            QPushButton* manageUser = new QPushButton(QIcon("E:\\Project\\MyProject\\photo\\quanlynguoidung.png"),"",alignContent);
            manageUser->setGeometry(QRect(800,5,65,65));
            manageUser->setIconSize(QSize(65,65));
            manageUser->setStyleSheet("background-color:white;");
            connect(manageUser,&QPushButton::clicked,this,&program::clickManagerUser);

            QPushButton* manageProduct = new QPushButton(QIcon("E:\\Project\\MyProject\\photo\\quanlysanpham.png"),"",alignContent);
            manageProduct->setGeometry(QRect(865,5,65,65));
            manageProduct->setIconSize(QSize(65,65));
            manageProduct->setStyleSheet("background-color:white;");
            connect(manageProduct,&QPushButton::clicked,this,&program::clickManagerProduct);

            QPushButton* managePurchaseHistory = new QPushButton(QIcon("E:\\Project\\MyProject\\photo\\quanlylichsu.png"),"",alignContent);
            managePurchaseHistory->setGeometry(QRect(930,5,65,65));
            managePurchaseHistory->setIconSize(QSize(65,65));
            managePurchaseHistory->setStyleSheet("background-color:white;");
            connect(managePurchaseHistory,&QPushButton::clicked,this,&program::clickManagergw);

            QPushButton* btnLogOutTop = new QPushButton(alignContent);
            btnLogOutTop->setGeometry(QRect(1760,0,50,50));
            connect(btnLogOutTop,&QPushButton::clicked,this,&program::clickLogOut);
            btnLogOutTop->setStyleSheet("border:none; background-color:white;");
            btnLogOutTop->setIcon(QIcon("E:/Project/MyProject/photo/dangxuat.png"));
            btnLogOutTop->setIconSize(QSize(50,50));
            btnLogOutTop->setCursor(Qt::PointingHandCursor);
            btnLogOutTop->show();

            QPushButton* infoUserTop = new QPushButton(QIcon("E:\\Project\\MyProject\\photo\\user.png"),QString(""),alignContent);
            infoUserTop->setGeometry(QRect(1560,0,50,50));
            infoUserTop->setIconSize(QSize(48,48));
            infoUserTop->setCursor(Qt::PointingHandCursor);
            connect(infoUserTop,&QPushButton::clicked,this,&program::clickInfo);
            infoUserTop->show();

            QLabel* label1Top = new QLabel(alignContent);
            label1Top->setText("Xin Chào");
            label1Top->setFont(QFont("Arial",11));
            label1Top->setStyleSheet("background-color:white;");
            label1Top->setGeometry(QRect(1615,0,100,20));
            label1Top->show();

            QLabel* userName_labelTop = new QLabel(alignContent);
            userName_labelTop->setText(QString::fromStdString(username));
            userName_labelTop->setFont(QFont("Arial",14));
            userName_labelTop->setStyleSheet("background-color:white;");
            userName_labelTop->setGeometry(QRect(1615,20,120,30));
            userName_labelTop->show();

    connect(ui->managerUser,&QAction::triggered,this,&program::clickManagerUser);
    connect(ui->managerProduct,&QAction::triggered,this,&program::clickManagerProduct);
    connect(ui->informationUser,&QAction::triggered,this,&program::clickInfo);
    connect(ui->editInformation,&QAction::triggered,this,&program::clickEditInfo);
    connect(ui->logOut,&QAction::triggered,this,&program::clickLogOut);
    connect(ui->managerPH,&QAction::triggered,this,&program::clickManagergw);
    connect(ui->purchaseHistory,&QAction::triggered,this,&program::clickHistoryPay);

//begin
    // widget bên trá hiển thị các danh phân loại
    leftContent = new QWidget(this);
    leftContent->setGeometry(60,280,220,700);
    leftContent->setStyleSheet("background-color:#BDC3C7; ");
    leftContent->hide();

    // nút button tất cả danh mục
    allcate = new QPushButton(QIcon("E:\\Project\\MyProject\\photo\\allcate.png"),"",this);
    allcate->setStyleSheet(" border:none; ");
    allcate->setIconSize(QSize(400,40));
    allcate->setCursor(Qt::PointingHandCursor);
    connect(allcate,&QPushButton::clicked,this,&program::printCate);
    allcate->setGeometry(QRect(80,225,230,40));

    // những danh mục cho lựa chọn
    menu = new QWidget(this);
    menu->show();

    QSignalMapper* mapCateBtn = new QSignalMapper(this);

    int row = 0, col = 0;
    for (auto p = DATApd.listCate.getHead() ;p!=NULL;p=p->next) {
        QWidget* element = new QWidget(menu);
        element->show();
        element->setGeometry(QRect(100+ 201*col,10+ 201*row,200,200));
        element->setStyleSheet(" border:1px solid black; background-color:white;");

        QPushButton* cateBtn = new QPushButton(QIcon(QString("E:/Project/MyProject/iconCategory/%1.png").arg(QString::number(p->id))),"",element);
        cateBtn->setFont(QFont("Arial",16));
        connect(cateBtn,SIGNAL(clicked()),mapCateBtn,SLOT(map()));
        mapCateBtn->setMapping(cateBtn,QString::fromStdString(p->name));
        cateBtn->setGeometry(0,0,200,200);
        cateBtn->setStyleSheet("border: 2px solid none;");
        cateBtn->setCursor(Qt::PointingHandCursor);
        cateBtn->setIconSize(QSize(400,100));

        QTextEdit* name = new QTextEdit(QString::fromStdString(p->name),element);
        name->setFont(QFont("Arial",9));
        name->show();
        name->setStyleSheet("border:none; background-color:white; color:black;");
        name->setGeometry(10,140,170,40);
        name->setEnabled(false);
        col++;
        if(col==6)
         {
             row ++;
             col = 0;
         }
    }
    menu->setGeometry(QRect(300,300,1550,20+ 210*(row+1)));
    connect(mapCateBtn,&QSignalMapper::mappedString,this,&program::clickCate);
//end

    viewProduct = new QWidget(this);
    viewProduct->setGeometry(270,300,1550,700);
    viewProduct->hide();

    viewCart = new QWidget(this);
    viewCart->setGeometry(0,28,1920,972);
    viewCart->hide();
    QWidget* tempCart = new QWidget(viewCart);
    tempCart->setObjectName("cart");
    QLabel* headerCart = new QLabel(viewCart);
    QPixmap HEADERcart("E:/Project/MyProject/photo/headerCart.png");
    headerCart->setPixmap(HEADERcart);
    headerCart->setStyleSheet("border: 1px solid black;");
    QPushButton* BackFromCart = new QPushButton(QIcon("E:/Project/MyProject/photo/cartBackCate.png"),"",viewCart);
    BackFromCart->setGeometry(QRect(1610,80,220,40));
    BackFromCart->setIconSize(QSize(400,40));
    BackFromCart->setStyleSheet("border:none;");
    BackFromCart->setCursor(Qt::PointingHandCursor);
    connect(BackFromCart,&QPushButton::clicked,this,&program::printCate);

    viewPay = new QWidget(this);
    viewPay->setGeometry(QRect(0,28,1920,972));
    viewPay->hide();
    QPixmap photoPay("E:/Project/MyProject/photo/headerPay.png");
    QLabel* headerPay = new QLabel(viewPay);
    headerPay->setGeometry(QRect(0,0,1920,120));
    headerPay->setPixmap(photoPay);
    headerPay->show();

    QPushButton* iconHomeViewPay = new QPushButton(QIcon("E:/Project/MyProject/photo/iconHomeYes24.png"),"",viewPay);
    iconHomeViewPay->setGeometry(QRect(160,12,210,80));
    iconHomeViewPay->show();
    iconHomeViewPay->setCursor(Qt::PointingHandCursor);
    iconHomeViewPay->setIconSize(QSize(600,150));
    iconHomeViewPay->setStyleSheet("border:none;background-color:white;");


    QWidget* tempPay = new QWidget(viewPay);
    tempPay->setObjectName("PAY");
}

void program::clickManagergw()
{
    viewPay->hide();
    viewCart->hide();
    qDeleteAll(viewProduct->children());
    viewProduct->hide();
    allcate->hide();

    menu->hide();

    QWidget* removeIt = alignContent->findChild<QWidget*>("exist");
    delete (removeIt);

    managerwg *w = new managerwg(alignContent);
    w->setObjectName("exist");
    w->show();
    w->setStyleSheet("background-color:white;");
    w->setGeometry(QRect(250,80,1700,900));
    ui->scrollArea->hide();
    alignContent->show();
}

void program::clickPay(QList<QString> listProductBuy)
{

    QWidget* removeIT = viewPay->findChild<QWidget*>("PAY");
    delete (removeIT);

    payWidget* w = new payWidget(Username,listProductBuy,viewPay);
    w->setGeometry(QRect(0,120,1920,880));
    w->show();
    w->setObjectName("PAY");
    viewPay->show();

    connect(w,&payWidget::payComplete,this,&program::printCate);

}

void program::clickCart()
{
    viewPay->hide();

    alignContent->hide();
    menu->hide();
    ui->scrollArea->hide();
    leftContent->hide();
    viewProduct->hide();
    topWidget->hide();

    viewCart->show();

    QWidget* removeIT = viewCart->findChild<QWidget*>("cart");
    delete (removeIT);


    cartWidget* w = new cartWidget(QString::fromStdString(Username),viewCart);
    w->show();
    w->setGeometry(QRect(0,150,1920,850));
    w->setObjectName("cart");

    connect(w,&cartWidget::continuePay,this,&program::clickPay);

}

// hàm đăng xuất
void program::clickLogOut()
{
    signin * w = new signin(NULL);
    this->close();
    w->show();
}

// hàm chỉnh sửa thông tin người dùng
void program::clickEditInfo()
{
    viewPay->hide();
    viewCart->hide();
    allcate->hide();
    qDeleteAll(ui->scrollAreaWidgetContents->children());
    viewProduct->hide();
    qDeleteAll(viewProduct->children());
    menu->hide();
    informationUser* w = new informationUser(Username,ui->scrollAreaWidgetContents);
    w->clickManageInfo();
    w->show();
    ui->scrollArea->show();
    alignContent->hide();
}

// hàm quản lý sản phẩm
void program::clickManagerProduct()
{
    viewPay->hide();
    viewCart->hide();
    qDeleteAll(viewProduct->children());
    viewProduct->hide();
    allcate->hide();

    menu->hide();

    QWidget* removeIt = alignContent->findChild<QWidget*>("exist");
    delete (removeIt);

    managerPd* w = new managerPd(alignContent);
    w->setObjectName("exist");

    w->show();
    w->setGeometry(150,80,1700,900);
    w->setStyleSheet("background-color:white;");
    ui->scrollArea->hide();
    alignContent->show();
}

//hàm quản lý người dùng
void program::clickManagerUser()
{
    viewPay->hide();
    viewCart->hide();
    qDeleteAll(leftContent->children());
    leftContent->hide();
    allcate->hide();
    viewProduct->hide();
    qDeleteAll(viewProduct->children());
    menu->hide();

    QWidget* removeIt = alignContent->findChild<QWidget*>("exist");
    delete (removeIt);

    qt_user* w = new qt_user(alignContent);
    w->setGeometry(150,80,1700,900);
    w->setObjectName("exist");
    alignContent->show();
    w->show();
    w->setStyleSheet("background-color:white;");
    ui->scrollArea->hide();
}

// hàm  xuất thông tin lịch sử mua hàng
void program::clickHistoryPay()
{
    allcate->show();
    viewPay->hide();
    qDeleteAll(leftContent->children());
    leftContent->hide();
    qDeleteAll(viewProduct->children());
    viewProduct->hide();
    menu->hide();
    alignContent->hide();
    ui->scrollArea->show();
    informationUser* newWindows = new informationUser(Username,ui->scrollAreaWidgetContents);
    newWindows->clickHistoryPay();
    newWindows->show();
//    newWindows->setGeometry(QRect(0,0,1620,800));
}

//hàm bấm vào xem thông tin người dùng
void program::clickInfo()
{

    allcate->show();
    viewPay->hide();
    qDeleteAll(leftContent->children());
    leftContent->hide();
    qDeleteAll(viewProduct->children());
    viewProduct->hide();
    menu->hide();
    alignContent->hide();
    ui->scrollArea->show();
    informationUser* newWindows = new informationUser(Username,ui->scrollAreaWidgetContents);
    newWindows->show();

}

// hàm bấm sản phẩm
void program::clickProduct(QString id)
{
    allcate->show();
    viewPay->hide();
    alignContent->hide();
    ui->scrollArea->hide();
    leftContent->hide();

    viewDetailProduct* newWindows = new viewDetailProduct(Username,id.toStdString(),viewProduct);
    viewProduct->show();
    newWindows->show();

    connect(newWindows,&viewDetailProduct::clickedAddCart,this,&program::clickCart);
    connect(newWindows,&viewDetailProduct::clickedHome,[this]{
       printCate();

    });
    connect(newWindows,&viewDetailProduct::clickedKind,this,&program::clickKind);
    connect(newWindows,&viewDetailProduct::clickedCategory,this,&program::clickCate);
}

// hàm click vào nút  tất cả danh mục
void program::printCate()
{
    allcate->show();
    viewPay->hide();
    topWidget->show();
    ui->scrollArea->show();
    viewCart->hide();
    viewProduct->hide();
    qDeleteAll(viewProduct->children());
    qDeleteAll(leftContent->children());
    leftContent->hide();
    alignContent->hide();
    qDeleteAll(ui->scrollAreaWidgetContents->children());

    menu->show();
}

// hàm click vào phân loại sản phẩm
void program::clickKind(QString name)
{
    allcate->show();
    qDeleteAll(ui->scrollAreaWidgetContents->children());
    ui->scrollArea->show();
    menu->hide();
    alignContent->hide();

    QGridLayout*  alignBtn = new QGridLayout(ui->scrollAreaWidgetContents);

    alignBtn->setSpacing(50);
    int row = 0, col = 0;
    QSignalMapper* mapProduct = new QSignalMapper(this);

    for(auto p = DATApd.getHead();p!=NULL;p=p->next)
    {
        if(QString::fromStdString( p->kind)==name)
        {
            QWidget* pd = new QWidget(this);

            QVBoxLayout* contentpd = new QVBoxLayout(pd);
            pd->setStyleSheet("background-color:white;");

            QString file = "E:/Project/MyProject/photoProducts/"+QString::fromStdString(p->id)+".png";
            if(!QFile::exists(file))
            {
                file = "E:/Project/MyProject/photo/imageNotFound.png";
            }
            QPixmap ptpd(file);
            QPushButton *photopd = new QPushButton(QIcon(ptpd),QString(""),pd);
            photopd->setIconSize(QSize(250,250));
            photopd->setStyleSheet("border:none;");
            photopd->setCursor(Qt::OpenHandCursor);
            connect(photopd,SIGNAL(clicked()),mapProduct,SLOT(map()));
            mapProduct->setMapping(photopd, QString::fromStdString(p->id));

            QLabel* brand = new QLabel(pd);
            brand->setText(QString::fromStdString(p->brand));
            brand->setFont(QFont("Arial",14));
            brand->setStyleSheet("border:none;");

            QTextEdit* namepd = new QTextEdit(pd);
            namepd->setText(QString::fromStdString(p->name));
            namepd->setFont(QFont("Arial",11));
            namepd->setStyleSheet("border:none");
            namepd->setEnabled(false);

            QLabel* pricepd = new QLabel(pd);
            pricepd->setFont(QFont("Arial",20));
            pricepd->setStyleSheet("color:red;border:none;");

            pricepd->setText(QLocale(QLocale::English).toString(QString::fromStdString(p->price).toInt())+"đ");
            contentpd->addWidget(photopd);
            contentpd->addWidget(brand);
            contentpd->addWidget(namepd);
            contentpd->addWidget(pricepd);

            alignBtn->addWidget(pd,row,col);
            col++;
            if(col==4)
              {
                  col = 0;
                  alignBtn->setRowMinimumHeight(row,500);
                  row ++;
              }
        }
    }
    connect(mapProduct,&QSignalMapper::mappedString,this,&program::clickProduct);
}

// hàm click vào danh mục hiển thị ra sản phẩm trong danh mục
void program::clickCate(QString name)
{

   qDeleteAll(ui->scrollAreaWidgetContents->children());
   ui->scrollArea->show();
   menu->hide();
   alignContent->hide();

   QGridLayout*  alignBtn = new QGridLayout(ui->scrollAreaWidgetContents);

   alignBtn->setSpacing(50);
   int row = 0, col = 0;
   QSignalMapper* mapProduct = new QSignalMapper(this);
    // hiển thị sản phẩm
   for(auto p = DATApd.getHead();p!=NULL;p=p->next)
   {
       if(QString::fromStdString( p->category)==name)
       {
           QWidget* pd = new QWidget(this);
           QVBoxLayout* contentpd = new QVBoxLayout(pd);
           pd->setStyleSheet("background-color:white;");

           QString file = "E:/Project/MyProject/photoProducts/"+QString::fromStdString(p->id)+".png";
           if(!QFile::exists(file))
           {
               file = "E:/Project/MyProject/photo/imageNotFound.png";
           }
           QPixmap ptpd(file);
           QPushButton *photopd = new QPushButton(QIcon(ptpd),QString(""),pd);
           photopd->setIconSize(QSize(250,250));
           photopd->setStyleSheet("border:none;");
           photopd->setCursor(Qt::OpenHandCursor);
           connect(photopd,SIGNAL(clicked()),mapProduct,SLOT(map()));
           mapProduct->setMapping(photopd, QString::fromStdString(p->id));


           QLabel* brand = new QLabel(pd);
           brand->setText(QString::fromStdString(p->brand));
           brand->setFont(QFont("Arial",14));
           brand->setStyleSheet("border:none;");

           QTextEdit* namepd = new QTextEdit(pd);
           namepd->setText(QString::fromStdString(p->name));
           namepd->setFont(QFont("Arial",11));
           namepd->setStyleSheet("border:none; ");
           namepd->setEnabled(false);

           QLabel* pricepd = new QLabel(pd);
           pricepd->setFont(QFont("Arial",20));
           pricepd->setStyleSheet("color:red;border:none;");

           pricepd->setText(QLocale(QLocale::English).toString(QString::fromStdString(p->price).toInt())+"đ");
           contentpd->addWidget(photopd);
           contentpd->addWidget(brand);
           contentpd->addWidget(namepd);
           contentpd->addWidget(pricepd);

           alignBtn->addWidget(pd,row,col);

           col++;
           if(col==4)
             {
                 col = 0;
                 alignBtn->setRowMinimumHeight(row,500);
                 row ++;
             }
       }
   }

   connect(mapProduct,&QSignalMapper::mappedString,this,&program::clickProduct);

   qDeleteAll(leftContent->children());
   leftContent->show();

    QLabel* labelCate = new QLabel(leftContent);
    labelCate->setText(name);
    labelCate->setGeometry(QRect(5,5,200,30));
    labelCate->setFont(QFont("Arial",14));
    labelCate->setStyleSheet("color:black; border:none;");
    labelCate->show();

    int idCate = DATApd.listCate.getCode(name.toStdString());


    QSignalMapper* mapKind = new QSignalMapper(this);

   int dem = 1;

   for (auto p = DATApd.listKind.getHead();p!=NULL;p=p->next) {
       if(p->idCate == idCate)
       {
           QPushButton* btnKind = new QPushButton(QIcon("E:/Project/MyProject/photo/daudong.png"),QString::fromStdString(p->name),leftContent);
           btnKind->setStyleSheet("border:none");
           btnKind->setFont(QFont("Arial",9));
           btnKind->setCursor(Qt::OpenHandCursor);
           btnKind->setGeometry(QRect(10,40*dem,200,30));
           btnKind->setStyleSheet("Text-align:left; border:none;");
           dem++;
           btnKind->show();
           btnKind->setIconSize(QSize(10,10));
           connect(btnKind,SIGNAL(clicked()),mapKind,SLOT(map()));
           mapKind->setMapping(btnKind,QString::fromStdString(p->name));

       }
   }

   connect(mapKind,&QSignalMapper::mappedString,this,&program::clickKind);
}



program::~program()
{
    delete ui;
}
