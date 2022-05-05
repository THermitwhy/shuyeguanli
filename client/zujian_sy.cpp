#include "zujian_sy.h"
#include<string>
#include <iostream>
pishijm::pishijm()
{

    PISHI_BINGREN=new QVBoxLayout(this);

    QS_BINGRENXX[0]= new QString("病人id  ");
    QS_BINGRENXX[1]= new QString("姓名    ");
    QS_BINGRENXX[2]= new QString("住址    ");
    QS_BINGRENXX[3]= new QString("家庭电话 ");
    for(int i=0;i<4;i++){

        LE_BINGREN[i]=new QLineEdit(this);
        //LE_BINGREN[i]->setReadOnly(true);
        LB_BINGREN[i]=new QLabel(*QS_BINGRENXX[i],this);
        PISHI_BINGRENXX[i]= new QHBoxLayout();
        PISHI_BINGRENXX[i]->addWidget(LB_BINGREN[i]);
        PISHI_BINGRENXX[i]->addWidget(LE_BINGREN[i]);
        PISHI_BINGREN->addLayout(PISHI_BINGRENXX[i]);
    }
    this->setLayout(PISHI_BINGREN);


}


int pishijm::setLayout_bingrenxx(){

    return 1;

}


listTab_sy::listTab_sy(){
    //tab_sy=new QTabWidget()
    liebiao_buju1=new QHBoxLayout();
    liebiao_buju2=new QHBoxLayout();
    liebiao_tab1=new QWidget();
    liebiao_tab2=new QWidget();
    list_sy[0] = new QListWidget();
    list_sy[1] = new QListWidget();
    //list_sy[0]->addItem("一号");
    //list_sy[1]->addItem("二号");
    //list_sy2 = new QListWidget();
    //list_sy1->addItem("一号");
   // list_sy1->addItem("二号");
    liebiao_buju1->addWidget(list_sy[0]);
    liebiao_buju2->addWidget(list_sy[1]);
    liebiao_tab1->setLayout(liebiao_buju1);
    liebiao_tab2->setLayout(liebiao_buju2);
    this->addTab(liebiao_tab1,"输液中");
    //this->addTab(liebiao_tab2,"待输液");
    send_mess("");
    //this->addTab()
    connect(list_sy[0],&QListWidget::itemClicked,this,&listTab_sy::mess);
    //connect(&Socket_sy,&QTcpSocket::readyRead,this,&listTab_sy::read_mess);

}


void listTab_sy::mess(QListWidgetItem *w){


    QVector<QString> param;
    param.append(w->text());
    socket_space::sendMess(json_space::str2json(4,param));


    //QString s;
    //s=json_space::login_json("user","123");
   // socket_space::sendMess(s);
    //other_use::speak("我是说");
    //other_use::draw();
    //list_sy[this->currentIndex()]->addItem(w->text());
    //std::cout<<this->currentIndex();

    //QVector<QString> s;
    //QString v;
    //s.append("2201");
    //socket_space::sendMess(json_space::str2json(2,s));
    //socket_space::Read_Data(v);
    //list_sy[0]->addItem(v);
    //emit to_jm(w->text());
    //other_use::printTO();

}

void listTab_sy::addMessage(){

    for(int i=0;i<5;i++){
        //list_sy1->addItem("m[i]");


    }


}


int listTab_sy::send_mess(QString m){
        //QString s;
        //s=json_space::login_json("user","123");
        //socket_space::sendMess(s);
        QVector<QString> param;
        param.append("1");
        socket_space::sendMess(json_space::str2json(3,param));
        return 1;

    }
void listTab_sy::read_mess(QVector<QVector<QString>> result){
    for(int i=0;i<result.size();i++)
    {
        list_sy[0]->addItem(result[i][0]);
    }


    //QMessageBox::information(NULL, "Title", result[0][0],QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

}
pushbutton_sy::pushbutton_sy()
{

}
pushbutton_sy::pushbutton_sy(QVector<QVector<QString>> results,QWidget *parent):QPushButton(parent)
{
    //this->setText(mingzi);
    result=results;
    for(int i=0;i<result.size();i++)
    {   QString yaopin=result[i][3]+"  "+result[i][4]+result[i][5]+"\n";
        Text_yaopin+=yaopin;
    }
    dqzt=result[0][6];
    Text_cishu="本院次数："+result[0][1]+"已执行次数："+result[0][2];
    this->setText(Text_yaopin+Text_cishu);
    sqdid=result[0][0];
    setFixedSize(150,100);
    if(dqzt=="0")
    {
        this->setStyleSheet("background-color: rgb(0,255,0)");
    }
    if(dqzt=="1")
    {
        this->setStyleSheet("background-color: rgb(255,0,0)");
    }
    btAct1=new QAction("打印",this);
    btAct2=new QAction("开始输液",this);
    btAct3=new QAction("完成输液",this);
    setContextMenuPolicy(Qt::CustomContextMenu);
    //other_use::printTO()
    connect(this,&QPushButton::clicked,this,&pushbutton_sy::addMenu);
    connect(btAct1,&QAction::triggered,this,&pushbutton_sy:: printSYK);//打印输液卡
    connect(btAct2,&QAction::triggered,this,&pushbutton_sy::startSy);//开始输液
    connect(btAct3,&QAction::triggered,this,&pushbutton_sy::endSy);//结束输液

}

void pushbutton_sy:: printSYK()
{
    other_use::printTO(result);
}
void pushbutton_sy::startSy()
{
    QVector<QString> par;
    par.append(sqdid);
    socket_space::sendMess(json_space::str2json(2007,par));
}

void pushbutton_sy::endSy()
{
    QVector<QString> par;
    par.append(sqdid);
    socket_space::sendMess(json_space::str2json(2006,par));
}

void pushbutton_sy::addMenu(){
    mu=new QMenu(this);

    mu->addAction(btAct1);
    if(dqzt=="0")
    {
        mu->addAction(btAct2);
    }
    if(dqzt=="1")
    {
        mu->addAction(btAct3);
    }

    mu->exec(QCursor::pos());

}

void pushbutton_sy::set_syxx(QVector<QVector<QString>> result)
{
    this->setText(result[0][0]);
}
shuyejm::shuyejm(QWidget *parent):QWidget(parent)
{
    vb=new QVBoxLayout();
    this->setLayout(vb);


}
void shuyejm::addBt(QString bt)
{
    //btsy=new pushbutton_sy(bt,this);
    //vb->addWidget(btsy);
}

void shuyejm::get_shenqingdid(QVector<QVector<QString>> result)
{
    if(count_shenqingdid==-1){
    count_shenqingdid=result.size();
    for(int i=0;i<result.size();i++)
    {
        res.append(result[i][0]);
    }
    count_bt=count_shenqingdid;
    //btsy=new pushbutton_sy[count_shenqingdid];
    }
    if(count_shenqingdid==0){
    QVector<QString> e;
    res.swap(e);
    for(int i=0;i<result.size();i++)
    {
        res.append(result[i][0]);
    }
    if(count_bt>0){
    for(int i=0;i<count_bt;i++)
    {
        delete btsy[i];
    }
    }
    //delete [] *btsy;
    count_shenqingdid=result.size();
    count_bt=count_shenqingdid;
    //btsy=new pushbutton_sy[count_shenqingdid];
    }
    QVector<QString> par;
    par.append(json_space::inJson(res));
    socket_space::sendMess(json_space::str2json(5,par));
    count_shenqingdid=0;

}
void shuyejm::get_syk(QVector<QVector<QString>> result)
{
    //vb->addWidget(btsy);
    for(int i=0;i<res.size();i++)
    {

        QString jieguo;
        QVector<QVector<QString>> result1;
        for(int j=0;j<result.size();j++){
        if(res[i]==result[j][0])
        {
            //jieguo+=result[j][3];
            result1.append(result[j]);
        }
        }
        btsy[i]=new pushbutton_sy(result1,this);
        vb->addWidget(btsy[i]);
        result1.clear();

    }
    count_bt=res.size();


}


sy_widget::sy_widget(QWidget *parent):QWidget(parent){
    hb=new QHBoxLayout(this);
    list=new listTab_sy();
    syjm=new shuyejm(this);
    hb->addWidget(list);
    hb->addWidget(syjm);
    this->setLayout(hb);
    connect(list,&listTab_sy::to_jm,syjm,&shuyejm::addBt);

}
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
pishidjs::pishidjs(QVector<QString> data,QWidget *parent):QWidget(parent),shuju(data)
{

    vb=new QVBoxLayout(this);
    hb=new QHBoxLayout();
    lab=new QLabel(this);
    lab->setText(shuju[0]+"\n"+shuju[2]);
    sqdid=shuju[1];
    bt1=new QPushButton(this);
    bt2=new QPushButton(this);
    bt3=new QPushButton(this);
    bt4=new QPushButton(this);
    bt5=new QPushButton(this);
    bar_time=new  QProgressBar(this);
    bar_time->setMinimum(0);
    bar_time->setMaximum(100);
    time1=new QTimer(this);
    bt1->setText("重计时");
    bt2->setText("结束");
    bt3->setText("取消");
    bt4->setText("录入结果");
    bt5->setText("开始计时");
    hb->addWidget(bt1);
    hb->addWidget(bt2);
    hb->addWidget(bt3);
    hb->addWidget(bt4);
    hb->addWidget(bt5);
    vb->addWidget(lab);
    vb->addLayout(hb);
    vb->addWidget(bar_time);
    this->setLayout(vb);
    time1->setInterval(1000);
    this->resize(100,100);
    //time1->start();
    bt1->setVisible(0);
    bt2->setVisible(0);
    bt3->setVisible(0);
    bt4->setVisible(0);
    connect(time1,&QTimer::timeout,this,&pishidjs::time_OUT);
    connect(bt5,&QPushButton::clicked,this,&pishidjs::start_jishi);
    connect(bt4,&QPushButton::clicked,this,&pishidjs::send_data);
    connect(bt3,&QPushButton::clicked,this,&pishidjs::quxiao);
    connect(bt2,&QPushButton::clicked,this,&pishidjs::end_jishi);




}
void pishidjs::send_data()
{
    emit emitBTmsg(sqdid);
}


void pishidjs::end_jishi()
{
    time1->stop();
    bt4->setVisible(1);
}
void pishidjs::start_jishi()
{

    QString tim=shuju[3];
    time_value_end=tim.toInt()*60;
    bar_time->setMaximum(time_value_end);
    bt1->setVisible(1);
    bt2->setVisible(1);
    bt3->setVisible(1);
    bt5->setVisible(0);
    time1->start();

}

void pishidjs::quxiao()
{
    bt1->setVisible(0);
    bt2->setVisible(0);
    bt3->setVisible(0);
    bt5->setVisible(1);
    time_value=0;
    time1->stop();
}

void pishidjs::time_OUT()//每秒触发
{
    time_value++;
    bar_time->setValue(time_value);
    if(time_value==time_value_end){
        time1->stop();
        bt4->setVisible(1);
    }

}

pishizhong::pishizhong(QWidget *parent):QWidget(parent)
{
    count_bt=0;
    layout=new QVBoxLayout();
    jglr= new pishijglr();

    this->setLayout(layout);


}
void pishizhong::addBt(QVector<QString> data)
{
    bt[count_bt]=new pishidjs(data,this);
    layout->addWidget(bt[count_bt]);
    connect(bt[count_bt],&pishidjs::emitBTmsg,this->jglr,&pishijglr::shows);
    count_bt++;
}


pishijglr::pishijglr()
{
    lab[0]=new QLabel("复核人1",this);
    lab[1]=new QLabel("复核人2",this);
    lab[2]=new QLabel("皮试结果",this);
    for(int i=0;i<5;i++)
    {
        edit[i]=new QLineEdit();
    }
    bt=new QPushButton("提交",this);
    lay=new QVBoxLayout(this);
    lay->addWidget(lab[0]);
    lay->addWidget(edit[0]);
    lay->addWidget(edit[1]);
    lay->addWidget(lab[1]);
    lay->addWidget(edit[2]);
    lay->addWidget(edit[3]);
    lay->addWidget(lab[2]);
    lay->addWidget(edit[4]);
    lay->addWidget(bt);
    //lay->addWidget(lab);
    this->setLayout(lay);
    connect(bt,&QPushButton::clicked,this,&pishijglr::luru1);
    //socket_space::sendMess(json_space::str2json(7,param));


}

void pishijglr::shows(QString s)
{
    sqlid=s;
    this->show();
}

void pishijglr::get_xx(QVector<QVector<QString>> result)
{
    if(result[0][0]!="2")
    {
        QMessageBox::information(NULL, "警告", "输入有误！",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    else{
        QVector<QString> param;

        param.append(edit[4]->text());
        param.append(sqlid);
        socket_space::sendMess(json_space::str2json(2008,param));
    }


}
void pishijglr::luru1()
{
    QVector<QString> param;
    for(int i=0;i<4;i++)
    {
        param.append(edit[i]->text());
    }
    socket_space::sendMess(json_space::str2json(6,param));

}

tab_pish::tab_pish(QWidget *parent):QTabWidget(parent)
{
    wait_pish=new QListWidget(this);
    pishiz=new pishizhong(this);
    //psan=new pishidjs(this);
    this->addTab(wait_pish,"等待皮试");
    this->addTab(pishiz,"皮试中");
    //connect(wait_pish,&QListWidget::itemClicked,this,&tab_pish::list_shuaxin);
    connect(this,&QTabWidget::currentChanged,this,&tab_pish::list_shuaxin);
    list_shuaxin(0);

}

void tab_pish::list_shuaxin(int x)
{
    if(x==0){
    QVector<QString> param;
    param.append("1");
    socket_space::sendMess(json_space::str2json(7,param));
    }
}

void tab_pish::get_liebiao(QVector<QVector<QString>> result)
{
    //disconnect(wait_pish,&QListWidget::itemClicked,this,&tab_pish::list_shuaxin);
    wait_pish->clear();
    for(int i=0;i<result.size();i++)
    {
        wait_pish->addItem(result[i][0]);
    }
    //connect(wait_pish,&QListWidget::itemClicked,this,&tab_pish::list_shuaxin);
}


pishixx::pishixx(QString s,bool y,QWidget *parent):QWidget(parent)
{
    lay=new QHBoxLayout(this);
    label=new QLabel(this);
    label->setText(s);
    edit=new QLineEdit();
    edit->setEnabled(y);
    lay->addWidget(label);
    lay->addWidget(edit);
    this->setLayout(lay);
}

QString pishixx::get_text()
{
    return edit->text();
}
void pishixx::clear()
{
    edit->setText("");

}


pishiry::pishiry(QWidget *parent):QWidget(parent)
{
    pishixxi[0] =new pishixx("姓名",false,this);
    pishixxi[1] =new pishixx("年龄",false,this);
    pishixxi[2] =new pishixx("申请单id",false,this);
    pishixxi[3] =new pishixx("皮试药品",false,this);
    pishixxi[4] =new pishixx("皮试时间",true,this);
    pishixxi[5] =new pishixx("皮试方法",true,this);
    vlay=new QVBoxLayout(this);
    bt1=new QPushButton("清空",this);
    bt2=new QPushButton("保存",this);
    for(int i=0;i<6;i++)
    {
        vlay->addWidget(pishixxi[i]);
    }
    vlay->addWidget(bt1);
    vlay->addWidget(bt2);
    this->setLayout(vlay);
    connect(bt1,&QPushButton::clicked,this,&pishiry::clear);
    connect(bt2,&QPushButton::clicked,this,&pishiry::baocun);
}


void pishiry::clear()
{
    for(int i=0;i<6;i++)
    {
       pishixxi[i]->clear();
    }
}

void pishiry::send_text(QListWidgetItem *w)
{
    QVector<QString> s;
    s.append(w->text());
    socket_space::sendMess(json_space::str2json(8,s));
}

void pishiry::set_text(QVector<QVector<QString>> result)
{
    pishixxi[2]->edit->setText(result[0][0]);
    pishixxi[0]->edit->setText(result[0][1]);
    pishixxi[3]->edit->setText(result[0][2]);
}
void pishiry::baocun()
{
    QVector<QString> vec;
    vec.append(pishixxi[0]->get_text());
    vec.append(pishixxi[2]->get_text());
    vec.append(pishixxi[3]->get_text());
    vec.append(pishixxi[4]->get_text());
    emit emitPishiryxx(vec);
}


pishi_jm::pishi_jm(QWidget *parent):QWidget(parent)
{
    pishick=new pishiry(this);
    pishitab=new tab_pish(this);
    //dia=new pishijglr();
    layout=new QHBoxLayout();
    layout->addWidget(pishick);
    layout->addWidget(pishitab);
    this->setLayout(layout);
    connect(pishitab->wait_pish,&QListWidget::itemClicked,pishick,&pishiry::send_text);
    connect(pishick,&pishiry::emitPishiryxx,pishitab->pishiz,&pishizhong::addBt);
}
