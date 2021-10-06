#pragma once

#include <string>
#include <fstream>

class category
{
    struct node
    {
        std::string name;
        int id;
        node* next, * prev;
    };

private:
    node* head, * tail;
public:
    category() { head = tail = NULL; }
    ~category()
    {
        while (head!=NULL) {
             node* p = head;
             head=head->next;
             delete (p);
        }
    }
    node* getNewNode(std::string name,int id)
    {
        node* newNode = new node();
        for(std::string::iterator it = name.begin(); it !=  name.end(); ++it) {
            if(*it==' ' ){
                ++it;
                *it = std::toupper(*it);
            }
            else  if( it == name.begin())    *it = std::toupper(*it);
        }
        newNode->name = name;
        newNode->id = id;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }

    node* getHead() { return head; }
    node* getTail() { return tail; }
    void add(std::string name,int id = -1)
    {
        node* p = getNewNode(name,id);
        if (head == NULL)
        {
            head = p;
            tail = p;
        }
        else {
            tail->next = p;
            p->prev = tail;
            tail = p;
          if(p->id == -1)  tail->id = tail->prev == NULL ? 1 : tail->prev->id + 1;
        }
    }

    std::string getCodeCate(std::string t);
    std::string getCate(std::string t);
    std::string getCate(int t);
    int getRows()
    {
        int dem =0;
        node* p = head;
        while(p!=NULL)
        {
            dem++;
            p=p->next;
        }
        return dem;
    }
};

void init(category& list);
void save(category list);
