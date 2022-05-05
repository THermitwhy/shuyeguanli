#ifndef ZUJIAN_SY_H
#define ZUJIAN_SY_H

#include <QLayout>
#include <QMenu>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QMainWindow>
#include <QLabel>
#include<QTabWidget>
#include <QMessageBox>
#include <QDialog>
#include <QListWidgetItem>
#include "socket_sy.h"
#include "json_sy.h"
#include "moer.h"
#include <QDebug>
#include<QProgressBar>
#include <QTimer>
class pishijm:public QWidget
{
    Q_OBJECT
public:
    pishijm();

    //QLineEdit *LE_BINGRENID;
    //QLineEdit *LE_BINGRENXM;
    //QLineEdit *LE_DIANHUAHM;
    //QLineEdit *LE_XINGBIE;
    QString *QS_BINGRENXX[4];
    QLineEdit *LE_BINGREN[4];
    QLabel *LB_BINGREN[4];
    QVBoxLayout *PISHI_BINGREN;
    QHBoxLayout *PISHI_BINGRENXX[4];
    int setLayout_bingrenxx();

};


class listTab_sy:public QTabWidget
{
    Q_OBJECT
public:
    listTab_sy();

    QListWidget *list_sy[2];
    //QListWidget *list_sy2;
    QHBoxLayout *liebiao_buju1;
    QHBoxLayout *liebiao_buju2;
    QWidget *liebiao_tab1;
    QWidget *liebiao_tab2;
    void mess(QListWidgetItem *w);
    void addMessage();
    int send_mess(QString m);
    void read_mess(QVector<QVector<QString>> result);
    void addListItem1(QVector<QVector<QString>> result);
signals:
    void to_jm(QString s);

};


class pushbutton_sy:public QPushButton
{
    Q_OBJECT
public:
    pushbutton_sy(QVector<QVector<QString>> result,QWidget *parent = nullptr);
    pushbutton_sy();
    QVector<QVector<QString>> result;
    QString mingzi;
    QString xingbie;
    QString color;
    QString sqdid;
    QString dqzt;
    QString Text_yaopin;
    QString Text_cishu;
    QMenu *mu;
    QAction *btAct1;
    QAction *btAct2;
    QAction *btAct3;
    void addMenu();
    void set_syxx(QVector<QVector<QString>> result);
    void printSYK();
    void on_pushbutton_sy_customContextMenuRequested(const QPoint &pos);
    void startSy();
    void endSy();

};


class shuyejm:public QWidget
{
    Q_OBJECT
public:
    shuyejm(QWidget *parent = nullptr);
    QVBoxLayout *vb;
    pushbutton_sy  *btsy[5];
    int count_syk=-1;
    int count_bt=-1;
    int count_shenqingdid=-1;
    QVector<QString> res;
    QVector<QVector<QString>> result_shenqingdid;
    QVector<QVector<QString>> result_syk;
    void get_shenqingdid(QVector<QVector<QString>> result);
    void get_syk(QVector<QVector<QString>> result);
    void addBt(QString bt);


};

class sy_widget:public QWidget
{
    Q_OBJECT
public:
    sy_widget(QWidget *parent = nullptr);
    QHBoxLayout *hb;
    listTab_sy *list;
    shuyejm *syjm;

};
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




class pishijglr:public QDialog
{
    Q_OBJECT
public:
    pishijglr();
    //pishidjs *jg;
    QLabel *lab[3];
    QVBoxLayout *lay;
    QLineEdit *edit[5];
    QPushButton *bt;
    QString sqlid;
    void luru1();
    void luru2();
    void shows(QString s);
    void get_xx(QVector<QVector<QString>> result);


};




class pishidjs:public QWidget
{
    Q_OBJECT
public:
    QVector<QString> shuju;
    int time_value=0;
    int time_value_end=0;
    QString sqdid;
    pishidjs(QVector<QString> data,QWidget *parent = nullptr);
    QVBoxLayout *vb;
    QHBoxLayout *hb;
    QLabel *lab;
    QPushButton *bt1;
    QPushButton *bt2;
    QPushButton *bt3;
    QPushButton *bt4;
    QPushButton *bt5;
    QProgressBar *bar_time;
    QTimer *time1;


    void set_labelText();
    void set_time();
    void time_OUT();
    void start_jishi();
    void end_jishi();
    void jishi_again();
    void quxiao();
    void send_data();
signals:
    void emitBTmsg(QString s);


};


class pishizhong:public QWidget
{
    Q_OBJECT
public:
    pishizhong(QWidget *parent=nullptr);
    int count_bt;
    QVBoxLayout *layout;
    pishidjs *bt[5];
    pishijglr *jglr;
    void addBt(QVector<QString> data);
};

class tab_pish:public QTabWidget
{
    Q_OBJECT
public:
    tab_pish(QWidget *parent = nullptr);
    QListWidget *wait_pish;
    pishizhong *pishiz;

    void list_shuaxin(int x);
    void get_liebiao(QVector<QVector<QString>> result);
signals:

};
class pishixx:public QWidget
{
    Q_OBJECT
public:
    pishixx(QString s,bool y,QWidget *parent = nullptr);
    QHBoxLayout *lay;
    QLabel *label;
    QLineEdit *edit;
    QString get_text();
    void clear();


};

class pishiry:public QWidget
{
    Q_OBJECT
public:
    pishiry(QWidget *parent = nullptr);
    pishixx *pishixxi[6];
    QVBoxLayout *vlay;
    QPushButton *bt1;
    QPushButton *bt2;
    void clear();
    void baocun();
    void send_text(QListWidgetItem *w);
    void set_text(QVector<QVector<QString>> result);
signals:
    void emitPishiryxx(QVector<QString> xx);
};


class pishi_jm:public QWidget
{
    Q_OBJECT
public:
    pishi_jm(QWidget *parent = nullptr);
    pishiry *pishick;
    tab_pish *pishitab;
    QHBoxLayout *layout;

};

#endif // ZUJIAN_SY_H
