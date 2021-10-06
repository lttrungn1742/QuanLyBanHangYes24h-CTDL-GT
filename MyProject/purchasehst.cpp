#include "purchasehst.h"
#include <QFile>
#include<qfile.h>
purchasehst::purchasehst()
{
    head = tail = NULL;
}

void purchasehst::addHead(QString ma ,QString  username, QString  maSp, QString tenSp,qlonglong soluongsanpham,QString  tenNguoiNhan,QString  diaChi,QString  giaTien,QString  thanhToan, QString  trangThai, QString datetime, QString updatetime)
{
    if(ma=="")
    {
        ma = maSp.left(2);
        ma += datetime;

        if(head ==NULL) ma += QString::number(0);
        else
        {
            QString s =  head->code;
            s = s.remove(0,10);
            long t = s.toLong();
            ma += QString::number(t+1);

        }

    }
    node* newNode = getNewNode(ma, username, maSp,tenSp ,soluongsanpham,tenNguoiNhan, diaChi, giaTien, thanhToan, trangThai, datetime, updatetime);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void initphlist(purchasehst& list){
    QFile file("E:/Project/MyProject/Huy/purchasehstlist.txt");
    if(!file.open((QIODevice::ReadOnly))){
        qWarning("Cannot open file purchasehstlist.txt for reading");
        return;
    }
    QTextStream in(&file);
    in.setCodec("UTF-8");
       while (!in.atEnd()) {
        QString a = in.readLine();
        QString b = in.readLine();
        QString maSp = in.readLine();
        QString tenSp = in.readLine();
        QString soluong = in.readLine();
        QString d = in.readLine();
        QString e = in.readLine();
        QString f = in.readLine();
        QString g = in.readLine();
        QString h = in.readLine();
        QString l = in.readLine();
        QString k = in.readLine();
        list.addHead(a,b, maSp,tenSp,soluong.toLongLong(),d, e, f, g, h, l,k);
    }
            file.close();
            initsttlist(list.sttlist);
            initpmlist(list.pmlist);

}
void outitphlist(purchasehst& list){
    QFile file("E:/Project/MyProject/Huy/purchasehstlist.txt");
    QTextStream out(&file);
    out.setCodec("UTF-8");
    if(file.open(QIODevice::WriteOnly)){
        for(auto p=list.tail;p!=NULL;p=p->prev){
            out<< p->code << Qt::endl;
            out<< p->username<<Qt::endl;
            out<< p->idProduct<<Qt::endl;
            out<< p->nameProduct<<Qt::endl;
            out<< p->quanityOfProduct<<Qt::endl;
            out<< p->namerecipient<<Qt::endl;
            out<< p->address <<Qt::endl;
            out<< p->price <<Qt::endl;
            out<< p->payments <<Qt::endl;
            out<< p->status <<Qt::endl;
            out<< p->datetime.toString("ddMMyyyy")<<Qt::endl;
            out<< p->updatetime.toString("ddMMyyyy")<<Qt::endl;
        }
    }else{
        qWarning("Could not open purchasehstlist.txt");
    }
    file.close();
}
int purchasehst::countlist(){
    int count=0;
    node* p=head;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;

}
