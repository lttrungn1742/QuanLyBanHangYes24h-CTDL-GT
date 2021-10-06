#ifndef PURCHASHST_H
#define PURCHASHST_H

#include"status.h"
#include"payment.h"
#include<QString>
#include<QFile>
#include<QTextStream>
#include<QDateTime>
#include"Products.h"

class purchasehst
{
public:
    struct node{
        QString code, username, idProduct,nameProduct ,namerecipient, address, price, payments, status;
        QDateTime datetime,updatetime;
        node* next, * prev;
        qlonglong quanityOfProduct;
    };
public:
    node* head, * tail;
public:

    status sttlist;
    payment pmlist;
    purchasehst();
    ~purchasehst(){
        while(head){
            node* p=head;
            head=head->next;
            delete (p);
        }
    }
    node* getNewNode(QString ma, QString username,QString maSp , QString tenSp,qlonglong soluongSanPham,QString tenNguoiNhan,QString diaChi,QString giaTien,QString thanhToan,QString trangThai, QString datetime,QString updatetime) {


        node* newNode = new node();
        newNode->code = ma;
        newNode->username = username;
        newNode->idProduct = maSp;

        newNode->nameProduct = tenSp;
        newNode->quanityOfProduct = soluongSanPham;
        newNode->namerecipient = tenNguoiNhan;
        newNode->address = diaChi;
        newNode->price = giaTien;
        newNode->payments = thanhToan;
        newNode->status = trangThai;
        newNode->datetime =QDateTime::fromString(datetime,"ddMMyyyy");
        newNode->updatetime= QDateTime::fromString(updatetime,"ddMMyyyy");
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }
    node* gethead(){
        return head;
    }
    node* gettail(){
        return tail;
    }
    void addHead(QString ma, QString username,QString maSp,QString tenSp,qlonglong soluongsanpham ,QString tenNguoiNhan,QString diaChi,QString giaTien,QString thanhToan,QString trangThai, QString datetime,QString updatetime);
    int countlist();

    node* nodeph(QString x){
         node* p= head;
         while(p!=NULL){
             if(p->code==x)
                 return p;
             p=p->next;
         }
         return NULL;
    }
    void changstatus(QString code,QString status){
        auto p=head;
        while(p!=NULL){
            if(p->code==code){
                p->status=status;
                return;
            }
            p=p->next;
        }
        return;
    }
    void changeupdatetime(QString code,QString updatetime){
        auto p=head;
        while(p!=NULL){
            if(p->code==code){
                p->updatetime= QDateTime::fromString(updatetime,"dd/MM/yyyy");
                return;
                }
            p=p->next;
        }
        return;
    }
    struct statistical{

    };
};
void initphlist(purchasehst& list);
void outitphlist(purchasehst& list);
#endif // PURCHASHST_H
