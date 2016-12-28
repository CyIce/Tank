#include "main.h"

int main()
{
	player1.position.x = 100;
	player1.position.y = 100;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Tank");
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutTimerFunc(20, playMoving, 1);
	glutTimerFunc(20, shellMoving, 1);

	player1Control();
	player2Control();

	setupRC();
	glutMainLoop();

	return 0;
}