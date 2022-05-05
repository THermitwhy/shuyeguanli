
#define SOCKET_H
#include<stdio.h>
#include<thread>
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
#include<iostream>
#include "json.h"
#include "lua_CPP.h"
#define MAX_THREAD 5
/*
lua_newstate *L;
int loadLuaFile(lua_newstate *L,const char *fileName)
{
    int bRet = luaL_loadfile(L, fileName);
    if(bRet)
    {
        std::cout<<"luaL_loadfile error"<<std::endl;
        return -1;
    }
    bRet = lua_pcall(L, 0,0,0);
    if(bRet)
    {
        std::cout<<"lua_pcall error"<<std::endl;
        return -2;
    }
    return 1;
}

int useLua(Lua_newstate *L,const char *sqlid)
{
    int bRet = Lua_getglobal(L,"TypeJudgment");
    if(bRet)
    {
        std::cout<<"lua_getglobal error"<<std::endl;
        return -1;
    }
    bRet = Lua_pushstring(L,sqlid);
    if(bRet)
    {
        std::cout<<"lua_pushstring error"<<std::endl;
        return -2;
    }
    bRet = Lua_pcall(L,1,2,0);
    if(bRet)
    {
        std::cout<<"lua_pcall error"<<std::endl;
        return -3;
    }
    
}
*/
//SQL_USE sy;
int mess2json(std::string request,std::string &sendmess)
{
    SQL_USE sql_use;
    int sqlid,count,param;
    std::vector<std::string> params;
    printf(request.c_str());
    if(json2param(request,sqlid,count,params)==0)
    {
        return 0;
    }
    else
    {
        int param;
        std::vector<std::string> vec_field;
        std::vector<std::vector<std::string> > vec_result;
        
        loadLua(vec_field,vec_result,param,sqlid,params);
        if(param==1)
        {
            sendmess=vec2json(vec_field,vec_result,std::to_string(sqlid));
            return 1;
        }
        if(param==2)
        {
            
            return 2;
        }
        else{
            return 0;
        }
}
}

int do_sock(int connfd)
{
    while(connfd)
    {
    char request[1024];
    if(recv(connfd,request,sizeof(request),0)<=0){
        connfd=0;
        break;
    }

    //std::string reques;
    //reques=request;
    //std::cout<<reques<<std::endl;
    printf("%s\n",request);
    request[strlen(request)+1]='\0';
    printf("%s\n",request);
    std::string sendme;
    int ques=mess2json(request,sendme);
    bzero(request,1024);
    if(ques=1)
    {
        char req[1024];
        strcpy(req,sendme.c_str());
        //req[strlen(req)+1]="\0";
        send(connfd,req,strlen(req),0);
    }
    else if(ques=2){
        continue;
    }
    else{
        break;
    }
    }
    close(connfd);
    return 1;
}


int main()
{
    
    int sock;
    std::thread td[MAX_THREAD];
    int num_thread=0;
    
    struct sockaddr_in sever_address;
    bzero(&sever_address,sizeof(sever_address));
    sever_address.sin_family = PF_INET;
    sever_address.sin_addr.s_addr = htons(INADDR_ANY);
    sever_address.sin_port = htons(7799);
 
    sock = socket(AF_INET,SOCK_STREAM,0);
 
    assert(sock>=0);
 
    int ret = bind(sock, (struct sockaddr*)&sever_address,sizeof(sever_address));
    assert(ret != -1);
 
    ret = listen(sock,1);
    assert(ret != -1);
    
    //int i=8; 

  while(1){
    int connfd;
    struct sockaddr_in client;
    socklen_t client_addrlength = sizeof(client);
	printf("接受中\n");
    //std::vector<std::string> v1;
    //v1.push_back("why");
    //v1.push_back("12345");
    //std::string sq="select count(*) from gy_ceshiyh where user='A0' and password='A1'";
    //str2sql(v1,sq);
    
    connfd = accept(sock, (struct sockaddr*)&client, &client_addrlength);
	printf("接受数据!\n");
        if(connfd<=0)
        {
            std::cout<<sizeof(client)<<std::endl;
            printf("errno\n");
	    continue;
        }

        td[num_thread]=std::thread(do_sock,connfd);
        num_thread++;
        /*
        while(connfd){
		printf("successeful connected!\n");
                char request[1024];
                if(recv(connfd,request,sizeof(request),0)<=0){
                    connfd=0;
                    break;
                };

                //std::string reques;
                //reques=request;
                //std::cout<<reques<<std::endl;
                printf("%s\n",request);
                request[strlen(request)+1]='\0';
                printf("%s\n",request);
                std::string sendme;
                int ques=mess2json(request,sendme);
                bzero(request,1024);
                if(ques=1)
                {
                    char req[1024];
                    strcpy(req,sendme.c_str());
                    //req[strlen(req)+1]="\0";
                    send(connfd,req,strlen(req),0);
                }
                else if(ques=2){
                    continue;
                }
                else{
                    break;
                }
                //const char *re=request;
                //send(connfd,request,strlen(request),0);
                //printf("successeful!\n");
                //char buf[520]="hellow";//HTTP响应
               // int s = send(connfd,buf,strlen(buf),0);//发送响应
                //printf("send=%d\n",s);
                //int fd = open("hello.html",O_RDONLY);//消息体
                //sendfile(connfd,fd,NULL,2500);//零拷贝发送消息体
                //close(fd);
                
			
        }
        */
	//close(connfd);
		
	
	//close(sock);
    printf("断开!\n");
    
    
}
close(sock);
}
