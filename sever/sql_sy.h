#ifndef SQL_SY_H
#define SQL_SY_H

#include <stdio.h>
#include <mysql/mysql.h>
#include <string>
#include <vector>

class SQL_USE{
    public:
    SQL_USE();
   // ~SQL_USE();
    int getSelect(std::vector<std::vector<std::string> > &vec,std::string sql,std::vector<std::string> &vec1,int &row,int &column);
    int login_verty(std::string user,std::string pass);
    int do_sql(std::string sql);
    std::string get_sql(int sql_id);
    //std::vector<std::vector<std::string>> vec,
    private:
    MYSQL conn;
    //int res; /*执行sql語句后的返回标志*/
    //MYSQL_RES *res_ptr; /*指向查询结果的指针*/
    //MYSQL_FIELD *field; /*字段结构指针*/
    //MYSQL_ROW result_row; 

};


#endif