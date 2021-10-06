#include "managerwg.h"
#include "muahang.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    managerwg w;
    w.show();
    return a.exec();
}
