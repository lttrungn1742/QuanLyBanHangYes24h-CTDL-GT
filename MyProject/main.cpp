
#include <QApplication>
#include<QMessageBox>
#include<clickmenu.h>
#include"cartwidget.h"
#include"program.h"
#include"signin.h"
#include<QLineEdit>
#include"viewdetailproduct.h"
#include"paywidget.h"
#include"managerwg.h"
#include "qt_user.h"
#include"lsmh.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   program  w("root");
// viewDetailProduct w("000000000");

   //cartWidget w("root");

   // payWidget w ("root",{"000000000","000002002"});

  // qt_user w;

 //   managerwg w;
  //  lsmh w("root");
   w.show();

 // QString s = "20102000";

 //  QMessageBox::information(NULL,"",QDateTime::fromString(s,"ddMMyyyy").toString("dd/MM/yyyy"));




    return a.exec();
}
