#include "statistics.h"
#include <QDebug>
#include <QStringRef>
#include <qdebug.h>

statistics::statistics()
{

} 
unsigned long long statistics::money_month(QString month){
    unsigned long long totalmoney=0;
    for(auto p=phlist.head;p!=NULL;p=p->next){
        if((p->updatetime.date().month()==QDate::fromString(month,"MM/yyyy").month())
         &&(p->updatetime.date().year()==QDate::fromString(month,"MM/yyyy").year()))
        {
            totalmoney+=p->price.toULong();
        }
    }
    return totalmoney;
}
unsigned long long statistics::money_category(QString category,QString month){
    unsigned long long totalmoney=0;
    int cl;
    for(auto p=cllist.getHead();p!=NULL;p=p->next){
        if(p->name==category.toStdString()){
            cl=p->id;break;
        }
    }
    for(auto p=phlist.gethead();p!=NULL;p=p->next){
        int temp = p->code.mid(0,2).toInt();
        if((temp==cl)
                &&(p->updatetime.date().month()==QDate::fromString(month,"MM/yyyy").month())
                &&(p->updatetime.date().year()==QDate::fromString(month,"MM/yyyy").year())
                &&(p->status.mid(3,4)=="giao"))
                   totalmoney+=p->price.toULong();
    }
    return totalmoney;

}
int statistics::number_product_month(QString month){
    int number=0;
    for(auto p=phlist.gethead();p!=NULL;p=p->next){
        if((p->updatetime.date().month()==QDate::fromString(month,"MM/yyyy").month())
         &&(p->updatetime.date().year()==QDate::fromString(month,"MM/yyyy").year()))
        {
            number++;
        }
    }
    return number;
}
int statistics::number_product_category(QString category,QString month){
    int number=0;
    int cl;
    for(auto p=cllist.getHead();p!=NULL;p=p->next){
        if(p->name==category.toStdString()){
            cl=p->id;break;
        }
    }
    for(auto p=phlist.gethead();p!=NULL;p=p->next){
        if((std::stoi(p->code.toStdString().substr(0,2))==cl)
         &&(p->updatetime.date().month()==QDate::fromString(month,"MM/yyyy").month())
         &&(p->updatetime.date().year()==QDate::fromString(month,"MM/yyyy").year())
         &&(p->status.mid(3,4)=="giao"))
        {
            number++;
        }
    }
    return number;
}
int statistics::sodonbihuy(QString month){
    int count=0;
    for(auto p=phlist.gethead();p!=NULL;p=p->next){
        if((p->updatetime.date().month()== QDate::fromString(month,"MM/yyyy").month())
         &&(p->updatetime.date().year()==QDate::fromString(month,"MM/yyyy").year())
                &&(p->status.contains("Đã hủy"))){
                count++;
    }
}
    return count;
}
