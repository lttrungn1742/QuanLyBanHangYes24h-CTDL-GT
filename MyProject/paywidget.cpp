#include "paywidget.h"
#include "ui_paywidget.h"

payWidget::~payWidget()
{
    delete ui;
}

payWidget::payWidget(std::string username ,QList<QString> idProduct,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::payWidget)
{

    initphlist(DATAph);
    init(DATAcart,username);
    init(DATAproduct);
    Username = username;
    listProduct = idProduct;

    qlonglong sumAmount = 0;
    for (auto it = idProduct.begin(); it!=idProduct.end() ;++it) {
        QString temp = *it;

       qlonglong tempAmount = std::stoi(DATAproduct.getPoiter(temp.toStdString())->price) * DATAcart.getPoiter(temp.toStdString())->quanity;
       listBill.append(tempAmount);
       sumAmount += tempAmount;
    }

    QWidget* backgroundColor = new QWidget(this);
    backgroundColor->setGeometry(QRect(0,0,1920,900));
    backgroundColor->setStyleSheet("background-color:#D6DBDF;");

    ui->setupUi(this);
    this->resize(1920,850);

    QLabel* iconDiaChiGiaoHang = new QLabel(this);
    QPixmap icon0("E:/Project/MyProject/photo/diachigiaohang.png");
    iconDiaChiGiaoHang->setPixmap(icon0.scaled(50,50));
    iconDiaChiGiaoHang->setGeometry(QRect(50,0,50,50));
    QLabel* label0 = new QLabel(this);
    label0->setText("Địa Chỉ Giao Hàng");
    label0->setFont(QFont("Arial",13));
    label0->setGeometry(QRect(100,0,250,50));

    QWidget* formInputAddress = new QWidget(this);
    formInputAddress->setGeometry(QRect(50,60,1000,150));
    formInputAddress->setStyleSheet("background-color:white;");

    name = new QLineEdit(formInputAddress);
    address = new QLineEdit(formInputAddress);
    numberphone = new QLineEdit(formInputAddress);

    address->setGeometry(QRect(230,60,500,30));
    address->setFont(QFont("Arial",12));
    numberphone->setGeometry(QRect(230,100,500,30));
    numberphone->setFont(QFont("Arial",12));
    name->setGeometry(230,10,500,40);
    name->setFont(QFont("Arial",15));

    QLabel* lable1 = new QLabel(formInputAddress);
    lable1->setGeometry(QRect(20,10,200,30));
    lable1->setText("Nhập tên người nhận: ");
    lable1->setFont(QFont("Arial",10));

    QLabel* label2 = new QLabel(formInputAddress);
    label2->setGeometry(QRect(20,60,200,30));
    label2->setFont(QFont("Arial",10));
    label2->setText("Nhập địa chỉ: ");

    QLabel *lable3 = new QLabel(formInputAddress);
    lable3->setText("Nhập số điện thoại: ");
    lable3->setFont(QFont("Arial",10));
    lable3->setGeometry(QRect(20,100,200,30));

    QLabel *label4 = new QLabel(this);
    QPixmap iconDola("E:/Project/MyProject/photo/iconDoLa.png");
    label4->setPixmap(iconDola.scaled(50,50));
    label4->setGeometry(QRect(50,250,50,50));
    QLabel* lable5 = new QLabel(this);
    lable5 ->setText("Hình Thức Thanh Toán");
    lable5->setFont(QFont("Arial",13));
    lable5->setGeometry(QRect(130,250,250,50));

    ui->scrollArea->setGeometry(QRect(50,310,1000,500));
    ui->scrollArea->setStyleSheet("border:none;");

    QVBoxLayout* listpayment = new QVBoxLayout(ui->scrollArea);
    QSignalMapper* mapListPayment = new QSignalMapper(this);
    int dem = 8;
    for (auto p = DATAph.pmlist.gethead();p!=NULL;p=p->next) {
        dem--;

        QRadioButton* Payment = new QRadioButton(p->payment,this);

        listpayment->addWidget(Payment);
        Payment->setIcon(QIcon(QString("E:/Project/MyProject/iconPayment/%1.png").arg(dem)));
        Payment->setIconSize(QSize(50,50));

        connect(Payment,SIGNAL(clicked()),mapListPayment,SLOT(map()));

        mapListPayment->setMapping(Payment,p->payment);

        Payment->setFont(QFont("Arial",20));


    }

    connect(mapListPayment,&QSignalMapper::mappedString,this,&payWidget::clickSelectPayment);

    QPixmap iconThanhTOAN("E:/Project/MyProject/photo/thanhToan.png");
    QLabel* iconThanhToan = new QLabel(this);
    iconThanhToan->setPixmap(iconThanhTOAN.scaled(70,70));
    iconThanhToan->setGeometry(QRect(1250,0,70,70));
    iconThanhToan->show();
    QLabel* label6 = new QLabel(this);
    label6->setText("Số tiền thanh toán");
    label6->setFont(QFont("Arial",13));
    label6->setGeometry(QRect(1330,20,250,30));

    QWidget* formPay = new QWidget(this);
    formPay->setStyleSheet("background-color:white;");
    formPay->setGeometry(QRect(1250,70,650,400));


    QLabel* l1 = new QLabel(formPay);
    QPixmap i1("E:/Project/MyProject/photo/price.png");
    l1->setPixmap(i1.scaled(30,30));
    l1->setGeometry(QRect(50,50,30,30));
    QLabel* l2= new QLabel(formPay);
    l2->setText("Đơn giá");
    l2->setFont(QFont("Arial",15));
    l2->setGeometry(QRect(100,50,100,30));
    QLabel* price = new QLabel(formPay);
    price->setText(QLocale(QLocale::English).toString(sumAmount)+"đ");   // -----------------------------------------------------------------------------------------//???
    price->setGeometry(QRect(250,50,350,40));
    price->setFont(QFont("Arial",15));
    price->setStyleSheet("color:#515A5A;");
    price->setAlignment(Qt::AlignRight);

    QLabel* l3 = new QLabel(formPay);
    QPixmap i2("E:/Project/MyProject/photo/discount.png");
    l3->setPixmap(i2.scaled(30,30));
    l3->setGeometry(QRect(50,100,30,30));
    QLabel* l4 = new QLabel(formPay);
    l4->setText("Giảm giá");
    l4->setFont(QFont("Arial",15));
    l4->setGeometry(QRect(100,100,100,30));

    QLabel* discount = new QLabel(formPay);
    discount->setGeometry(QRect(560,100,40,30));
    discount->setText("0đ");
    discount->setFont(QFont("Arial",15));
    discount->setStyleSheet("color:#515A5A;");
    discount->setAlignment(Qt::AlignRight);

    QLabel* l5 = new QLabel(formPay);
    QPixmap iconSale("E:/Project/MyProject/photo/iconSale.png");
    l5->setPixmap(iconSale.scaled(30,30));
    l5->setGeometry(QRect(50,150,30,30));
    QLabel* l6 = new QLabel(formPay);
    l6->setText("Mã giảm giá");
    l6->setFont(QFont("Arial",15));
    l6->setGeometry(QRect(100,150,150,30));
    QLabel* sale = new QLabel(formPay);
    sale->setText("0đ");
    sale->setStyleSheet("color:#515A5A;");
    sale->setGeometry(QRect(450,150,150,30));
    sale->setFont(QFont("Arial",15));
    sale->setAlignment(Qt::AlignRight);

    QLabel* l7 = new QLabel(formPay);
    QPixmap iconVanChuyen("E:/Project/MyProject/photo/iconvanchuyen.png");
    l7->setPixmap(iconVanChuyen.scaled(50,30));
    l7->setGeometry(QRect(50,200,50,30));
    QLabel* l8= new QLabel(formPay);
    l8->setText("Phí vận chuyển");
    l8->setFont(QFont("Arial",15));
    l8->setGeometry(QRect(100,200,180,30));
    QLabel* l9= new QLabel(formPay);
    l9->setText("+40,000đ");
    l9->setStyleSheet("color:#515A5A;");
    l9->setGeometry(QRect(450,200,150,30));
    l9->setAlignment(Qt::AlignRight);
    l9->setFont(QFont("Arial",15));

    QLabel* lineHorizal= new QLabel(formPay);
    lineHorizal->setGeometry(QRect(0,260,650,10));
    lineHorizal->setStyleSheet("border-top: 2px solid black;");

    QLabel* payText = new QLabel(formPay);
    payText->setGeometry(QRect(50,320,200,40));
    payText->setText("Thanh Toán");
    payText->setFont(QFont("Arial",20));


    QLabel* amount = new QLabel(formPay);
    amount->setText(QLocale(QLocale::English).toString(sumAmount + 40000)+"đ");// ---------------- set text
    amount->setFont(QFont("Arial",22));
    amount->setStyleSheet("color:#E0280F;");
    amount->setAlignment(Qt::AlignRight);
    amount->setGeometry(QRect(250,320,350,50));

    QPushButton* done =  new QPushButton("HOÀN TẤT",this);
    done->setGeometry(QRect(1250,480,650,70));
    done->setFont(QFont("Arial",30));
    done->setStyleSheet("background-color:#CB2812;color:white;border:none;");
    connect(done,&QPushButton::clicked,this,&payWidget::clickDone);

}

void payWidget::clickDone()
{
    if(paymentSelect == "")
    {
        QMessageBox::information(this,"Thông báo","Vui lòng chọn hình thức thanh toán");
        return;
    }

    if(name->text()=="")
    {
        QMessageBox::information(this,"Thông báo","Vui lòng  nhập tên người nhận");
        return;
    }

    if(address->text()=="")
    {
        QMessageBox::information(this,"Thông báo","Vui lòng nhập địa chỉ nhận hàng");
        return;
    }
    if(numberphone->text()=="")
    {
        QMessageBox::information(this,"Thông báo","Vui lòng nhập số điện thoại nhận hàng");
        return;
    }


    QList<QString> listName;
    QList<long> listQuanityPd;
    DATAproduct.~Products();
    init(DATAproduct);
    for(int i =0 ;i<listProduct.size();++i)
    {

        auto p = DATAproduct.getPoiter(listProduct[i].toStdString());
        long k = DATAcart.getPoiter(listProduct[i].toStdString())->quanity;
        if(p->quanity < k)
        {
            QMessageBox::information(this,"Thông báo","Xin lỗi quý khách hiện tại sản phẩm "+ QString::fromStdString(p->name)+" chỉ còn "+QString::number(p->quanity)+" sản phẩm");
            return;
        }
        listName.append(QString::fromStdString(p->name));
        listQuanityPd.append(k);
        p->quanity -= k;
    }

    for(int i =0 ;i<listProduct.size();++i)
    {
        QDateTime cd = QDateTime::currentDateTime();
        DATAph.addHead("",QString::fromStdString(Username),listProduct[i],listName[i],listQuanityPd[i],name->text(),address->text(),QString::number(listBill[i]),paymentSelect,"Chờ xác nhận",cd.toString("ddMMyyyy"),cd.toString("ddMMyyyy"));
        auto p = DATAcart.getPoiter(listProduct[i].toStdString());
        DATAcart.remove(p);
    }
    save(DATAcart,Username);
    outitphlist(DATAph);
    QMessageBox::information(this,"Thành công","Xin cảm ơn quý khách","Tiếp tục mua sắm");

    save(DATAproduct);

    emit payComplete();

    this->close();
}

void payWidget::clickSelectPayment(QString text)
{
    paymentSelect = text;
}
