#include "emag.h"
#include <QPainter>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <QApplication>
#include <iostream>

Emag::Emag(QWidget *parent) : QWidget(parent)
{
	setFocusPolicy(Qt::StrongFocus);
	setMouseTracking(true);
	xCharacter = 0;
	yCharacter = 0;
	gameOver = false;
	gameWon = false;
	paused = false;
	gameStart = false;
	level=1;
	score=0;
	lives=10;
	randnum=0;
	character = new Character();
	treasure = new Treasure();
	bull = new Bull();
	pig = new Pig();
	dog = new Dog();
	bee1 = new Bee();
	bee2 = new Bee();
	bee3 = new Bee();
	doghouse = new Doghouse();
	heart = new Heart();
	crow = new Crow();
	bullet = new Bullet();
	chicken = new Chicken();
	egg = new Egg();
	levelone = new Levelone();
	leveltwo = new Leveltwo();
	levelthree = new Levelthree();
	lose = new Lose();
	win = new Win();
	start = new Start();

	setPalette(QPalette(QColor(250,250,200,127)));
	setAutoFillBackground(true);
}

Emag::~Emag()
{
	delete character;
	delete treasure;
	delete bull;
	delete pig;
	delete dog;
	delete bee1;
	delete bee2;
	delete bee3;
	delete doghouse;
	delete heart;
	delete crow;
	delete bullet;
	delete chicken;
	delete egg;
	delete levelone;
	delete leveltwo;
	delete levelthree;
	delete start;
}

void Emag::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	if(!gameStart && (!gameOver && !gameWon))
		painter.drawImage(start->getRect(), start->getImage());
	else if(gameWon){
		painter.drawImage(win->getRect(), win->getImage());
		QFont font("Courier", 20, QFont::DemiBold);
    	QFontMetrics fm(font);
	    int textWidth = fm.width("You Win!");

	    painter.setFont(font);
	    int h = height();
	    int w = width();

	    painter.translate(QPoint(w/4, h/2-60));
	    painter.drawText(textWidth/2, 0, "You Win!");
	}
	else if(gameOver){
		painter.drawImage(lose->getRect(), lose->getImage());
		QFont font("Courier", 20, QFont::DemiBold);
    	QFontMetrics fm(font);
	    int textWidth = fm.width("Game Over");

	    painter.setFont(font);
	    int h = height();
	    int w = width();

	    painter.translate(QPoint(w/4, h/2+40));
	    painter.drawText(textWidth/2, 0, "Game Over");
	}
  	/*else if(gameWon) 
  	{
	    QFont font("Courier", 15, QFont::DemiBold);
	    QFontMetrics fm(font);
	    int textWidth = fm.width("Victory");

	    painter.setFont(font);
	    int h = height();
	    int w = width();

	    painter.translate(QPoint(w/4, h/2));
	    painter.drawText(-textWidth/2, 0, "Level Up!");
	    startGame();
  	}*/
	else
	{
		if(level==1)
			painter.drawImage(levelone->getRect(), levelone->getImage());
		else if (level==2)
			painter.drawImage(leveltwo->getRect(), leveltwo->getImage());
		else if(level>=3)
			painter.drawImage(levelthree->getRect(), levelthree->getImage());

		painter.drawImage(character->getRect(), character->getImage());
		painter.drawImage(treasure->getRect(), treasure->getImage());

		if(bull->isAppear())
			painter.drawImage(bull->getRect(), bull->getImage());

		if(pig->isAppear())
			painter.drawImage(pig->getRect(), pig->getImage());

		if(dog->isAppear())
			painter.drawImage(dog->getRect(), dog->getImage());
		if(bee1->isAppear())
			painter.drawImage(bee1->getRect(), bee1->getImage());
		if(bee2->isAppear())
			painter.drawImage(bee2->getRect(), bee2->getImage());
		if(bee3->isAppear())
			painter.drawImage(bee3->getRect(), bee3->getImage());

		if(heart->isAppear())
			painter.drawImage(heart->getRect(), heart->getImage());

		if(level>1)
			painter.drawImage(doghouse->getRect(), doghouse->getImage());

		if(level>=3)
		{
		painter.drawImage(crow->getRect(), crow->getImage());
		painter.drawImage(bullet->getRect(), bullet->getImage());
		}

		if(level>=2)
		{
			painter.drawImage(chicken->getRect(), chicken->getImage());

			painter.drawImage(egg->getRect(), egg->getImage());
		}
	}
}

void Emag::timerEvent(QTimerEvent *event)
{
	character->automove();	
	bull->automove();		
	pig->automove();
	bee1->automove();
	bee2->automove();
	bee3->automove();


	srand ( time(NULL) );

	randnum = rand() % 19;

	srand ( time(NULL) );

	rNum = rand() % 20;

	if(rNum==15)
	{
		heart->resetState();
		heart->setAppear(true);
	}
	if(pig->isAppear()==false)
	{
		if(rNum%2==0)
		{
			pig->setAppear(true);
		}
	}

	if(bull->isAppear()==false)
	{
		if(rNum%2==0)
		{
			bull->setAppear(true);
		}
	}

//bee movement
	switch(randnum) {
	case 0:
		bee1->setXD(1);
	case 1:
		bee2->setXD(1);
		break;
	case 2: 
		bee3->setXD(0);
		break;
	case 3:
		bee2->setXD(1);
		break;
	case 4:
		bee3->setXD(0);
		break;
	case 5:
		bee1->setXD(-1);
	case 6:
		bee3->setXD(1);
		break;
	case 7:
		bee1->setXD(0);
		break;
	case 8:
		bee2->setXD(-1);
		break;
	case 9:
		bee1->setYD(1);
	case 10:
		bee2->setYD(0);
		break;
	case 11:
		bee3->setYD(-1);
		break;
	case 12:
		bee2->setYD(1);
		break;
	case 13:
		bee3->setYD(0);
	case 14:
		bee1->setYD(-1);
		break;
	case 15:
		bee3->setYD(1);
		break;
	case 16:
		bee1->setYD(0);
	case 17:
		bee2->setYD(-1);
	default:
		bee3->setYD(1);
	}

		//Horizontal movement
	
		if ((character->getRect().x() - dog->getRect().x()) > 7 )
		{
			dog->setXD(1);
		}
		else if ((character->getRect().x() - dog->getRect().x()) < -7 )
		{
			dog->setXD(-1);
		}
		else
		{	
			dog->setXD(0);
		}

	//vertical movement
		if ((character->getRect().y() - dog->getRect().y()) > 7 )
		{
			dog->setYD(1);
		}
		else if ((character->getRect().y() - dog->getRect().y()) < -7 )
		{
			dog->setYD(-1);
		}
		else
		{	
			dog->setYD(0);
		}

	dog->automove();


	//crow movement

	if(level>=3)
	{

		if ((character->getRect().y() - crow->getRect().y()) > 0 )
		{
			crow->setYD(1);
		}
		else if ((character->getRect().y() - crow->getRect().y()) < 0 )
		{
			crow->setYD(-1);
		}
		else
		{	
			crow->setYD(0);
		}

		crow->automove();

			
		//bullet movement
		if(randnum%3==0  && bullet->isAppear() == false){
			bullet->setPosition(50, crow->getRect().y());
			bullet->setAppear(true);
			
		}					//insert automove thing here too....

		if (bullet->isAppear() == true)
			bullet->automove();

	}

	if(level>=2)
	{
	//chicken movement
		if ((character->getRect().x() - chicken->getRect().x()) > 0 )
		{
			chicken->setXD(1);
		}
		else if ((character->getRect().x() - chicken->getRect().x()) < 0 )
		{
			chicken->setXD(-1);
		}
		else
		{	
			chicken->setXD(0);
		}

	chicken->automove();

	//egg movement
	if(rNum%3==0  && egg->isAppear() == false){
		egg->setPosition(chicken->getRect().x(),0);
		egg->setAppear(true);
		
	}					//insert automove thing here too....

	if (egg->isAppear() == true)
		egg->automove();

	}

	checkCollision();
	repaint();
}

void Emag::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
		case Qt::Key_Left:
			{
				int xCharacter = character->getRect().x();
				for (int i = 0; i < 20; i++)
					character->moveLeft(xCharacter--);
			}
			break;
		case Qt::Key_Right:
			{
				int xCharacter = character->getRect().x();
				for (int i = 0; i < 20; i++)
					character->moveRight(xCharacter++);
			}
			break;
		case Qt::Key_Up:
			{
				int yCharacter = character->getRect().y();
				for (int i = 0; i < 20; i++)
					character->moveUp(yCharacter--);
			}
			break;
		case Qt::Key_Down:
			{
				int yCharacter = character->getRect().y();
				for (int i = 0; i < 20; i++)
					character->moveDown(yCharacter++);
			}
			break;
		case Qt::Key_P:
			{
				pauseGame();
			}
			break;
		case Qt::Key_Space:
			{
				startGame();
			}
			break;
		case Qt::Key_Escape:
			{
				qApp->exit();
			}
			break;
		default:
			QWidget::keyPressEvent(event);
	}
}

void Emag::mouseMoveEvent(QMouseEvent *event)
{
	QPoint pos = event -> pos();

	//Horizontal movement
	if ((pos.x() - character->getRect().x()) > 7 )
	{
		character->setXD(2);
	}
	else if ((pos.x() - character->getRect().x()) < -7 )
	{
		character->setXD(-2);
	}
	else
	{	
		character->setXD(0);
	}

	//vertical movement
	if ((pos.y() - character->getRect().y()) > 7 )
	{
		character->setYD(2);
	}
	else if ((pos.y() - character->getRect().y()) < -7 )
	{
		character->setYD(-2);
	}
	else
	{	
		character->setYD(0);
	}
}


void Emag::startGame()
{
	if (!gameStart)
	{
		character->resetState();
		treasure->resetState();
		bull->resetState();
		pig->resetState();

		level = 1; 
		score = 0;
		lives = 5; 

		gameOver = false;
		gameWon = false;
		gameStart = true;
		emit scoreChanged(score);
    	emit levelChanged(level);
    	emit livesChanged(lives);
		timerId = startTimer(10);
	}
}

void Emag::pauseGame()
{
	if (paused && gameStart)
	{
		timerId = startTimer(10);
		paused = false;
	}
	else
	{
		paused = true;
		killTimer(timerId);
	}
}

void Emag::stopGame()
{
	killTimer(timerId);
	gameOver = true;
	gameStart = false;
	score=0;
	level=0;
}

void Emag::victory()
{
	killTimer(timerId);
	gameWon = true;
	//level++;
	gameStart = false;
}

void Emag::checkCollision()
{
	srand ( time(NULL) );

	if (bull->getRect().x()==450)
			bull->resetState();	

	if(score==35)
		victory();
	if(!gameOver){
		emit scoreChanged(score);
		emit livesChanged(lives);
	}
		
	if (character->getRect().intersects(treasure->getRect()) == true)
	{
		score++;// Add stuff about score
		srand ( time(NULL) );
		treasure->resetState();
		bee1->setAppear(true);
		if(score==5)
		{
			level++;
			emit levelChanged(level);
			bee1->setAppear(true);
			bee2->setAppear(true);
		}
		if(score==15)
		{
			level++;
			emit levelChanged(level);
			bee3->setAppear(true);
		}
		if(score==25)
		{
			level++;
			emit levelChanged(level);
		}	
		if((score>=25 && score%10==0) || lives>15)
		{
			bee1->setAppear(true);
			bee2->setAppear(true);
			if(score%3==0)
				bee3->setAppear(true);
		}
	}
	if (character->getRect().intersects(pig->getRect())==true && pig->isAppear()==true)
	{
		lives--;
		character->resetState();
		pig->setAppear(false);
	}
	if (character->getRect().intersects(bull->getRect())==true && bull->isAppear()==true)
	{
		lives--;
		character->resetState();
		bull->setAppear(false);
	}

//dog hitting bee
	if(dog->getRect().intersects(bee1->getRect())==true && dog->isAppear()==true)
	{
		bee1->setAppear(false);
	} 
	if(dog->getRect().intersects(bee2->getRect())==true && dog->isAppear()==true)
	{
		bee2->setAppear(false);
	}
	if(dog->getRect().intersects(bee3->getRect())==true && dog->isAppear()==true)
	{
		bee3->setAppear(false);
	}

//jack hitting bee
	if (character->getRect().intersects(bee1->getRect())==true && bee1->isAppear()==true)
	{
		//if(randnum%2==0){
			lives--;
			bee1->setAppear(false);
		//}
		character->resetState();
		bee1->setPosition(rand()%386 + 1, rand()%458 + 1);
	}
	if (character->getRect().intersects(bee2->getRect())==true && bee2->isAppear()==true)
	{
		//if(randnum%2==0){
			lives--;
			bee2->setAppear(false);
		//}
			
		character->resetState();
		bee1->setPosition(rand()%386 + 1, rand()%458 + 1);
	}
		if (character->getRect().intersects(bee3->getRect())==true && bee3->isAppear()==true)
	{
		//if(randnum%2==0){
			lives--;
			bee3->setAppear(false);
		//}
		character->resetState();
		bee1->setPosition(rand()%386 + 1, rand()%458 + 1);
	}

//jack hitting doghouse
	if (character->getRect().intersects(doghouse->getRect())==true)
	{	
		srand ( time(NULL) );
		if(dog->isAppear()==false)	
			dog->setAppear(true);
		else
			dog->setAppear(false);
		doghouse->resetState();
	}

//jack hitting heart
	if (character->getRect().intersects(heart->getRect())==true && heart->isAppear()==true)
	{	
		srand ( time(NULL) );
		lives+=1;
		emit livesChanged(lives);
		heart->setAppear(false);
		heart->resetState();
	}
//bullet hitting jack
	if(character->getRect().intersects(bullet->getRect())==true && bullet->isAppear()==true)
	{
		lives--;
		bullet->setAppear(false);
	}

//egg hitting jack
	if(character->getRect().intersects(egg->getRect())==true && egg->isAppear()==true)
	{
		lives--;
		egg->setAppear(false);
	}

		
	if(lives==0)
	{
		emit livesChanged(lives);
		gameOver==true;
		stopGame();
	}

}

