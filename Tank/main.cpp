#include "main.h"

int main()
{

	initializate();

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Tank");
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutTimerFunc(20, tankMoving, 1);
	glutTimerFunc(20, shellMoving, 1);

	player1Control();
	player2Control();

	setupRC();
	glutMainLoop();

	return 0;
}