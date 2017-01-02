#pragma once
#include<gl/glut.h>

//定义一个浮点型的三维的向量；
struct Vector3f
{
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

//定义一个整型的三维的向量；
struct Vector3i
{
	GLint x;
	GLint y;
	GLint z;
};

//定义一个坦克的结构体；
struct Tank
{
	//坦克的位置；
	Vector3i position;
	//坦克下一步位置的增量；
	Vector3i increment;
	//坦克的颜色；
	Vector3f RBG;
	//坦克的种类；
	GLint type;
	//坦克的运动方向,相对于X轴顺时针旋转的角度；
	GLint direction;
	//坦克的生命值；
	GLfloat HP;
	//坦克的速度；
	GLfloat speed;
	//坦克发射子弹的时间间隔；
	GLfloat time;
	//指向下一个坦克的指针;
	Tank *next;
	//判断坦克是否存在；
	GLboolean isAlive;

};

struct Shell
{
	//当前子弹的位置；
	Vector3i position;
	//子弹下一步的位置；
	Vector3i increment;
	//子弹的最大运动距离；
	GLint power;
	//子弹的运动速度；
	GLfloat speed;
	//子弹的类型；
	GLint type;
	//指向下一个子弹的指针
	Shell *next;
	//判断子弹是否存在；
	GLboolean isAlive;
};