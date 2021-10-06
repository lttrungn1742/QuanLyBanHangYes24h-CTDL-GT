#include "status.h"
#include<fstream>

status::status()
{
    head=tail=NULL;
}

void status::addhead(QString x){
    node* newnode=status::getnewnode(x);
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
void initsttlist(status &list){
    QFile file("E:/Project/MyProject/statuslist.txt");
    if(!file.open((QIODevice::ReadOnly))){
        qWarning("Cannot open file statuslist.txt for reading");
        return;
    }
    QTextStream in(&file);
    in.setCodec("UTF-8");
        while(!in.atEnd()){
            QString status;
            status=in.readLine();
            list.addhead(status);
        }
        file.close();
}


void outitsttlist(status &list){
    QFile file("E:/Project/MyProject/statuslist.txt");
    QTextStream out(&file);
    out.setCodec("UTF-8");
    if(file.open(QIODevice::WriteOnly)){
        for(auto p=list.gettail();p!=NULL;p=p->prev){
            out<< p->status << Qt::endl;
        }
    }else{
        qWarning("Could not open statuslist.txt");
    }
    file.close();
}
int status::countlist(){
    int count=0;
    for(auto p=gethead();p!=NULL;p=p->next){
        count++;
    }
    return count;
}
