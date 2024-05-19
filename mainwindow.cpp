#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<fstream>
#include<QFile>
#include<QDebug>
#include<QTextStream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //项目中真实用到的需求
    //从文件读数据
    ifstream file("D:\\Qt\\Tools\\QtCreator\\TestQt\\build-readAndWriteFile-Desktop_Qt_6_3_2_MinGW_64_bit-Debug\\debug\\data.txt");

    char str[10]={0};
    int i=0;
    while(file.getline(str,sizeof(str)))
        {

            if(i==0)
            {
                ui->lineEdit_jd->setText(str);
            }
            else if(i==1)
            {
                ui->lineEdit_wd->setText(str);
            }
            else if(i==2)
            {
                ui->lineEdit_height->setText(str);
            }
            else if(i==3)
            {
                ui->lineEdit_g->setText(str);
            }
            else if(i==4)
            {
                ui->lineEdit_fwj->setText(str);
            }
            else if(i==5)
            {
                ui->lineEdit_sc->setText(str);
            }
            else if(i==6)
            {
                break;
            }
            i++;
        }


}

MainWindow::~MainWindow()
{
    delete ui;
}

//30.1234
//40.6754
//100.345
//9.90765
//150.456
//234.765
void MainWindow::on_pushButton_point_clicked()
{
    QFile f("D:\\Qt\\Tools\\QtCreator\\TestQt\\build-readAndWriteFile-Desktop_Qt_6_3_2_MinGW_64_bit-Debug\\debug\\data.txt");
    if(!f.open(QIODevice::WriteOnly | QIODevice::Text))
    {
            qDebug() << ("打开文件失败");
    }
    QTextStream txtOutput(&f);
    txtOutput<<ui->lineEdit_jd->text();
    txtOutput<<'\n';
    txtOutput<<ui->lineEdit_wd->text();
    txtOutput<<'\n';
    txtOutput<<ui->lineEdit_height->text();
    txtOutput<<'\n';
    txtOutput<<ui->lineEdit_g->text();
    txtOutput<<'\n';
    txtOutput<<ui->lineEdit_fwj->text();
    txtOutput<<'\n';
    txtOutput<<ui->lineEdit_sc->text();
    f.close();
    //软件启动，数据初始化，点击按钮，保存数据到本地文件
}

