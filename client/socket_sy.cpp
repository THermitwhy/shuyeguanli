#include "socket_sy.h"




namespace socket_space{
//QTcpSocket Socket_sy;
QString json;
int connect(){
    //QTcpSocket Socket_sy;
    //Socket_sy.connectToHost("175.24.187.109",7799);
    //Socket_sy.abort();
    Socket_sy.connectToHost("175.24.187.109",7799);

    return 1;


}
int deleted(){

    //delete Socket_sy;
    Socket_sy.disconnect();

    return 1;
}


int sendMess(QString s){
    Socket_sy.write(s.toStdString().c_str());
    return 1;


}

int Read_Data(QString &mess)
{
    QByteArray buffer;
    //读取缓冲区数据
    buffer = Socket_sy.readAll();
    if(!buffer.isEmpty())
        {
            QString str ;
            mess=QString(buffer);
            return 1;

        }
    //json=mess;
    return 0;
}

}
