#include "sql_sy.h"
//#include "json.h"

SQL_USE::SQL_USE(){
    //MYSQL conn;
    //int res;
    mysql_init(&conn);
    if(mysql_real_connect(&conn,"localhost","root","200514why","his",0,NULL,CLIENT_FOUND_ROWS)){
        printf("successful! connect to mysql\n");
    }
    else{
        printf("error!");
    }

}
int SQL_USE::getSelect(std::vector<std::vector<std::string> > &vec,std::string sql,std::vector<std::string> &vec1,int &row,int &column){
    //std::vector<std::vector<std::string>> vec,
        
        mysql_query(&conn, "set names utf8");
		MYSQL_RES *res_ptr; /*指向查询结果的指针*/
        MYSQL_FIELD *field; /*字段结构指针*/
        MYSQL_ROW result_row; 
        /*下面这句话就是用mysql_query函数来执行我们刚刚传入的sql語句，
        这会返回一个int值，如果为0，证明語句执行成功*/
        int res;
        res = mysql_query(&conn, sql.c_str());
        //int row,column;
        if (res) 
		{ /*现在就代表执行失败了*/
            printf("Error： mysql_query !n");
            printf(sql.c_str());
            /*不要忘了关闭连接*/
           // mysql_close(&conn);
            return -1;
        }
		else 
		{ 
			/*现在就代表执行成功了*/
            /*将查询的結果给res_ptr*/
            res_ptr = mysql_store_result(&conn);
 
            /*如果结果不为空，就把结果print*/
            if (res_ptr) 
			{
                /*取得結果的行数和*/
                column = mysql_num_fields(res_ptr);
                row = mysql_num_rows(res_ptr) + 1;
                printf("查询到 %lu 行 n", row);
 
                /*输出結果的字段名*/
                for (int i = 0; field = mysql_fetch_field(res_ptr); i++){
                    vec1.push_back(field->name);
                    printf("%s", field->name);
                printf("\n");
                }
                /*按行输出結果*/
                for (int i = 1; i < row; i++)
				{
                    result_row = mysql_fetch_row(res_ptr);
                    std::vector<std::string> sql_res;
                    for (int j = 0; j < column; j++){
                        printf("%st", result_row[j]);   
                        sql_res.push_back(result_row[j]);
                    }
                    vec.push_back(sql_res);
                    printf("\n");
                }
                return 1;
            }
            else{
                return 0;
            }

}
}






int SQL_USE::login_verty(std::string user,std::string pass)
{
    mysql_query(&conn, "set names utf8");
    MYSQL_RES *result;
	//MYSQL_RES *res_ptr; /*指向查询结果的指针*/
    MYSQL_FIELD *field; /*字段结构指针*/
    MYSQL_ROW result_row; 	
        /*下面这句话就是用mysql_query函数来执行我们刚刚传入的sql語句，
        这会返回一个int值，如果为0，证明語句执行成功*/
    int res;
    res = mysql_query(&conn, "select count(*) from gy_ceshiyh ");
        
    if (res) 
	{ /*现在就代表执行失败了*/
        printf("Error： mysql_query !n");
        /*不要忘了关闭连接*/
        //mysql_close(&conn);
        return -1;
    }
    else{
        result = mysql_store_result(&conn);
        if (result) {
            
            return 1;
        }
        else{
            return 0;
        }

    }



}



std::string SQL_USE::get_sql(int sql_id)
{
    mysql_query(&conn, "set names utf8");
    int res;
    MYSQL_RES *result;
    MYSQL_ROW result_row;
		
        /*下面这句话就是用mysql_query函数来执行我们刚刚传入的sql語句，
        这会返回一个int值，如果为0，证明語句执行成功*/
    std::string sqlid=std::to_string(sql_id);
    sqlid="'"+sqlid;
    sqlid=sqlid+"'";
    sqlid="select SQL1 from XT_SELECTSQL1 where SQLID ="+sqlid;
    res = mysql_query(&conn, sqlid.c_str());
    if (res) 
	{ /*现在就代表执行失败了*/
        printf("Error： mysql_query in get_sql!n");
        printf(sqlid.c_str());
        /*不要忘了关闭连接*/ 
        //mysql_close(&conn);
        return "error";
    }
    else{
        result = mysql_store_result(&conn);
        if (result) {
            result_row = mysql_fetch_row(result);
            printf(result_row[0]);
            return result_row[0];
        }
        else{
            return "error";
        }

    }






}



int SQL_USE::do_sql(std::string sql)
{
    mysql_query(&conn, "set names utf8");
    int res;
    MYSQL_RES *result;
    MYSQL_ROW result_row;
    res = mysql_query(&conn, sql.c_str());
    if (res) 
	{ /*现在就代表执行失败了*/
        printf("Error： mysql_query in do_sql!n");
        printf(sql.c_str());
        /*不要忘了关闭连接*/ 
        //mysql_close(&conn);
        return 0;
    }
    else{
        return 1;

    }

}
//int main(){
    //std::vector<std::vector<std::string> > ve;//获取返回的sql值
    //int x,y;
    //std::vector<std::string> vec1;
    //SQL_USE sy("localhost","root","200514why","his");
   // sy.getSelect(ve,"select * from gy_ceshiyh",vec1,x,y);
    //std::string r = vec2json(vec1,ve);
    //std::cout<<r<<std::endl;


//}