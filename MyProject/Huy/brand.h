#pragma once
#include<string>
#include<fstream>

class brand
{
    struct node
    {
        std::string  name;
        int id;
        node* next, * prev;
    };

private:
    node* head, * tail;
public:
    node* getNewNode(std::string name,int id)
    {
        node* newNode = new node();
        for(std::string::iterator it = name.begin(); it !=  name.end(); ++it) {
            if(*it==' ' ){
                ++it;
                *it = std::toupper(*it);
            }
            else if( it == name.begin())
                {
                     *it = std::toupper(*it);
                }
        }
        newNode->name = name;
        newNode->id = id;
        newNode->next = NULL;
        newNode->prev = NULL; return newNode;
    }

    brand(){ head = tail = NULL; }
   ~brand()
    {
        while (head!=NULL) {
             node* p = head;
             head=head->next;
             delete (p);
        }

    }

    void add(std::string name,int id = -1) {
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
            if(p->id == -1)    tail->id = tail->prev == NULL ? 1 : tail->prev->id + 1;
        }
    }
    node* getHead()	{	return head;}
    node* getTail() { return tail; }

    std::string getCodeBrand(std::string t)
    {
        node* p = head;
        while (p != NULL)
        {
            if (p->name == t) return p->id < 10 ? ("0" + std::to_string(p->id)) : std::to_string(p->id);
            p = p->next;
        }
        return "";
    }

    std::string getBrand(std::string t)
    {
        node* p = head;
        while (p != NULL)
        {
            if (p->id == std::stoi(t)) return p->name;
            p = p->next;
        }

        return  "";
    }

    int getRows()
    {
        node* p = head;
        int dem =0;
        while (p!=NULL) {
           dem++;
            p=p->next;
        }
        return dem;
    }
};

void init(brand& t);
void save(brand t);
