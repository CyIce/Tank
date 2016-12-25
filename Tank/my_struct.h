#pragma once
#include<gl/glut.h>

//定义一个三维的向量；
struct Vector3
{
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

//定义一个坦克的结构体；
struct Tank
{
	//坦克的位置；
	Vector3 position;
	//坦克下一步位置的增量；
	Vector3 increment;
	//坦克的颜色；
	Vector3 RBG;
	//坦克的运动方向,相对于X轴顺时针旋转的角度；
	GLfloat direction;
	//坦克的生命值；
	GLfloat HP;
	//坦克的速度；
	GLfloat speed;

};

struct shell
{
	Vector3 position;
	Vector3 direcion;
	GLfloat lifetime;
	GLfloat speed;
};