#include "mainwindow_sy.h"
#include "qmenu_WHY.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>


QTcpSocket Socket_sy;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "SYGL_WHY_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    //login_sy login;
    //login.setAttribute(Qt::WA_QuitOnClose, true);
    //int rec=login.exec();
    //if(rec==QDialog::Accepted)
   // {
        MainWindow_sy w;
        w.show();
        return a.exec();
    //}
    //else{

    //a.quit();
    //}
}
