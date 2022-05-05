#include "qmenu_WHY.h"
//#include "socket_sy.h"
//#include "mainwindow.h"

 //extern const MainWindow_sy w;
QMenu_WHY::QMenu_WHY(QWidget *parent)
    : QMenuBar{parent}
{


        QM = new QMenu("wnjian");
        ac1=new QAction("文件");
        ac2=new QAction("输液");
        ac3=new QAction("输液系统");
        ac4=new QAction("皮试系统");
        QM->addAction(ac1);
        QM->addAction(ac2);
        QM->addAction(ac3);
        QM->addAction(ac4);
        this->addMenu(QM);
        connect(ac1,&QAction::triggered,this,&QMenu_WHY::connect_sy);
        //connect(ac1,&QAction::triggered,w,&MainWindow_sy::tishi);

}



int QMenu_WHY::connect_sy(){
    socket_space::connect();
    //QMessageBox::information(NULL, "Title", "Content",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    return 1;

}
