#include "json_sy.h"


namespace json_space
{
QString login_json(QString user,QString pass)
{
    QJsonObject json;
    QJsonArray array;

    json.insert("SQLID",001);
    json.insert("count",2);
    array.append(user);
    array.append(pass);
    json.insert("param",array);
    return QJsonDocument(json).toJson();

}

QString inJson(QVector<QString> param)
{
    QVector<QString> param2;
    int i=param.size();
    QString param3;
    for(int j=0;j<i;j++)
    {
        param2.append("'"+param[j]+"'");
    }
    for(int j=0;j<i-1;j++)
    {
        param3+=param2[j]+",";
    }
    param3+=param2[i-1];
    return param3;
}


QString str2json(int sqlid,QVector<QString> param)
{
    QJsonObject json;
    QJsonArray array;
    json.insert("SQLID",sqlid);
    json.insert("count",param.size());
    for(int i=0;i<param.size();i++)
    {
        array.append(param[i]);
    }
    json.insert("param",array);
    QString ss=QJsonDocument(json).toJson();

    return QJsonDocument(json).toJson();

}


QString get_Sqlid(QString json){
    QByteArray data=QByteArray(json.toUtf8());
    QJsonParseError jsonError;
    QJsonDocument jso = QJsonDocument::fromJson(data, &jsonError);//Qt5新类
    if (jsonError.error == QJsonParseError::NoError)
    {
        if(jso.isObject())
        {
            QJsonObject json_obj=jso.object();
            if(json_obj.contains("sqlid"))
            {
                QJsonValue value=json_obj.value("sqlid");
                QString sqlid=value.toString();
                return sqlid;

            }
            else
            {
                return "error";
            }
        }
        else
        {
            return "error";
        }
    }
    else
    {
        return "error";
    }
}
int json2str(QString json,QVector<QString> &field,QVector<QVector<QString>> &result,QString &sqlid)
{
    QByteArray data=QByteArray(json.toUtf8());
    QJsonParseError jsonError;//Qt5新类
    QJsonDocument jso = QJsonDocument::fromJson(data, &jsonError);//Qt5新类
    if (jsonError.error == QJsonParseError::NoError)
    {
        if(jso.isObject())
        {

            QJsonObject json_obj=jso.object();
           // QVector<QVector<QString>> result;
            //QVector<QString> field;
            if(json_obj.contains("field"))
            {
                QJsonValue value=json_obj.value("field");
                if(value.isArray())
                {
                    QJsonArray jsonarray_field=value.toArray();
                    for(int i=0;i<jsonarray_field.count();i++)
                    {
                        QJsonValue childvalue=jsonarray_field[i];
                        field.append(childvalue.toString());
                    }

                }
            }
            if(json_obj.contains("sqlid"))
            {
                QJsonValue value=json_obj.value("sqlid");
                sqlid=value.toString();
            }
            if(json_obj.contains("Info"))
            {
                QJsonValue value=json_obj.value("Info");
                if(value.isArray())
                {
                    QJsonArray jsonarray_Info=value.toArray();
                    for(int i=0;i<jsonarray_Info.count();i++)
                    {
                        QJsonArray arrayvalue=jsonarray_Info[i].toArray();
                        QVector<QString> sult;
                        for(int j=0;j<arrayvalue.count();j++)
                        {
                            QJsonValue childvalue=arrayvalue[j];

                            sult.append(childvalue.toString());

                        }
                        result.append(sult);
                        //for(int j=0;j<jsonarray_Info[i].count())
                        //QJsonValue childvalue=jsonarray_Info[i];
                        //field.append(childvalue.toString());
                    }
                }
                else
                {
                    return 0;
                }
            }
        }
        else
        {
            return 0;
        }
        return 1;

    }
    else
    {
        return 0;
    }
}





}
