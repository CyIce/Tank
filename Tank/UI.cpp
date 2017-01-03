#include "UI.h"
#include<stdio.h>
void score()
{
	rank();

	char score1[8], score2[8];

	itoa(player1Score, score1, 10);
	itoa(player2Score, score2, 10);

	glColor3f(1, 0, 0);
	glRasterPos3f(420, 160, 0);
	drawString("Play1:  ");	
	glRasterPos3f(440, 160, 0);
	drawString(score1);

	glColor3f(1, 0.4, 0);
	glRasterPos3f(420, 140, 0);
	drawString("Play2:  ");
	glRasterPos3f(440, 140, 0);
	drawString(score2);
}

void rank()
{
	//updateRank();

	FILE *fp;

	if ((fp = fopen("Gold", "r")) == NULL)
	{
		return;
	}

	char score[8];

	fscanf(fp, "%s", score);

	glColor3f(0.7, 0.84, 0.3);
	glRasterPos3f(420, 210, 0);
	drawString("Gold:  ");
	glRasterPos3f(440, 210, 0);
	drawString(score);

	fclose(fp);

	if ((fp = fopen("Silver", "r")) == NULL)
	{
		return;
	}

	fscanf(fp, "%s", score);

	glColor3f(0.7, 0.6, 0.3);
	glRasterPos3f(420, 200, 0);
	drawString("Silver:  ");
	glRasterPos3f(440, 200, 0);
	drawString(score);

	fclose(fp);

	if ((fp = fopen("Bronze", "r")) == NULL)
	{
		return;
	}


	fscanf(fp, "%s", score);

	glColor3f(0.7, 0.7, 0.6);
	glRasterPos3f(420, 190, 0);
	drawString("Bronze:  ");
	glRasterPos3f(440,190, 0);
	drawString(score);

	fclose(fp);
	updateRank();
}

void gameOver(GLint value)
{	
	if (gameState >= 3 )
	{
		glColor3f(0.46, 0.65, 0.3);
		glRasterPos3f(200, 150, 0);
		drawString("GameOver!");
          
	}

	glutTimerFunc(20, gameOver, 1);
}

void updateRank()
{
	FILE *fp1, *fp2, *fp3;

	if ((fp1 = fopen("Gold", "r")) == NULL)
	{
		return;
	}
	if ((fp2 = fopen("Bronze", "r")) == NULL)
	{
		return;
	}
	if ((fp3= fopen("Silver", "r")) == NULL)
	{
		return;
	}

	int Gold, Silver, Bronze;

	fscanf(fp1, "%d", &Gold);
	fscanf(fp2, "%d", &Silver);
	fscanf(fp3, "%d", &Bronze);

	fclose(fp1);
	fclose(fp2);
	fclose(fp3);

	if (player1Score + player2Score > Gold)
	{
		Bronze = Silver;
		Silver = Gold;
		Gold = player1Score + player2Score;		
	}
	else if (player1Score + player2Score > Silver)
	{
		Bronze = Silver;
		Silver = player1Score + player2Score;	
	}
	else if (player1Score + player2Score > Bronze)
	{
		Bronze = player1Score;
	}

	if ((fp1 = fopen("Gold", "w")) == NULL)
	{
		return;
	}
	if ((fp2 = fopen("Bronze", "w")) == NULL)
	{
		return;
	}
	if ((fp3 = fopen("Silver", "w")) == NULL)
	{
		return;
	}

	fprintf(fp1, "%d", Gold);
	fprintf(fp2, "%d", Silver);
	fprintf(fp3, "%d", Bronze);

	fclose(fp1);
	fclose(fp2);
	fclose(fp3);

}

