#ifndef INFORMATIONUSER_H
#define INFORMATIONUSER_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QFormLayout>
#include<QLineEdit>
#include"vs_user.h"
#include<QRadioButton>
#include<lsmh.h>

namespace Ui {
class informationUser;
}

class informationUser : public QWidget
{
    Q_OBJECT

public:
    explicit informationUser(std::string username,QWidget *parent = nullptr);
    ~informationUser();
    std::string Username ;
    USERS DATAuser;
private:
    Ui::informationUser *ui;
    QWidget* alignContent;
     QPushButton *allInformationUser,*managerAccout, *purchaseHistory;
public slots:
  void clickAllInfo();
  void clickManageInfo();
  void clickHistoryPay();
};

#endif // INFORMATIONUSER_H
