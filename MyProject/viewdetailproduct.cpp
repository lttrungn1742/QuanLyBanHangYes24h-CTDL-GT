#include "viewdetailproduct.h"
#include "ui_viewdetailproduct.h"

viewDetailProduct::viewDetailProduct(std::string username,std::string id,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewDetailProduct)
{
    QWidget* newWindows = new QWidget(this);
    newWindows->setGeometry(0,0,1980,1000);
    newWindows->setStyleSheet("background-color:white;");

    init(DATA);
    init(DATAcart,username);
    Username = username;
    ui->setupUi(this);




    QPixmap iconTuiXach("E:/Project/MyProject/photo/tuixach.png");
    ui->iconTuiXach->setPixmap(iconTuiXach.scaled(50,50,Qt::KeepAspectRatio));
    QPixmap chungNhan("E:/Project/MyProject/photo/chungnhan.png");
    ui->chungNhan->setPixmap(chungNhan.scaled(150,150,Qt::KeepAspectRatio));

    ui->addCart->setStyleSheet("background-color:#ff3838;");
    ui->addCart->setFont(QFont("Arial",13));
    ui->addCart->setIcon(QIcon("E:/Project/MyProject/photo/giohang.png"));
    ui->addCart->setIconSize(QSize(50,50));
    connect(ui->addCart,&QPushButton::clicked,this,&viewDetailProduct::clickAddCart);


    ui->buyNow->setStyleSheet("background-color:#17c0eb;");
    ui->buyNow->setFont(QFont("Arial",13));
    ui->buyNow->setIcon(QIcon("E:/Project/MyProject/photo/tich.png"));
    ui->buyNow->setIconSize(QSize(50,50));
    connect(ui->buyNow,&QPushButton::clicked,this,&viewDetailProduct::clickPayNow);


    auto p = DATA.getPoiter(id);

    QString filePhoto = QString("E:\\Project\\MyProject\\photoProducts\\%1.png").arg(QString::fromStdString(p->id));
    if(!QFile::exists(filePhoto)) filePhoto = "E:/Project/MyProject/photo/imageNotFound.png";

    QPixmap iconKho("E:/Project/MyProject/photo/nhacungcap.png"),
            conheo("E:/Project/MyProject/photo/conheo.png"),
            help("E:/Project/MyProject/photo/hoidap.png"),
            xetai("E:/Project/MyProject/photo/donvivanchuyen.png"),
            photoOfProduct(filePhoto);

    ui->icon->setPixmap(photoOfProduct.scaled(750,520,Qt::KeepAspectRatio));

    ui->name->setText(  QString::fromStdString(p->name));
    ui->name->setFont(QFont("Arial",15));
    ui->name->setEnabled(false);
    ui->name->setStyleSheet("border:none; color: #4b4b4b;background-color:white;");

    ui->price->setText(QLocale(QLocale::English).toString(QString::fromStdString(p->price).toInt())+"đ");
    ui->price->setFont(QFont("Arial",30));
    ui->price->setStyleSheet("color:#E74C3C;");


    ui->brand->setText(QString::fromStdString(p->brand));
    ui->brand->setFont(QFont("Arial",15));
    ui->brand->setStyleSheet("color:#17c0eb;");

    ui->idProduct->setText(QString::fromStdString(p->id));
    ui->idProduct->setStyleSheet(" color:#3498DB;");
    ui->idProduct->setFont(QFont("Arial",17));
    ui->quanity->setFont(QFont("Arial",13));

    ui->madein->setText(QString::fromStdString(p->madein));
    ui->madein->setStyleSheet("color:#2E86C1;");
    ui->madein->setFont(QFont("Arial",15));

    ui->kho->setPixmap(iconKho.scaled(50,50,Qt::KeepAspectRatio));
    ui->conheo->setPixmap(conheo.scaled(50,50,Qt::KeepAspectRatio));
    ui->help->setPixmap(help.scaled(50,50,Qt::KeepAspectRatio));
    ui->iconXetai->setPixmap(xetai.scaled(50,50,Qt::KeepAspectRatio));


    ui->home->setStyleSheet("border:none;");
    ui->home->setFont(QFont("Arial",13));
    ui->category->setText(QString::fromStdString(p->category));
    ui->category->setFont(QFont("Arial",13));
    ui->category->setStyleSheet("border:none;");
    ui->kind->setText(QString::fromStdString(p->kind));
    ui->kind->setFont(QFont("Arial",13));
    ui->kind->setStyleSheet("border:none;");

    strCate = QString::fromStdString(p->category);
    strKind = QString::fromStdString(p->kind);

    connect(ui->home,&QPushButton::clicked,this,&viewDetailProduct::clickHome);
    connect(ui->category,&QPushButton::clicked,this,&viewDetailProduct::clickCategory);
    connect(ui->kind,&QPushButton::clicked,this,&viewDetailProduct::clickKind);

}

void viewDetailProduct::clickCategory()
{
    emit clickedCategory(strCate);
    this->close();
}

void viewDetailProduct::clickKind()
{
    emit clickedKind(strKind);
    this->close();
}

void viewDetailProduct::clickHome()
{
    emit clickedHome();
    this->close();
}


void viewDetailProduct::clickAddCart()
{
    if(ui->quanity->text().toInt() <= 0)
    {

            QMessageBox::information(this,"Thông báo", "Thêm vào giỏ hàng thất bại, Vui lòng thử lại sau.", "Đóng");

            ui->quanity->setText("1");
            return;
    }
    for(int i = 0;i< ui->quanity->text().length();++i)
    {
        if(!(ui->quanity->text()[i] >= '0' && ui->quanity->text()[i] <= '9'))
        {
            QMessageBox::information(this,"Thông báo", "Thêm vào giỏ hàng thất bại, Vui lòng thử lại sau.", "Đóng");

            ui->quanity->setText("1");
            return;
        }
    }
   DATAcart.add(ui->idProduct->text().toStdString(),ui->quanity->text().toLongLong());
   save(DATAcart,Username);
   int ret = QMessageBox::information(this,"Thông báo","Thêm vào giỏ hàng thành công","Tiếp tục mua sắm","Thanh toán");
   if(ret == 1)
   {
       emit clickedAddCart();
       this->close();
   }
}

void viewDetailProduct::clickPayNow()
{
    if(ui->quanity->text().toInt() <= 0)
    {

            QMessageBox::information(this,"Thông báo", "Thêm vào giỏ hàng thất bại, Vui lòng thử lại sau.", "Đóng");

            ui->quanity->setText("1");
            return;
    }
    for(int i = 0;i< ui->quanity->text().length();++i)
    {
        if(!(ui->quanity->text()[i] >= '0' && ui->quanity->text()[i] <= '9'))
        {
            QMessageBox::information(this,"Thông báo", "Thêm vào giỏ hàng thất bại, Vui lòng thử lại sau.", "Đóng");

            ui->quanity->setText("1");
            return;
        }
    }
   DATAcart.add(ui->idProduct->text().toStdString(),ui->quanity->text().toLongLong());
   save(DATAcart,Username);
   emit clickedAddCart();
   this->close();
}

viewDetailProduct::~viewDetailProduct()
{
    delete ui;
}
