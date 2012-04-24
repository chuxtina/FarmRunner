#ifndef EMAG_H
#define EMAG_H

#include "character.h"
#include "treasure.h"
#include "bull.h"
#include "animal.h"
#include "pig.h"
#include "dog.h"
#include "doghouse.h"
#include "bee.h"
#include "heart.h"
#include "crow.h"
#include "bullet.h"
#include "chicken.h" 
#include "egg.h" 
#include "levels.h"
#include "levelone.h"
#include "leveltwo.h"
#include "levelthree.h"
#include "lose.h" 
#include "win.h" 
#include "start.h"
#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPoint>

class Emag : public QWidget
{
	Q_OBJECT
public:
	Emag(QWidget *parent = 0);
	~Emag();

protected:
	void paintEvent(QPaintEvent *event);
	void timerEvent(QTimerEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void victory();
	void checkCollision();

public slots:
    void startGame();
    void pauseGame();
    void stopGame();

signals:
     void scoreChanged(int score);
     void levelChanged(int level);
     void livesChanged(int lives);

private:
	int xCharacter;
	int yCharacter;
	int timerId;
	Character *character;
	Treasure *treasure;
	Bull *bull;
	Pig *pig;
	Dog *dog;
	Bee *bee1;
	Bee *bee2;
	Bee *bee3;
	Doghouse *doghouse;
	Heart *heart;
	Crow *crow;
	Bullet *bullet;
	Chicken *chicken;
	Egg *egg;
	Levelone *levelone;
	Leveltwo *leveltwo;
	Levelthree *levelthree;
	Lose *lose;
	Win *win;
	Start *start;
	bool gameOver;
	bool gameWon;
	bool gameStart;
	bool paused;
	int level;
	int score;
	int lives;
	int randnum;
	int rNum;

};


#endif