#ifndef JSON_SY_H
#define JSON_SY_H
#include <QString>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonDocument>

namespace json_space
{
    QString login_json(QString user,QString pass);
    QString str2json(int sqlid,QVector<QString> param);
    QString inJson(QVector<QString> param);
    int json2str(QString json,QVector<QString> &field,QVector<QVector<QString>> &result,QString &sqlid);
    QString get_Sqlid(QString json);





}


#endif // JSON_SY_H
