#include "graphics.h"

void setupRC()
{
	glClearColor(0, 0, 1, 1);
}

void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//����������Ϸ��ң�
	tankShowing();

	//generateBlock(0,0,0);
	//test();

	shellShowing();

	score();

	glutSwapBuffers();
}

void changeSize(GLsizei w, GLsizei h)
{

	if (h == 0)		h = 1;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	if (w <= h)
	{
		windowHeight = 250 * h / w;
		windowWidth = 250;
	}
	else
	{
		windowWidth = 250 * w / h;
		windowHeight = 250;
	}

	glOrtho(0, windowWidth, 0, windowHeight, 1, -1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	mapWidth = int(windowWidth*1.6);
	mapHeight = windowHeight;

	gameBoundary();
}
