#include "mainwindow.h"

#include <QApplication>
#include<fstream>
#include<QString>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //使用git新建分支的分支 git checkout -b new_branch

    w.show();
    return a.exec();
}
