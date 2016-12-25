
#include "main.h"

int main()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Tank");
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutTimerFunc(20, playMoving, 1);

	glutSpecialFunc(processSpecialKeys);
	glutSpecialUpFunc(processSpecialKeysUp);

	glutKeyboardFunc(processKeys);
	glutKeyboardUpFunc(processKeysUp);

	setupRC();
	glutMainLoop();

	return 0;
}