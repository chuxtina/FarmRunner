#include "emag.h"
#include "emagwindow.h"

#include <QDesktopWidget>
#include <QApplication>

/*void center(QWidget &widget)
{
	int x;
	int y;
	int screenWidth;
	int screenHeight;

	int WIDTH = 300;
	int HEIGHT = 400;

	QDesktopWidget *desktop = QApplication::desktop();

	screenHeight = desktop -> height();
	screenWidth = desktop -> width();

	x = (screenWidth - WIDTH) / 2;
	y = (screenHeight - HEIGHT) / 2;

	widget.setGeometry(x, y, WIDTH, HEIGHT);
	widget.setFixedSize(WIDTH, HEIGHT);

	widget.setMouseTracking(true);
}
*/
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);  
    
	//Emag window;
  	EmagWindow window;
	window.setWindowTitle("Farm Runner");
	window.show();
	//center(window);

	return app.exec();
}