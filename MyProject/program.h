#ifndef PROGRAM_H
#define PROGRAM_H

#include <QMainWindow>
#include<QGridLayout>
#include"Products.h"
#include<QSignalMapper>
#include<QMessageBox>
#include<QPushButton>
#include<QSignalBlocker>
#include<QLabel>
#include<QFile>
#include<QTextEdit>
#include"informationuser.h"
#include"qt_user.h"
#include"managerPd.h"
#include"signin.h"
#include<QLocale>
#include"viewdetailproduct.h"
#include"managerwg.h"
#include"cartwidget.h"
#include"paywidget.h"
#include"lsmh.h"

namespace Ui {
class program;
}

class program : public QMainWindow
{
    Q_OBJECT

public:
    explicit program(std::string username ,QWidget *parent = nullptr);
    ~program();

private:
    Ui::program *ui;
    std::string Username ;
    Products DATApd;
    QWidget* leftContent,*alignContent,*menu,* topWidget, * mainWindows,* viewProduct, *viewCart,*viewPay;
    QPushButton* allcate;



    void printCate();
private slots:
    void clickCate(QString name);
    void clickInfo();
    void clickManagerUser();
    void clickManagerProduct();
    void clickEditInfo();
    void clickLogOut();
    void clickProduct(QString name);
    void clickKind(QString idKind);
    void clickCart();
    void clickManagergw();
    void clickPay(QList<QString> listProductBuy);
    void clickHistoryPay();
};

#endif // PROGRAM_H
