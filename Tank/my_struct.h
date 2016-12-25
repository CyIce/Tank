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
	GLuint direction;
	//坦克的生命值；
	GLfloat HP;
	//坦克的速度；
	GLfloat speed;

};

struct Shell
{
	//当前子弹的位置；
	Vector3 position;
	//子弹下一步的位置；
	Vector3 increment;
	//子弹的最大运动距离；
	GLuint power;
	//子弹的运动速度；
	GLfloat speed;
	//子弹的类型；
	GLuint type;
	//指向下一个子弹的指针
	Shell *next;
};