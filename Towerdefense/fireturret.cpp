#include "fireturret.h"

//火防御塔类函数实现
//构造
FireTurret::FireTurret(int x, int y, int FUpLeftX, int FUpLeftY, int Fwidth, int Fheight)
{

    mx = x, my = y;
    BaseImgPath = QString(":/image/FireBottleBase.png");
    DefImgPath = QString(":/image/FireBottle.png");
    width = Fwidth, height = Fheight;
    UpLeftX = FUpLeftX, UpLeftY = FUpLeftY;

    Range = 170;    //射程

    BullPath = QString(":/image/Shells1.png");
    bullwidth = 40, bullheight = 40;           //子弹大小

    attack = 65;    //攻击力

}
