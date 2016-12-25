
#include "main.h"

int main()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Tank");
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutTimerFunc(20, playMoving, 1);

	player1Control();
	player2Control();

	setupRC();
	glutMainLoop();

	return 0;
}