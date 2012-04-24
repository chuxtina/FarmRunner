#ifndef EMAGWINDOW_H
#define EMAGWINDOW_H
#include <QtGui>
#include <QFrame>
#include <QWidget>
#include "emag.h"

 //class QLCDNumber;
 //class QLabel;
// class QPushButton;

#include <QString>
#include <QLCDNumber>
#include <QLabel>
#include <QPushButton>


//class Emag;
//#include "emag.h"

 class EmagWindow : public QWidget
 {
     Q_OBJECT

 public:
     EmagWindow();

 private:
     QLabel *createLabel(const QString &text);
     Emag *board;
     QLCDNumber *scoreLcd;
     QLCDNumber *levelLcd;
     QLCDNumber *livesLcd;
     QPushButton *startButton;
     QPushButton *quitButton;
     QPushButton *pauseButton;
 };

 #endif
