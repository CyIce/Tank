
#include "prefabs.h"

#include "global.h"

void generateTank(Tank tank)
{
	//test();
	//旋转坦克;
	glPushMatrix();
	glTranslatef(tank.position.x + 10, tank.position.y + 10, 0);
	glRotatef(tank.direction, 0, 0, -1);
	glTranslatef(-(tank.position.x + 10), -(tank.position.y + 10), 0);

	//两节履带；
	glColor3f(tank.RBG.x*0.9, tank.RBG.y*0.9, tank.RBG.z*0.9);
	glRectf(tank.position.x, tank.position.y, tank.position.x + 5, tank.position.y + 15);
	glRectf(tank.position.x + 15, tank.position.y, tank.position.x + 20, tank.position.y + 15);

	//履带的线条；
	glLineWidth(5);
	glColor3f(tank.RBG.x*0.84, tank.RBG.y*0.84, tank.RBG.z*0.84);
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
	glColor3f(tank.RBG.x*0.92, tank.RBG.y*0.92, tank.RBG.z*0.92);
	glRectf(tank.position.x + 6, tank.position.y + 3, tank.position.x + 14, tank.position.y + 12);

	//坦克炮台
	glColor3f(tank.RBG.x, tank.RBG.y, tank.RBG.z);
	glRectf(tank.position.x + 8, tank.position.y + 6, tank.position.x + 12, tank.position.y + 10);

	//坦克炮筒；
	glColor3f(tank.RBG.x*0.86, tank.RBG.y*0.86, tank.RBG.z*0.86);
	glRectf(tank.position.x + 9, tank.position.y + 7, tank.position.x + 11, tank.position.y + 19);


	//test;

	glPopMatrix();
}

void generateShell(Shell shell)
{
	glPointSize(7.0f);

	glColor3f(0.7, 0.5, 0.7);
	glBegin(GL_POINTS);

	glVertex3f(shell.position.x, shell.position.y, shell.position.z);

	glEnd();
}

void generateBlock(GLint x, GLint y, GLint color)
{
	glColor3f(0.7, 0.5, 0.7);
	glRectf(x, y, x + 10, y + 10);
}

void test()
{
	int i, j;
	
	glColor3f(0.7, 0.5, 0.7);

	for (i = 0; i <= 900; i++)
	{
		for (j = 0; j <= 900; j++)
		{
			if (map[i][j] == 4)
			{
				glBegin(GL_POINTS);
				glVertex3i(i, j, 0);
				glEnd();
			}
		}
	}
}