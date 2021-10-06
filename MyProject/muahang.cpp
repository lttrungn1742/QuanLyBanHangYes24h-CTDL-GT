#include "muahang.h"
#include "ui_muahang.h"

muahang::muahang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::muahang)
{
    initpmlist(pmlist);
    ui->setupUi(this);
    populatepmbox();

}

muahang::~muahang()
{
    delete ui;
}
void muahang::populatepmbox(){
    for(auto p=pmlist.gethead();p!=NULL;p=p->next ){
        ui->pmcombobox->addItem(p->payment.toUtf8(),p->payment);
    }
}
