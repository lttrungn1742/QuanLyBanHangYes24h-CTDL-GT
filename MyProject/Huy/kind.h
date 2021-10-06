#pragma once

#include <string>
#include <fstream>

class kind
{
    struct node
    {
        std::string name;
        int idKind,idCate;
        node* next, * prev;
    };

private:
    node* head, * tail;
public:
    kind() { head = tail = NULL; }
    ~kind()
    {
        while (head!=NULL) {
             node* p = head;
             head=head->next;
             delete (p);
        }
    }
    node* getNewNode(std::string name,int idCate,int id)
    {
        node* newNode = new node();
        for(std::string::iterator it = name.begin(); it !=  name.end(); ++it) {
            if(*it==' ' ){
                ++it;
                *it = std::toupper(*it);
            }
            else
                if( it == name.begin())
                {
                     *it = std::toupper(*it);
                }

        }
        newNode->name = name;
        newNode->idCate= idCate;
        newNode->idKind=id;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }

    node* getHead() { return head; }
    node* getTail() { return tail; }
    void add(std::string name,int idCate,int id=-1)
    {
        node* p = getNewNode(name,idCate,id);
        if (head == NULL)
        {
            head = p;
            tail = p;
        }
        else {
            tail->next = p;
            p->prev = tail;
            tail = p;
            if(p->idKind==-1)   tail->idKind = tail->prev == NULL ? 1 : tail->prev->idKind + 1;
        }
    }

     int getRows(int k)
     {
         int dem =0;
         node* p = head;
         while(p!=NULL)
         {
             if(p->idCate==k)
                dem++;
              p=p->next;
         }
         return dem;
     }
    std::string getKind(std::string t);

};

void init(kind& list);
void save(kind list);
