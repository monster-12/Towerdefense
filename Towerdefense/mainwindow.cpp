#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QDebug>
#include<QTimer>
#include <cmath>
#include <QPushButton>
QVector<Monster*> MonsterVec;

#define InsterMonster(PathNum, StaCoorNum, MonsterId)

//路线
void MainWindow::IrodMonsProgDefa(CoorStr** Waypointarr1, CoorStr* staco, int* PathLength, QLabel* victorylable)
{
    CoorStr** pointarr[] = {Waypointarr1};

    /*插入怪物*/
    if(counter >= 1 && counter <= 10)
    {
        InsterMonster(0, 0, 1); //第几条路径、第几个起始点、怪物编号
    }
    else if(counter > 10 && counter <= 20)
    {
        InsterMonster(0, 0, 1);
        InsterMonster(0, 0, 2);
    }
    else if (counter > 20 && counter <= 35)
    {
        InsterMonster(0, 0, 3);
        InsterMonster(0, 0, 2);
    }
    else if (counter > 35 && counter <= 50)
    {
        InsterMonster(0, 0, 4);
        InsterMonster(0, 0, 3);
        InsterMonster(0, 0, 2);
    }
    if(counter > 50 && counter <= 56)
    {
        InsterMonster(0, 0, 3);
        InsterMonster(0, 0, 3);
    }
    if (counter > 52 && counter <= 71)
    {
        InsterMonster(0, 0, 5);
        InsterMonster(0, 0, 4);
        InsterMonster(0, 0, 3);
        InsterMonster(0, 0, 2);
    }

    if (counter > 71 && MonsterVec.empty())   //时间大于71且怪物数组为空时游戏胜利
        victorylable->show();

    counter++;          //计数器+1
    update();
}

//根据数组画出地图函数
//由绘图函数调用
void MainWindow::DrawMapArr(QPainter& painter)
{
    int Map_1[16][26] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    int Map[16][26];    //用于拷贝不同的关卡数组
    memcpy(Map, Map_1, sizeof(Map));
    for (int j = 0; j < 16; j++)
        for (int i = 0; i < 26; i++)
        {
            switch (Map[j][i])
            {
            case 0:     /*星空*/
                painter.drawPixmap(i * 40, j * 40, 40, 40,
                    QPixmap(":/image/GrassBlock.png"));
                break;
            case 1:     /*路线*/
                painter.drawPixmap(i * 40, j * 40, 40, 40,
                    QPixmap(":/image/GroundBlock.png"));
                break;
            case 2:     /*防御塔安放处*/
                painter.drawPixmap(i * 40, j * 40, 80, 80,
                    QPixmap(":/image/StoneBrick.png"));
                break;
            case 3:     /*月亮*/
                painter.drawPixmap(i * 40, j * 40, 40, 40,
                    QPixmap(":/image/GroundBlock.png"));

                break;
            }
        }
}



//画出怪物
void MainWindow::DrawMonster(QPainter& painter)
{
    for (auto moni : MonsterVec)//画出怪物
        painter.drawPixmap(moni->GetX(), moni->GetY(), moni->GetWidth(), moni->GetHeight(), QPixmap(moni->GetImgPath()));
}



//绘图事件
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);     //创建画家类

    painter.setRenderHint(QPainter::Antialiasing);    //设置抗锯齿

    DrawMapArr(painter);        //画出地图

    DrawMonster(painter);       //画出怪物

}

MainWindow::~MainWindow()
{
    for (auto it = MonsterVec.begin(); it != MonsterVec.end(); it++)//释放monster
    {
        delete *it;
        *it = NULL;
    }
}


