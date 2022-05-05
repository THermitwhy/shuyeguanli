#ifndef MOER_H
#define MOER_H
#include <Windows.h>
#include "sapi.h"
#include <list>
#include <string>
#include <QPixmap>
#include <QPainter>
#include <QPrinter>

#include<QPrintPreviewDialog>
#include "sphelper.h"
#pragma comment(lib, "sapi.lib")
namespace other_use{



void printTO(QVector<QVector<QString>> result);
void drawPic(QPrinter *print1,QVector<QVector<QString>> result);
void createPix(QPixmap *pix,QVector<QVector<QString>> result);
class TTS
{
public:
    TTS();
    ~TTS();
    bool Speak(std::wstring);
    bool IsUseful();

private:
    ISpVoice*	m_pSpVoice;

    bool InitVoice();
    void StopVoice();
};
std::wstring StringToWString(const std::string& str);
int speak(std::string juzi);
int draw();

}

#endif // MOER_H
