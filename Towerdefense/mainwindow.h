#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QTimer>       //定时器
#include "defetowerparent.h"    //防御塔父类
#include "monster.h"    //怪物类
#include <QLabel>

class MainWindow : public QWidget
{

public:
    int counter=0;
    QVector<Monster*> MonsterVec;
    MainWindow(int);            //构造
    void IrodMonsProgDefa(CoorStr** Waypointarr1, CoorStr* staco, int* PathLength, QLabel* victorylable);
    void DrawMapArr(QPainter& painter);
    void DrawMonster(QPainter& painter);
    void paintEvent(QPaintEvent *);
    ~MainWindow();
};

#endif  //MAINWINDOW_H
