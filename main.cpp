#include "socialnetwork.h"
#include <QApplication>


//Nima is connected
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    socialNetwork w;
    w.show();


    return a.exec();
}
