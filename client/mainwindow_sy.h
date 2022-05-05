#ifndef MAINWINDOW_SY_H
#define MAINWINDOW_SY_H

#include <QMainWindow>
#include <QWidget>
#include "qmenu_WHY.h"
#include "zujian_sy.h"
//class QMenu_WHY;


class login_sy:public QDialog{
    Q_OBJECT
public:
    login_sy();
    void login_verity();
    void login_();
    void connect_to();
    QLineEdit *user;
    QLineEdit *pass;
    QPushButton *log_in;
    QPushButton *connect_;
    QVBoxLayout *lay;
};



class MainWindow_sy : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow_sy(QWidget *parent = nullptr);
    ~MainWindow_sy();
    int syOpenFlag=0,psOpenFlag=0;
    int tishi();
    void get_Data();
    void set_Win_sy();
    void set_Win_ps();
    void close_Win_sy();
    void close_Win_ps();
    sy_widget *wdt;
    //pishijm *jm;
    listTab_sy *tab1;
    QMenu_WHY *QMenu_sy;

    //pishidjs *pish;

    pishi_jm *pishi;
signals:
    void emitTolistsy1(QVector<QVector<QString>> result);
    void emitSqdid(QVector<QVector<QString>> result);
    void emitSyk(QVector<QVector<QString>> result);
    void emitPishilb(QVector<QVector<QString>> result);
    void emiPishixx(QVector<QVector<QString>> result);
    void emiPishilr(QVector<QVector<QString>> result);

};
#endif // MAINWINDOW_SY_H
