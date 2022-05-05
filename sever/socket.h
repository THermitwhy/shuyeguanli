
#ifndef SOCKET_H
#define SOCKET_H
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/sendfile.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<unistd.h>
#include<string.h>
#include "json.h"


class socket_sy{
public:
    
    socket_sy();
    int setPort(int port);
    int start();
    int accep();
    void Close();
    //void recv();
private:
    int Port;
    int sock;   
    int connfd;
};

int mess2json(std::string request,std::string &sendmess);


#endif