#include "payment.h"

payment::payment()
{
    head=tail=NULL;
}
void payment::addhead(QString x){
    node* newnode=payment::getnewnode(x);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        return;
    }
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    return;
}

void initpmlist(payment &list){
    QFile file("E:/Project/MyProject/Huy/paymentlist.txt");
    if(!file.open((QIODevice::ReadOnly))){
        qWarning("Cannot open file paymentlist.txt for reading");
        return;
    }
    QTextStream in(&file);
    in.setCodec("UTF-8");
        while(!in.atEnd()){
            QString payment =in.readLine();
            list.addhead(payment);
        }
        file.close();
}
void outitpmlist(payment &list){
    QFile file("E:/Project/MyProject/Huy/paymentlist.txt");
    QTextStream out(&file);
    out.setCodec("UTF-8");
    if(file.open(QIODevice::ReadWrite)){
        for(auto p=list.head;p!=NULL;p=p->next){
            out<< p->payment << Qt::endl;
        }
    }else{
        qWarning("Could not open paymentlist.txt");
    }
    file.close();
}
