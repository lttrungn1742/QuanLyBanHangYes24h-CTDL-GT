#include "vs_user.h"

USERS::USERS()
{
    uhead = NULL;
    utail = NULL;
}

USERS::~USERS()
{
    while (uhead)
    {
        usr* temp = uhead;
        uhead = uhead->right;
        delete(temp);
    }
}

usr* newone(std::string ten, std::string id, std::string mk, int gt, std::string sdt, std::string mail, int quyen, int stt)
{
    usr* u = new usr();
    u->left = NULL;
    u->name = ten;
    u->username = id;
    u->password = mk;
    u->gender = gt;
    u->phonenumber = sdt;
    u->email = mail;
    u->rights = quyen;
    u->enable = stt;
    u->right = NULL;
    return u;
}

std::string getname(usr* u)
{
    for (int i = u->name.length() - 1; i >= 0; i--)
        if (u->name[i] == ' ')
            return u->name.substr(i + 1, u->name.length() - i - 1);
}

void USERS::insert(usr* u)
{
    if (uhead == NULL)
    {
        uhead = u;
        utail = u;
    }
    else
    {
        utail->right = u;
        u->left = utail;
        utail = u;
    }
}

void Init(USERS &dataUser)
{
    std::ifstream f;
    std::string ten, id, mk, sdt, mail;
    int gt, quyen, stt;
    f.open("E:/Project/MyProject/Users.txt", std::ios::in);
    while (!f.eof())
    {
        getline(f, ten); if(ten=="") return;
        getline(f, id);
        getline(f, mk);
        f >> gt;
        f.ignore(1);
        getline(f, sdt);
        getline(f, mail);
        f >> quyen;
        f >> stt;
        f.ignore(1);
        usr* u = newone(ten, id, mk, gt, sdt, mail, quyen, stt);
        dataUser.insert(u);
    }
}

usr* USERS::gethead()
{
    return uhead;
}

usr* USERS::gettail()
{
    return utail;
}

usr* USERS::getpointer(std::string id)
{
    for(usr* i = uhead; i != NULL; i=i->right)
        if(i->username == id)
            return i;
    return NULL;
}

int USERS::getRows()
{
    int dem = 0;
    for(usr* i = uhead; i!= NULL; i=i->right)
        dem++;
    return dem;
}

int USERS::checksignin(std::string id, std::string mk)
{
    mk = convertPass(mk);
    for(usr* i = uhead; i != NULL; i = i->right)
    {
        if (i->username == id && i->password == mk)
        {
            if (i->enable == 0)
                return -2; // tài khoản bị chặn
            else if (i->rights == 0)
                return 0; // khách hàng
            else if (i->rights == 1)
                return 1; // admin
        }
    }
    return -1; //sai thông tin đăng nhập
}

int USERS::checkID(std::string id)
{
    if ((id[0] >= 48 && id[0] <= 57) || id.length() == 0)
            return -1;
    for(int i = 0; i < id.length(); i++)
    {
        if (!(id[i] >= 48 && id[i] <= 57 || id[i] >= 65 && id[i] <= 90 || id[i] >= 97 && id[i] <= 122))
            return -1;
    }
    for(usr* i = uhead; i != NULL; i=i->right)
        if (i->username == id)
            return 1;
    return 0;
}

std::string USERS::convertPass(std::string mk)
{
    for (int i = 0; i < mk.length(); i++)
    {
        if (isalpha(mk[i]))
        {
            if ((mk[i] + 13 > 90 && mk[i] + 13 < 104) || mk[i] + 13 > 122)
                mk[i] = mk[i] - 26 + 13;
            else
                mk[i] = mk[i] + 13;
        }
    }
    return mk;
}

int USERS::checkPass(std::string mk)
{
    if (mk.length() >= 6)
        return 1;
    return 0;
}

int USERS::checkConfPass(std::string mk, std::string conf)
{
    if (mk == conf)
        return 1;
    return 0;
}

int USERS::checkNum(std::string sdt)
{
    if (sdt.length() == 0)
        return 0;
    return 1;
}

int USERS::checkMail(std::string mail)
{
    if(mail.length() == 0)
        return -1;
    int dem = 0;
    for(int i = 0; i < mail.length(); i++)
    {
        if (mail[i] == '@')
            dem++;
    }
    if (dem != 1)
        return 0;
    return 1;
}

void save(USERS u)
{
     std::ofstream  f("E:/Project/MyProject/Users.txt", std::ios::out );
     for(usr* i = u.gethead(); i != NULL; i=i->right)
         f << i->name << "\n" << i->username << "\n" << i->password << "\n" << i->gender << "\n" << i->phonenumber << "\n" << i->email << "\n" << i->rights << "\n"<< i->enable <<"\n";
}



