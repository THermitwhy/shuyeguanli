#ifndef SOCKET_SY_H
#define SOCKET_SY_H
#include <QTcpSocket>
#include <QString>
//QTcpSocket *Socket_sy;
extern QTcpSocket Socket_sy;
namespace socket_space{
    //QTcpSocket Socket_sy;

    int connect();
    int deleted();
    int sendMess(QString s);
    int Read_Data(QString &mess);
}


#endif // SOCKET_SY_H
