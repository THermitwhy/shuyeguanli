#include "mainwindow_sy.h"
//#include "qmenu_WHY.h"


login_sy::login_sy()
    :QDialog()
{
    user=new QLineEdit(this);
    pass=new QLineEdit(this);
    log_in=new QPushButton("登录",this);
    connect_= new QPushButton("连接",this);
    lay=new QVBoxLayout();
    lay->addWidget(user);
    lay->addWidget(pass);
    lay->addWidget(log_in);
    lay->addWidget(connect_);
    this->setLayout(lay);
    user->setPlaceholderText("用户名");
    pass->setPlaceholderText("密码");
    connect(log_in,&QPushButton::clicked,this,&login_sy::login_);
    connect(connect_,&QPushButton::clicked,this,&login_sy::connect_to);
    connect(&Socket_sy,&QTcpSocket::readyRead,this,&login_sy::login_verity);
}


void login_sy::login_(){

    QVector<QString> vec;
    vec.append(user->text());
    vec.append(pass->text());

    socket_space::sendMess(json_space::str2json(1,vec));
    //if(user->text()=="汪华煜"&&pass->text()=="123")
    //{
    //    this->accept();
    //}
    //else
    //{
    //    QMessageBox::information(NULL, "Title", "登陆失败！",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    //}


}


void login_sy::login_verity()
{
    QVector<QString> field;
    QVector<QVector<QString>> result;
    QString sqlid;
    QString msg;
    socket_space::Read_Data(msg);
    json_space::json2str(msg,field,result,sqlid);
    if(result[0][0]=="0")
    {
        QMessageBox::information(NULL, "Title", "登陆失败！",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    else
    {
        this->accept();
    }
}
void  login_sy::connect_to()
{
    socket_space::connect();
}

MainWindow_sy::MainWindow_sy(QWidget *parent)
    : QMainWindow(parent)
{

    socket_space::connect();
    QMenu_sy = new QMenu_WHY();
    this->setMenuBar(QMenu_sy);
    //wdt=new sy_widget(this);
    //pishi=new pishi_jm(this);
    //setCentralWidget(pishi);
    connect(&Socket_sy,&QTcpSocket::readyRead,this,&MainWindow_sy::get_Data);
    connect(QMenu_sy->ac3,&QAction::triggered,this,&MainWindow_sy::set_Win_sy);
    connect(QMenu_sy->ac4,&QAction::triggered,this,&MainWindow_sy::set_Win_ps);
    /*
    connect(this,&MainWindow_sy::emitTolistsy1,wdt->list,&listTab_sy::read_mess);
    connect(this,&MainWindow_sy::emitSqdid,wdt->syjm,&shuyejm::get_shenqingdid);
    connect(this,&MainWindow_sy::emitSyk,wdt->syjm,&shuyejm::get_syk);
    */
    /*
    connect(this,&MainWindow_sy::emitPishilb,pishi->pishitab,&tab_pish::get_liebiao);
    connect(this,&MainWindow_sy::emiPishixx,pishi->pishick,&pishiry::set_text);//emiPishilr
    connect(this,&MainWindow_sy::emiPishilr,pishi->pishitab->pishiz->jglr,&pishijglr::get_xx);
    */

}

MainWindow_sy::~MainWindow_sy()
{
}

void MainWindow_sy::set_Win_sy()
{
    if(syOpenFlag==0){
     wdt=new sy_widget(this);
     if(psOpenFlag==1)
     {
         close_Win_ps();
     }
     setCentralWidget(wdt);
     connect(this,&MainWindow_sy::emitTolistsy1,wdt->list,&listTab_sy::read_mess);
     connect(this,&MainWindow_sy::emitSqdid,wdt->syjm,&shuyejm::get_shenqingdid);
     connect(this,&MainWindow_sy::emitSyk,wdt->syjm,&shuyejm::get_syk);
     }
    syOpenFlag=1;
}

void MainWindow_sy::set_Win_ps()
{
    if(psOpenFlag==0){
        pishi=new pishi_jm(this);
        if(syOpenFlag==1)
        {
            close_Win_sy();
        }
        setCentralWidget(pishi);
        connect(this,&MainWindow_sy::emitPishilb,pishi->pishitab,&tab_pish::get_liebiao);
        connect(this,&MainWindow_sy::emiPishixx,pishi->pishick,&pishiry::set_text);//emiPishilr
        connect(this,&MainWindow_sy::emiPishilr,pishi->pishitab->pishiz->jglr,&pishijglr::get_xx);
    }
    psOpenFlag=1;
}

void MainWindow_sy::close_Win_sy()
{   if(syOpenFlag){
    disconnect(this,&MainWindow_sy::emitTolistsy1,wdt->list,&listTab_sy::read_mess);
    disconnect(this,&MainWindow_sy::emitSqdid,wdt->syjm,&shuyejm::get_shenqingdid);
    disconnect(this,&MainWindow_sy::emitSyk,wdt->syjm,&shuyejm::get_syk);
    delete wdt;
    syOpenFlag=0;
    }
}

void MainWindow_sy::close_Win_ps()
{
    if(psOpenFlag){
    disconnect(this,&MainWindow_sy::emitPishilb,pishi->pishitab,&tab_pish::get_liebiao);
    disconnect(this,&MainWindow_sy::emiPishixx,pishi->pishick,&pishiry::set_text);//emiPishilr
    disconnect(this,&MainWindow_sy::emiPishilr,pishi->pishitab->pishiz->jglr,&pishijglr::get_xx);
    delete pishi;
    psOpenFlag=0;
    }
}


int MainWindow_sy::tishi(){
    //QMessageBox::information(NULL, "Title", "Content",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    socket_space::connect();
    return 1;
}

void MainWindow_sy::get_Data()
{
    QString message;
    QVector<QString> field;
    QVector<QVector<QString>> result;
    QString sqlid;
    socket_space::Read_Data(message);
    int ret=json_space::json2str(message,field,result,sqlid);
    if(ret!=0)
    {
        if(sqlid!="error")
        {
            if(sqlid=="1")
            {

            }
            else if(sqlid=="2")
            {

            }
            else if(sqlid=="3")
            {
                emit emitTolistsy1(result);

            }
            else if(sqlid=="4")
            {

                emit emitSqdid(result);
            }
            else if(sqlid=="5")
            {
                emit emitSyk(result);//
            }
            else if(sqlid=="6")
            {

                emit emiPishilr(result);
            }
            else if(sqlid=="7")
            {
                emit emitPishilb(result);
            }
            else if(sqlid=="8")
            {
                emit emiPishixx(result);
            }


        }
    }



}
