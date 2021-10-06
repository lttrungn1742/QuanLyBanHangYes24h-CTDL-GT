
#include "Products.h"


void init(Products& list)
{
    init(list.listBrand);
    init(list.listKind);
    init(list.listCate);
    init(list.listMadein);

    std::ifstream f;
    f.open("E:\\project\\MyProject\\dataProducts.txt", std::ios::in);

    while (!f.eof())
    {
        std::string ma, gia, ten;
        std::getline(f, ma);
        if (ma == "") break;
        std::getline(f, ten);
        std::getline(f, gia);
        int soluong,tontai;
        f>>soluong;
        f>>tontai;
             f.ignore(1);
        list.insert(ma, ten, gia,soluong,tontai);
    }
    f.close();

}

int Products::length()
{
    int dem = 0;

    node* p = head;

    while (p != NULL)
    {
        ++dem;
        p = p->next;
    }

    return dem;
}

void save(Products list)
{
    std::ofstream f;

        f.open("E:\\project\\MyProject\\dataProducts.txt", std::ios::out | std::ios::trunc);
        auto p = list.getHead();
        int dem = 0;
        while (p != NULL)
        {
//            p->id = p->id.substr(0, 8) + std::to_string(dem); ++dem;
            f << p->id	<< std::endl << p->name<< std::endl <<p-> price<<std::endl<<p->quanity<<std::endl<<p->disable;
            p = p->next;
            if (p != NULL) f << std::endl;
        }
        f.close();
        save(list.listBrand);
        save(list.listCate);
        save(list.listKind);
        save(list.listMadein);
}

void Products::remove(node* p)
{
    if (p == head)
    {
        head = head->next; return;
    }
    if (p->prev != NULL)
    {
        p->prev->next = p->next;
    }
    if (p->next != NULL)
    {
        p->next->prev = p->prev;
    }
    delete(p);
}
