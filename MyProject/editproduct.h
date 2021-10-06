#ifndef EDITPRODUCT_H
#define EDITPRODUCT_H

#include <QDialog>
#include<QLineEdit>
#include<QComboBox>
#include"Products.h"
#include<QFileDialog>
#include<QMessageBox>

namespace Ui {
class EditProduct;
}

class EditProduct : public QDialog
{
    Q_OBJECT

public:
    explicit EditProduct(std::string str,QWidget *parent = nullptr);
    ~EditProduct();
     Products dataPd;
private:
    Ui::EditProduct *ui;
    QString file,fileNew,fileTemp;
    std::string strId;
private slots:
    void Category();
    void Kind();
    void Brand();
    void Madein();
    void EditPhoto();
    void on_buttonBox_accepted();
    void on_deletePd_clicked();
    void on_apply_clicked();
};

#endif // EDITPRODUCT_H
