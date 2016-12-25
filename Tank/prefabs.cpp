
#include "prefabs.h"

void generateTank(tank tank)
{

	//旋转坦克;
	glPushMatrix();
	glTranslatef(tank.position.x + 10, tank.position.y + 7, 0);
	glRotatef(tank.direction, 0, 0, -1);
	glTranslatef(-(tank.position.x + 10), -(tank.position.y + 7), 0);

	//两节履带；
	glColor3f(tank.RBG.x, tank.RBG.y, tank.RBG.z);
	glRectf(tank.position.x, tank.position.y, tank.position.x + 5, tank.position.y + 15);
	glRectf(tank.position.x + 15, tank.position.y, tank.position.x + 20, tank.position.y + 15);

	//履带的线条；
	glLineWidth(5);
	glColor3f(tank.RBG.x, tank.RBG.y, tank.RBG.z);
	glBegin(GL_LINES);
	for (int i = 1; i <= 5; i++)
	{

		glVertex3f(tank.position.x + 0.5, tank.position.y + 1 + 2 * i, 0);
		glVertex3f(tank.position.x + 5, tank.position.y + 1 + 2 * i, 0);
	}
	for (int i = 1; i <= 5; i++)
	{
		glVertex3f(tank.position.x + 19.5, tank.position.y + 1 + 2 * i, 0);
		glVertex3f(tank.position.x + 15, tank.position.y + 1 + 2 * i, 0);
	
	}
	glEnd();

	/*
	//血量环；
	GLfloat i, r, a, b, step;
	a = tank.position.x + 10;
	b = tank.position.y + 8;
	r = 12;
	step = (2 * PI) / 101;

	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
	glColor3f(1, 0.2, 0);
	for (i = 0; i <= 200; i += step)
	{
		glVertex3f(a + r*cos(i), b + r*sin(i), 0);
	}
	glEnd();
	*/

	//坦克中心；
	glColor3f(tank.RBG.x, tank.RBG.y, tank.RBG.z);
	glRectf(tank.position.x + 6, tank.position.y + 3, tank.position.x + 14, tank.position.y + 12);

	//坦克炮台
	glColor3f(tank.RBG.x, tank.RBG.y, tank.RBG.z);
	glRectf(tank.position.x + 8, tank.position.y + 6, tank.position.x + 12, tank.position.y + 10);

	//坦克炮筒；
	glColor3f(tank.RBG.x, tank.RBG.y, tank.RBG.z);
	glRectf(tank.position.x + 9, tank.position.y + 7, tank.position.x + 11, tank.position.y + 19);

	glPopMatrix();
}
