#pragma once
#include<gl/glut.h>

//����һ�������͵���ά��������
struct Vector3f
{
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

//����һ�����͵���ά��������
struct Vector3i
{
	GLint x;
	GLint y;
	GLint z;
};

//����һ��̹�˵Ľṹ�壻
struct Tank
{
	//̹�˵�λ�ã�
	Vector3i position;
	//̹����һ��λ�õ�������
	Vector3i increment;
	//̹�˵���ɫ��
	Vector3f RBG;
	//̹�˵����ࣻ
	GLint type;
	//̹�˵��˶�����,�����X��˳ʱ����ת�ĽǶȣ�
	GLint direction;
	//̹�˵�����ֵ��
	GLfloat HP;
	//̹�˵��ٶȣ�
	GLfloat speed;
	//̹�˷����ӵ���ʱ������
	GLfloat time;
	//ָ����һ��̹�˵�ָ��;
	Tank *next;
	//�ж�̹���Ƿ���ڣ�
	GLboolean isAlive;

};

struct Shell
{
	//��ǰ�ӵ���λ�ã�
	Vector3i position;
	//�ӵ���һ����λ�ã�
	Vector3i increment;
	//�ӵ�������˶����룻
	GLint power;
	//�ӵ����˶��ٶȣ�
	GLfloat speed;
	//�ӵ������ͣ�
	GLint type;
	//ָ����һ���ӵ���ָ��
	Shell *next;
	//�ж��ӵ��Ƿ���ڣ�
	GLboolean isAlive;
};