#include "moer.h"

namespace other_use{


void printTO(QVector<QVector<QString>> result)
{
   QPixmap pm("D:/a1.jpg");
   QPrinter printer(QPrinter::HighResolution);
       //自定义纸张大小，特别重要，不然预览效果极差
       printer.setPageSize(QPageSize::A4);
       printer.setFullPage(1);
       drawPic(&printer,result);
       //printer.setPaperSize(QSizeF(70, 50.3), QPrinter::Millimeter);
       //QPrintPreviewDialog preview(&printer);// 创建打印预览对话框
       //preview.setMinimumSize(1000,600);


}

void drawPic(QPrinter *print1,QVector<QVector<QString>> result){
        QPixmap pix = QPixmap(800,600);
        //这个函数算是画模板的函数吧，毕竟打印时有模板的
        createPix(&pix,result);
        pix.save("D:\a2.jpg");
        //纵向：Portrait 横向：Landscape
       // print1->setO
        //获取界面的图片
        QPainter painterPixmap;
        painterPixmap.begin(print1);
        QRect rect = painterPixmap.viewport();
        int x = rect.width() / pix.width();
        int y = rect.height() / pix.height();
        //设置图像长宽是原图的多少倍
        painterPixmap.scale(x, y);
        painterPixmap.drawPixmap(0, 0, pix);
        painterPixmap.end();
    }
    void createPix(QPixmap *pix,QVector<QVector<QString>> result)
    {
        QString res;
        for(int i=0;i<result.size();i++)
        {
            QString xinxi=result[i][3]+result[i][4]+result[i][5]+"\n";
            res+=xinxi;
        }
        res+="本院次数："+result[0][1]+"已执行次数："+result[0][2];
        QPainter *painter = new QPainter();
        painter->begin(pix);
        painter->setRenderHint(QPainter::Antialiasing, true);
        // 设置画笔颜色、宽度
        painter->setPen(QPen(QColor(255, 255, 255), 2));
        // 设置画刷颜色
        painter->setBrush(QColor(255, 255, 255));
        QRect rect(0,0,800,600);
        //整张图设置画刷白底
        painter->fillRect(rect,QColor(255, 255, 255));
        painter->drawRect(rect);
        //画数据部分的线条
        painter->setPen(QPen(QColor(0, 0, 0), 1));
        QVector<QLine> lines;
        lines.append(QLine(QPoint(50,50),QPoint(750,50)));//上边
        lines.append(QLine(QPoint(750,50),QPoint(750,550)));//右边
        lines.append(QLine(QPoint(50,550),QPoint(750,550)));//下边
        lines.append(QLine(QPoint(50,50),QPoint(50,550)));//左边
        lines.append(QLine(QPoint(50,120),QPoint(750,120)));//名称下边
        lines.append(QLine(QPoint(50,180),QPoint(750,180)));//信息下边
        lines.append(QLine(QPoint(50,200),QPoint(750,200)));//条目下边
        lines.append(QLine(QPoint(50,490),QPoint(750,490)));//数据下边
        //lines.append(QLine(QPoint(120,180),QPoint(120,200)));//类型分割边
        //lines.append(QLine(QPoint(190,180),QPoint(190,200)));//类型分割边
        //lines.append(QLine(QPoint(260,180),QPoint(260,200)));//类型分割边
        //lines.append(QLine(QPoint(330,180),QPoint(330,200)));//类型分割边
        //lines.append(QLine(QPoint(400,180),QPoint(400,490)));//结果和曲线分割边
        painter->drawLines(lines);
        QFont font;
        font.setPointSize(13);
        font.setFamily("黑体");

        font.setItalic(true);
        painter->setFont(font);
        //第一部分
        painter->drawText(50,50,700,40,Qt::AlignCenter,"X医院");//单位名称
        //painter->drawText(QPoint(650,110),"No:");
        font.setPointSize(20);
        painter->setFont(font);
        painter->drawText(50,80,700,40,Qt::AlignCenter,"输液卡");//报告名称
        font.setPointSize(10);
        painter->setFont(font);
        //第二部分
        //painter->drawText(50,120,700,60,Qt::AlignVCenter,QString("样本ID： ")+QString("11111111"));
        //painter->drawText(210,120,700,60,Qt::AlignVCenter,QString("标本类型： ")+QString("ABC"));
        //painter->drawText(370,120,700,60,Qt::AlignVCenter,QString("检测方法： ")+"ui->lE_means->text()");
        //painter->drawText(600,120,700,60,Qt::AlignVCenter,QString("仪器： ")+"zzz");
        //第三部分
       // painter->drawText(50,180,70,20,Qt::AlignCenter,"序号");
        //painter->drawText(120,180,70,20,Qt::AlignCenter,"检测项目");
        //painter->drawText(190,180,70,20,Qt::AlignCenter,"Ct");
        //painter->drawText(260,180,70,20,Qt::AlignCenter,"检测下限");
        //painter->drawText(330,180,70,20,Qt::AlignCenter,"结果");
        //第四部分
        painter->drawText(50,210,res);
        //painter->drawText(120,210,70,20,Qt::AlignCenter,"我");
        //painter->drawText(190,210,70,20,Qt::AlignCenter,"真的");
        //painter->drawText(260,210,70,20,Qt::AlignCenter,"不知道");
       // painter->drawText(330,210,70,20,Qt::AlignCenter,"写啥");
        //第五部分
        painter->drawText(50,490,700,30,Qt::AlignVCenter,QString("姓名： ")+"ui->lE_inspect->text()");
        painter->drawText(230,490,700,30,Qt::AlignVCenter,QString("病人id： ")+"ui->lE_code->text()");
        //painter->drawText(410,490,700,30,Qt::AlignVCenter,QString("检验者： ")+"ui->lE_detection->text()");
        painter->drawText(590,490,700,30,Qt::AlignVCenter,QString("审核者： ")+"ui->lE_audit->text()");
        painter->drawText(50,520,700,30,Qt::AlignVCenter,QString("送检日期： ")+"ui->lE_inspectDate->text()");
        painter->drawText(410,520,700,30,Qt::AlignVCenter,QString("报告日期： ")+"ui->lE_reportDate->text()");

        painter->end();


}
TTS::TTS()
{
    m_pSpVoice = nullptr;
}


TTS::~TTS()
{
    StopVoice();
    ::CoUninitialize();
}

bool TTS::InitVoice()
{
    HRESULT ret = ::CoInitialize(NULL);
    ret = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_INPROC_SERVER, IID_ISpVoice, (void**)&m_pSpVoice);
    if (0 == ret && m_pSpVoice)
    {
        m_pSpVoice->SetVolume(80);

        IEnumSpObjectTokens *pSpEnumTokens = NULL;
        if (SUCCEEDED(SpEnumTokens(SPCAT_VOICES, NULL, NULL, &pSpEnumTokens)))		//找到lili语音进行朗读, 否则就跳出
        {
            ISpObjectToken *pSpToken = NULL;
            while (SUCCEEDED(pSpEnumTokens->Next(1, &pSpToken, NULL)) && pSpToken != NULL)
            {
                LPWSTR pId = new WCHAR[32];
                pSpToken->GetId(&pId);

                int nLen = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)pId, -1, NULL, 0, NULL, NULL);

                char *s = new char[nLen + 1];
                WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)pId, -1, s, nLen, NULL, NULL);

                if (0 == strcmp(s, ("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Speech\\Voices\\Tokens\\MS-Lili-2052-20-DSK")))
                {
                    m_pSpVoice->SetVoice(pSpToken);      // 设置lili语音
                    pSpToken->Release();
                    delete[] s;
                    break;
                }
                delete[] s;
                pSpToken->Release();
            }
            pSpEnumTokens->Release();
        }
        return true;
    }
    else
    {

    }
    return false;
}

bool TTS::Speak(std::wstring word)
{
    StopVoice();
    if (InitVoice())
    {
        HRESULT ret = m_pSpVoice->Speak(word.c_str(), SPF_ASYNC, NULL);
        return ret;
    }
    else
    {
        return false;
    }

}

bool TTS::IsUseful()
{
    bool bRet = InitVoice();
    StopVoice();
    return bRet;
}

void TTS::StopVoice()
{
    if (m_pSpVoice!=nullptr)
    {
        m_pSpVoice->Release();
    }
}

std::wstring StringToWString(const std::string& str)
{
    int num = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
    wchar_t *wide = new wchar_t[num];
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, wide, num);
    std::wstring w_str(wide);
    delete[] wide;
    return w_str;
}

int speak(std::string juzi){

    TTS ts;
    ts.Speak(StringToWString(juzi));

    return 1;
}

int draw(){
    QPixmap p("D:\a1.jpg");
    QPainter pa;
    QPrinter printer;
    pa.begin(&printer);
    pa.drawPixmap(200,3000,p);
    pa.end();
    return 1;





}

}
