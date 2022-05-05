#ifndef QMENU_WHY_H
#define QMENU_WHY_H
#include "socket_sy.h"
//#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QWidget>
#include <QAction>
#include <QMessageBox>
class QMenu_WHY : public QMenuBar
{
    Q_OBJECT
public:
    //int m;
    explicit QMenu_WHY(QWidget *parent = nullptr);
    QMenu *QM;
    QAction *ac1;
    QAction *ac2;
    QAction *ac3;
    QAction *ac4;
    int connect_sy();

signals:

};




#endif // QMENU_WHY_H
