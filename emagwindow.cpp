//#include <QtGui>
#include <QDesktopWidget>
//#include <QApplication>
//#include "emag.h"

#include "emagwindow.h"

EmagWindow::EmagWindow()
{
    board = new Emag(this);

    scoreLcd = new QLCDNumber(3);
    scoreLcd->setSegmentStyle(QLCDNumber::Filled);
    scoreLcd->setPalette(QPalette(QColor(0, 230, 0, 127)));
    scoreLcd->setAutoFillBackground(true);

    levelLcd = new QLCDNumber(2);
    levelLcd->setSegmentStyle(QLCDNumber::Filled);
    levelLcd->setPalette(QPalette(QColor(0, 230, 0, 127)));
    levelLcd->setAutoFillBackground(true);


    livesLcd = new QLCDNumber(2);
    livesLcd->setSegmentStyle(QLCDNumber::Filled);
    livesLcd->setPalette(QPalette(QColor(0, 230, 0, 127)));
    livesLcd->setAutoFillBackground(true);

    startButton = new QPushButton(tr("&Start"));
    startButton->setFocusPolicy(Qt::NoFocus);
    quitButton = new QPushButton(tr("&Quit"));
    quitButton->setFocusPolicy(Qt::NoFocus);
    pauseButton = new QPushButton(tr("&Pause"));
    pauseButton->setFocusPolicy(Qt::NoFocus);

    connect(startButton, SIGNAL(clicked()), board, SLOT(startGame()));
    connect(quitButton , SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(pauseButton, SIGNAL(clicked()), board, SLOT(pauseGame()));
    connect(board, SIGNAL(scoreChanged(int)), scoreLcd, SLOT(display(int)));
    connect(board, SIGNAL(levelChanged(int)), levelLcd, SLOT(display(int)));
    connect(board, SIGNAL(livesChanged(int)), livesLcd, SLOT(display(int)));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createLabel(tr("LEVEL")), 0, 4);
    layout->addWidget(levelLcd, 1, 4);
    layout->addWidget(board, 0, 2, 10, 2);
    layout->addWidget(createLabel(tr("SCORE")), 2, 4);
    layout->addWidget(scoreLcd, 3, 4);
    layout->addWidget(createLabel(tr("LIVES")), 4, 4);
    layout->addWidget(livesLcd, 5, 4);
    layout->addWidget(startButton, 6, 4);
    layout->addWidget(quitButton, 7, 4);
    layout->addWidget(pauseButton, 8, 4);
    setLayout(layout);

    setWindowTitle(tr("Farm Runner"));
    resize(640, 500);
}


void center(QWidget &widget)
{
  int x, y;
  int screenWidth;
  int screenHeight;

  int WIDTH = 390;
  int HEIGHT = 460;


  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();

  x = (screenWidth - WIDTH) / 2;
  y = (screenHeight - HEIGHT) / 2;

  widget.setGeometry(x, y, WIDTH, HEIGHT);
  widget.setFixedSize(WIDTH, HEIGHT);
}

QLabel *EmagWindow::createLabel(const QString &text)
{
    QLabel *lbl = new QLabel(text);
    lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return lbl;
}