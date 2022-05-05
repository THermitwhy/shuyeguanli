// ConsoleApplication14.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "json.h"

using namespace rapidjson;

//std::string createObjectJson()
//{
//	rapidjson::Document doc;
//	doc.SetObject();
//	rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();
//	//成员1
//	rapidjson::Value str(rapidjson::kStringType);
//	str.SetString("kexue");
//	//成员2
//	rapidjson::Value ary(rapidjson::kArrayType);
//	ary.PushBack("zhai", allocator).PushBack("wang", allocator).PushBack("luo", allocator);
//	//加入doc中
//	doc.AddMember("company", str, allocator);
//	doc.AddMember("member", ary, allocator);
//	//转化为string
//	rapidjson::StringBuffer buffer;
//	rapidjson::Writer<rapidjson::StringBuffer> write(buffer);
//	doc.Accept(write);
//	std::string json = buffer.GetString();
//	return json;
//}


std::string vec2json(std::vector<std::string>& vec1, std::vector<std::vector <std::string>>& vec,std::string sqlid)
{

    int vec1_size = vec1.size();
    int vec_size = vec.size();
    Document doc;
    doc.SetObject();
    rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();

    
    doc.AddMember("sqlid",StringRef(sqlid.c_str()), allocator);
    rapidjson::Value field(rapidjson::kArrayType);
    for(int j = 0; j < vec1_size; j++) 
    {
        field.PushBack(StringRef(vec1[j].c_str()), allocator);

    }
    doc.AddMember("field", field, allocator);
    rapidjson::Value info_array(rapidjson::kArrayType);


    //std::string c = "why";
    for (int i = 0; i < vec_size; i++) {
        rapidjson::Value info_object(rapidjson::kArrayType);
        //info_object.SetObject();
        for (int j = 0; j < vec1_size; j++) {
            int k = 1;
            
            info_object.PushBack(StringRef(vec[i][j].c_str()), allocator);
        }
        




        info_array.PushBack(info_object, allocator);

    }

    doc.AddMember("Info", info_array, allocator);


    // 3. Stringify the DOM
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    doc.Accept(writer);
    std::cout << buffer.GetString() << std::endl;
    return buffer.GetString();



} 


int str2sql(std::vector<std::string> str,std::string &sql){
    for(int i=0;i<str.size();i++)
    {
        std::string param="A"+std::to_string(i);
        std::regex r(param.c_str());
        sql=std::regex_replace(sql,r,str[i].c_str());
    }
    
    return 1;


}

int json2param(std::string json_str,int &sqlid, int &count, std::vector<std::string> &param)
{
    rapidjson::Document doc;
    doc.Parse(json_str.c_str());
    if (doc.HasParseError())
    {
        printf("parse失败:%d\n", doc.GetParseError());
        printf(json_str.c_str());
        return 0;
    }
    else
    {
        rapidjson::Value& json_obj = doc;

        if (json_obj.IsObject())
        {
            if (json_obj.HasMember("SQLID"))//假设有name成员
            {
                rapidjson::Value& json_SQLID = json_obj["SQLID"];
                if (json_SQLID.IsInt())
                {
                    sqlid = json_obj["SQLID"].GetInt();

                }
                else
                {
                    return 0;
                }
            }
            if (json_obj.HasMember("count"))
            {
                rapidjson::Value& json_count = json_obj["count"];
                if (json_count.IsInt())
                {
                    count = json_count.GetInt();
                }
                else
                {
                    return 0;
                }
            }
            if (json_obj.HasMember("param"))
            {
                rapidjson::Value& json_param = json_obj["param"];
                if (json_param.IsArray())
                {
                    
                    for (rapidjson::SizeType i = 0; i < json_param.Size(); i++)
                    {
                        rapidjson::Value& json_value = json_param[i];
                        param.push_back(json_value.GetString());
                    }
                }
                else
                {
                    return 0;
                }
            }
        }
        return 1;
    }
}

//int main() {
    // 1. Parse a JSON string into DOM.
    //const char* json = "{\"Info\":[{\"lots\":10,\"order_algorithm\":\"01\",\"buy_close\":9000,\"spread_shift\":0,\"position_b_sell\":0,\"position_a_buy_today\":0,\"position_a_buy_yesterday\":0,\"sell_open\":-9000,\"list_instrument_id\":[\"rb1705\",\"rb1701\"],\"position_b_buy_today\":0,\"buy_open\":-9000,\"position_a_sell_yesterday\":0,\"strategy_id\":\"02\",\"position_b_buy\":0,\"a_wait_price_tick\":1,\"trade_model\":\"boll_reversion\",\"b_wait_price_tick\":0,\"sell_close\":9000,\"only_close\":0,\"order_action_limit\":400,\"is_active\":1,\"lots_batch\":1,\"position_a_sell\":0,\"position_b_buy_yesterday\":0,\"user_id\":\"063802\",\"position_a_buy\":0,\"trader_id\":\"1601\",\"position_a_sell_today\":0,\"stop_loss\":0,\"position_b_sell_today\":0,\"position_b_sell_yesterday\":0,\"on_off\":0},{\"lots\":20,\"order_algorithm\":\"02\",\"buy_close\":9000,\"spread_shift\":0,\"position_b_sell\":0,\"position_a_buy_today\":0,\"position_a_buy_yesterday\":0,\"sell_open\":-9000,\"list_instrument_id\":[\"ni1705\",\"ni1701\"],\"position_b_buy_today\":0,\"buy_open\":-9000,\"position_a_sell_yesterday\":0,\"strategy_id\":\"01\",\"position_b_buy\":0,\"a_wait_price_tick\":1,\"trade_model\":\"boll_reversion\",\"b_wait_price_tick\":0,\"sell_close\":9000,\"only_close\":0,\"order_action_limit\":400,\"is_active\":1,\"lots_batch\":1,\"position_a_sell\":0,\"position_b_buy_yesterday\":0,\"user_id\":\"063802\",\"position_a_buy\":0,\"trader_id\":\"1601\",\"position_a_sell_today\":0,\"stop_loss\":0,\"position_b_sell_today\":0,\"position_b_sell_yesterday\":0,\"on_off\":0}],\"MsgSendFlag\":0,\"MsgErrorReason\":\"IDorpassworderror\",\"MsgRef\":1,\"MsgType\":3,\"MsgResult\":0}";
    //std::cout << json << std::endl;
    //std::cout << "\n" << std::endl;
    //std::cout << "|==================|" << std::endl;
   // std::cout << "||rapidjson output||" << std::endl;
    //std::cout << "|==================|" << std::endl;
    //Document doc;
    //doc.SetObject();
    //rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();

    //doc.AddMember("MsgSendFlag", 1, allocator);
    //doc.AddMember("MsgErrorReason", "IDorpassworderror", allocator);
    //doc.AddMember("MsgRef", 1, allocator);

    //rapidjson::Value info_array(rapidjson::kArrayType);

    //for (int i = 0; i < 2; i++) {
    //    rapidjson::Value info_object(rapidjson::kObjectType);
    //    info_object.SetObject();
    //    info_object.AddMember("lots", 10 + i, allocator);
    //    info_object.AddMember("order_algorithm", "01", allocator);

    //    
    //    

    //   
    //    info_array.PushBack(info_object, allocator);

    //}

    //doc.AddMember("Info", info_array, allocator);


    //// 3. Stringify the DOM
    //StringBuffer buffer;
    //Writer<StringBuffer> writer(buffer);
    //doc.Accept(writer);
    //std::cout << buffer.GetString() << std::endl;
    //return 0;


    //std::vector<std::string> a;
    //a.push_back("a");
    //a.push_back("b");
    //std::vector<std::vector <std::string> > b;
    //for (int i = 0; i < 3; i++) {
    //    std::vector<std::string> c;
    //    c.push_back("1");
    //    c.push_back("2");
     //   b.push_back(c);


    //}
    //std::string shuchu = vec2json(a, b);
    //std::cout << shuchu << std::endl;





//}



